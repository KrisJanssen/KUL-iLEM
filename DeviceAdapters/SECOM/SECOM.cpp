// TODO: add header

#include "SECOM.h"
#include "../../micromanager/MMDevice/ModuleInterface.h"
#include <sstream>
#include <cstdio>
#include <time.h>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define snprintf _snprintf 
#endif

const char* g_DeviceNameSECOMHub = "SECOM-Hub";
const char* g_DeviceNameSECOMSampleXY = "SECOM-Sample-XY";
const char* g_DeviceNameSECOMObjectiveXY = "SECOM-Objective-XY";
const char* g_DeviceNameSECOMObjectiveZ = "SECOM-Objective-Z";

// Exported MMDevice API
/*
  When creating a Dynamic Link Library (dll) only functions which are explicitly exported can be
  used by external executables. All other functions can only be called from within the dll itself.
  To allow Micro-Manager to load device adapters, a Module API was created. The functions of this API
  need to be implemented in a custom Device Adapter dll and exposed to Micro Manager through export.
  To make the export process easy, a macro was defined in ModuleInterface.h:

  #define MODULE_API __declspec(dllexport).
*/
/*
  Tell Micro-Manager what types of devices are in this module and how they are called.
  This is what will be seen in the Device Manager.
*/
MODULE_API void InitializeModuleData()
{
	RegisterDevice(g_DeviceNameSECOMHub, MM::HubDevice, "SECOM Hub (required)");
	RegisterDevice(g_DeviceNameSECOMSampleXY, MM::XYStageDevice, "SECOM Stage XY");
	RegisterDevice(g_DeviceNameSECOMObjectiveXY, MM::XYStageDevice, "SECOM Objective XY");
	RegisterDevice(g_DeviceNameSECOMObjectiveZ, MM::StageDevice, "SECOM Objective Z");
}

/*
  Here, we instruct Micro-Manager which class to instantiate when a device with a specific
  devicename is created.
*/
MODULE_API MM::Device* CreateDevice(const char* deviceName)
{
	if (deviceName == 0)
		return 0;

	if (strcmp(deviceName, g_DeviceNameSECOMHub) == 0)
	{
		return new CSECOMStageHub;
	}
	else if (strcmp(deviceName, g_DeviceNameSECOMSampleXY) == 0)
	{
		// The addresses used here are hard-wired values of the setup.
		return new CSECOMStageXY(true, '4', '5');
	}
	else if (strcmp(deviceName, g_DeviceNameSECOMObjectiveXY) == 0)
	{
		// The addresses used here are hard-wired values of the setup.
		return new CSECOMStageXY(false, '1', '2');
	}
	else if (strcmp(deviceName, g_DeviceNameSECOMObjectiveZ) == 0)
	{
		return new CSECOMStageZ; // channel 1
	}

	return 0;
}

MODULE_API void DeleteDevice(MM::Device* pDevice)
{
	delete pDevice;
}

/*
  For the SECOM platform, one E-861 controller acts as the master device in a 5 controller daisy chain.
  This configuration can be abstracted by using the "Hub" arrangement in Micro-Manager.
*/
CSECOMStageHub::CSECOMStageHub()
	: controllerType_("E-861")
	, dllName_("PI_GCS2_DLL_X64.dll")
	, initialized_(false)
	, interfaceParameter_("PI E-861 PiezoWalk(R) Controller SN 0112000802")
	, isSerialBusy_(false)
	, slewrate_(1.0)
{
	portAvailable_ = false;

	InitializeDefaultErrorMessages();

	SetErrorText(COM_ERROR, "COM Error");
	SetErrorText(PI_CNTR_NO_ERROR, "No Error");
	SetErrorText(PI_CNTR_UNKNOWN_COMMAND, "Unknown Command");

	/*
	  Here, we create a property of the Hub, it's port. This port wille be the COM
	  port through which we will communicate with the controller. Additionally,
	  we hook up a property action, i.e. a method that will be called when the property
	  value is requested or updated.
	*/
	//CPropertyAction* pAct = new CPropertyAction(this, &CSECOMStageHub::OnPort);
	//CreateProperty(MM::g_Keyword_Port, "Undefined", MM::String, false, pAct, true);
}

CSECOMStageHub::~CSECOMStageHub()
{
	//Shutdown();
	CloseAndUnload();
}

void CSECOMStageHub::GetName(char* name) const
{
	CDeviceUtils::CopyLimitedString(name, g_DeviceNameSECOMHub);
}

// TODO: Check if we can add "real" functionality here.
bool CSECOMStageHub::Busy()
{
	/*int ready = 0;
	IsControllerReady_(ID_, &ready);
	return (bool)ready;*/
	return false;
}

// TODO: implement properly...
MM::DeviceDetectionStatus CSECOMStageHub::DetectDevice(void)
{
	// If the device is initialized already, return a positive result. No need to do the other stuff.
	if (initialized_)
		return MM::CanCommunicate;

	// The device is not initialized yet so initially we set a negative result.
	MM::DeviceDetectionStatus result = MM::Misconfigured;

	//// Reserve space for the controller answer.
	//char answerTO[MM::MaxStrLength];

	//try
	//{
	//	std::string portLowerCase = controllerType_;

	//	// Iterate the string character by character and convert to lowercase.
	//	for (std::string::iterator its = portLowerCase.begin(); its != portLowerCase.end(); ++its)
	//	{
	//		*its = (char)tolower(*its);
	//	}


	//	if (0 < portLowerCase.length() && 0 != portLowerCase.compare("undefined") && 0 != portLowerCase.compare("unknown"))
	//	{
	//		result = MM::CanNotCommunicate;

	//		// record the default answer time out
	//		GetCoreCallback()->GetDeviceProperty(controllerType_.c_str(), "AnswerTimeout", answerTO);

	//		GetCoreCallback()->SetDeviceProperty(controllerType_.c_str(), MM::g_Keyword_Handshaking, "Off");
	//		GetCoreCallback()->SetDeviceProperty(controllerType_.c_str(), MM::g_Keyword_BaudRate, "115200");
	//		GetCoreCallback()->SetDeviceProperty(controllerType_.c_str(), MM::g_Keyword_StopBits, "1");
	//		GetCoreCallback()->SetDeviceProperty(controllerType_.c_str(), "AnswerTimeout", "500.0");
	//		GetCoreCallback()->SetDeviceProperty(controllerType_.c_str(), "DelayBetweenCharsMs", "0");

	//		MM::Device* pS = GetCoreCallback()->GetDevice(this, controllerType_.c_str());
	//		pS->Initialize();

	//		// to succeed must reach here....
	//		result = MM::CanCommunicate;

	//		pS->Shutdown();
	//		// always restore the AnswerTimeout to the default
	//		GetCoreCallback()->SetDeviceProperty(controllerType_.c_str(), "AnswerTimeout", answerTO);

	//	}
	//}
	//catch (...)
	//{
	//	LogMessage("Exception in DetectDevice!", false);
	//}

	//return result;

	return MM::CanCommunicate;
}

/*
  The Initialize() and Shudown() methods are critical to ensure that Device Adapter 
  behaves as expected within Micro-manager environment. 
  Rules for implementing these two methods are as follows:

  * The Device Adapter instance does not communicate with hardware before Initialize() is called for the first time.
  * Initialize() establishes the connection with the hardware and makes device ready to accept commands
  * Once the device is successfully initialized, repeated calls to Initialize() (if they occur) should have no effect
  * Shutdown() disconnects Device Adapter from the hardware and practically reverses the effect of Initialize()
  * Once the device is successfully shut down, repeated calls to Shutdown() should not have any effect
  * After Shutdown() is called device should never attempt to communicate with the hardware, except after Inititalize() is called again
*/
int CSECOMStageHub::Initialize()
{
	// If initialized, return immediately (rule 3).
	if (initialized_)
		return DEVICE_OK;

	// Try and load the dll.
	int ret = LoadDLL(dllName_);

	// If the dll cannot be loaded, inform the user and clean up.
	if (ret != DEVICE_OK)
	{
		LogMessage(std::string("Cannot load dll ") + dllName_);
		Shutdown();
		return ret;
	}

	// Connect.
	ret = ConnectUSB(interfaceParameter_);
	
	// In case of trouble, inform the user and clean up.
	if (ret != DEVICE_OK)
	{
		LogMessage("Cannot connect");
		Shutdown();
		return ret;
	}

    std::string answer("");

	ret = qGCSCommand("*IDN?", answer);

	unsigned int param = 0x7000002;

	ret = qSPA_(ID_, "1", &param, &slewrate_, NULL, MM::MaxStrLength);

	// We got here without errors o all is well.
	initialized_ = true;

	return DEVICE_OK;
}

int CSECOMStageHub::DetectInstalledDevices()
{
	// Only proceed if a the Hub was properly detected.
	if (MM::CanCommunicate == DetectDevice())
	{
		std::vector<std::string> peripherals;
		peripherals.clear();
		peripherals.push_back(g_DeviceNameSECOMSampleXY);
		peripherals.push_back(g_DeviceNameSECOMObjectiveXY);
		peripherals.push_back(g_DeviceNameSECOMObjectiveZ);

		for (size_t i = 0; i < peripherals.size(); i++)
		{
			// ::CreateDevice is part of the Module API and it is the factory that creates our devices for us.
			MM::Device* pDev = ::CreateDevice(peripherals[i].c_str());

			// If a pointer to a device is returned, add it to the list of devices for the hub.
			if (pDev)
			{
				AddInstalledDevice(pDev);
			}
		}
	}

	return DEVICE_OK;
}

int CSECOMStageHub::Shutdown()
{
	if (!initialized_)
		return DEVICE_OK;

	CloseAndUnload();
	initialized_ = false;
	return DEVICE_OK;
}

//bool CSECOMStageHub::SendGCSCommand(unsigned char singlebyte)
//{
//	int ret = 1;
//	try {
//		ret = WriteToComPort(controllerType_.c_str(), &singlebyte, 1);
//	}
//	catch (...)
//	{
//		LogMessage("Serial Error", false);
//	}
//	if (ret != DEVICE_OK)
//	{
//		lastError_ = ret;
//		return false;
//	}
//	return true;
//}
//
//bool CSECOMStageHub::SendGCSCommand(const std::string command)
//{
//	int ret = 1;
//	try {
//		ret = SendSerialCommand(controllerType_.c_str(), command.c_str(), "\n");
//	}
//	catch (...)
//	{
//		LogMessage("Serial Error", false);
//	}
//
//	if (ret != DEVICE_OK)
//	{
//		lastError_ = ret;
//		return false;
//	}
//	return true;
//}
//
//bool CSECOMStageHub::GCSCommandWithAnswer(const std::string command, std::vector<std::string>& answer, int nExpectedLines)
//{
//	if (!SendGCSCommand(command))
//		return false;
//	return ReadGCSAnswer(answer, nExpectedLines);
//}
//
//bool CSECOMStageHub::GCSCommandWithAnswer(unsigned char singlebyte, std::vector<std::string>& answer, int nExpectedLines)
//{
//	if (!SendGCSCommand(singlebyte))
//		return false;
//	return ReadGCSAnswer(answer, nExpectedLines);
//}

bool CSECOMStageHub::DoReset(char device)
{
	int count = -1;
	std::ostringstream command;
	std::vector<std::string> answer;
	command << device << " ERR?";
	do
	{
		//GCSCommandWithAnswer(command.str(), answer, 1);
		count++;
	} while (count < 10 && answer[0][0] != '0');
	if (count < 10)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool CSECOMStageHub::GCSCommand(const char* command)
{
	std::ostringstream msg;

	try
	{
		int ret = GcsCommandset_(ID_, command);
		return ret;
	}
	catch (...)
	{
		msg.str("");
		msg.clear();
		msg << "Could not send command: " << command;
		LogMessage(msg.str());
		return false;
	}
}

bool CSECOMStageHub::qGCSCommand(const char* command, std::string& answer)
{
	std::ostringstream out;
	out.str("");
	out.clear();

	int ret = GCSCommand(command);
	int answerSz = 0;
	char reply[MM::MaxStrLength];

	std::ostringstream msg;

	try
	{
		while (answerSz <= 0)
		{
			ret = GcsGetAnswerSize_(ID_, &answerSz);

			if (answerSz > 0)
			{
				ret = GcsGetAnswer_(ID_, reply, answerSz);
				out << std::string(reply);
			}
		}

		answer = out.str();

		return ret;
	}
	catch (...)
	{
		LogMessage("Could not receive answer for command!");
		return false;
	}

	
}

//bool CSECOMStageHub::ReadGCSAnswer(std::vector<std::string>& answer, int nExpectedLines)
//{
//	answer.clear();
//	std::string line;
//	int ret = 1;
//	do
//	{
//		// block/wait for acknowledge, or until we time out;
//		try {
//			ret = GetSerialAnswer(controllerType_.c_str(), "\n", line);
//		}
//		catch (...)
//		{
//			LogMessage("Serial Error", false);
//		}
//		if (ret != DEVICE_OK)
//		{
//			lastError_ = ret;
//			return false;
//		}
//		answer.push_back(line);
//	} while (!line.empty() && line[line.length() - 1] == ' ');
//	if ((unsigned)nExpectedLines >= 0 && answer.size() != (unsigned)nExpectedLines)
//		return false;
//	return true;
//}

int CSECOMStageHub::LoadDLL(const std::string & dllName)
{
	/* All exported functions in PI libraries have a prefix which is often dll specific.
	   For PI_GCS2_DLL.dll this is "PI_".
	*/
	dllPrefix_ = "PI_";
	
	// Load the dll.
#ifdef WIN32
	module_ = LoadLibrary(dllName.c_str());
#else
	module_ = dlopen(dllName.c_str(), RTLD_LAZY);
#endif
	if (module_ == NULL)
	{
		printf("load module failed\n");
		//return ERR_DLL_PI_DLL_NOT_FOUND;
		return DEVICE_ERR;
	}

	// Assign the Function Pointers with the correct addresses.
	CloseConnection_ = (FP_CloseConnection)LoadDLLFunc("CloseConnection");
	ConnectUSB_ = (FP_ConnectUSB)LoadDLLFunc("ConnectUSB");
	EnumerateUSB_ = (FP_EnumerateUSB)LoadDLLFunc("EnumerateUSB");
	GcsCommandset_ = (FP_GcsCommandset)LoadDLLFunc("GcsCommandset");
	GcsGetAnswerSize_ = (FP_GcsGetAnswerSize)LoadDLLFunc("GcsGetAnswerSize");
	GcsGetAnswer_ = (FP_GcsGetAnswer)LoadDLLFunc("GcsGetAnswer");
	IsConnected_ = (FP_IsConnected)LoadDLLFunc("IsConnected");
	IsControllerReady_ = (FP_IsControllerReady)LoadDLLFunc("IsControllerReady");
	qSPA_ = (FP_qSPA)LoadDLLFunc("qSPA");

	// Return OK.
	return DEVICE_OK;
}

void CSECOMStageHub::CloseAndUnload()
{
	if (module_ == NULL)
		return;

	if (ID_ >= 0 && CloseConnection_ != NULL)
		CloseConnection_(ID_);

	ID_ = -1;

	// Unload the dll.
#ifdef WIN32
	FreeLibrary(module_);
	module_ = NULL;
#else
#endif
}

void* CSECOMStageHub::LoadDLLFunc(const char * funcName)
{
#ifdef WIN32
	return GetProcAddress(module_, (dllPrefix_ + funcName).c_str());
#else
	return(dlsym(module_, (dllPrefix_ + funcName).c_str()));
#endif
}

int CSECOMStageHub::ConnectUSB(const std::string & interfaceParameter)
{
	if (ConnectUSB_ == NULL || EnumerateUSB_ == NULL)
		return DEVICE_NOT_SUPPORTED;

	// Allocate sufficient space for all discovered device strings.
	char szDevices[128 * 80 + 1];

	// We enumerate all devices that feature the desired controller type as a substring in their description.
	int nrDevices = EnumerateUSB_(szDevices, 128 * 80, controllerType_.c_str());
	
	if (nrDevices < 0)
		//return TranslateError(nrDevices);
		return -1;
	if (nrDevices == 0)
		return DEVICE_NOT_CONNECTED;

	std::string deviceName;
	if (interfaceParameter_.empty())
	{
		if (nrDevices != 1)
			//return ERR_DLL_PI_INVALID_INTERFACE_PARAMETER;
			return -1;
		deviceName = szDevices;
	}
	else
	{
		//deviceName = FindDeviceNameInUSBList(szDevices, interfaceParameter);
		deviceName =  interfaceParameter;
	}
	if (deviceName.empty())
		return DEVICE_NOT_CONNECTED;

	ID_ = ConnectUSB_(deviceName.c_str());

	if (ID_<0)
		return DEVICE_NOT_CONNECTED;

	return DEVICE_OK;
}

//int CSECOMStageHub::OnPort(MM::PropertyBase* pProp, MM::ActionType pAct)
//{
//	if (pAct == MM::BeforeGet)
//	{
//		pProp->Set(controllerType_.c_str());
//	}
//	else if (pAct == MM::AfterSet)
//	{
//		pProp->Get(controllerType_);
//		portAvailable_ = true;
//	}
//	return DEVICE_OK;
//}

CSECOMStageXY::CSECOMStageXY(bool feedback, char addressX, char addressY)
	: initialized_(false),
	supportsPositionFeedback_(feedback),
	addressX_(addressX),
	addressY_(addressY)
{
	// Set up default error messages.
	InitializeDefaultErrorMessages();

	// Create a property representing the parent Hub
	CreateHubIDProperty();

	// SECOM has two XY stages. Only one of them supports position feedback but otherwise, they are identical.
	CPropertyAction* pAct = new CPropertyAction(this, &CSECOMStageXY::OnHasPositionFeedback);
	CreateProperty("HasFeedback", "Supports Position Feedback", MM::PropertyType::Integer, true, pAct, true);
	AddAllowedValue("HasFeedback", "0");
	AddAllowedValue("HasFeedback", "1");
}

CSECOMStageXY::~CSECOMStageXY()
{
	Shutdown();
}

void CSECOMStageXY::GetName(char* name) const
{
	if (supportsPositionFeedback_)
	{
		CDeviceUtils::CopyLimitedString(name, g_DeviceNameSECOMSampleXY);
	}
	else
	{
		CDeviceUtils::CopyLimitedString(name, g_DeviceNameSECOMObjectiveXY);
	}
}

int CSECOMStageXY::Initialize()
{
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	//  if (!hub || !hub->IsPortAvailable()) {
	//     return ERR_NO_PORT_SET;
	//  }
	char hubLabel[MM::MaxStrLength];
	hub->GetLabel(hubLabel);
	SetParentID(hubLabel); // for backward comp.
	int ret;

	if (supportsPositionFeedback_)
	{
		ret = CreateProperty(MM::g_Keyword_Description, "SECOM XY Stage w Feedback", MM::String, true);
		assert(DEVICE_OK == ret);

		// Name
		ret = CreateProperty(MM::g_Keyword_Name, g_DeviceNameSECOMSampleXY, MM::String, true);
		assert(DEVICE_OK == ret);
	}
	else
	{
		ret = CreateProperty(MM::g_Keyword_Description, "SECOM XY Stage wo Feedback", MM::String, true);
		assert(DEVICE_OK == ret);

		// Name
		ret = CreateProperty(MM::g_Keyword_Name, g_DeviceNameSECOMObjectiveXY, MM::String, true);
		assert(DEVICE_OK == ret);
	}

	

	CPropertyAction* pAct = new CPropertyAction(this, &CSECOMStageXY::OnFineVoltageX);
	ret = CreateProperty("Fine Voltage X", "0", MM::Float, false, pAct);
	assert(DEVICE_OK == ret);

	pAct = new CPropertyAction(this, &CSECOMStageXY::OnFineVoltageY);
	ret = CreateProperty("Fine Voltage R", "0", MM::Float, false, pAct);
	assert(DEVICE_OK == ret);

	pAct = new CPropertyAction(this, &CSECOMStageXY::OnReset);
	ret = CreateProperty("Reset?", "0", MM::Integer, false, pAct);
	assert(DEVICE_OK == ret);

	//pAct = new CPropertyAction(this, &CSECOMStageXY::OnStepVoltage);
	ret = CreateProperty("Step Voltage XP", "30.0", MM::Float, false);
	assert(DEVICE_OK == ret);
	ret = CreateProperty("Step Voltage XN", "30.0", MM::Float, false);
	assert(DEVICE_OK == ret);
	ret = CreateProperty("Step Voltage YP", "30.0", MM::Float, false);
	assert(DEVICE_OK == ret);
	ret = CreateProperty("Step Voltage YN", "30.0", MM::Float, false);
	assert(DEVICE_OK == ret);

	initialized_ = true;

	return DEVICE_OK;
}

int CSECOMStageXY::Shutdown()
{
	initialized_ = false;
	return DEVICE_OK;
}

bool CSECOMStageXY::Busy()
{
	return false;
}

int CSECOMStageXY::OnFineVoltageX(MM::PropertyBase* pProp, MM::ActionType pAct)
{
	if (pAct == MM::BeforeGet) {
		// Nothing to do, let the caller use cached property
	}
	else if (pAct == MM::AfterSet) {
		std::ostringstream command;
		CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
		double val;
		pProp->Get(val);
		// if (!hub || !hub->IsPortAvailable())
		//    return ERR_NO_PORT_SET;
		if (isFirstMoveL_)
		{
			wasLastMoveStepL_ = true;
			isFirstMoveL_ = false;
		}
		if (wasLastMoveStepL_)
		{
			command.str("");
			command.clear();
			//command << "5 RNP 1 0";
			command << addressX_;
			command << " RNP 1 0";
			hub->GCSCommand(command.str().c_str());
		}
		command.str("");
		command.clear();
		//command << "5 OAD 1 " << val;
		command << addressX_;
		command << " OAD 1 " << val;
		hub->GCSCommand(command.str().c_str());
		wasLastMoveStepL_ = false;
	}

	return DEVICE_OK;
}

int CSECOMStageXY::OnFineVoltageY(MM::PropertyBase* pProp, MM::ActionType pAct)
{
	if (pAct == MM::BeforeGet) {
		// Nothing to do, let the caller use cached property
	}
	else if (pAct == MM::AfterSet) {
		std::ostringstream command;
		CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
		double val;
		pProp->Get(val);
		// if (!hub || !hub->IsPortAvailable())
		//    return ERR_NO_PORT_SET;
		if (isFirstMoveR_)
		{
			wasLastMoveStepR_ = true;
			isFirstMoveR_ = false;
		}
		if (wasLastMoveStepR_)
		{
			command.str("");
			command.clear();
			//command << "4 RNP 1 0";
			command << addressY_;
			command << " RNP 1 0";
			hub->GCSCommand(command.str().c_str());
		}
		command.str("");
		command.clear();
		//command << "4 OAD 1 " << val;
		command << addressY_;
		command << " OAD 1 " << val;
		hub->GCSCommand(command.str().c_str());
		wasLastMoveStepR_ = false;
	}

	return DEVICE_OK;
}

int CSECOMStageXY::OnHasPositionFeedback(MM::PropertyBase * pProp, MM::ActionType pAct)
{
	if (pAct == MM::BeforeGet)
	{
		long val = (long)supportsPositionFeedback_;
		pProp->Set(val);
	}
	else if (pAct == MM::AfterSet)
	{
		long val;
		pProp->Get(val);
		supportsPositionFeedback_ = (0 == val ? false : true);
	}

	return DEVICE_OK;
}

int CSECOMStageXY::OnReset(MM::PropertyBase* pProp, MM::ActionType pAct)
{
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	if (pAct == MM::AfterSet)
	{
		pProp->Set((long)(0));
		hub->DoReset(addressX_);
		hub->DoReset(addressY_);
	}
	return DEVICE_OK;
}

int CSECOMStageXY::SetPositionSteps(long x, long y)
{
	std::ostringstream command;
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	// if (!hub || !hub->IsPortAvailable())
	//    return ERR_NO_PORT_SET;

	double val;
	if (x != 0)
	{
		if (x > 0)
		{
			GetProperty("Step Voltage XP", val);
			command.str("");
			command.clear();
			//command << "2 SSA 1 " << val;
			command << addressX_;
			command << " SSA 1 " << val;
			hub->GCSCommand(command.str().c_str());
		}
		else if (x < 0)
		{
			GetProperty("Step Voltage XN", val);
			command.str("");
			command.clear();
			//command << "2 SSA 1 " << val;
			command << addressX_;
			command << " SSA 1 " << val;
			hub->GCSCommand(command.str().c_str());
		}

		command.str("");
		command.clear();
		command << addressX_;
		command << " OSM 1 " << x;
		hub->GCSCommand(command.str().c_str());
	}
	if (y != 0)
	{

		if (y > 0)
		{
			GetProperty("Step Voltage YP", val);
			command.str("");
			command.clear();
			command << addressY_;
			command << " SSA 1 " << val;
			hub->GCSCommand(command.str().c_str());
		}
		else if (y < 0)
		{
			GetProperty("Step Voltage YN", val);
			command.str("");
			command.clear();
			command << addressY_;
			command << " SSA 1 " << val;
			hub->GCSCommand(command.str().c_str());
		}

		command.str("");
		command.clear();
		command << addressY_;
		command << " OSM 1 " << y;
		hub->GCSCommand(command.str().c_str());
	}

	return DEVICE_OK;
}

int CSECOMStageXY::GetPositionSteps(long& x, long& y)
{
	x = 0;
	y = 0;

	return DEVICE_OK;
}

double CSECOMStageXY::GetStepSize()
{
	return 1.0;
}

int CSECOMStageXY::Home()
{
	// TODO: check hardware support for homing.
	if (supportsPositionFeedback_)
	{
		/*CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
		std::ostringstream command;
		command.str("");
		command.clear();
		command << addressX_ << " SVO 1 1";
		hub->GCSCommand(command.str().c_str());
		command.str("");
		command.clear();
		command << addressY_ << " SVO 1 1";
		hub->GCSCommand(command.str().c_str());
		command.str("");
		command.clear();
		command << addressX_ << " FRF 1";
		hub->GCSCommand(command.str().c_str());
		command.str("");
		command.clear();
		command << addressY_ << " FRF 1";
		hub->GCSCommand(command.str().c_str());

		command << addressX_ << " POS 1 " << xOrigin_ / 1000;
		hub->GCSCommand(command.str().c_str());
		command.str("");
		command.clear();

		command << addressY_ << " POS 1 " << yOrigin_ / 1000;
		hub->GCSCommand(command.str().c_str());
		return DEVICE_OK;*/

		return DEVICE_UNSUPPORTED_COMMAND;
	}
	else
	{
		return DEVICE_UNSUPPORTED_COMMAND;
	}
}

int CSECOMStageXY::SetRelativePositionUm(double dx, double dy)
{
	if (supportsPositionFeedback_)
	{
		CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
		std::ostringstream command;
		bool mirrorX, mirrorY;
		char val[MM::MaxStrLength];
		int ret = this->GetProperty(MM::g_Keyword_Transpose_MirrorX, val);
		assert(ret == DEVICE_OK);
		mirrorX = strcmp(val, "1") == 0 ? true : false;

		ret = this->GetProperty(MM::g_Keyword_Transpose_MirrorY, val);
		assert(ret == DEVICE_OK);
		mirrorY = strcmp(val, "1") == 0 ? true : false;
		if (mirrorX == true)
		{
			dx = -1 * dx;
		}
		if (mirrorY == true)
		{
			dy = -1 * dy;
		}

		dx = dx / 1000;
		dy = dy / 1000;

		command.str("");
		command.clear();
		command << addressX_ << " SVO 1 1";
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime());
		command.str("");
		command.clear();
		command << addressX_ << " RON 1 0";
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime());

		command.str("");
		command.clear();
		command << addressY_ << " SVO 1 1";
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime());
		command.str("");
		command.clear();
		command << addressX_ << " RON 1 0";
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime());

		command.str("");
		command.clear();
		command << addressX_ << " MVR 1 " << dx;
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime() * 2.0);
		command.str("");
		command.clear();
		command << addressY_ << " MVR 1 " << dy;
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime() * 2.0);

		command.str("");
		command.clear();
		command << addressX_ << " SVO 1 0";
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime());
		command.str("");
		command.clear();
		command << addressY_ << " SVO 1 0";
		hub->GCSCommand(command.str().c_str());
		Sleep(hub->WaitingTime());

		return DEVICE_OK;
	}
	else
	{
		SetPositionSteps(long(dx), long(dy));
		return DEVICE_OK;
	}
}

int CSECOMStageXY::SetPositionUm(double dx, double dy)
{
	if (supportsPositionFeedback_)
	{
		CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
		std::ostringstream command;
		dx = dx / 1000;
		dy = dy / 1000;
		command.str("");
		command.clear();
		command << addressX_ << " MOV 1 " << dx;
		hub->GCSCommand(command.str().c_str());
		command.str("");
		command.clear();
		command << addressY_ << " MOV 1 " << dy;
		hub->GCSCommand(command.str().c_str());

		return DEVICE_OK;
	}
	else
	{
		return DEVICE_UNSUPPORTED_COMMAND;
	}
}

int CSECOMStageXY::GetPositionUm(double &dx, double &dy)
{
	if (supportsPositionFeedback_)
	{
		CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
		std::string answer("");

		std::ostringstream command;
		command.str("");
		command.clear();
		command << addressX_ << " POS? 1";
		hub->qGCSCommand(command.str().c_str(), answer);
		int length = answer.length();
		if (length > 6)
		{
			try {
				dx = (stod(answer.substr(6, length - 1))) * 1000;
			}
			catch (...)
			{
				return DEVICE_SERIAL_INVALID_RESPONSE;
			}
		}
		else
		{
			return DEVICE_SERIAL_INVALID_RESPONSE;
		}

		command.str("");
		command.clear();
		command << addressY_ << " POS? 1";
		hub->qGCSCommand(command.str().c_str(), answer);
		length = answer.length();
		if (length > 6)
		{
			try {
				dy = (stod(answer.substr(6, length - 1))) * 1000;
			}
			catch (...)
			{
				return DEVICE_SERIAL_INVALID_RESPONSE;
			}
		}
		else
		{
			return DEVICE_SERIAL_INVALID_RESPONSE;
		}
		return DEVICE_OK;
	}
	else
	{
		// We silently continue.
		return DEVICE_OK;
	}
}

int CSECOMStageXY::Stop()
{
	return DEVICE_UNSUPPORTED_COMMAND;
}

int CSECOMStageXY::SetOrigin()
{
	if (supportsPositionFeedback_)
	{
		GetPositionUm(xOrigin_, yOrigin_);
		return DEVICE_OK;
	}
	else
	{
		return DEVICE_UNSUPPORTED_COMMAND;
	}
	
}

int CSECOMStageXY::GetLimitsUm(double& xMin, double& xMax, double& yMin, double& yMax)
{
	return DEVICE_UNSUPPORTED_COMMAND;
}

int CSECOMStageXY::GetStepLimits(long& xMin, long& xMax, long& yMin, long& yMax)
{
	return DEVICE_UNSUPPORTED_COMMAND;
}

double CSECOMStageXY::GetStepSizeXUm()
{
	return 1.0;
}

double CSECOMStageXY::GetStepSizeYUm()
{
	return 1.0;
}


CSECOMStageZ::CSECOMStageZ() :initialized_(false), umPerStepDown_(1.0), umPerStepUp_(1.0), _wasLastMoveStep(false), _isFirstMove(true)
{
	InitializeDefaultErrorMessages();

	// Description


	// parent ID display
	CreateHubIDProperty();

}

CSECOMStageZ::~CSECOMStageZ()
{
	Shutdown();
}

int CSECOMStageZ::OnFineVoltage(MM::PropertyBase* pProp, MM::ActionType pAct)
{
	if (pAct == MM::BeforeGet) {
		// Nothing to do, let the caller use cached property
	}
	else if (pAct == MM::AfterSet) {
		std::ostringstream command;
		CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
		double val;
		pProp->Get(val);
		// if (!hub || !hub->IsPortAvailable())
		//    return ERR_NO_PORT_SET;
		if (_isFirstMove)
		{
			_wasLastMoveStep = true;
			_isFirstMove = false;
		}
		if (_wasLastMoveStep)
		{
			command.str("");
			command.clear();
			command << "3 RNP 1 0";
			hub->GCSCommand(command.str().c_str());
		}
		command.str("");
		command.clear();
		command << "3 OAD 1 " << val;
		hub->GCSCommand(command.str().c_str());
		_wasLastMoveStep = false;
	}

	return DEVICE_OK;
}

int CSECOMStageZ::OnReset(MM::PropertyBase* pProp, MM::ActionType pAct)
{
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	if (pAct == MM::AfterSet)
	{
		pProp->Set((long)(0));
		hub->DoReset(3);
	}
	return DEVICE_OK;
}

void CSECOMStageZ::GetName(char* name) const
{
	CDeviceUtils::CopyLimitedString(name, g_DeviceNameSECOMObjectiveZ);
}

int CSECOMStageZ::Initialize()
{
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	//  if (!hub || !hub->IsPortAvailable()) {
	//     return ERR_NO_PORT_SET;
	//  }
	char hubLabel[MM::MaxStrLength];
	hub->GetLabel(hubLabel);
	SetParentID(hubLabel); // for backward comp.

	int ret = CreateProperty(MM::g_Keyword_Description, "SECOM Objective Z Stage", MM::String, true);
	assert(DEVICE_OK == ret);
	CPropertyAction* pAct = new CPropertyAction(this, &CSECOMStageZ::OnFineVoltage);
	ret = CreateProperty("Fine Voltage", "0", MM::Float, false, pAct);
	assert(DEVICE_OK == ret);
	pAct = new CPropertyAction(this, &CSECOMStageZ::OnReset);
	ret = CreateProperty("Reset?", "0", MM::Integer, false, pAct);
	assert(DEVICE_OK == ret);
	// pAct = new CPropertyAction(this, &CSECOMStageZ::OnStepVoltage);
	ret = CreateProperty("Step Voltage P", "30", MM::Float, false);
	assert(DEVICE_OK == ret);
	ret = CreateProperty("Step Voltage N", "30", MM::Float, false);
	assert(DEVICE_OK == ret);
	pAct = new CPropertyAction(this, &CSECOMStageZ::OnHome);
	assert(DEVICE_OK == ret);
	ret = CreateProperty("Home?", "false", MM::String, false, pAct);
	assert(DEVICE_OK == ret);
	pAct = new CPropertyAction(this, &CSECOMStageZ::OnOrigin);
	assert(DEVICE_OK == ret);
	ret = CreateProperty("SetOrigin?", "false", MM::String, false, pAct);
	assert(DEVICE_OK == ret);

	// Name
	ret = CreateProperty(MM::g_Keyword_Name, g_DeviceNameSECOMObjectiveZ, MM::String, true);
	assert(DEVICE_OK == ret);

	initialized_ = true;

	return DEVICE_OK;
}

int CSECOMStageZ::Shutdown()
{
	initialized_ = false;
	return DEVICE_OK;
}

bool CSECOMStageZ::Busy()
{
	return false;
}

int CSECOMStageZ::SetPositionSteps(long steps)
{
	std::ostringstream command;
	double stepvoltage;
	GetProperty("Step Voltage", stepvoltage);
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	// if (!hub || !hub->IsPortAvailable())
	//    return ERR_NO_PORT_SET;

	if (_isFirstMove)
	{
		_wasLastMoveStep = false;
		_isFirstMove = false;
	}
	if (!_wasLastMoveStep)
	{
		command.str("");
		command.clear();
		command << "3 RNP 1 0";
		hub->GCSCommand(command.str().c_str());
	}
	if (steps > 0)
	{
		GetProperty("Step Voltage P", stepvoltage);
		command.str("");
		command.clear();
		command << "3 SSA 1 " << stepvoltage;
		hub->GCSCommand(command.str().c_str());
	}
	else if (steps < 0)
	{
		GetProperty("Step Voltage N", stepvoltage);
		command.str("");
		command.clear();
		command << "3 SSA 1 " << stepvoltage;
		hub->GCSCommand(command.str().c_str());
	}
	command.str("");
	command.clear();
	command << "3 OSM 1 " << steps;
	hub->GCSCommand(command.str().c_str());
	_wasLastMoveStep = true;
	return DEVICE_OK;
}

int CSECOMStageZ::SetPositionUm(double pos)
{
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	std::ostringstream command;
	pos = pos / 1000;
	command.str("");
	command.clear();
	command << "3 MOV 1 " << pos;
	hub->GCSCommand(command.str().c_str());
	return DEVICE_OK;
}

int CSECOMStageZ::SetRelativePositionUm(double pos)
{
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	std::ostringstream command;
	pos = pos / 1000;

	command.str("");
	command.clear();
	command << "3 SVO 1 1";
	hub->GCSCommand(command.str().c_str());
	Sleep(hub->WaitingTime());

	command.str("");
	command.clear();
	command << "3 RON 1 0";
	hub->GCSCommand(command.str().c_str());
	Sleep(hub->WaitingTime());

	command.str("");
	command.clear();
	command << "3 MVR 1 " << pos;
	hub->GCSCommand(command.str().c_str());
	Sleep(hub->WaitingTime() * 5);

	command.str("");
	command.clear();
	command << "3 SVO 1 0";
	hub->GCSCommand(command.str().c_str());
	Sleep(hub->WaitingTime());

	return DEVICE_OK;
}

int CSECOMStageZ::GetPositionUm(double &pos)
{
	CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
	std::string answer;
	hub->qGCSCommand("3 POS? 1", answer);
	int length = answer.length();
	if (length > 6)
	{
		try {
			pos = (stod(answer.substr(6, length - 1))) * 1000;
		}
		catch (...)
		{
			return DEVICE_SERIAL_INVALID_RESPONSE;
		}
		return DEVICE_OK;
	}
	else
	{
		return DEVICE_SERIAL_INVALID_RESPONSE;
	}
}

int CSECOMStageZ::OnHome(MM::PropertyBase* pProp, MM::ActionType pAct)
{
	std::string state;
	if (pAct == MM::AfterSet)
	{
		pProp->Get(state);
		if (state == "true")
		{
			CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
			hub->GCSCommand("3 SVO 1 1");
			hub->GCSCommand("3 GOH 1");
			pProp->Set("false");
		}
	}
	return DEVICE_OK;
}

int CSECOMStageZ::OnOrigin(MM::PropertyBase* pProp, MM::ActionType pAct)
{
	std::string state;
	if (pAct == MM::AfterSet)
	{
		pProp->Get(state);
		if (state == "true")
		{
			CSECOMStageHub* hub = static_cast<CSECOMStageHub*>(GetParentHub());
			hub->GCSCommand("3 POS 1 0.0");
			pProp->Set("false");
		}
	}
	return DEVICE_OK;
}
// TODO: add header

#include "FEISEM.h"
#include "../../micromanager/MMDevice/ModuleInterface.h"
#include <sstream>
#include <cstdio>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define snprintf _snprintf 
#endif

// The ip of the Microscope PC.
/*
_T is a macro that, when applied to a string, expands either to:
* nothing -if you are not compiling for Unicode-
* L, if you are compiling for Unicode.

Refer to:
https://msdn.microsoft.com/en-us/library/se784sk6.aspx
*/
#define MACHINE		_T("192.168.0.1")

using namespace std;

double g_IntensityFactor_ = 1.0;

const double g_DistanceMultiplier = 1000000;
const double g_StigmationMultiplier = 1000;
const double g_BeamShiftMultiplier = 100000;
const double g_TimeMultiplier = 1000000;
const double g_ScanRotationMultiplier = 180/3.141582;

// constants for naming pixel types (allowed values of the "PixelType" property)
const char* g_MODE_HIVAC = "Hi-Vac";
const char* g_MODE_CHARGENEUT = "Low Vacuum";
const char* g_MODE_ENVIRONMENTAL = "Environmental";

const char* g_STATE_ALL_AIR = "Vented";
const char* g_STATE_PUMPING = "Pumping - Pumping";
const char* g_STATE_PREVAC = "Pumping - Prevac";
const char* g_STATE_VACUUM = "Vacuum";
const char* g_STATE_VENTING = "Venting";
const char* g_STATE_ERROR = "Error";

const char* g_SCAN_NONE = "None";
const char* g_SCAN_EXTERNAL = "External";
const char* g_SCAN_FULLFRAME = "Full Frame";
const char* g_SCAN_SPOT = "Spot";
const char* g_SCAN_LINE = "Line";


const char* g_HTSTATE_ON = "ON";
const char* g_HTSTATE_OFF = "OFF";
const char* g_HTSTATE_RAMPING_UP = "Ramping Up";
const char* g_HTSTATE_RAMPING_DOWN = "Ramping Down";
const char* g_HTSTATE_INITIALIZING = "Initialising";

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
	RegisterDevice(g_HubDeviceName, MM::HubDevice, "FEI Quanta FEG 250");
	RegisterDevice(g_BeamDeviceName, MM::GenericDevice, "QFEG 250 Beam Controller");
	//RegisterDevice(g_StageDeviceName, MM::GenericDevice, "QFEG 250 Stage Controller");
	RegisterDevice(g_ScanDeviceName, MM::GenericDevice, "QFEG 250 Scan Controller");
	RegisterDevice(g_VacSystemDeviceName, MM::GenericDevice, "QFEG 250 Vacuum Controller");
}

/*
Here, we instruct Micro-Manager which class to instantiate when a device with a specific
devicename is created.
*/
MODULE_API MM::Device* CreateDevice(const char* deviceName)
{
	if (deviceName == 0)
		return 0;

	if (strcmp(deviceName, g_HubDeviceName) == 0)
	{
		return new QFeg250;
	}
	if (strcmp(deviceName, g_BeamDeviceName) == 0)
	{
		return new QFeg250ElectronBeamControl;
	}
	if (strcmp(deviceName, g_ScanDeviceName) == 0)
	{
		return new QFeg250ScanControl;
	}
	if (strcmp(deviceName, g_VacSystemDeviceName) == 0)
	{
		return new QFeg250VacSystemControl;
	}

	return DEVICE_OK;
}

MODULE_API void DeleteDevice(MM::Device* pDevice)
{
	delete pDevice;
}

QFeg250::QFeg250():initialized_(false),busy_(false)
{
	pIMicroscopeControl = NULL;
	pIBeamControl = NULL;
	pIScanControl = NULL;
	pIStageControl = NULL;
	pIVideoControl = NULL;
	pIVacSystemControl = NULL;
	
	pIElectronBeamControl = NULL;

	pIConnectionPointContainer = NULL;
	pIDispatch = NULL; 

	// Name
	int ret = CreateProperty(MM::g_Keyword_Name, g_HubDeviceName, MM::String, true);
	assert(ret == DEVICE_OK);
}

void QFeg250::LogFEIError(HRESULT hresult)
{
	LogMessage("XTLib Error: " + hresult, true);
}

int QFeg250::Shutdown()
{
	LogMessage("Releasing ElectronBeamControl ...");
	if(pIElectronBeamControl)
	{
		pIElectronBeamControl->Release();
		pIElectronBeamControl = NULL;
		LogMessage("ElectronBeamControl Released");
	}
	LogMessage("Releasing VacSystemControl ...");
	if (pIVacSystemControl)
	{
		pIVacSystemControl->Release();
		pIVacSystemControl = NULL;
		LogMessage("VacSysemControl Released");
	}
	LogMessage("Releasing VideoControl ...");
	if (pIVideoControl)
	{
		pIVideoControl->Release();
		pIVideoControl = NULL;
		LogMessage("VideoControl Released");
	}
	LogMessage("Releasing StageControl ...");
	if (pIStageControl)
	{
		pIStageControl->Release();
		pIStageControl = NULL;
		LogMessage("StageControl Released");
	}
	LogMessage("Releasing ScanControl ...");
	if (pIScanControl)
	{
		pIScanControl->Release();
		pIScanControl = NULL;
		LogMessage("ScanControl Released");

	}
	LogMessage("Releasing BeamControl ...");
	if(pIBeamControl)
	{
		pIBeamControl->Release();
		pIBeamControl = NULL;
		LogMessage("BeamControl Released");
	}
	LogMessage("Releasing MicroscopeControl ...");
	if ( pIMicroscopeControl )
	{
		pIMicroscopeControl->Disconnect();
		pIMicroscopeControl->Release();
		pIMicroscopeControl = NULL;
		LogMessage("MicroscopeControl Released");
	}

	CoUninitialize();

	initialized_ = false;

	return DEVICE_OK;
}

QFeg250::~QFeg250()
{
	Shutdown();
}

void QFeg250::COMInit()
{
	if ( pIMicroscopeControl )
	{
	}
	else
	{

	}
}

MM::DeviceDetectionStatus QFeg250::DetectDevice(void)
{
	return MM::CanCommunicate;
}

int QFeg250::DetectInstalledDevices()
{
	ClearInstalledDevices();

	// make sure this method is called before we look for available devices
	InitializeModuleData();

	// Only proceed if a the Hub was properly detected.
	if (MM::CanCommunicate == DetectDevice())
	{
		std::vector<std::string> peripherals;
		peripherals.clear();
		peripherals.push_back(g_BeamDeviceName);
		peripherals.push_back(g_ScanDeviceName);
		peripherals.push_back(g_StageDeviceName);
		peripherals.push_back(g_VideoDeviceName);
		peripherals.push_back(g_VacSystemDeviceName);

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

int QFeg250::Initialize()
{
	HRESULT hr = E_FAIL;
	bool COMOK = true;

	// Convert the IP address of the Microscope PC to an ATL wrapper for the COM Basic String.
	CComBSTR sMachine(MACHINE);

	// Try and connect to the different components of the microscope.
	if (SUCCEEDED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
	{
		if (SUCCEEDED(hr = CoCreateInstance(CLSID_MicroscopeControl, NULL, CLSCTX_INPROC_SERVER, IID_IMicroscopeControl, reinterpret_cast <void **> (&pIMicroscopeControl))))
		{
			if (SUCCEEDED(hr = pIMicroscopeControl->Connect(sMachine)))
			{
				if (SUCCEEDED(hr = pIMicroscopeControl->BeamControl(&pIBeamControl)) && (pIBeamControl != NULL))
				{
					LogMessage("XTLib got BeamControl!");

					if (SUCCEEDED(hr = pIBeamControl->ElectronBeamControl(&pIElectronBeamControl)) && (pIElectronBeamControl != NULL))
					{
						LogMessage("XTLib got ElectronBeamControl!");
					}
					else
					{
						LogMessage("XTLib could not get ElectronBeamControl!");
						LogFEIError(hr);
						COMOK = false;
					}

				}
				else
				{
					LogMessage("XTLib could not get BeamControl!");
					LogFEIError(hr);
					COMOK = false;
				}
				if (SUCCEEDED(hr = pIMicroscopeControl->ScanControl(&pIScanControl)) && (pIScanControl != NULL))
				{
					LogMessage("XTLib got ScanControl!");
				}
				else
				{
					LogMessage("XTLib could not get ScanControl!");
					LogFEIError(hr);
					COMOK = false;
				}
				if (SUCCEEDED(hr = pIMicroscopeControl->StageControl(&pIStageControl)) && (pIStageControl != NULL))
				{
					LogMessage("XTLib got StageControl!");
				}
				else
				{
					LogMessage("XTLib could not get StageControl!");
					LogFEIError(hr);
					COMOK = false;
				}
				if (SUCCEEDED(hr = pIMicroscopeControl->VideoControl(&pIVideoControl)) && (pIVideoControl != NULL))
				{
					LogMessage("XTLib got VideoControl!");
				}
				else
				{
					LogMessage("XTLib could not get VideoControl!");
					LogFEIError(hr);
					COMOK = false;
				}
				if (SUCCEEDED(hr = pIMicroscopeControl->VacSystemControl(&pIVacSystemControl)) && (pIVacSystemControl != NULL))
				{
					LogMessage("XTLib got VacSystemControl!");
				}
				else
				{
					LogMessage("XTLib could not get VacSystemControl!");
					LogFEIError(hr);
					COMOK = false;
				}
			}
			else
			{
				LogMessage("XTLib failed to connect!");
				LogFEIError(hr);
				COMOK = false;
			}
		}
		else
		{
			LogMessage("XTLib co-creation failed!");
			LogFEIError(hr);
			COMOK = false;
		}
	}
	else
	{
		LogMessage("XTLib co-init failed!");
		LogFEIError(hr);
	}
	if (COMOK)
	{
		initialized_ = true;
	}
	else
	{
		initialized_ = false;
		return DEVICE_ERR;
	}
	return DEVICE_OK;
}

void QFeg250::GetName(char* pName) const
{
	CDeviceUtils::CopyLimitedString(pName, g_HubDeviceName);
}

//Camera

//QFeg250::QFeg250():initialized_(false),busy_(false)
//{
//		hub = NULL;
//		//pIBeamControl = NULL;
//        //pIElectronBeamControl = NULL;
//        pIMicroscopeControl = NULL;
//		pIScanControl = NULL;
//		pIVideoControl = NULL;
//		pIChannels = NULL;
//		pIDetectorGroup = NULL;
//		pIDetectorGroups = NULL;
//		pIChannel = NULL;
//		//pIVacSystemControl = NULL;
//		pIConnectionPointContainer = NULL;
//		pIDispatch = NULL; 
//
//		CreateProperty(MM::g_Keyword_Description, "FEISEM Controller", MM::String, true);
//		int ret = CreateProperty(MM::g_Keyword_Description, "FEISEM Controller", MM::String, true);
//		assert(DEVICE_OK == ret);
//
//   // Name
//   ret = CreateProperty(MM::g_Keyword_Name, g_ControllerDeviceName, MM::String, true);
//   assert(DEVICE_OK == ret);
//   CreateHubIDProperty();
//}

//int FEISEMCamera::Initialize()
//{
//   hub = static_cast<FEISEMHub*>(GetParentHub());
//
//   char hubLabel[MM::MaxStrLength];
//   hub->GetLabel(hubLabel);
//   SetParentID(hubLabel); // for backward comp.
//
//   double min, max;
//   long lmin, lmax;
//   int nRetCode = 0;
//
//        HRESULT hr = E_FAIL;
//        
//        CComBSTR sMachine( MACHINE );
//
//        if ( SUCCEEDED( hr = CoInitialize( NULL ) ) )
//        {
//  //          cout << _T( "COM library initialized successfully" ) << endl;
//
//            if ( SUCCEEDED( hr = CoCreateInstance( CLSID_MicroscopeControl, NULL, CLSCTX_INPROC_SERVER, IID_IMicroscopeControl, reinterpret_cast < void ** > (&pIMicroscopeControl) ) ) )
//            {
//  //              cout << _T( "Create instance of MicroscopeControl object succeeded" ) << endl;
//
//                if ( SUCCEEDED( hr = pIMicroscopeControl->Connect( sMachine ) ) )
//                {
//  //                  cout << _T( "Connect to microscope server succeeded" ) << endl;
//
//                    if ( SUCCEEDED( hr = pIMicroscopeControl->VideoControl( &pIVideoControl ) ) && (pIVideoControl != NULL) )
//                    {
//  //                      cout << _T( "BeamControl object created successfully" ) << endl;
//
//                        if ( SUCCEEDED( hr = pIVideoControl->Channels( &pIChannels ) ) && (pIChannels != NULL) )
//                        {
//    //                        cout << _T( "ElectronBeamControl object created successfully" ) << endl;
//
//                           
//
//                            // Get High voltage value 
//							/*
//                            if ( SUCCEEDED( hr = pIElectronBeamControl->get_HTVoltage( &dHV ) ) )
//                            {
//      //                          cout << _T( "HTVoltage = " ) << dHV << endl;
//                            }
//                            else
//                            {
//       //                         cout << _T( "ERROR: Cannot get value of HTVoltage" ) << endl;
//                            }*/   
//                        }
//                        else
//                        {
//             //               cout << _T( "ERROR: Cannot create ElectronBeamControl object" ) << endl;
//                        }
//						
//                    }
//                    else
//                    {
//               //         cout << _T( "ERROR: Cannot create BeamControl object" ) << endl;
//                    }
//					if( SUCCEEDED( hr = pIMicroscopeControl->ScanControl( &pIScanControl ) ) && (pIScanControl != NULL) )
//					{
//
//					}
//					else
//					{
//					}
//                }
//                else
//                {
//                 //   cout << _T( "ERROR: Cannot connect to microscope server" ) << endl;
//                }
//            }
//            else
//            {
//       //         cout << _T( "ERROR: Cannot create instance of MicroscopeControl object" ) << endl;
//            }
//        }
//        else
//        {
//       //     cout << _T( "ERROR: Cannot initialize COM library" ) << endl;
//        }
//
//		vector<string> BOOLOPT;
//		BOOLOPT.push_back("true");
//		BOOLOPT.push_back("false");
//
//		pAct = new CPropertyAction (this, &FEISEMCamera::OnDwellTime);
//		ret = CreateProperty("Frame Time", "0.0" , MM::Float, false, pAct);
//		assert(DEVICE_OK == ret);
////		ret = CreateProperty("Dwell Time Max", "0.0" , MM::Float, true);
////		assert(DEVICE_OK == ret);
////		ret = CreateProperty("Dwell Time Min", "0.0" , MM::Float, true);
////		assert(DEVICE_OK == ret);
//
//		hr = pIScanControl->get_DwellTimeRange((XTLibRange)XTLIB_RANGE_MIN, &min);
//		if(hr != S_OK)
//		{
//			LogFEIError(hr);
//		}
//		hr = pIScanControl->get_DwellTimeRange((XTLibRange)XTLIB_RANGE_MAX, &max);
//		if(hr != S_OK)
//		{
//			LogFEIError(hr);
//		}
//		SetPropertyLimits("Frame Time", min, max);
//
//
//		pAct = new CPropertyAction (this, &FEISEMCamera::OnVPixels);
//		ret = CreateProperty("Image Height", "442" , MM::Integer, false, pAct);
//		assert(DEVICE_OK == ret);
//
//		vector<string> VertPixelValues;
//		VertPixelValues.push_back("442");
//		VertPixelValues.push_back("884");
//		VertPixelValues.push_back("1768");
//		VertPixelValues.push_back("3536");
//		ret = SetAllowedValues("Image Height", VertPixelValues);
//		assert(DEVICE_OK == ret);
//
//		pAct = new CPropertyAction (this, &FEISEMCamera::OnHPixels);
//		ret = CreateProperty("Image Width", "512" , MM::Integer, false, pAct);
//		assert(DEVICE_OK == ret);
//
//		vector<string> HoriPixelValues;
//		HoriPixelValues.push_back("512");
//		HoriPixelValues.push_back("1024");
//		HoriPixelValues.push_back("2048");
//		HoriPixelValues.push_back("4096");
//		ret = SetAllowedValues("Image Width", HoriPixelValues);
//		assert(DEVICE_OK == ret);
//
///*		ret = CreateProperty("Vertical Pixels Max", "3536" , MM::Integer, true);
//		assert(DEVICE_OK == ret);
//		ret = CreateProperty("Vertical Pixels Min", "442" , MM::Integer, true);
//		assert(DEVICE_OK == ret);
//		ret = CreateProperty("Horizontal Pixels Max", "4096" , MM::Integer, true);
//		assert(DEVICE_OK == ret);
//		ret = CreateProperty("Horizontal Pixels Min", "512" , MM::Integer, true);
//		assert(DEVICE_OK == ret);*/
//		
//		hr = pIScanControl->get_NrOfVertPixelsRange((XTLibRange)XTLIB_RANGE_MIN, &lmin);
//		if(hr != S_OK)
//		{
//			LogFEIError(hr);
//		}
//		hr = pIScanControl->get_NrOfVertPixelsRange((XTLibRange)XTLIB_RANGE_MAX, &lmax);
//		if(hr != S_OK)
//		{
//			LogFEIError(hr);
//		}
//		SetPropertyLimits("Image Height", static_cast<double>(lmin), static_cast<double>(lmax));
//
//		hr = pIScanControl->get_NrOfHorPixelsRange((XTLibRange)XTLIB_RANGE_MIN, &lmin);
//		if(hr != S_OK)
//		{
//			LogFEIError(hr);
//		}
//		hr = pIScanControl->get_NrOfHorPixelsRange((XTLibRange)XTLIB_RANGE_MAX, &lmax);
//		if(hr != S_OK)
//		{
//			LogFEIError(hr);
//		}
//		SetPropertyLimits("Image Width", static_cast<double>(lmin), static_cast<double>(lmax));
//
//
//		pAct = new CPropertyAction (this, &FEISEMCamera::OnSelectedAreaXStart);
//		ret = CreateProperty("Selected Area X Start", "0" , MM::Integer, false, pAct);
//		assert(DEVICE_OK == ret);
//		pAct = new CPropertyAction (this, &FEISEMCamera::OnSelectedAreaYStart);
//		ret = CreateProperty("Selected Area Y Start", "0" , MM::Integer, false, pAct);
//		assert(DEVICE_OK == ret);
//		pAct = new CPropertyAction (this, &FEISEMCamera::OnSelectedAreaX);
//		ret = CreateProperty("Selected Area X Size", "512" , MM::Integer, false, pAct);
//		assert(DEVICE_OK == ret);
//		pAct = new CPropertyAction (this, &FEISEMCamera::OnSelectedAreaY);
//		ret = CreateProperty("Selected Area Y Size", "442" , MM::Integer, false, pAct);
//		assert(DEVICE_OK == ret);
//        pAct = new CPropertyAction (this, &FEISEMCamera::OnSelectedEnabled);
//		ret = CreateProperty("Selected Area Enabled", "false" , MM::String, false, pAct);
//		assert(DEVICE_OK == ret);
//
//		ret = SetAllowedValues("Selected Area Enabled", BOOLOPT);
//
//		
//
//  	initialized_ = true;
// 
//	return DEVICE_OK;
//}
//
//void FEISEMCamera::GetName(char* pName) const
//{
//   CDeviceUtils::CopyLimitedString(pName, g_CameraDeviceName);
//}
//
//int SnapImage();
//
//const unsigned char* GetImageBuffer()
//{
//}
//
//const unsigned char* GetImageBuffer(unsigned channelNr)
//{
//}
//
//const unsigned int* GetImageBufferAsRGB32()
//{
//}
//
//unsigned GetNumberOfComponents()
//{
//}
//
// int GetComponentName(unsigned component, char* name)
// {
// }
//
// int unsigned GetNumberOfChannels()
// {
// }
//
// int GetChannelName(unsigned channel, char* name)
// {
// }
//
// long GetImageBufferSize()
// {
// }
//
// unsigned GetImageWidth()
// {
//	 int ImageWidth;
//	 GetProperty("Image Width", ImageWidth);
//	 return unsigned(ImageWidth);
// }
//
// unsigned GetImageHeight()
// {
//	 int ImageHeight;
//	 GetProperty("Image Height", ImageHeight);
//	 return unsigned(ImageHeight);
// }
//
// unsigned GetImageBytesPerPixel()
// {
// }
//
// unsigned GetBitDepth()
// {
// }
//
// double GetPixelSizeUm()
// {
//	 double FOV; 
//	 int ImageWidth;
//	 GetProperty("Image Width", ImageWidth);
//	 GetProperty("FOV", FOV);
//	 return (FOV/ImageWidth)*1000000;
// }

QFeg250ElectronBeamControl::QFeg250ElectronBeamControl():busy_(false),initialized_(false)
{
	CreateHubIDProperty();
}

QFeg250ElectronBeamControl::~QFeg250ElectronBeamControl()
{
	Shutdown();
}

int QFeg250ElectronBeamControl::Initialize()
{
	if (initialized_)
		return DEVICE_OK;

	hub_ = static_cast<QFeg250*>(GetParentHub());

	if (hub_)
	{
		char hubLabel[MM::MaxStrLength];
		hub_->GetLabel(hubLabel);
		SetParentID(hubLabel); // for backward comp.
	}
	else
		LogMessage(NoHubError);

	if (hub_ != NULL && hub_->initialized_)
	{
		pIBeamControl_ = hub_->pIBeamControl;
		pIElectronBeamControl_ = hub_->pIElectronBeamControl;

		// Helper variables for retreiving min and max values.
		double min, max;
		long lmin, lmax;
		vector<string> BOOLOPT;
		BOOLOPT.push_back("true");
		BOOLOPT.push_back("false");


		/*
		The ElectronBeamControl exposes a number of properties:
		* HTState: The state of the high power voltage in the column (On/Off)
		* HTVoltage: The high tension voltage
		* FWD: The free working distance
		* SpotSize: The electron beam spot size
		* BeamBlank: The state of the beam blank (On/Off)
		* Stigmator: The stigmator setting

		These properties usually have a range of possible/allowed values.

		These properties will be translated to the Micro-Manager property system.
		*/
		// HTState
		CPropertyAction * pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnHTState);
		int ret = CreateProperty("HTState", "unknown", MM::String, false, pAct);
		assert(ret == DEVICE_OK);

		vector<string> HTStateValues;
		HTStateValues.push_back(g_HTSTATE_ON);
		HTStateValues.push_back(g_HTSTATE_OFF);
		ret = SetAllowedValues("HTState", HTStateValues);
		assert(ret == DEVICE_OK);

		//HTVoltage
		pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnHTVoltage);
		ret = CreateProperty("Acceleration Voltage (V)", "20000.0", MM::Float, false, pAct);
		assert(ret == DEVICE_OK);


		pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnSpotSize);
		ret = CreateProperty("Spot Size", "2.0", MM::Float, false, pAct);
		assert(ret == DEVICE_OK);

		/*	ret = CreateProperty("Spot Min", "1.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Spot Max", "7.0" , MM::Float, true);
		assert(DEVICE_OK == ret);*/

		HRESULT hr = pIElectronBeamControl_->get_SpotSizeRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIElectronBeamControl_->get_SpotSizeRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("Spot Size", min, max);
		assert(ret == DEVICE_OK);

		pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnBeamBlank);
		ret = CreateProperty("Beam Blank", "false", MM::String, false, pAct);
		assert(ret == DEVICE_OK);


		ret = SetAllowedValues("Beam Blank", BOOLOPT);
		assert(ret == DEVICE_OK);
		pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnStigmationX);
		ret = CreateProperty("Stigmation X", "0.0", MM::Float, false, pAct);
		assert(ret == DEVICE_OK);

		pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnStigmationY);
		ret = CreateProperty("Stigmation Y", "0.0", MM::Float, false, pAct);
		assert(ret == DEVICE_OK);

		/*	ret = CreateProperty("Stigmation X Min", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Stigmation Y Min", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Stigmation X Max", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Stigmation Y Max", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);*/

		hr = pIElectronBeamControl_->get_StigmatorXRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIElectronBeamControl_->get_StigmatorXRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("Stigmation X", min*g_StigmationMultiplier, max*g_StigmationMultiplier);
		assert(ret == DEVICE_OK);

		hr = pIElectronBeamControl_->get_StigmatorYRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIElectronBeamControl_->get_StigmatorYRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("Stigmation Y", min*g_StigmationMultiplier, max*g_StigmationMultiplier);
		assert(ret == DEVICE_OK);

		//BeamControl
		pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnBeamShiftX);
		ret = CreateProperty("Beam Shift X", "0.0", MM::Float, false, pAct);
		assert(ret == DEVICE_OK);

		pAct = new CPropertyAction(this, &QFeg250ElectronBeamControl::OnBeamShiftY);
		ret = CreateProperty("Beam Shift Y", "0.0", MM::Float, false, pAct);
		assert(ret == DEVICE_OK);

		/*	ret = CreateProperty("Beam Shift X Min", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Beam Shift Y Min", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Beam Shift X Max", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Beam Shift Y Max", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);*/

		hr = pIBeamControl_->get_BeamShiftXRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIBeamControl_->get_BeamShiftXRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("Beam Shift X", min*g_BeamShiftMultiplier, max*g_BeamShiftMultiplier);
		assert(ret == DEVICE_OK);

		hr = pIBeamControl_->get_BeamShiftYRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIBeamControl_->get_BeamShiftYRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("Beam Shift Y", min*g_BeamShiftMultiplier, max*g_BeamShiftMultiplier);
		assert(ret == DEVICE_OK);

		initialized_ = true;
		return DEVICE_OK;
	}
	else
	{
		initialized_ = false;
		return DEVICE_ERR;
	}
}

int QFeg250ElectronBeamControl::Shutdown()
{
	if (pIBeamControl_)
	{
		pIBeamControl_ = NULL;
	}
	if (pIElectronBeamControl_)
	{
		pIElectronBeamControl_ = NULL;
	}
	return DEVICE_OK;
}

void QFeg250ElectronBeamControl::GetName(char* pName) const
{
	CDeviceUtils::CopyLimitedString(pName, g_BeamDeviceName);
}

int QFeg250ElectronBeamControl::OnHTState(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	HTState state;
	string statestring;
	if (eAct == MM::BeforeGet)
	{
		hresult = pIElectronBeamControl_->get_HTState(&state);
		if (hresult == S_OK)
		{
			switch (state)
			{
			case HT_ON:
				pProp->Set(g_HTSTATE_ON);
				break;

			case HT_OFF:
				pProp->Set(g_HTSTATE_OFF);
				break;

			case HT_RAMPING_UP:
				pProp->Set(g_HTSTATE_RAMPING_UP);
				break;

			case HT_RAMPING_DOWN:
				pProp->Set(g_HTSTATE_RAMPING_DOWN);
				break;

			case HT_INITIALIZING:
				pProp->Set(g_HTSTATE_INITIALIZING);
				break;
			default:pProp->Set("Unknown");
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(statestring);
		if (statestring == g_HTSTATE_ON)
		{
			hresult = pIElectronBeamControl_->put_HTOnOff((short)(1));
		}
		else if (statestring == g_HTSTATE_OFF)
		{
			hresult = pIElectronBeamControl_->put_HTOnOff((short)(0));
		}
		if (hresult == S_OK)
		{

		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ElectronBeamControl::OnHTVoltage(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double voltage;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIElectronBeamControl_->get_HTVoltage(&voltage);
		if (hresult == S_OK)
		{
			pProp->Set(voltage);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(voltage);
		hresult = pIElectronBeamControl_->put_HTVoltage(voltage);
		if (hresult == S_OK)
		{
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ElectronBeamControl::OnSpotSize(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double spotsize;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIElectronBeamControl_->get_SpotSize(&spotsize);
		if (hresult == S_OK)
		{
			pProp->Set(spotsize);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(spotsize);
		hresult = pIElectronBeamControl_->put_SpotSize(spotsize);
		if (hresult == S_OK)
		{
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ElectronBeamControl::OnBeamBlank(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	VARIANT_BOOL enabled;
	string stringenabled;
	HRESULT hresult;

	if (eAct == MM::BeforeGet)
	{

		hresult = pIElectronBeamControl_->get_BeamIsBlanked(&enabled);
		if (hresult == S_OK)
		{
			if (enabled == 0)
			{
				pProp->Set("false");

			}
			else
			{
				pProp->Set("true");
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(stringenabled);
		if (stringenabled == "true")
		{
			enabled = 1;
		}
		else
		{
			enabled = 0;
		}
		hresult = pIElectronBeamControl_->put_BeamBlank(enabled);
		if (hresult == S_OK)
		{

		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ElectronBeamControl::OnStigmationX(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double X, Y;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIElectronBeamControl_->GetStigmator(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Set(X*g_StigmationMultiplier);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIElectronBeamControl_->GetStigmator(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Get(X);
			X = X / g_StigmationMultiplier;
			if (X > pProp->GetUpperLimit())
			{
				X = pProp->GetUpperLimit();
			}
			else if (X < pProp->GetLowerLimit())
			{
				X = pProp->GetLowerLimit();
			}
			hresult = pIElectronBeamControl_->SetStigmator(X, Y);
			if (hresult == S_OK)
			{
			}
			else
			{
				hub_->LogFEIError(hresult);
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}

	}
	return DEVICE_OK;
}

int QFeg250ElectronBeamControl::OnStigmationY(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double X, Y;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIElectronBeamControl_->GetStigmator(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Set(Y*g_StigmationMultiplier);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIElectronBeamControl_->GetStigmator(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Get(Y);
			Y = Y / g_StigmationMultiplier;
			if (Y > pProp->GetUpperLimit())
			{
				Y = pProp->GetUpperLimit();
			}
			else if (Y < pProp->GetLowerLimit())
			{
				Y = pProp->GetLowerLimit();
			}
			hresult = pIElectronBeamControl_->SetStigmator(X, Y);
			if (hresult == S_OK)
			{
			}
			else
			{
				hub_->LogFEIError(hresult);
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}

	}
	return DEVICE_OK;
}

int QFeg250ElectronBeamControl::OnBeamShiftX(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double X, Y;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIBeamControl_->GetBeamShift(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Set(X*g_BeamShiftMultiplier);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIBeamControl_->GetBeamShift(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Get(X);
			X = X / g_BeamShiftMultiplier;
			if (X > pProp->GetUpperLimit())
			{
				X = pProp->GetUpperLimit();
			}
			else if (X < pProp->GetLowerLimit())
			{
				X = pProp->GetLowerLimit();
			}
			hresult = pIBeamControl_->SetBeamShift(X, Y);
			if (hresult == S_OK)
			{
			}
			else
			{
				hub_->LogFEIError(hresult);
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}

	}
	return DEVICE_OK;
}

int QFeg250ElectronBeamControl::OnBeamShiftY(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double X, Y;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIBeamControl_->GetBeamShift(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Set(Y*g_BeamShiftMultiplier);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIBeamControl_->GetBeamShift(&X, &Y);
		if (hresult == S_OK)
		{
			pProp->Get(Y);
			Y = Y / g_BeamShiftMultiplier;
			if (Y > pProp->GetUpperLimit())
			{
				Y = pProp->GetUpperLimit();
			}
			else if (Y < pProp->GetLowerLimit())
			{
				Y = pProp->GetLowerLimit();
			}
			hresult = pIBeamControl_->SetBeamShift(X, Y);
			if (hresult == S_OK)
			{
			}
			else
			{
				hub_->LogFEIError(hresult);
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}

	}
	return DEVICE_OK;
}

QFeg250VacSystemControl::QFeg250VacSystemControl():busy_(false),initialized_(false)
{
	CreateHubIDProperty();
}

QFeg250VacSystemControl::~QFeg250VacSystemControl()
{
	Shutdown();
}

int QFeg250VacSystemControl::Initialize()
{
	if (initialized_)
		return DEVICE_OK;

	hub_ = static_cast<QFeg250*>(GetParentHub());

	pIVacSystemControl_ = hub_->pIVacSystemControl;

	if (hub_)
	{
		char hubLabel[MM::MaxStrLength];
		hub_->GetLabel(hubLabel);
		SetParentID(hubLabel); // for backward comp.
	}
	else
		LogMessage(NoHubError);

	if (hub_ != NULL && hub_->initialized_)
	{
		// Helper variables for retreiving min and max values.
		double min, max;
		long lmin, lmax;
		vector<string> BOOLOPT;
		BOOLOPT.push_back("true");
		BOOLOPT.push_back("false");

		//VacSystemControl
		CPropertyAction* pAct = new CPropertyAction(this, &QFeg250VacSystemControl::OnPressure);
		int ret = CreateProperty("Pressure (Pa)", "1000.0", MM::Float, false, pAct);
		assert(DEVICE_OK == ret);


		//	ret = CreateProperty("Pressure Range (Pa)", "0.0" , MM::Float, true);
		//	assert(DEVICE_OK == ret);
		pAct = new CPropertyAction(this, &QFeg250VacSystemControl::OnChamberState);
		ret = CreateProperty("Chamber State", "unknown", MM::String, true, pAct);
		assert(DEVICE_OK == ret);


		vector<string> StateValues;
		StateValues.push_back(g_STATE_ALL_AIR);
		StateValues.push_back(g_STATE_PUMPING);
		StateValues.push_back(g_STATE_PREVAC);
		StateValues.push_back(g_STATE_VACUUM);
		StateValues.push_back(g_STATE_VENTING);
		StateValues.push_back(g_STATE_ERROR);
		ret = SetAllowedValues("Chamber State", StateValues);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250VacSystemControl::OnChamberMode);
		ret = CreateProperty("Chamber Mode", "unknown", MM::String, true, pAct);
		assert(DEVICE_OK == ret);


		vector<string> ModeValues;
		ModeValues.push_back(g_MODE_HIVAC);
		ModeValues.push_back(g_MODE_CHARGENEUT);
		ModeValues.push_back(g_MODE_ENVIRONMENTAL);
		ret = SetAllowedValues("Chamber Mode", ModeValues);
		assert(DEVICE_OK == ret);
		HRESULT hr = pIVacSystemControl_->get_PressureRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIVacSystemControl_->get_PressureRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		SetPropertyLimits("Pressure (Pa)", min, max);

		initialized_ = true;
		return DEVICE_OK;
	}
	else
	{
		initialized_ = false;
		return DEVICE_ERR;
	}
}

int QFeg250VacSystemControl::Shutdown()
{
	if (pIVacSystemControl_)
	{
		pIVacSystemControl_ = NULL;
	}
	return DEVICE_OK;
}

void QFeg250VacSystemControl::GetName(char * pName) const
{
	CDeviceUtils::CopyLimitedString(pName, g_VacSystemDeviceName);
}

int QFeg250VacSystemControl::OnPressure(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double pressure;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIVacSystemControl_->get_Pressure(&pressure);
		if(hresult == S_OK)
		{
			pProp->Set(pressure);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(pressure);

		if(pressure > pProp->GetUpperLimit())
		{
			pressure = pProp->GetUpperLimit();
		}
		else if(pressure < pProp->GetLowerLimit())
		{
			pressure = pProp->GetLowerLimit();
		}
		hresult = pIVacSystemControl_->put_Pressure(pressure);
		if(hresult == S_OK)
		{
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250VacSystemControl::OnChamberState(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	XTLibVacuumUserState state; 
	if (eAct == MM::BeforeGet)
	{
		hresult = pIVacSystemControl_->get_State(&state);	  
		if(hresult == S_OK)
		{
			switch (state) {
			case XTLIB_VACUUM_USER_STATE_ALL_AIR:
				pProp->Set(g_STATE_ALL_AIR);
				break;

			case XTLIB_VACUUM_USER_STATE_PUMPING: 
				pProp->Set(g_STATE_PUMPING);
				break;

			case XTLIB_VACUUM_USER_STATE_PREVAC: 
				pProp->Set(g_STATE_PREVAC);
				break;
			case XTLIB_VACUUM_USER_STATE_VACUUM:
				pProp->Set(g_STATE_VACUUM);
				break;
			case XTLIB_VACUUM_USER_STATE_VENTING: 
				pProp->Set(g_STATE_VENTING);
				break;
			case XTLIB_VACUUM_USER_STATE_ERROR: 
				pProp->Set(g_STATE_ERROR);
				break;
			default:pProp->Set(g_STATE_ERROR);
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250VacSystemControl::OnChamberMode(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	XTLibVacuumUserMode mode; 
	if (eAct == MM::BeforeGet)
	{
		hresult = pIVacSystemControl_->get_Mode(&mode);	  
		if(hresult == S_OK)
		{
			switch (mode) {
			case XTLIB_VACUUMUSER_MODE_HIVAC:
				pProp->Set(g_MODE_HIVAC);
				break;

			case XTLIB_VACUUMUSER_MODE_CHARGENEUT: 
				pProp->Set(g_MODE_CHARGENEUT);
				break;

			case XTLIB_VACUUMUSER_MODE_ENVIRONMENTAL: 
				pProp->Set(g_MODE_ENVIRONMENTAL);
				break;
			default:pProp->Set(g_MODE_ENVIRONMENTAL);
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

QFeg250ScanControl::QFeg250ScanControl():busy_(false),initialized_(false)
{
	CreateHubIDProperty();
}

QFeg250ScanControl::~QFeg250ScanControl()
{
	Shutdown();
}

int QFeg250ScanControl::Initialize()
{
	if (initialized_)
		return DEVICE_OK;

	hub_ = static_cast<QFeg250*>(GetParentHub());

	pIScanControl_ = hub_->pIScanControl;

	if (hub_)
	{
		char hubLabel[MM::MaxStrLength];
		hub_->GetLabel(hubLabel);
		SetParentID(hubLabel); // for backward comp.
	}
	else
		LogMessage(NoHubError);

	if (hub_ != NULL && hub_->initialized_)
	{
		// Helper variables for retreiving min and max values.
		double min, max;
		long lmin, lmax;
		vector<string> BOOLOPT;
		BOOLOPT.push_back("true");
		BOOLOPT.push_back("false");

		//ScanControl
		CPropertyAction * pAct = new CPropertyAction(this, &QFeg250ScanControl::OnScanMode);
		int ret = CreateProperty("Scan Mode", g_SCAN_NONE, MM::String, false, pAct);
		assert(DEVICE_OK == ret);

		vector<string> ScanValues;
		ScanValues.push_back(g_SCAN_NONE);
		ScanValues.push_back(g_SCAN_EXTERNAL);
		ScanValues.push_back(g_SCAN_FULLFRAME);
		ScanValues.push_back(g_SCAN_SPOT);
		ScanValues.push_back(g_SCAN_LINE);
		ret = SetAllowedValues("Scan Mode", ScanValues);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnDwellTime);
		ret = CreateProperty("Dwell Time (us)", "0.0", MM::Float, false, pAct);
		assert(DEVICE_OK == ret);

		//		ret = CreateProperty("Dwell Time Max", "0.0" , MM::Float, true);
		//		assert(DEVICE_OK == ret);
		//		ret = CreateProperty("Dwell Time Min", "0.0" , MM::Float, true);
		//		assert(DEVICE_OK == ret);

		HRESULT hr = pIScanControl_->get_DwellTimeRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIScanControl_->get_DwellTimeRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("Dwell Time (us)", min*g_TimeMultiplier, max*g_TimeMultiplier);
		assert(DEVICE_OK == ret);


		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnVPixels);
		ret = CreateProperty("Vertical Pixels", "512", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);


		vector<string> VertPixelValues;
		VertPixelValues.push_back("512");
		VertPixelValues.push_back("1024");
		VertPixelValues.push_back("2048");
		VertPixelValues.push_back("4096");
		ret = SetAllowedValues("Vertical Pixels", VertPixelValues);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnHPixels);
		ret = CreateProperty("Horizontal Pixels", "768", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);

		vector<string> HoriPixelValues;
		HoriPixelValues.push_back("768");
		HoriPixelValues.push_back("1536");
		HoriPixelValues.push_back("3072");
		HoriPixelValues.push_back("6144");
		ret = SetAllowedValues("Horizontal Pixels", HoriPixelValues);
		assert(DEVICE_OK == ret);

		/*		ret = CreateProperty("Vertical Pixels Max", "3536" , MM::Integer, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Vertical Pixels Min", "442" , MM::Integer, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Horizontal Pixels Max", "4096" , MM::Integer, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Horizontal Pixels Min", "512" , MM::Integer, true);
		assert(DEVICE_OK == ret);*/

		hr = pIScanControl_->get_NrOfVertPixelsRange((XTLibRange)XTLIB_RANGE_MIN, &lmin);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIScanControl_->get_NrOfVertPixelsRange((XTLibRange)XTLIB_RANGE_MAX, &lmax);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		//ret = SetPropertyLimits("Vertical Pixels", static_cast<double>(lmin), static_cast<double>(lmax));
		//assert(DEVICE_OK == ret);

		hr = pIScanControl_->get_NrOfHorPixelsRange((XTLibRange)XTLIB_RANGE_MIN, &lmin);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIScanControl_->get_NrOfHorPixelsRange((XTLibRange)XTLIB_RANGE_MAX, &lmax);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		//ret = SetPropertyLimits("Horizontal Pixels", static_cast<double>(lmin), static_cast<double>(lmax));
		//assert(DEVICE_OK == ret);


		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnSelectedAreaXStart);
		ret = CreateProperty("Selected Area X Start", "0", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnSelectedAreaYStart);
		ret = CreateProperty("Selected Area Y Start", "0", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnSelectedAreaX);
		ret = CreateProperty("Selected Area X Size", "512", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnSelectedAreaY);
		ret = CreateProperty("Selected Area Y Size", "442", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);

		//512 x 442
		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnFOV);
		ret = CreateProperty("FOV X (um)", "1", MM::Float, false, pAct);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnFOV);
		ret = CreateProperty("FOV Y (um)", "0.86328125", MM::Float, true, pAct);
		assert(DEVICE_OK == ret);

		/*		ret = CreateProperty("FOV X Min", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("FOV Y Min", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("FOV X Max", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("FOV Y Max", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);*/

		hr = pIScanControl_->get_ScanFieldXRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIScanControl_->get_ScanFieldXRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("FOV X (um)", min*g_DistanceMultiplier, max*g_DistanceMultiplier);
		assert(DEVICE_OK == ret);

		hr = pIScanControl_->get_ScanFieldYRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIScanControl_->get_ScanFieldYRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("FOV Y (um)", min*g_DistanceMultiplier, max*g_DistanceMultiplier);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnRotation);
		ret = CreateProperty("Rotation", "0.0", MM::Float, false, pAct);
		assert(DEVICE_OK == ret);

		/*		ret = CreateProperty("Rotation Min", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);
		ret = CreateProperty("Rotation Max", "0.0" , MM::Float, true);
		assert(DEVICE_OK == ret);*/

		hr = pIScanControl_->get_RotationRange((XTLibRange)XTLIB_RANGE_MIN, &min);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		hr = pIScanControl_->get_RotationRange((XTLibRange)XTLIB_RANGE_MAX, &max);
		if (hr != S_OK)
		{
			hub_->LogFEIError(hr);
		}
		ret = SetPropertyLimits("Rotation", min*g_ScanRotationMultiplier, max*g_ScanRotationMultiplier);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnSelectedEnabled);
		ret = CreateProperty("Selected Area Enabled", "false", MM::String, false, pAct);
		assert(DEVICE_OK == ret);


		ret = SetAllowedValues("Selected Area Enabled", BOOLOPT);
		assert(DEVICE_OK == ret);
		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnSpotX);
		ret = CreateProperty("Spot X", "384", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);

		pAct = new CPropertyAction(this, &QFeg250ScanControl::OnSpotY);
		ret = CreateProperty("Spot Y", "256", MM::Integer, false, pAct);
		assert(DEVICE_OK == ret);

		initialized_ = true;
		return DEVICE_OK;
	}
	else
	{
		initialized_ = false;
		return DEVICE_ERR;
	}
}

int QFeg250ScanControl::Shutdown()
{
	if (pIScanControl_)
	{
		pIScanControl_ = NULL;
	}

	return DEVICE_OK;
}

void QFeg250ScanControl::GetName(char * pName) const
{
	CDeviceUtils::CopyLimitedString(pName, g_ScanDeviceName);
}

int QFeg250ScanControl::OnScanMode(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	XTLibScanMode mode;
	string modestring;
	if (eAct == MM::BeforeGet)
	{
		hresult = pIScanControl_->get_ScanMode(&mode);	  
		if(hresult == S_OK)
		{
			switch (mode) 
			{
			case XTLIB_SCAN_NONE:
				pProp->Set(g_SCAN_NONE);
				break;

			case XTLIB_SCAN_EXTERNAL: 
				pProp->Set(g_SCAN_EXTERNAL);
				break;

			case XTLIB_SCAN_FULLFRAME: 
				pProp->Set(g_SCAN_FULLFRAME);
				break;

			case XTLIB_SCAN_SPOT:
				pProp->Set(g_SCAN_SPOT);
				break;

			case XTLIB_SCAN_LINE: 
				pProp->Set(g_SCAN_LINE);
				break;
			default:pProp->Set(g_SCAN_LINE);
			}
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(modestring);
		if(modestring == g_SCAN_NONE)
		{
			hresult = pIScanControl_->put_ScanMode(XTLIB_SCAN_NONE);
		}
		else if(modestring == g_SCAN_EXTERNAL)
		{
			hresult = pIScanControl_->put_ScanMode(XTLIB_SCAN_EXTERNAL);
		}
		else if(modestring == g_SCAN_FULLFRAME)
		{
			hresult = pIScanControl_->put_ScanMode(XTLIB_SCAN_FULLFRAME);
		}
		else if(modestring == g_SCAN_SPOT)
		{
			hresult = pIScanControl_->put_ScanMode(XTLIB_SCAN_SPOT);
		}
		else if(modestring == g_SCAN_LINE)
		{
			hresult = pIScanControl_->put_ScanMode(XTLIB_SCAN_LINE);
		}
		if(hresult == S_OK)
		{

		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnDwellTime(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	double dwelltime;
	if (eAct == MM::BeforeGet)
	{
		hresult = pIScanControl_->get_DwellTime(&dwelltime);
		if(hresult == S_OK)
		{
			pProp->Set(dwelltime*g_TimeMultiplier);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(dwelltime);
		dwelltime= dwelltime/g_TimeMultiplier;
		/*	   if(dwelltime > pProp->GetUpperLimit())
		{
		dwelltime = pProp->GetUpperLimit();
		}
		else if(dwelltime < pProp->GetLowerLimit())
		{
		dwelltime = pProp->GetLowerLimit();
		}*/
		hresult = pIScanControl_->put_DwellTime(dwelltime);
		if(hresult == S_OK)
		{
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnHPixels(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	long Pixels;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIScanControl_->get_NrOfHorPixels(&Pixels);
		if(hresult == S_OK)
		{
			pProp->Set(Pixels);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(Pixels);
		hresult = pIScanControl_->put_NrOfHorPixels(Pixels);
		if(hresult == S_OK)
		{
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnVPixels(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	long Pixels;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIScanControl_->get_NrOfVertPixels(&Pixels);
		if(hresult == S_OK)
		{
			pProp->Set(Pixels);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(Pixels);
		hresult = pIScanControl_->put_NrOfVertPixels(Pixels);
		if(hresult == S_OK)
		{
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnSelectedAreaX(MM::PropertyBase* pProp, MM::ActionType eAct)
{

	HRESULT hresult;
	long XStart, YStart, X, Y;
	if (eAct == MM::BeforeGet)
	{	  
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Set(X);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Get(X);
			hresult = pIScanControl_->SetSelectedArea(XStart, YStart, X, Y);
			if(hresult == S_OK)
			{
			}
			else
			{	
				hub_->LogFEIError(hresult);
			}
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnSelectedAreaY(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	long XStart, YStart, X, Y;
	if (eAct == MM::BeforeGet)
	{	  
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Set(Y);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Get(Y);
			hresult = pIScanControl_->SetSelectedArea(XStart, YStart, X, Y);
			if(hresult == S_OK)
			{
			}
			else
			{	
				hub_->LogFEIError(hresult);
			}
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnSelectedAreaXStart(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	long XStart, YStart, X, Y;
	if (eAct == MM::BeforeGet)
	{	  
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Set(XStart);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Get(XStart);
			hresult = pIScanControl_->SetSelectedArea(XStart, YStart, X, Y);
			if(hresult == S_OK)
			{
			}
			else
			{	
				hub_->LogFEIError(hresult);
			}
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnSelectedAreaYStart(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	long XStart, YStart, X, Y;
	if (eAct == MM::BeforeGet)
	{	  
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Set(YStart);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIScanControl_->GetSelectedArea(&XStart, &YStart, &X, &Y);
		if(hresult == S_OK)
		{
			pProp->Get(YStart);
			hresult = pIScanControl_->SetSelectedArea(XStart, YStart, X, Y);
			if(hresult == S_OK)
			{
			}
			else
			{	
				hub_->LogFEIError(hresult);
			}
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnFOV(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double XFOV, YFOV;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIScanControl_->GetScanFieldSize(&XFOV, &YFOV);
		if(hresult == S_OK)
		{
			pProp->Set(XFOV*g_DistanceMultiplier);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(XFOV);

		if(XFOV > pProp->GetUpperLimit())
		{
			XFOV = pProp->GetUpperLimit();
		}
		else if(XFOV < pProp->GetLowerLimit())
		{
			XFOV = pProp->GetLowerLimit();
		}
		hresult = pIScanControl_->SetScanFieldSize(XFOV/g_DistanceMultiplier, (0.86328125*XFOV)/g_DistanceMultiplier);
		if(hresult == S_OK)
		{
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnRotation(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	double rotation;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIScanControl_->get_Rotation(&rotation);
		if(hresult == S_OK)
		{
			pProp->Set(rotation*g_ScanRotationMultiplier);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(rotation);
		if(rotation > pProp->GetUpperLimit())
		{
			rotation = pProp->GetUpperLimit();
		}
		else if(rotation < pProp->GetLowerLimit())
		{
			rotation = pProp->GetLowerLimit();
		}
		hresult = pIScanControl_->put_Rotation(rotation/g_ScanRotationMultiplier);
		if(hresult == S_OK)
		{
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnSelectedEnabled(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	VARIANT_BOOL enabled;
	string stringenabled;
	HRESULT hresult;

	if (eAct == MM::BeforeGet)
	{

		hresult = pIScanControl_->get_SelectedAreaState(&enabled);
		if(hresult == S_OK)
		{
			if(enabled == 0)	
			{
				pProp->Set("false");
			}
			else
			{
				pProp->Set("true");
			}

		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		pProp->Get(stringenabled);
		if(stringenabled == "true")
		{
			enabled = 1;
		}
		else
		{
			enabled = 0;
		}
		hresult = pIScanControl_->put_SelectedAreaState(enabled);
		if(hresult == S_OK)
		{

		}
		else
		{	
			hub_->LogFEIError(hresult);
		}
	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnSpotX(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	long X,Y;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIScanControl_->GetSpot(&X, &Y);
		if(hresult == S_OK)
		{
			pProp->Set(X);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIScanControl_->GetSpot(&X, &Y);
		if(hresult == S_OK)
		{
			pProp->Get(X);
			hresult = pIScanControl_->SetSpot(X, Y);
			if(hresult == S_OK)
			{
			}
			else
			{	
				hub_->LogFEIError(hresult);
			}
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}

	}
	return DEVICE_OK;
}

int QFeg250ScanControl::OnSpotY(MM::PropertyBase* pProp, MM::ActionType eAct)
{
	HRESULT hresult;
	long X,Y;
	if (eAct == MM::BeforeGet)
	{

		hresult = pIScanControl_->GetSpot(&X, &Y);
		if(hresult == S_OK)
		{
			pProp->Set(Y);
		}
		else
		{
			hub_->LogFEIError(hresult);
		}
	}
	else if (eAct == MM::AfterSet)
	{
		hresult = pIScanControl_->GetSpot(&X, &Y);
		if(hresult == S_OK)
		{
			pProp->Get(Y);
			hresult = pIScanControl_->SetSpot(X, Y);
			if(hresult == S_OK)
			{
			}
			else
			{	
				hub_->LogFEIError(hresult);
			}
		}
		else
		{	
			hub_->LogFEIError(hresult);
		}

	}
	return DEVICE_OK;
}

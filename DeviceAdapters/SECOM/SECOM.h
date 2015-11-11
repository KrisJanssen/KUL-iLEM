// TODO: add header

/* 
  This is effectively an inclusion guard:
  Once the header is included, it checks if a unique value (in this case SECOM_H_) is defined. 
  If it is not it defines it and continues. When the code is included again, the first ifndef fails,
  resulting in a blank file. This prevents double declarations of any identifiers such as types, 
  enums and static variables. Please not how there is an #endif at the very end of this header.
  http://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
*/
#ifndef SECOM_H_
#define SECOM_H_

/*
  These macros define some constant values through easy to read strings. 
  TODO: This might actually be bad practice as these macros do not respect scope, they are all global.
        Consider using enums.
*/
#define COM_ERROR -1L
#define PI_CNTR_NO_ERROR  0L
#define PI_CNTR_UNKNOWN_COMMAND 2L

/*
  Necessary references:
  - DeviceBase.h is necessary to work with MM style devices
  - We will use some string handling
  - Maps are associative containers that store elements formed by a combination 
    of a key value and a mapped value, following a specific order.
*/
#include "../../micromanager/MMDevice/DeviceBase.h"
#include "../../micromanager/MMDevice/DeviceThreads.h"
#include <string>
#include <map>

#ifndef WIN32
#define WINAPI
#define BOOL int
#define TRUE 1
#define FALSE 0
#endif

/*
  The SECOM platform features a single E-861 controller devices that features as the master 
  in a daisy chain configuration. This device acts as a "Hub" to which child devices are
  connected.
*/
class CSECOMStageHub : public HubBase<CSECOMStageHub>
{

public:
	// Constructor and destructor
	CSECOMStageHub();
	~CSECOMStageHub();

	// MMDevice API
	int Initialize();
	int Shutdown();
	void GetName(char* pszName) const;
	bool Busy();

	// HUB API
	MM::DeviceDetectionStatus DetectDevice(void);
	int DetectInstalledDevices();

	// Action interface
	/* 
	  Functions declared here can be supplied as property action handlers during property defenition.
	  These handlers are subsequently called when e.g. a property value is requested, changed, ...
	  E.g:

	  CPropertyAction* pAct = new CPropertyAction(this, &CSECOMStageHub::OnPort);
	  CreateProperty(MM::g_Keyword_Port, "Undefined", MM::String, false, pAct, true);
	*/
	//int OnPort(MM::PropertyBase* pPropt, MM::ActionType pAct);

	// Custom interface for child devices
	bool IsPortAvailable() { return portAvailable_; }

	bool DoReset(char device);
	bool GCSCommand(const char* command);
	bool qGCSCommand(const char* command, std::string& answer);

	double WaitingTime() { return slewrate_ * 5.0; }

	/*bool GCSCommandWithAnswer(const std::string command, std::vector<std::string>& answer, int nExpectedLines = -1);
	bool GCSCommandWithAnswer(unsigned char singleByte, std::vector<std::string>& answer, int nExpectedLines = -1);
	bool SendGCSCommand(const std::string command);
	bool SendGCSCommand(unsigned char singlebyte);
	bool ReadGCSAnswer(std::vector<std::string>& answer, int nExpectedLines = -1);*/
	int GetLastError() const { return lastError_; };

private:
	typedef int (WINAPI *FP_CloseConnection) (int);
	typedef int (WINAPI *FP_ConnectUSB) (const char*);
	typedef int (WINAPI *FP_EnumerateUSB) (char*, long, const char*);
	typedef int (WINAPI *FP_GcsCommandset) (int, const char*);
	typedef int (WINAPI *FP_GcsGetAnswer) (int, char*, int);
	typedef int (WINAPI *FP_GcsGetAnswerSize) (int, int*);
	typedef int (WINAPI *FP_IsConnected) (int);
	typedef int (WINAPI *FP_IsControllerReady) (int, int*);
	typedef int (WINAPI *FP_qSPA) (int, const char*, unsigned int*, double*, char*, int);
	
	FP_CloseConnection CloseConnection_;
	FP_ConnectUSB ConnectUSB_;
	FP_EnumerateUSB EnumerateUSB_;
	FP_GcsCommandset GcsCommandset_;
	FP_GcsGetAnswer GcsGetAnswer_;
	FP_GcsGetAnswerSize GcsGetAnswerSize_;
	FP_IsConnected IsConnected_;
	FP_IsControllerReady IsControllerReady_;
	FP_qSPA qSPA_;

	int LoadDLL(const std::string& dllName);
	void* LoadDLLFunc(const char* funcName);
	void CloseAndUnload();
	int ConnectUSB(const std::string& interfaceParameter);

	std::string controllerType_, dllName_, dllPrefix_, interfaceParameter_;
	bool initialized_, portAvailable_, isSerialBusy_;
	int lastError_, ID_;
	double slewrate_;


#ifdef WIN32
	HMODULE module_;
#else
	void* module_;
#endif
};

class CSECOMStageXY : public CXYStageBase<CSECOMStageXY>
{
public:

	// Constructor and destructor.
	CSECOMStageXY(bool feedback, char addressX, char addressY);
	~CSECOMStageXY();

	// MMDevice API
	int Initialize();
	int Shutdown();

	void GetName(char* pszName) const;
	bool Busy();

	// Stage API
	virtual double GetStepSize();
	virtual int SetPositionSteps(long x, long y);
	virtual int GetPositionSteps(long &x, long &y);
	virtual int Home();
	virtual int Stop();
	virtual int SetOrigin();
	virtual int GetLimitsUm(double& xMin, double& xMax, double& yMin, double& yMax);
	virtual int GetStepLimits(long& xMin, long& xMax, long& yMin, long& yMax);
	virtual double GetStepSizeXUm();
	virtual double GetStepSizeYUm();
	virtual int SetRelativePositionUm(double dx, double dy);
	virtual int SetPositionUm(double dx, double dy);
	virtual int GetPositionUm(double &dx, double &dy);

	int IsXYStageSequenceable(bool& isSequenceable) const { isSequenceable = false; return DEVICE_OK; }

	// Action interface. Refer to the code above for a detailed explanation on Actions.
	//int CSECOMStageXY::OnStepVoltage(MM::PropertyBase* pProp, MM::ActionType pAct);
	int CSECOMStageXY::OnFineVoltageX(MM::PropertyBase* pProp, MM::ActionType pAct);
	int CSECOMStageXY::OnFineVoltageY(MM::PropertyBase* pProp, MM::ActionType pAct);
	int CSECOMStageXY::OnHasPositionFeedback(MM::PropertyBase* pProp, MM::ActionType pAct);
	int OnReset(MM::PropertyBase* pPropt, MM::ActionType pAct);

private:
	bool initialized_;
	std::string name_;
	double umPerStepUp_, umPerStepDown_, umPerStepLeft_, umPerStepRight_;
	double xPos_, yPos_;
	double xOrigin_, yOrigin_;
	bool wasLastMoveStepL_;
	bool isFirstMoveL_;
	bool wasLastMoveStepR_;
	bool isFirstMoveR_;
	bool supportsPositionFeedback_;
	char addressX_, addressY_;
};

//class CSECOMStageLR : public CXYStageBase<CSECOMStageLR>
//{
//public:
//	// Constructor and destructor
//	CSECOMStageLR();
//	~CSECOMStageLR();
//
//	// MMDevice API
//	int Initialize();
//	int Shutdown();
//	void GetName(char* pszName) const;
//	bool Busy();
//
//	// Stage API
//	virtual double GetStepSize();
//	virtual int SetPositionSteps(long x, long y);
//	virtual int GetPositionSteps(long &x, long &y);
//	virtual int Home();
//	virtual int Stop();
//	virtual int SetOrigin();
//	virtual int GetLimitsUm(double& xMin, double& xMax, double& yMin, double& yMax);
//	virtual int GetStepLimits(long& xMin, long& xMax, long& yMin, long& yMax);
//	virtual double GetStepSizeXUm();
//	virtual double GetStepSizeYUm();
//	virtual int SetRelativePositionUm(double dx, double dy);
//
//	int IsXYStageSequenceable(bool& isSequenceable) const { isSequenceable = false; return DEVICE_OK; }
//
//	// Action interface. Refer to the code above for a detailed explanation on Actions.
//	//int CSECOMStageLR::OnStepVoltage(MM::PropertyBase* pProp, MM::ActionType pAct);
//	int CSECOMStageLR::OnFineVoltageX(MM::PropertyBase* pProp, MM::ActionType pAct);
//	int CSECOMStageLR::OnFineVoltageY(MM::PropertyBase* pProp, MM::ActionType pAct);
//	int OnReset(MM::PropertyBase* pPropt, MM::ActionType pAct);
//
//private:
//	bool initialized_;
//	std::string name_;
//	double umPerStepUp_, umPerStepDown_, umPerStepLeft_, umPerStepRight_;
//	double xPos_, yPos_;
//	bool wasLastMoveStepL_;
//	bool isFirstMoveL_;
//	bool wasLastMoveStepR_;
//	bool isFirstMoveR_;
//
//};

class CSECOMStageZ : public CStageBase<CSECOMStageZ>
{
public:

	// Constructor and destructor.
	CSECOMStageZ();
	~CSECOMStageZ();

	// MMDevice API
	int Initialize();
	int Shutdown();
	void GetName(char* pszName) const;
	bool Busy();

	// Stage API
	virtual int SetPositionUm(double pos);
	virtual int GetPositionUm(double& pos);
	virtual int SetRelativePositionUm(double pos);
	virtual double GetStepSize() { return 1.0; }
	virtual int GetPositionSteps(long& steps)
	{
		steps = 0;
		return DEVICE_OK;
	}
	virtual int SetPositionSteps(long steps);
	virtual int SetOrigin() { return DEVICE_OK; }
	virtual int GetLimits(double& lower, double& upper)
	{
		lower = -1.0;
		upper = 1.0;
		return DEVICE_OK;
	}
	virtual int Move(double /*v*/) { return DEVICE_OK; }
	int IsStageSequenceable(bool& isSequenceable) const { isSequenceable = false; return DEVICE_OK; }
	bool IsContinuousFocusDrive() const { return false; }

	// Action interface. Refer to the code above for a detailed explanation on Actions.
	int CSECOMStageZ::OnFineVoltage(MM::PropertyBase* pProp, MM::ActionType pAct);
	int CSECOMStageZ::OnStepVoltage(MM::PropertyBase* pProp, MM::ActionType pAct);
	int OnReset(MM::PropertyBase* pPropt, MM::ActionType pAct);
	int OnHome(MM::PropertyBase* pPropt, MM::ActionType pAct);
	int OnOrigin(MM::PropertyBase* pPropt, MM::ActionType pAct);

private:
	bool initialized_;
	std::string name_;
	double umPerStepUp_, umPerStepDown_;
	bool _wasLastMoveStep;
	bool _isFirstMove;
	double _Pos;
};

#endif // !SECOM_H_

// TODO: add header

/*
This is effectively an inclusion guard:
Once the header is included, it checks if a unique value (in this case SECOM_H_) is defined.
If it is not it defines it and continues. When the code is included again, the first ifndef fails,
resulting in a blank file. This prevents double declarations of any identifiers such as types,
enums and static variables. Please not how there is an #endif at the very end of this header.
http://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
*/
#ifndef _FEISEM_H_
#define _FEISEM_H_

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

/*
Necessary includes for FEI DCOM.
*/
#include <atlbase.h>
#include "FEI\xtlib2.h"   // XTLib includes (interface definitions)
#include "FEI\xtlib2_i.c" // XTLib includes (constants CLSID,IDD)

/*
These macros define some constant values through easy to read strings.
TODO: This might actually be bad practice as these macros do not respect scope, they are all global.
Consider using enums.
*/
#define ERR_UNKNOWN_MODE         102
#define ERR_UNKNOWN_POSITION     103
#define ERR_IN_SEQUENCE          104
#define ERR_SEQUENCE_INACTIVE    105
#define ERR_STAGE_MOVING         106
#define SIMULATED_ERROR          200
#define HUB_NOT_AVAILABLE        107x

const char* NoHubError = "Parent Hub not defined.";

const char* g_HubDeviceName = "QFEG-250";
const char* g_BeamDeviceName = "QFEG-250-BeamControl";
const char* g_StageDeviceName = "QFEG-250-StageControl";
const char* g_ScanDeviceName = "QFEG-250-ScanControl";
const char* g_VacSystemDeviceName = "QFEG-250-VacSystemControl";
const char* g_VideoDeviceName = "QFEG-250-VideoControl";

//class QFeg250 : public HubBase<QFeg250>
//{
//public:
//	// Constructor and destructor
//	QFeg250();
//	~QFeg250();
//
//   // MMDevice API
//   int Initialize();
//   int Shutdown();
//   void GetName(char* pName) const; 
//   bool Busy() { return busy_;} ;
//   //bool GenerateRandomError();
//
//   // HUB api
//   MM::DeviceDetectionStatus DetectDevice(void);
//   int DetectInstalledDevices();
//   void LogFEIError(HRESULT hresult);
//   // action interface
// //  int OnErrorRate(MM::PropertyBase* pProp, MM::ActionType eAct);
// //  int OnDivideOneByMe(MM::PropertyBase* pProp, MM::ActionType eAct);
//
//private:
// //  void GetPeripheralInventory();
//
//   //std::vector<std::string> peripherals_;
//   bool initialized_;
//   bool busy_;
//   int lastError_;
//   static MMThreadLock lock_;
//   IMicroscopeControl * pIMicroscopeControl;
//};

/*class FEISEMCamera : public CCameraBase<FEISEMCamera>
{

}*/

class QFeg250 : public HubBase<QFeg250>
{
public:
	QFeg250();
	~QFeg250();

	int Initialize();
	int Shutdown();
	void GetName(char* pszName) const;
	bool Busy() { return busy_; };

	void LogFEIError(HRESULT hresult);
	void COMInit();

	// HUB API
	MM::DeviceDetectionStatus DetectDevice(void);
	int DetectInstalledDevices();

	friend class QFeg250ElectronBeamControl;
	friend class QFeg250ScanControl;
	friend class QFeg250StageControl;
	friend class QFeg250VideoControl;
	friend class QFeg250VacSystemControl;

private:
	bool initialized_;
	bool busy_;
	int counter_;

	// The core interfaces of XTLib.
	IMicroscopeControl * pIMicroscopeControl;
	IBeamControl * pIBeamControl;
	IScanControl * pIScanControl;
	IStageControl * pIStageControl;
	IVideoControl * pIVideoControl;
	IVacSystemControl * pIVacSystemControl;

	IElectronBeamControl * pIElectronBeamControl;

	IConnectionPointContainer * pIConnectionPointContainer;
	IDispatch * pIDispatch;
};

class QFeg250ElectronBeamControl : public CGenericBase<QFeg250ElectronBeamControl>
{
public:
	QFeg250ElectronBeamControl();
	~QFeg250ElectronBeamControl();

	int Initialize();
	int Shutdown();
	void GetName(char* pszName) const;
	bool Busy() { return busy_; };

	int OnHTState(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnHTVoltage(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSpotSize(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnBeamBlank(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnStigmationX(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnStigmationY(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnBeamShiftX(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnBeamShiftY(MM::PropertyBase* pProp, MM::ActionType eAct);

private:
	QFeg250 * hub_;
	bool initialized_;
	bool busy_;
	IBeamControl * pIBeamControl_;
	IElectronBeamControl * pIElectronBeamControl_;

};

class QFeg250ScanControl : public CGenericBase<QFeg250ScanControl>
{
public:
	QFeg250ScanControl();
	~QFeg250ScanControl();

	int Initialize();
	int Shutdown();
	void GetName(char* pName) const;
	bool Busy() { return busy_; };

	int OnScanMode(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnDwellTime(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnHPixels(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnVPixels(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSelectedAreaX(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSelectedAreaY(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSelectedAreaXStart(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSelectedAreaYStart(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnRotation(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnFOV(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSelectedEnabled(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSpotX(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnSpotY(MM::PropertyBase* pProp, MM::ActionType eAct);

private:
	QFeg250 * hub_;
	bool initialized_;
	bool busy_;
	IScanControl * pIScanControl_;
};

class QFeg250StageControl : public CGenericBase<QFeg250StageControl>
{
public:
	
	QFeg250StageControl();
	~QFeg250StageControl();

	int Initialize();
	int Shutdown();



private:
	bool initialized_;
	bool busy_;

};

class QFeg250VideoControl : public CGenericBase<QFeg250VideoControl>
{
public:
	QFeg250VideoControl();
	~QFeg250VideoControl();

	int Initialize();
	int Shutdown();



private:
	bool initialized_;
	bool busy_;

};

class QFeg250VacSystemControl : public CGenericBase<QFeg250VacSystemControl>
{
public:
	QFeg250VacSystemControl();
	~QFeg250VacSystemControl();

	int Initialize();
	int Shutdown();
	void GetName(char* pName) const;
	bool Busy() { return busy_; };

	int OnPressure(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnChamberState(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnChamberMode(MM::PropertyBase* pProp, MM::ActionType eAct);

private:
	QFeg250 * hub_;
	bool initialized_;
	bool busy_;
	IVacSystemControl * pIVacSystemControl_;

};

#endif //_FEISEM_H_

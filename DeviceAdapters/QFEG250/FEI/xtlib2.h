

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Apr 29 14:21:23 2011
 */
/* Compiler settings for ..\..\export\include\idl\xtlib2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __xtlib2_h__
#define __xtlib2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVacSystemControl_FWD_DEFINED__
#define __IVacSystemControl_FWD_DEFINED__
typedef interface IVacSystemControl IVacSystemControl;
#endif 	/* __IVacSystemControl_FWD_DEFINED__ */


#ifndef ___IVacSystemControlEvents_FWD_DEFINED__
#define ___IVacSystemControlEvents_FWD_DEFINED__
typedef interface _IVacSystemControlEvents _IVacSystemControlEvents;
#endif 	/* ___IVacSystemControlEvents_FWD_DEFINED__ */


#ifndef __VacSystemControl_FWD_DEFINED__
#define __VacSystemControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class VacSystemControl VacSystemControl;
#else
typedef struct VacSystemControl VacSystemControl;
#endif /* __cplusplus */

#endif 	/* __VacSystemControl_FWD_DEFINED__ */


#ifndef __IElectronBeamControl_FWD_DEFINED__
#define __IElectronBeamControl_FWD_DEFINED__
typedef interface IElectronBeamControl IElectronBeamControl;
#endif 	/* __IElectronBeamControl_FWD_DEFINED__ */


#ifndef ___IElectronBeamControlEvents_FWD_DEFINED__
#define ___IElectronBeamControlEvents_FWD_DEFINED__
typedef interface _IElectronBeamControlEvents _IElectronBeamControlEvents;
#endif 	/* ___IElectronBeamControlEvents_FWD_DEFINED__ */


#ifndef __ElectronBeamControl_FWD_DEFINED__
#define __ElectronBeamControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class ElectronBeamControl ElectronBeamControl;
#else
typedef struct ElectronBeamControl ElectronBeamControl;
#endif /* __cplusplus */

#endif 	/* __ElectronBeamControl_FWD_DEFINED__ */


#ifndef __IBeamControl_FWD_DEFINED__
#define __IBeamControl_FWD_DEFINED__
typedef interface IBeamControl IBeamControl;
#endif 	/* __IBeamControl_FWD_DEFINED__ */


#ifndef ___IBeamControlEvents_FWD_DEFINED__
#define ___IBeamControlEvents_FWD_DEFINED__
typedef interface _IBeamControlEvents _IBeamControlEvents;
#endif 	/* ___IBeamControlEvents_FWD_DEFINED__ */


#ifndef __BeamControl_FWD_DEFINED__
#define __BeamControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class BeamControl BeamControl;
#else
typedef struct BeamControl BeamControl;
#endif /* __cplusplus */

#endif 	/* __BeamControl_FWD_DEFINED__ */


#ifndef __IStageControl_FWD_DEFINED__
#define __IStageControl_FWD_DEFINED__
typedef interface IStageControl IStageControl;
#endif 	/* __IStageControl_FWD_DEFINED__ */


#ifndef ___IStageControlEvents_FWD_DEFINED__
#define ___IStageControlEvents_FWD_DEFINED__
typedef interface _IStageControlEvents _IStageControlEvents;
#endif 	/* ___IStageControlEvents_FWD_DEFINED__ */


#ifndef __StageControl_FWD_DEFINED__
#define __StageControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class StageControl StageControl;
#else
typedef struct StageControl StageControl;
#endif /* __cplusplus */

#endif 	/* __StageControl_FWD_DEFINED__ */


#ifndef __IScanControl_FWD_DEFINED__
#define __IScanControl_FWD_DEFINED__
typedef interface IScanControl IScanControl;
#endif 	/* __IScanControl_FWD_DEFINED__ */


#ifndef ___IScanControlEvents_FWD_DEFINED__
#define ___IScanControlEvents_FWD_DEFINED__
typedef interface _IScanControlEvents _IScanControlEvents;
#endif 	/* ___IScanControlEvents_FWD_DEFINED__ */


#ifndef __ScanControl_FWD_DEFINED__
#define __ScanControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScanControl ScanControl;
#else
typedef struct ScanControl ScanControl;
#endif /* __cplusplus */

#endif 	/* __ScanControl_FWD_DEFINED__ */


#ifndef __IDetectorGroup_FWD_DEFINED__
#define __IDetectorGroup_FWD_DEFINED__
typedef interface IDetectorGroup IDetectorGroup;
#endif 	/* __IDetectorGroup_FWD_DEFINED__ */


#ifndef ___IDetectorGroupEvents_FWD_DEFINED__
#define ___IDetectorGroupEvents_FWD_DEFINED__
typedef interface _IDetectorGroupEvents _IDetectorGroupEvents;
#endif 	/* ___IDetectorGroupEvents_FWD_DEFINED__ */


#ifndef __DetectorGroup_FWD_DEFINED__
#define __DetectorGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class DetectorGroup DetectorGroup;
#else
typedef struct DetectorGroup DetectorGroup;
#endif /* __cplusplus */

#endif 	/* __DetectorGroup_FWD_DEFINED__ */


#ifndef __IDetectorGroups_FWD_DEFINED__
#define __IDetectorGroups_FWD_DEFINED__
typedef interface IDetectorGroups IDetectorGroups;
#endif 	/* __IDetectorGroups_FWD_DEFINED__ */


#ifndef __DetectorGroups_FWD_DEFINED__
#define __DetectorGroups_FWD_DEFINED__

#ifdef __cplusplus
typedef class DetectorGroups DetectorGroups;
#else
typedef struct DetectorGroups DetectorGroups;
#endif /* __cplusplus */

#endif 	/* __DetectorGroups_FWD_DEFINED__ */


#ifndef __IChannel_FWD_DEFINED__
#define __IChannel_FWD_DEFINED__
typedef interface IChannel IChannel;
#endif 	/* __IChannel_FWD_DEFINED__ */


#ifndef ___IChannelEvents_FWD_DEFINED__
#define ___IChannelEvents_FWD_DEFINED__
typedef interface _IChannelEvents _IChannelEvents;
#endif 	/* ___IChannelEvents_FWD_DEFINED__ */


#ifndef __Channel_FWD_DEFINED__
#define __Channel_FWD_DEFINED__

#ifdef __cplusplus
typedef class Channel Channel;
#else
typedef struct Channel Channel;
#endif /* __cplusplus */

#endif 	/* __Channel_FWD_DEFINED__ */


#ifndef __ICCDChannel_FWD_DEFINED__
#define __ICCDChannel_FWD_DEFINED__
typedef interface ICCDChannel ICCDChannel;
#endif 	/* __ICCDChannel_FWD_DEFINED__ */


#ifndef ___ICCDChannelEvents_FWD_DEFINED__
#define ___ICCDChannelEvents_FWD_DEFINED__
typedef interface _ICCDChannelEvents _ICCDChannelEvents;
#endif 	/* ___ICCDChannelEvents_FWD_DEFINED__ */


#ifndef __CCDChannel_FWD_DEFINED__
#define __CCDChannel_FWD_DEFINED__

#ifdef __cplusplus
typedef class CCDChannel CCDChannel;
#else
typedef struct CCDChannel CCDChannel;
#endif /* __cplusplus */

#endif 	/* __CCDChannel_FWD_DEFINED__ */


#ifndef __IChannels_FWD_DEFINED__
#define __IChannels_FWD_DEFINED__
typedef interface IChannels IChannels;
#endif 	/* __IChannels_FWD_DEFINED__ */


#ifndef ___IChannelsEvents_FWD_DEFINED__
#define ___IChannelsEvents_FWD_DEFINED__
typedef interface _IChannelsEvents _IChannelsEvents;
#endif 	/* ___IChannelsEvents_FWD_DEFINED__ */


#ifndef __Channels_FWD_DEFINED__
#define __Channels_FWD_DEFINED__

#ifdef __cplusplus
typedef class Channels Channels;
#else
typedef struct Channels Channels;
#endif /* __cplusplus */

#endif 	/* __Channels_FWD_DEFINED__ */


#ifndef __IVideoControl_FWD_DEFINED__
#define __IVideoControl_FWD_DEFINED__
typedef interface IVideoControl IVideoControl;
#endif 	/* __IVideoControl_FWD_DEFINED__ */


#ifndef ___IVideoControlEvents_FWD_DEFINED__
#define ___IVideoControlEvents_FWD_DEFINED__
typedef interface _IVideoControlEvents _IVideoControlEvents;
#endif 	/* ___IVideoControlEvents_FWD_DEFINED__ */


#ifndef __VideoControl_FWD_DEFINED__
#define __VideoControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class VideoControl VideoControl;
#else
typedef struct VideoControl VideoControl;
#endif /* __cplusplus */

#endif 	/* __VideoControl_FWD_DEFINED__ */


#ifndef __IMicroscopeControl_FWD_DEFINED__
#define __IMicroscopeControl_FWD_DEFINED__
typedef interface IMicroscopeControl IMicroscopeControl;
#endif 	/* __IMicroscopeControl_FWD_DEFINED__ */


#ifndef ___IMicroscopeControlEvents_FWD_DEFINED__
#define ___IMicroscopeControlEvents_FWD_DEFINED__
typedef interface _IMicroscopeControlEvents _IMicroscopeControlEvents;
#endif 	/* ___IMicroscopeControlEvents_FWD_DEFINED__ */


#ifndef __MicroscopeControl_FWD_DEFINED__
#define __MicroscopeControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class MicroscopeControl MicroscopeControl;
#else
typedef struct MicroscopeControl MicroscopeControl;
#endif /* __cplusplus */

#endif 	/* __MicroscopeControl_FWD_DEFINED__ */


#ifndef __IElectronBeamControl2_FWD_DEFINED__
#define __IElectronBeamControl2_FWD_DEFINED__
typedef interface IElectronBeamControl2 IElectronBeamControl2;
#endif 	/* __IElectronBeamControl2_FWD_DEFINED__ */


#ifndef ___IElectronBeamControl2Events_FWD_DEFINED__
#define ___IElectronBeamControl2Events_FWD_DEFINED__
typedef interface _IElectronBeamControl2Events _IElectronBeamControl2Events;
#endif 	/* ___IElectronBeamControl2Events_FWD_DEFINED__ */


#ifndef __ElectronBeamControl2_FWD_DEFINED__
#define __ElectronBeamControl2_FWD_DEFINED__

#ifdef __cplusplus
typedef class ElectronBeamControl2 ElectronBeamControl2;
#else
typedef struct ElectronBeamControl2 ElectronBeamControl2;
#endif /* __cplusplus */

#endif 	/* __ElectronBeamControl2_FWD_DEFINED__ */


#ifndef __IBeamControl2_FWD_DEFINED__
#define __IBeamControl2_FWD_DEFINED__
typedef interface IBeamControl2 IBeamControl2;
#endif 	/* __IBeamControl2_FWD_DEFINED__ */


#ifndef __BeamControl2_FWD_DEFINED__
#define __BeamControl2_FWD_DEFINED__

#ifdef __cplusplus
typedef class BeamControl2 BeamControl2;
#else
typedef struct BeamControl2 BeamControl2;
#endif /* __cplusplus */

#endif 	/* __BeamControl2_FWD_DEFINED__ */


#ifndef __IStageControl2_FWD_DEFINED__
#define __IStageControl2_FWD_DEFINED__
typedef interface IStageControl2 IStageControl2;
#endif 	/* __IStageControl2_FWD_DEFINED__ */


#ifndef ___IStageControl2Events_FWD_DEFINED__
#define ___IStageControl2Events_FWD_DEFINED__
typedef interface _IStageControl2Events _IStageControl2Events;
#endif 	/* ___IStageControl2Events_FWD_DEFINED__ */


#ifndef __StageControl2_FWD_DEFINED__
#define __StageControl2_FWD_DEFINED__

#ifdef __cplusplus
typedef class StageControl2 StageControl2;
#else
typedef struct StageControl2 StageControl2;
#endif /* __cplusplus */

#endif 	/* __StageControl2_FWD_DEFINED__ */


#ifndef __IMicroscopeControl2_FWD_DEFINED__
#define __IMicroscopeControl2_FWD_DEFINED__
typedef interface IMicroscopeControl2 IMicroscopeControl2;
#endif 	/* __IMicroscopeControl2_FWD_DEFINED__ */


#ifndef __MicroscopeControl2_FWD_DEFINED__
#define __MicroscopeControl2_FWD_DEFINED__

#ifdef __cplusplus
typedef class MicroscopeControl2 MicroscopeControl2;
#else
typedef struct MicroscopeControl2 MicroscopeControl2;
#endif /* __cplusplus */

#endif 	/* __MicroscopeControl2_FWD_DEFINED__ */


#ifndef __IScanControl2_FWD_DEFINED__
#define __IScanControl2_FWD_DEFINED__
typedef interface IScanControl2 IScanControl2;
#endif 	/* __IScanControl2_FWD_DEFINED__ */


#ifndef __ScanControl2_FWD_DEFINED__
#define __ScanControl2_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScanControl2 ScanControl2;
#else
typedef struct ScanControl2 ScanControl2;
#endif /* __cplusplus */

#endif 	/* __ScanControl2_FWD_DEFINED__ */


#ifndef __IStageControl3_FWD_DEFINED__
#define __IStageControl3_FWD_DEFINED__
typedef interface IStageControl3 IStageControl3;
#endif 	/* __IStageControl3_FWD_DEFINED__ */


#ifndef __StageControl3_FWD_DEFINED__
#define __StageControl3_FWD_DEFINED__

#ifdef __cplusplus
typedef class StageControl3 StageControl3;
#else
typedef struct StageControl3 StageControl3;
#endif /* __cplusplus */

#endif 	/* __StageControl3_FWD_DEFINED__ */


#ifndef __IMicroscopeControl3_FWD_DEFINED__
#define __IMicroscopeControl3_FWD_DEFINED__
typedef interface IMicroscopeControl3 IMicroscopeControl3;
#endif 	/* __IMicroscopeControl3_FWD_DEFINED__ */


#ifndef __MicroscopeControl3_FWD_DEFINED__
#define __MicroscopeControl3_FWD_DEFINED__

#ifdef __cplusplus
typedef class MicroscopeControl3 MicroscopeControl3;
#else
typedef struct MicroscopeControl3 MicroscopeControl3;
#endif /* __cplusplus */

#endif 	/* __MicroscopeControl3_FWD_DEFINED__ */


#ifndef __IElectronBeamControl3_FWD_DEFINED__
#define __IElectronBeamControl3_FWD_DEFINED__
typedef interface IElectronBeamControl3 IElectronBeamControl3;
#endif 	/* __IElectronBeamControl3_FWD_DEFINED__ */


#ifndef ___IElectronBeamControl3Events_FWD_DEFINED__
#define ___IElectronBeamControl3Events_FWD_DEFINED__
typedef interface _IElectronBeamControl3Events _IElectronBeamControl3Events;
#endif 	/* ___IElectronBeamControl3Events_FWD_DEFINED__ */


#ifndef __IConsoleControl_FWD_DEFINED__
#define __IConsoleControl_FWD_DEFINED__
typedef interface IConsoleControl IConsoleControl;
#endif 	/* __IConsoleControl_FWD_DEFINED__ */


#ifndef ___IConsoleControlEvents_FWD_DEFINED__
#define ___IConsoleControlEvents_FWD_DEFINED__
typedef interface _IConsoleControlEvents _IConsoleControlEvents;
#endif 	/* ___IConsoleControlEvents_FWD_DEFINED__ */


#ifndef __IMicroscopeControl4_FWD_DEFINED__
#define __IMicroscopeControl4_FWD_DEFINED__
typedef interface IMicroscopeControl4 IMicroscopeControl4;
#endif 	/* __IMicroscopeControl4_FWD_DEFINED__ */


#ifndef __ElectronBeamControl3_FWD_DEFINED__
#define __ElectronBeamControl3_FWD_DEFINED__

#ifdef __cplusplus
typedef class ElectronBeamControl3 ElectronBeamControl3;
#else
typedef struct ElectronBeamControl3 ElectronBeamControl3;
#endif /* __cplusplus */

#endif 	/* __ElectronBeamControl3_FWD_DEFINED__ */


#ifndef __ConsoleControl_FWD_DEFINED__
#define __ConsoleControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class ConsoleControl ConsoleControl;
#else
typedef struct ConsoleControl ConsoleControl;
#endif /* __cplusplus */

#endif 	/* __ConsoleControl_FWD_DEFINED__ */


#ifndef __MicroscopeControl4_FWD_DEFINED__
#define __MicroscopeControl4_FWD_DEFINED__

#ifdef __cplusplus
typedef class MicroscopeControl4 MicroscopeControl4;
#else
typedef struct MicroscopeControl4 MicroscopeControl4;
#endif /* __cplusplus */

#endif 	/* __MicroscopeControl4_FWD_DEFINED__ */


#ifndef __IBeamAperture_FWD_DEFINED__
#define __IBeamAperture_FWD_DEFINED__
typedef interface IBeamAperture IBeamAperture;
#endif 	/* __IBeamAperture_FWD_DEFINED__ */


#ifndef __IBeamApertures_FWD_DEFINED__
#define __IBeamApertures_FWD_DEFINED__
typedef interface IBeamApertures IBeamApertures;
#endif 	/* __IBeamApertures_FWD_DEFINED__ */


#ifndef __IElectronBeamControl4_FWD_DEFINED__
#define __IElectronBeamControl4_FWD_DEFINED__
typedef interface IElectronBeamControl4 IElectronBeamControl4;
#endif 	/* __IElectronBeamControl4_FWD_DEFINED__ */


#ifndef ___IElectronBeamControl4Events_FWD_DEFINED__
#define ___IElectronBeamControl4Events_FWD_DEFINED__
typedef interface _IElectronBeamControl4Events _IElectronBeamControl4Events;
#endif 	/* ___IElectronBeamControl4Events_FWD_DEFINED__ */


#ifndef __BeamAperture_FWD_DEFINED__
#define __BeamAperture_FWD_DEFINED__

#ifdef __cplusplus
typedef class BeamAperture BeamAperture;
#else
typedef struct BeamAperture BeamAperture;
#endif /* __cplusplus */

#endif 	/* __BeamAperture_FWD_DEFINED__ */


#ifndef __BeamApertures_FWD_DEFINED__
#define __BeamApertures_FWD_DEFINED__

#ifdef __cplusplus
typedef class BeamApertures BeamApertures;
#else
typedef struct BeamApertures BeamApertures;
#endif /* __cplusplus */

#endif 	/* __BeamApertures_FWD_DEFINED__ */


#ifndef __ElectronBeamControl4_FWD_DEFINED__
#define __ElectronBeamControl4_FWD_DEFINED__

#ifdef __cplusplus
typedef class ElectronBeamControl4 ElectronBeamControl4;
#else
typedef struct ElectronBeamControl4 ElectronBeamControl4;
#endif /* __cplusplus */

#endif 	/* __ElectronBeamControl4_FWD_DEFINED__ */


#ifndef __IVacSystemControl2_FWD_DEFINED__
#define __IVacSystemControl2_FWD_DEFINED__
typedef interface IVacSystemControl2 IVacSystemControl2;
#endif 	/* __IVacSystemControl2_FWD_DEFINED__ */


#ifndef __VacSystemControl2_FWD_DEFINED__
#define __VacSystemControl2_FWD_DEFINED__

#ifdef __cplusplus
typedef class VacSystemControl2 VacSystemControl2;
#else
typedef struct VacSystemControl2 VacSystemControl2;
#endif /* __cplusplus */

#endif 	/* __VacSystemControl2_FWD_DEFINED__ */


#ifndef __IMicroscopeControl5_FWD_DEFINED__
#define __IMicroscopeControl5_FWD_DEFINED__
typedef interface IMicroscopeControl5 IMicroscopeControl5;
#endif 	/* __IMicroscopeControl5_FWD_DEFINED__ */


#ifndef __MicroscopeControl5_FWD_DEFINED__
#define __MicroscopeControl5_FWD_DEFINED__

#ifdef __cplusplus
typedef class MicroscopeControl5 MicroscopeControl5;
#else
typedef struct MicroscopeControl5 MicroscopeControl5;
#endif /* __cplusplus */

#endif 	/* __MicroscopeControl5_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_xtlib2_0000_0000 */
/* [local] */ 

#ifndef __XTLib_CONSTANTS__
#define __XTLib_CONSTANTS__
typedef /* [public] */ 
enum tagXTLibRange
    {	XTLIB_RANGE_MIN	= 0,
	XTLIB_RANGE_MAX	= ( XTLIB_RANGE_MIN + 1 ) 
    } 	XTLibRange;

typedef /* [public] */ 
enum tagXTLibMode
    {	XTLIB_TEST_MODE	= 0,
	XTLIB_RUN_MODE	= ( XTLIB_TEST_MODE + 1 ) 
    } 	XTLibMode;

typedef /* [public] */ 
enum tagXTLibCallMode
    {	XTLIB_SYNC_CALLS	= 0,
	XTLIB_ASYNC_CALLS	= ( XTLIB_SYNC_CALLS + 1 ) 
    } 	XTLibCallMode;

typedef /* [public] */ 
enum tagXTLibBeamMode
    {	XTLIB_BEAM_UNKNOWN	= 0,
	XTLIB_BEAM_ELECTRON	= ( XTLIB_BEAM_UNKNOWN + 1 ) ,
	XTLIB_BEAM_ION	= ( XTLIB_BEAM_ELECTRON + 1 ) 
    } 	XTLibBeamMode;

typedef /* [public] */ 
enum tagXTLibVacuumUserMode
    {	XTLIB_VACUUMUSER_MODE_HIVAC	= 1,
	XTLIB_VACUUMUSER_MODE_CHARGENEUT	= 2,
	XTLIB_VACUUMUSER_MODE_ENVIRONMENTAL	= 3
    } 	XTLibVacuumUserMode;

typedef /* [public] */ 
enum tagXTLibVacuumUserState
    {	XTLIB_VACUUM_USER_STATE_ALL_AIR	= 1,
	XTLIB_VACUUM_USER_STATE_PUMPING	= 2,
	XTLIB_VACUUM_USER_STATE_PREVAC	= 3,
	XTLIB_VACUUM_USER_STATE_VACUUM	= 4,
	XTLIB_VACUUM_USER_STATE_VENTING	= 5,
	XTLIB_VACUUM_USER_STATE_ERROR	= 6
    } 	XTLibVacuumUserState;

typedef /* [public] */ 
enum tagHTState
    {	HT_ON	= 1,
	HT_OFF	= 2,
	HT_RAMPING_UP	= 4,
	HT_RAMPING_DOWN	= 8,
	HT_INITIALIZING	= 16,
	HT_DISABLED	= 32,
	HT_VAC_NOT_OK	= 64,
	DEGAUSS_BUSY	= 128,
	AVA_MOVING	= 256,
	L1_RAMPING	= 512,
	SOURCE_ON	= 1024,
	SOURCE_OFF	= 2048
    } 	HTState;

typedef /* [public] */ 
enum tagStageAxisMask
    {	STAGE_AXIS_NONE	= 0,
	STAGE_AXIS_X	= 1,
	STAGE_AXIS_Y	= 2,
	STAGE_AXIS_Z	= 4,
	STAGE_AXIS_T	= 8,
	STAGE_AXIS_R	= 16,
	STAGE_AXIS_B	= 32,
	STAGE_AXIS_ALL	= 63
    } 	StageAxisMask;

typedef /* [public] */ 
enum tagXTLibScanMode
    {	XTLIB_SCAN_NONE	= -1,
	XTLIB_SCAN_EXTERNAL	= 0,
	XTLIB_SCAN_FULLFRAME	= 1,
	XTLIB_SCAN_SPOT	= 2,
	XTLIB_SCAN_LINE	= 3
    } 	XTLibScanMode;

typedef /* [public] */ 
enum tagXTLibFilterMode
    {	XTLIB_LIVE	= 0,
	XTLIB_AVERAGE	= ( XTLIB_LIVE + 1 ) ,
	XTLIB_INTEGRATE	= ( XTLIB_AVERAGE + 1 ) 
    } 	XTLibFilterMode;

typedef /* [public] */ 
enum tagXTLibFilterFrames
    {	XTLIB_FRAMES_1	= 0,
	XTLIB_FRAMES_2	= ( XTLIB_FRAMES_1 + 1 ) ,
	XTLIB_FRAMES_4	= ( XTLIB_FRAMES_2 + 1 ) ,
	XTLIB_FRAMES_8	= ( XTLIB_FRAMES_4 + 1 ) ,
	XTLIB_FRAMES_16	= ( XTLIB_FRAMES_8 + 1 ) ,
	XTLIB_FRAMES_32	= ( XTLIB_FRAMES_16 + 1 ) ,
	XTLIB_FRAMES_64	= ( XTLIB_FRAMES_32 + 1 ) ,
	XTLIB_FRAMES_128	= ( XTLIB_FRAMES_64 + 1 ) ,
	XTLIB_FRAMES_256	= ( XTLIB_FRAMES_128 + 1 ) 
    } 	XTLibFilterFrames;

typedef /* [public] */ 
enum tagXTLibChannelState
    {	XTLIB_CHANNELSTATE_RUN	= 0,
	XTLIB_CHANNELSTATE_STOP	= ( XTLIB_CHANNELSTATE_RUN + 1 ) ,
	XTLIB_CHANNELSTATE_CANCEL	= ( XTLIB_CHANNELSTATE_STOP + 1 ) 
    } 	XTLibChannelState;

typedef /* [public] */ 
enum tagXTLibFileFormat
    {	XTLIB_TIF8	= 0,
	XTLIB_TIF16	= ( XTLIB_TIF8 + 1 ) ,
	XTLIB_BMP	= ( XTLIB_TIF16 + 1 ) ,
	XTLIB_JPG	= ( XTLIB_BMP + 1 ) 
    } 	XTLibFileFormat;

typedef /* [public] */ 
enum tagXTLibDisplaySize
    {	XTLIB_SMALL_SIZE	= 512,
	XTLIB_LARGE_SIZE	= 1024
    } 	XTLibDisplaySize;

typedef /* [public] */ 
enum tagXTLibAutoFunctionAction
    {	XTLIB_START	= 0,
	XTLIB_STOP	= ( XTLIB_START + 1 ) ,
	XTLIB_CANCEL	= ( XTLIB_STOP + 1 ) 
    } 	XTLibAutoFunctionAction;

typedef /* [public] */ 
enum tagXTLibActiveChannel
    {	XTLIB_CHANNEL_0	= 0,
	XTLIB_CHANNEL_1	= ( XTLIB_CHANNEL_0 + 1 ) ,
	XTLIB_CHANNEL_2	= ( XTLIB_CHANNEL_1 + 1 ) ,
	XTLIB_CHANNEL_CCD	= ( XTLIB_CHANNEL_2 + 1 ) ,
	XTLIB_CHANNEL_0_ELECTRON	= ( XTLIB_CHANNEL_CCD + 1 ) ,
	XTLIB_CHANNEL_1_ELECTRON	= ( XTLIB_CHANNEL_0_ELECTRON + 1 ) ,
	XTLIB_CHANNEL_2_ELECTRON	= ( XTLIB_CHANNEL_1_ELECTRON + 1 ) ,
	XTLIB_CHANNEL_3_ELECTRON	= ( XTLIB_CHANNEL_2_ELECTRON + 1 ) ,
	XTLIB_CHANNEL_0_ION	= ( XTLIB_CHANNEL_3_ELECTRON + 1 ) ,
	XTLIB_CHANNEL_1_ION	= ( XTLIB_CHANNEL_0_ION + 1 ) ,
	XTLIB_CHANNEL_2_ION	= ( XTLIB_CHANNEL_1_ION + 1 ) ,
	XTLIB_CHANNEL_3_ION	= ( XTLIB_CHANNEL_2_ION + 1 ) ,
	XTLIB_CHANNEL_0_OPTICAL	= ( XTLIB_CHANNEL_3_ION + 1 ) ,
	XTLIB_CHANNEL_1_OPTICAL	= ( XTLIB_CHANNEL_0_OPTICAL + 1 ) ,
	XTLIB_CHANNEL_2_OPTICAL	= ( XTLIB_CHANNEL_1_OPTICAL + 1 ) ,
	XTLIB_CHANNEL_3_OPTICAL	= ( XTLIB_CHANNEL_2_OPTICAL + 1 ) 
    } 	XTLibActiveChannel;

typedef /* [public] */ struct _XTLibImageInfo
    {
    long lWidth;
    long lHeight;
    int iBitsPerSample;
    int iBitShift;
    } 	XTLibImageInfo;

#endif


extern RPC_IF_HANDLE __MIDL_itf_xtlib2_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_xtlib2_0000_0000_v0_0_s_ifspec;


#ifndef __XTLIBLib_LIBRARY_DEFINED__
#define __XTLIBLib_LIBRARY_DEFINED__

/* library XTLIBLib */
/* [helpstring][version][uuid] */ 

#define	clcPressureActualValueChanged	( 1 )

#define	clcPressureTargetValueChanged	( 2 )

#define	clcModeActualValueChanged	( 3 )

#define	clcModeTargetValueChanged	( 4 )

#define	clcHTVoltageActualValueChanged	( 1 )

#define	clcHTVoltageTargetValueChanged	( 2 )

#define	clcHTOnOffActualValueChanged	( 3 )

#define	clcHTOnOffTargetValueChanged	( 4 )

#define	clcSpotSizeActualValueChanged	( 5 )

#define	clcSpotSizeTargetValueChanged	( 6 )

#define	clcFWDActualValueChanged	( 7 )

#define	clcFWDTargetValueChanged	( 8 )

#define	clcBeamBlankActualValueChanged	( 9 )

#define	clcBeamBlankTargetValueChanged	( 10 )

#define	clcStigmatorActualValueChanged	( 11 )

#define	clcStigmatorTargetValueChanged	( 12 )

#define	clcBeamShiftActualValueChanged	( 3 )

#define	clcBeamShiftTargetValueChanged	( 4 )

#define	clcStageActualPositionChanged	( 1 )

#define	clcStageLimitsChanged	( 2 )

#define	clcScanModeActualValueChanged	( 1 )

#define	clcScanModeTargetValueChanged	( 2 )

#define	clcDwellTimeActualValueChanged	( 3 )

#define	clcDwellTimeTargetValueChanged	( 4 )

#define	clcNrOfVertPixelsActualValueChanged	( 5 )

#define	clcNrOfVertPixelsTargetValueChanged	( 6 )

#define	clcNrOfHorPixelsActualValueChanged	( 7 )

#define	clcNrOfHorPixelsTargetValueChanged	( 8 )

#define	clcSpecimenTiltActualValueChanged	( 11 )

#define	clcSpecimenTiltTargetValueChanged	( 12 )

#define	clcScanFieldSizeActualValueChanged	( 13 )

#define	clcScanFieldSizeTargetValueChanged	( 14 )

#define	clcScanRotationActualValueChanged	( 15 )

#define	clcScanRotationTargetValueChanged	( 16 )

#define	clcSelectedAreaActualValueChanged	( 17 )

#define	clcSelectedAreaTargetValueChanged	( 18 )

#define	clcSelectedAreaStateActualValueChanged	( 19 )

#define	clcSelectedAreaStateTargetValueChanged	( 20 )

#define	clcSpotActualValueChanged	( 21 )

#define	clcSpotTargetValueChanged	( 22 )

#define	clcContrastActualValueChanged	( 1 )

#define	clcContrastTargetValueChanged	( 2 )

#define	clcBrightnessActualValueChanged	( 3 )

#define	clcBrightnessTargetValueChanged	( 4 )

#define	clcFilterModeActualValueChanged	( 5 )

#define	clcFilterModeTargetValueChanged	( 6 )

#define	clcFilterFramesActualValueChanged	( 7 )

#define	clcFilterFramesTargetValueChanged	( 8 )

#define	clcChannelStateActualValueChanged	( 9 )

#define	clcChannelStateTargetValueChanged	( 10 )

#define	clcVideoScopeStateActualValueChanged	( 11 )

#define	clcVideoScopeStateTargetValueChanged	( 12 )

#define	clcVideoScopeLineActualValueChanged	( 13 )

#define	clcVideoScopeLineTargetValueChanged	( 14 )

#define	clcVideoScopeDataValueChanged	( 15 )

#define	clcDisplayStateValueChanged	( 16 )

#define	clcDisplayPositionValueChanged	( 17 )

#define	clcAutoCBProgressChanged	( 18 )

#define	clcAutoCBExecutingChanged	( 19 )

#define	clcAutoFocusProgressChanged	( 20 )

#define	clcAutoFocusExecutingChanged	( 21 )

#define	clcCCDChannelStateActualValueChanged	( 1 )

#define	clcCCDChannelStateTargetValueChanged	( 2 )

#define	clcCCDDisplayStateValueChanged	( 3 )

#define	clcCCDDisplayPositionValueChanged	( 4 )

#define	clcActiveChannel	( 1 )

#define	clcZFWDCouplingValueChanged	( 1 )

#define	clcFWDFollowsZValueChanged	( 2 )

#define	clcEmissionCurrentValueChanged	( 3 )

#define	clcSourceBrokenValueChanged	( 4 )

#define	clcMoveCompletedChanged	( 1 )

#define	clcHomedChanged	( 2 )

typedef /* [public] */ 
enum tagLensMode
    {	LensModeUHR	= 1,
	LensModeHR	= 2,
	LensModeIntermediate	= 3,
	LensModeEDX	= 4,
	LensModeCathode	= 5,
	LensModeFIBI	= 6,
	LensModeStandard	= 7,
	LensModeAnalytical	= 8,
	LensModeFishEye	= 9
    } 	LensMode;

#define	clcLandingEnergyActualValueChanged	( 1 )

#define	clcLandingEnergyTargetValueChanged	( 2 )

#define	clcBeamDecelerationActualValueChanged	( 3 )

#define	clcBeamDecelerationTargetValueChanged	( 4 )

#define	clcStageBiasActualValueChanged	( 5 )

#define	clcStageBiasTargetValueChanged	( 6 )

#define	clcLensModeActualValueChanged	( 7 )

#define	clcLensModeTargetValueChanged	( 8 )

typedef /* [public] */ 
enum tagLevelingState
    {	LevelingStateOff	= 1,
	LevelingStateOn	= 2,
	LevelingStateQuiet	= 3,
	LevelingStateUnknown	= 4
    } 	LevelingState;

#define	clcLevelingActualValueChanged	( 1 )

#define	clcLevelingTargetValueChanged	( 2 )

#define	clcActiveApertureChanged	( 1 )


EXTERN_C const IID LIBID_XTLIBLib;

#ifndef __IVacSystemControl_INTERFACE_DEFINED__
#define __IVacSystemControl_INTERFACE_DEFINED__

/* interface IVacSystemControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IVacSystemControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8B506283-8A1D-11D4-A5EE-00B0D03B7B0E")
    IVacSystemControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pressure( 
            /* [retval][out] */ double *pdPressure) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Pressure( 
            /* [in] */ double dPressure) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PressureRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mode( 
            /* [retval][out] */ XTLibVacuumUserMode *pvarXTLibVacuumUserMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ XTLibVacuumUserState *pvarXTLibVacuumUserState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallMode( 
            /* [retval][out] */ long *pvarXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallMode( 
            /* [in] */ XTLibCallMode varXTLibCallMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVacSystemControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVacSystemControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVacSystemControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVacSystemControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVacSystemControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVacSystemControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVacSystemControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVacSystemControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pressure )( 
            IVacSystemControl * This,
            /* [retval][out] */ double *pdPressure);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pressure )( 
            IVacSystemControl * This,
            /* [in] */ double dPressure);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PressureRange )( 
            IVacSystemControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mode )( 
            IVacSystemControl * This,
            /* [retval][out] */ XTLibVacuumUserMode *pvarXTLibVacuumUserMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IVacSystemControl * This,
            /* [retval][out] */ XTLibVacuumUserState *pvarXTLibVacuumUserState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallMode )( 
            IVacSystemControl * This,
            /* [retval][out] */ long *pvarXTLibCallMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallMode )( 
            IVacSystemControl * This,
            /* [in] */ XTLibCallMode varXTLibCallMode);
        
        END_INTERFACE
    } IVacSystemControlVtbl;

    interface IVacSystemControl
    {
        CONST_VTBL struct IVacSystemControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVacSystemControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVacSystemControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVacSystemControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVacSystemControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVacSystemControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVacSystemControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVacSystemControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVacSystemControl_get_Pressure(This,pdPressure)	\
    ( (This)->lpVtbl -> get_Pressure(This,pdPressure) ) 

#define IVacSystemControl_put_Pressure(This,dPressure)	\
    ( (This)->lpVtbl -> put_Pressure(This,dPressure) ) 

#define IVacSystemControl_get_PressureRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_PressureRange(This,varRange,pdRangeValue) ) 

#define IVacSystemControl_get_Mode(This,pvarXTLibVacuumUserMode)	\
    ( (This)->lpVtbl -> get_Mode(This,pvarXTLibVacuumUserMode) ) 

#define IVacSystemControl_get_State(This,pvarXTLibVacuumUserState)	\
    ( (This)->lpVtbl -> get_State(This,pvarXTLibVacuumUserState) ) 

#define IVacSystemControl_get_CallMode(This,pvarXTLibCallMode)	\
    ( (This)->lpVtbl -> get_CallMode(This,pvarXTLibCallMode) ) 

#define IVacSystemControl_put_CallMode(This,varXTLibCallMode)	\
    ( (This)->lpVtbl -> put_CallMode(This,varXTLibCallMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVacSystemControl_INTERFACE_DEFINED__ */


#ifndef ___IVacSystemControlEvents_DISPINTERFACE_DEFINED__
#define ___IVacSystemControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IVacSystemControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IVacSystemControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8B506284-8A1D-11D4-A5EE-00B0D03B7B0E")
    _IVacSystemControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IVacSystemControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IVacSystemControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IVacSystemControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IVacSystemControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IVacSystemControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IVacSystemControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IVacSystemControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IVacSystemControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IVacSystemControlEventsVtbl;

    interface _IVacSystemControlEvents
    {
        CONST_VTBL struct _IVacSystemControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IVacSystemControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IVacSystemControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IVacSystemControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IVacSystemControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IVacSystemControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IVacSystemControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IVacSystemControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IVacSystemControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VacSystemControl;

#ifdef __cplusplus

class DECLSPEC_UUID("E6820A62-896F-11D4-A5ED-00B0D03B7B0E")
VacSystemControl;
#endif

#ifndef __IElectronBeamControl_INTERFACE_DEFINED__
#define __IElectronBeamControl_INTERFACE_DEFINED__

/* interface IElectronBeamControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IElectronBeamControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B34B3F3-8AD9-11D4-A5EF-00B0D03B7B0E")
    IElectronBeamControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HTState( 
            /* [retval][out] */ HTState *pvarHTState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HTOnOff( 
            /* [in] */ VARIANT_BOOL bHTOnOff) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HTIsOn( 
            /* [retval][out] */ VARIANT_BOOL *pbHTIsOn) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HTVoltage( 
            /* [in] */ double dHTVoltage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HTVoltage( 
            /* [retval][out] */ double *pdHTVoltage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HTVoltageRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FWD( 
            /* [in] */ double dFWD) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FWD( 
            /* [retval][out] */ double *pdFWD) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FWDRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdFWD) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpotSize( 
            /* [retval][out] */ double *pdSpotSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpotSize( 
            /* [in] */ double dSpotSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpotSizeRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BeamBlank( 
            /* [in] */ VARIANT_BOOL bBeamBlank) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BeamIsBlanked( 
            /* [retval][out] */ VARIANT_BOOL *pbBeamBlank) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStigmator( 
            /* [ref][out][in] */ double *pdValueX,
            /* [ref][out][in] */ double *pdValueY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStigmator( 
            /* [in] */ double dValueX,
            /* [in] */ double dValueY) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StigmatorXRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StigmatorYRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallMode( 
            /* [retval][out] */ long *pvarXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallMode( 
            /* [in] */ XTLibCallMode varXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeltaFWD( 
            /* [retval][out] */ double *pdDeltaFWD) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IElectronBeamControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IElectronBeamControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IElectronBeamControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IElectronBeamControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IElectronBeamControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IElectronBeamControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IElectronBeamControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IElectronBeamControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HTState )( 
            IElectronBeamControl * This,
            /* [retval][out] */ HTState *pvarHTState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HTOnOff )( 
            IElectronBeamControl * This,
            /* [in] */ VARIANT_BOOL bHTOnOff);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HTIsOn )( 
            IElectronBeamControl * This,
            /* [retval][out] */ VARIANT_BOOL *pbHTIsOn);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HTVoltage )( 
            IElectronBeamControl * This,
            /* [in] */ double dHTVoltage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HTVoltage )( 
            IElectronBeamControl * This,
            /* [retval][out] */ double *pdHTVoltage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HTVoltageRange )( 
            IElectronBeamControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FWD )( 
            IElectronBeamControl * This,
            /* [in] */ double dFWD);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FWD )( 
            IElectronBeamControl * This,
            /* [retval][out] */ double *pdFWD);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FWDRange )( 
            IElectronBeamControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdFWD);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpotSize )( 
            IElectronBeamControl * This,
            /* [retval][out] */ double *pdSpotSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpotSize )( 
            IElectronBeamControl * This,
            /* [in] */ double dSpotSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpotSizeRange )( 
            IElectronBeamControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BeamBlank )( 
            IElectronBeamControl * This,
            /* [in] */ VARIANT_BOOL bBeamBlank);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BeamIsBlanked )( 
            IElectronBeamControl * This,
            /* [retval][out] */ VARIANT_BOOL *pbBeamBlank);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStigmator )( 
            IElectronBeamControl * This,
            /* [ref][out][in] */ double *pdValueX,
            /* [ref][out][in] */ double *pdValueY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetStigmator )( 
            IElectronBeamControl * This,
            /* [in] */ double dValueX,
            /* [in] */ double dValueY);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StigmatorXRange )( 
            IElectronBeamControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StigmatorYRange )( 
            IElectronBeamControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallMode )( 
            IElectronBeamControl * This,
            /* [retval][out] */ long *pvarXTLibCallMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallMode )( 
            IElectronBeamControl * This,
            /* [in] */ XTLibCallMode varXTLibCallMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeltaFWD )( 
            IElectronBeamControl * This,
            /* [retval][out] */ double *pdDeltaFWD);
        
        END_INTERFACE
    } IElectronBeamControlVtbl;

    interface IElectronBeamControl
    {
        CONST_VTBL struct IElectronBeamControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IElectronBeamControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IElectronBeamControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IElectronBeamControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IElectronBeamControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IElectronBeamControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IElectronBeamControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IElectronBeamControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IElectronBeamControl_get_HTState(This,pvarHTState)	\
    ( (This)->lpVtbl -> get_HTState(This,pvarHTState) ) 

#define IElectronBeamControl_put_HTOnOff(This,bHTOnOff)	\
    ( (This)->lpVtbl -> put_HTOnOff(This,bHTOnOff) ) 

#define IElectronBeamControl_get_HTIsOn(This,pbHTIsOn)	\
    ( (This)->lpVtbl -> get_HTIsOn(This,pbHTIsOn) ) 

#define IElectronBeamControl_put_HTVoltage(This,dHTVoltage)	\
    ( (This)->lpVtbl -> put_HTVoltage(This,dHTVoltage) ) 

#define IElectronBeamControl_get_HTVoltage(This,pdHTVoltage)	\
    ( (This)->lpVtbl -> get_HTVoltage(This,pdHTVoltage) ) 

#define IElectronBeamControl_get_HTVoltageRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_HTVoltageRange(This,varRange,pdRangeValue) ) 

#define IElectronBeamControl_put_FWD(This,dFWD)	\
    ( (This)->lpVtbl -> put_FWD(This,dFWD) ) 

#define IElectronBeamControl_get_FWD(This,pdFWD)	\
    ( (This)->lpVtbl -> get_FWD(This,pdFWD) ) 

#define IElectronBeamControl_get_FWDRange(This,varRange,pdFWD)	\
    ( (This)->lpVtbl -> get_FWDRange(This,varRange,pdFWD) ) 

#define IElectronBeamControl_get_SpotSize(This,pdSpotSize)	\
    ( (This)->lpVtbl -> get_SpotSize(This,pdSpotSize) ) 

#define IElectronBeamControl_put_SpotSize(This,dSpotSize)	\
    ( (This)->lpVtbl -> put_SpotSize(This,dSpotSize) ) 

#define IElectronBeamControl_get_SpotSizeRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_SpotSizeRange(This,varRange,pdRangeValue) ) 

#define IElectronBeamControl_put_BeamBlank(This,bBeamBlank)	\
    ( (This)->lpVtbl -> put_BeamBlank(This,bBeamBlank) ) 

#define IElectronBeamControl_get_BeamIsBlanked(This,pbBeamBlank)	\
    ( (This)->lpVtbl -> get_BeamIsBlanked(This,pbBeamBlank) ) 

#define IElectronBeamControl_GetStigmator(This,pdValueX,pdValueY)	\
    ( (This)->lpVtbl -> GetStigmator(This,pdValueX,pdValueY) ) 

#define IElectronBeamControl_SetStigmator(This,dValueX,dValueY)	\
    ( (This)->lpVtbl -> SetStigmator(This,dValueX,dValueY) ) 

#define IElectronBeamControl_get_StigmatorXRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_StigmatorXRange(This,varRange,pdRangeValue) ) 

#define IElectronBeamControl_get_StigmatorYRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_StigmatorYRange(This,varRange,pdRangeValue) ) 

#define IElectronBeamControl_get_CallMode(This,pvarXTLibCallMode)	\
    ( (This)->lpVtbl -> get_CallMode(This,pvarXTLibCallMode) ) 

#define IElectronBeamControl_put_CallMode(This,varXTLibCallMode)	\
    ( (This)->lpVtbl -> put_CallMode(This,varXTLibCallMode) ) 

#define IElectronBeamControl_get_DeltaFWD(This,pdDeltaFWD)	\
    ( (This)->lpVtbl -> get_DeltaFWD(This,pdDeltaFWD) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IElectronBeamControl_INTERFACE_DEFINED__ */


#ifndef ___IElectronBeamControlEvents_DISPINTERFACE_DEFINED__
#define ___IElectronBeamControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IElectronBeamControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IElectronBeamControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7B34B3F5-8AD9-11D4-A5EF-00B0D03B7B0E")
    _IElectronBeamControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IElectronBeamControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IElectronBeamControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IElectronBeamControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IElectronBeamControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IElectronBeamControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IElectronBeamControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IElectronBeamControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IElectronBeamControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IElectronBeamControlEventsVtbl;

    interface _IElectronBeamControlEvents
    {
        CONST_VTBL struct _IElectronBeamControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IElectronBeamControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IElectronBeamControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IElectronBeamControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IElectronBeamControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IElectronBeamControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IElectronBeamControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IElectronBeamControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IElectronBeamControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ElectronBeamControl;

#ifdef __cplusplus

class DECLSPEC_UUID("7B34B3F4-8AD9-11D4-A5EF-00B0D03B7B0E")
ElectronBeamControl;
#endif

#ifndef __IBeamControl_INTERFACE_DEFINED__
#define __IBeamControl_INTERFACE_DEFINED__

/* interface IBeamControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IBeamControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B34B3E3-8AD9-11D4-A5EF-00B0D03B7B0E")
    IBeamControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ElectronBeamControl( 
            /* [retval][out] */ IElectronBeamControl **ppElectronBeamControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBeamShift( 
            /* [ref][out][in] */ double *pdShiftX,
            /* [ref][out][in] */ double *pdShiftY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBeamShift( 
            /* [in] */ double dShiftX,
            /* [in] */ double dShiftY) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BeamShiftXRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BeamShiftYRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallMode( 
            /* [retval][out] */ long *pvarXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallMode( 
            /* [in] */ XTLibCallMode varXTLibCallMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBeamControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBeamControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBeamControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBeamControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBeamControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBeamControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBeamControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBeamControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ElectronBeamControl )( 
            IBeamControl * This,
            /* [retval][out] */ IElectronBeamControl **ppElectronBeamControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBeamShift )( 
            IBeamControl * This,
            /* [ref][out][in] */ double *pdShiftX,
            /* [ref][out][in] */ double *pdShiftY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBeamShift )( 
            IBeamControl * This,
            /* [in] */ double dShiftX,
            /* [in] */ double dShiftY);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BeamShiftXRange )( 
            IBeamControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BeamShiftYRange )( 
            IBeamControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallMode )( 
            IBeamControl * This,
            /* [retval][out] */ long *pvarXTLibCallMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallMode )( 
            IBeamControl * This,
            /* [in] */ XTLibCallMode varXTLibCallMode);
        
        END_INTERFACE
    } IBeamControlVtbl;

    interface IBeamControl
    {
        CONST_VTBL struct IBeamControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBeamControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBeamControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBeamControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBeamControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBeamControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBeamControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBeamControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBeamControl_ElectronBeamControl(This,ppElectronBeamControl)	\
    ( (This)->lpVtbl -> ElectronBeamControl(This,ppElectronBeamControl) ) 

#define IBeamControl_GetBeamShift(This,pdShiftX,pdShiftY)	\
    ( (This)->lpVtbl -> GetBeamShift(This,pdShiftX,pdShiftY) ) 

#define IBeamControl_SetBeamShift(This,dShiftX,dShiftY)	\
    ( (This)->lpVtbl -> SetBeamShift(This,dShiftX,dShiftY) ) 

#define IBeamControl_get_BeamShiftXRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_BeamShiftXRange(This,varRange,pdRangeValue) ) 

#define IBeamControl_get_BeamShiftYRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_BeamShiftYRange(This,varRange,pdRangeValue) ) 

#define IBeamControl_get_CallMode(This,pvarXTLibCallMode)	\
    ( (This)->lpVtbl -> get_CallMode(This,pvarXTLibCallMode) ) 

#define IBeamControl_put_CallMode(This,varXTLibCallMode)	\
    ( (This)->lpVtbl -> put_CallMode(This,varXTLibCallMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBeamControl_INTERFACE_DEFINED__ */


#ifndef ___IBeamControlEvents_DISPINTERFACE_DEFINED__
#define ___IBeamControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IBeamControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IBeamControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7B34B3E5-8AD9-11D4-A5EF-00B0D03B7B0E")
    _IBeamControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IBeamControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IBeamControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IBeamControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IBeamControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IBeamControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IBeamControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IBeamControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IBeamControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IBeamControlEventsVtbl;

    interface _IBeamControlEvents
    {
        CONST_VTBL struct _IBeamControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IBeamControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IBeamControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IBeamControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IBeamControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IBeamControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IBeamControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IBeamControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IBeamControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BeamControl;

#ifdef __cplusplus

class DECLSPEC_UUID("7B34B3E4-8AD9-11D4-A5EF-00B0D03B7B0E")
BeamControl;
#endif

#ifndef __IStageControl_INTERFACE_DEFINED__
#define __IStageControl_INTERFACE_DEFINED__

/* interface IStageControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStageControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B34B3E6-8AD9-11D4-A5EF-00B0D03B7B0E")
    IStageControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [ref][out][in] */ double *pdXPos,
            /* [ref][out][in] */ double *pdYPos,
            /* [ref][out][in] */ double *pdZPos,
            /* [ref][out][in] */ double *pdTPos,
            /* [ref][out][in] */ double *pdRPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXPos,
            /* [in] */ double dYPos,
            /* [in] */ double dZPos,
            /* [in] */ double dTPos,
            /* [in] */ double dRPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveNoWait( 
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXPos,
            /* [in] */ double dYPos,
            /* [in] */ double dZPos,
            /* [in] */ double dTPos,
            /* [in] */ double dRPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveDelta( 
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXOffSet,
            /* [in] */ double dYOffSet,
            /* [in] */ double dZXOffSet,
            /* [in] */ double dTOffSet,
            /* [in] */ double dROffSet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveDeltaNoWait( 
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXOffSet,
            /* [in] */ double dYOffSet,
            /* [in] */ double dZOffSet,
            /* [in] */ double dTOffSet,
            /* [in] */ double dROffSet) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XPosRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_YPosRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ZPosRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TPosRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RPosRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopMovement( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsMoving( 
            /* [retval][out] */ VARIANT_BOOL *pbIsMoving) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StageType( 
            /* [retval][out] */ long *plStageType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartJogging( 
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXSpeed,
            /* [in] */ double dYSpeed,
            /* [in] */ double dZSpeed,
            /* [in] */ double dTSpeed,
            /* [in] */ double dRSpeed) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LockedAxis( 
            /* [retval][out] */ StageAxisMask *pvarLockedAxis) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LockedAxis( 
            /* [in] */ StageAxisMask varLockedAxis) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MotorizedAxis( 
            /* [retval][out] */ StageAxisMask *pvarMotorizedAxis) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Home( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HomeNoWait( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallMode( 
            /* [retval][out] */ long *pvarXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallMode( 
            /* [in] */ XTLibCallMode varXTLibCallMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStageControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStageControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStageControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStageControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStageControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStageControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStageControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStageControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPosition )( 
            IStageControl * This,
            /* [ref][out][in] */ double *pdXPos,
            /* [ref][out][in] */ double *pdYPos,
            /* [ref][out][in] */ double *pdZPos,
            /* [ref][out][in] */ double *pdTPos,
            /* [ref][out][in] */ double *pdRPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IStageControl * This,
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXPos,
            /* [in] */ double dYPos,
            /* [in] */ double dZPos,
            /* [in] */ double dTPos,
            /* [in] */ double dRPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveNoWait )( 
            IStageControl * This,
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXPos,
            /* [in] */ double dYPos,
            /* [in] */ double dZPos,
            /* [in] */ double dTPos,
            /* [in] */ double dRPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveDelta )( 
            IStageControl * This,
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXOffSet,
            /* [in] */ double dYOffSet,
            /* [in] */ double dZXOffSet,
            /* [in] */ double dTOffSet,
            /* [in] */ double dROffSet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveDeltaNoWait )( 
            IStageControl * This,
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXOffSet,
            /* [in] */ double dYOffSet,
            /* [in] */ double dZOffSet,
            /* [in] */ double dTOffSet,
            /* [in] */ double dROffSet);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XPosRange )( 
            IStageControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YPosRange )( 
            IStageControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ZPosRange )( 
            IStageControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TPosRange )( 
            IStageControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RPosRange )( 
            IStageControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopMovement )( 
            IStageControl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsMoving )( 
            IStageControl * This,
            /* [retval][out] */ VARIANT_BOOL *pbIsMoving);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StageType )( 
            IStageControl * This,
            /* [retval][out] */ long *plStageType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartJogging )( 
            IStageControl * This,
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ double dXSpeed,
            /* [in] */ double dYSpeed,
            /* [in] */ double dZSpeed,
            /* [in] */ double dTSpeed,
            /* [in] */ double dRSpeed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LockedAxis )( 
            IStageControl * This,
            /* [retval][out] */ StageAxisMask *pvarLockedAxis);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LockedAxis )( 
            IStageControl * This,
            /* [in] */ StageAxisMask varLockedAxis);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MotorizedAxis )( 
            IStageControl * This,
            /* [retval][out] */ StageAxisMask *pvarMotorizedAxis);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Home )( 
            IStageControl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HomeNoWait )( 
            IStageControl * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallMode )( 
            IStageControl * This,
            /* [retval][out] */ long *pvarXTLibCallMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallMode )( 
            IStageControl * This,
            /* [in] */ XTLibCallMode varXTLibCallMode);
        
        END_INTERFACE
    } IStageControlVtbl;

    interface IStageControl
    {
        CONST_VTBL struct IStageControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStageControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStageControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStageControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStageControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IStageControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IStageControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IStageControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IStageControl_GetPosition(This,pdXPos,pdYPos,pdZPos,pdTPos,pdRPos)	\
    ( (This)->lpVtbl -> GetPosition(This,pdXPos,pdYPos,pdZPos,pdTPos,pdRPos) ) 

#define IStageControl_Move(This,AxisMask,dXPos,dYPos,dZPos,dTPos,dRPos)	\
    ( (This)->lpVtbl -> Move(This,AxisMask,dXPos,dYPos,dZPos,dTPos,dRPos) ) 

#define IStageControl_MoveNoWait(This,AxisMask,dXPos,dYPos,dZPos,dTPos,dRPos)	\
    ( (This)->lpVtbl -> MoveNoWait(This,AxisMask,dXPos,dYPos,dZPos,dTPos,dRPos) ) 

#define IStageControl_MoveDelta(This,AxisMask,dXOffSet,dYOffSet,dZXOffSet,dTOffSet,dROffSet)	\
    ( (This)->lpVtbl -> MoveDelta(This,AxisMask,dXOffSet,dYOffSet,dZXOffSet,dTOffSet,dROffSet) ) 

#define IStageControl_MoveDeltaNoWait(This,AxisMask,dXOffSet,dYOffSet,dZOffSet,dTOffSet,dROffSet)	\
    ( (This)->lpVtbl -> MoveDeltaNoWait(This,AxisMask,dXOffSet,dYOffSet,dZOffSet,dTOffSet,dROffSet) ) 

#define IStageControl_get_XPosRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_XPosRange(This,varRange,pdRangeValue) ) 

#define IStageControl_get_YPosRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_YPosRange(This,varRange,pdRangeValue) ) 

#define IStageControl_get_ZPosRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_ZPosRange(This,varRange,pdRangeValue) ) 

#define IStageControl_get_TPosRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_TPosRange(This,varRange,pdRangeValue) ) 

#define IStageControl_get_RPosRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_RPosRange(This,varRange,pdRangeValue) ) 

#define IStageControl_StopMovement(This)	\
    ( (This)->lpVtbl -> StopMovement(This) ) 

#define IStageControl_IsMoving(This,pbIsMoving)	\
    ( (This)->lpVtbl -> IsMoving(This,pbIsMoving) ) 

#define IStageControl_StageType(This,plStageType)	\
    ( (This)->lpVtbl -> StageType(This,plStageType) ) 

#define IStageControl_StartJogging(This,AxisMask,dXSpeed,dYSpeed,dZSpeed,dTSpeed,dRSpeed)	\
    ( (This)->lpVtbl -> StartJogging(This,AxisMask,dXSpeed,dYSpeed,dZSpeed,dTSpeed,dRSpeed) ) 

#define IStageControl_get_LockedAxis(This,pvarLockedAxis)	\
    ( (This)->lpVtbl -> get_LockedAxis(This,pvarLockedAxis) ) 

#define IStageControl_put_LockedAxis(This,varLockedAxis)	\
    ( (This)->lpVtbl -> put_LockedAxis(This,varLockedAxis) ) 

#define IStageControl_get_MotorizedAxis(This,pvarMotorizedAxis)	\
    ( (This)->lpVtbl -> get_MotorizedAxis(This,pvarMotorizedAxis) ) 

#define IStageControl_Home(This)	\
    ( (This)->lpVtbl -> Home(This) ) 

#define IStageControl_HomeNoWait(This)	\
    ( (This)->lpVtbl -> HomeNoWait(This) ) 

#define IStageControl_get_CallMode(This,pvarXTLibCallMode)	\
    ( (This)->lpVtbl -> get_CallMode(This,pvarXTLibCallMode) ) 

#define IStageControl_put_CallMode(This,varXTLibCallMode)	\
    ( (This)->lpVtbl -> put_CallMode(This,varXTLibCallMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStageControl_INTERFACE_DEFINED__ */


#ifndef ___IStageControlEvents_DISPINTERFACE_DEFINED__
#define ___IStageControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IStageControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IStageControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7B34B3E8-8AD9-11D4-A5EF-00B0D03B7B0E")
    _IStageControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IStageControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IStageControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IStageControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IStageControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IStageControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IStageControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IStageControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IStageControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IStageControlEventsVtbl;

    interface _IStageControlEvents
    {
        CONST_VTBL struct _IStageControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IStageControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IStageControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IStageControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IStageControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IStageControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IStageControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IStageControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IStageControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_StageControl;

#ifdef __cplusplus

class DECLSPEC_UUID("7B34B3E7-8AD9-11D4-A5EF-00B0D03B7B0E")
StageControl;
#endif

#ifndef __IScanControl_INTERFACE_DEFINED__
#define __IScanControl_INTERFACE_DEFINED__

/* interface IScanControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IScanControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B34B3F0-8AD9-11D4-A5EF-00B0D03B7B0E")
    IScanControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScanMode( 
            /* [retval][out] */ XTLibScanMode *pvarScanMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScanMode( 
            /* [in] */ XTLibScanMode varScanMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DwellTime( 
            /* [retval][out] */ double *pdDwellTime) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DwellTime( 
            /* [in] */ double dDwellTime) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DwellTimeRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NrOfVertPixels( 
            /* [retval][out] */ long *plNrOfVertPixels) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NrOfVertPixels( 
            /* [in] */ long lNrOfVertPixels) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NrOfVertPixelsRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ long *plRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NrOfHorPixels( 
            /* [retval][out] */ long *plNrOfHorPixels) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NrOfHorPixels( 
            /* [in] */ long lNrOfHorPixels) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NrOfHorPixelsRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ long *plRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpecimenTilt( 
            /* [retval][out] */ double *pdSpecimenTilt) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpecimenTilt( 
            /* [in] */ double dSpecimenTilt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpecimenTiltRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *plRangeValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSelectedArea( 
            /* [out] */ long *plXStartPos,
            /* [out] */ long *plYStartPos,
            /* [out] */ long *plXSize,
            /* [out] */ long *plYSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSelectedArea( 
            /* [in] */ long lXStartPos,
            /* [in] */ long lYStartPos,
            /* [in] */ long lXSize,
            /* [in] */ long lYSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallMode( 
            /* [retval][out] */ long *pvarXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallMode( 
            /* [in] */ XTLibCallMode varXTLibCallMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetScanFieldSize( 
            /* [ref][out][in] */ double *pdSizeX,
            /* [ref][out][in] */ double *pdSizeY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetScanFieldSize( 
            /* [in] */ double dSizeX,
            /* [in] */ double dSizeY) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScanFieldXRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScanFieldYRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rotation( 
            /* [in] */ double dRotation) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rotation( 
            /* [retval][out] */ double *pdRotation) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RotationRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *plRangeValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SelectedAreaState( 
            /* [retval][out] */ VARIANT_BOOL *pbSAState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SelectedAreaState( 
            /* [in] */ VARIANT_BOOL bSAState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSpot( 
            /* [out] */ long *plXPos,
            /* [out] */ long *plYPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSpot( 
            /* [in] */ long lXPos,
            /* [in] */ long lYPos) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScanControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScanControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScanControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScanControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScanControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScanControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScanControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScanControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScanMode )( 
            IScanControl * This,
            /* [retval][out] */ XTLibScanMode *pvarScanMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ScanMode )( 
            IScanControl * This,
            /* [in] */ XTLibScanMode varScanMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DwellTime )( 
            IScanControl * This,
            /* [retval][out] */ double *pdDwellTime);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DwellTime )( 
            IScanControl * This,
            /* [in] */ double dDwellTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DwellTimeRange )( 
            IScanControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NrOfVertPixels )( 
            IScanControl * This,
            /* [retval][out] */ long *plNrOfVertPixels);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NrOfVertPixels )( 
            IScanControl * This,
            /* [in] */ long lNrOfVertPixels);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NrOfVertPixelsRange )( 
            IScanControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ long *plRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NrOfHorPixels )( 
            IScanControl * This,
            /* [retval][out] */ long *plNrOfHorPixels);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NrOfHorPixels )( 
            IScanControl * This,
            /* [in] */ long lNrOfHorPixels);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NrOfHorPixelsRange )( 
            IScanControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ long *plRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpecimenTilt )( 
            IScanControl * This,
            /* [retval][out] */ double *pdSpecimenTilt);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpecimenTilt )( 
            IScanControl * This,
            /* [in] */ double dSpecimenTilt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpecimenTiltRange )( 
            IScanControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *plRangeValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSelectedArea )( 
            IScanControl * This,
            /* [out] */ long *plXStartPos,
            /* [out] */ long *plYStartPos,
            /* [out] */ long *plXSize,
            /* [out] */ long *plYSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSelectedArea )( 
            IScanControl * This,
            /* [in] */ long lXStartPos,
            /* [in] */ long lYStartPos,
            /* [in] */ long lXSize,
            /* [in] */ long lYSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallMode )( 
            IScanControl * This,
            /* [retval][out] */ long *pvarXTLibCallMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallMode )( 
            IScanControl * This,
            /* [in] */ XTLibCallMode varXTLibCallMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetScanFieldSize )( 
            IScanControl * This,
            /* [ref][out][in] */ double *pdSizeX,
            /* [ref][out][in] */ double *pdSizeY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetScanFieldSize )( 
            IScanControl * This,
            /* [in] */ double dSizeX,
            /* [in] */ double dSizeY);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScanFieldXRange )( 
            IScanControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScanFieldYRange )( 
            IScanControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *pdRangeValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rotation )( 
            IScanControl * This,
            /* [in] */ double dRotation);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rotation )( 
            IScanControl * This,
            /* [retval][out] */ double *pdRotation);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RotationRange )( 
            IScanControl * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ double *plRangeValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SelectedAreaState )( 
            IScanControl * This,
            /* [retval][out] */ VARIANT_BOOL *pbSAState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SelectedAreaState )( 
            IScanControl * This,
            /* [in] */ VARIANT_BOOL bSAState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSpot )( 
            IScanControl * This,
            /* [out] */ long *plXPos,
            /* [out] */ long *plYPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSpot )( 
            IScanControl * This,
            /* [in] */ long lXPos,
            /* [in] */ long lYPos);
        
        END_INTERFACE
    } IScanControlVtbl;

    interface IScanControl
    {
        CONST_VTBL struct IScanControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScanControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScanControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScanControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScanControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScanControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScanControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScanControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScanControl_get_ScanMode(This,pvarScanMode)	\
    ( (This)->lpVtbl -> get_ScanMode(This,pvarScanMode) ) 

#define IScanControl_put_ScanMode(This,varScanMode)	\
    ( (This)->lpVtbl -> put_ScanMode(This,varScanMode) ) 

#define IScanControl_get_DwellTime(This,pdDwellTime)	\
    ( (This)->lpVtbl -> get_DwellTime(This,pdDwellTime) ) 

#define IScanControl_put_DwellTime(This,dDwellTime)	\
    ( (This)->lpVtbl -> put_DwellTime(This,dDwellTime) ) 

#define IScanControl_get_DwellTimeRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_DwellTimeRange(This,varRange,pdRangeValue) ) 

#define IScanControl_get_NrOfVertPixels(This,plNrOfVertPixels)	\
    ( (This)->lpVtbl -> get_NrOfVertPixels(This,plNrOfVertPixels) ) 

#define IScanControl_put_NrOfVertPixels(This,lNrOfVertPixels)	\
    ( (This)->lpVtbl -> put_NrOfVertPixels(This,lNrOfVertPixels) ) 

#define IScanControl_get_NrOfVertPixelsRange(This,varRange,plRangeValue)	\
    ( (This)->lpVtbl -> get_NrOfVertPixelsRange(This,varRange,plRangeValue) ) 

#define IScanControl_get_NrOfHorPixels(This,plNrOfHorPixels)	\
    ( (This)->lpVtbl -> get_NrOfHorPixels(This,plNrOfHorPixels) ) 

#define IScanControl_put_NrOfHorPixels(This,lNrOfHorPixels)	\
    ( (This)->lpVtbl -> put_NrOfHorPixels(This,lNrOfHorPixels) ) 

#define IScanControl_get_NrOfHorPixelsRange(This,varRange,plRangeValue)	\
    ( (This)->lpVtbl -> get_NrOfHorPixelsRange(This,varRange,plRangeValue) ) 

#define IScanControl_get_SpecimenTilt(This,pdSpecimenTilt)	\
    ( (This)->lpVtbl -> get_SpecimenTilt(This,pdSpecimenTilt) ) 

#define IScanControl_put_SpecimenTilt(This,dSpecimenTilt)	\
    ( (This)->lpVtbl -> put_SpecimenTilt(This,dSpecimenTilt) ) 

#define IScanControl_get_SpecimenTiltRange(This,varRange,plRangeValue)	\
    ( (This)->lpVtbl -> get_SpecimenTiltRange(This,varRange,plRangeValue) ) 

#define IScanControl_GetSelectedArea(This,plXStartPos,plYStartPos,plXSize,plYSize)	\
    ( (This)->lpVtbl -> GetSelectedArea(This,plXStartPos,plYStartPos,plXSize,plYSize) ) 

#define IScanControl_SetSelectedArea(This,lXStartPos,lYStartPos,lXSize,lYSize)	\
    ( (This)->lpVtbl -> SetSelectedArea(This,lXStartPos,lYStartPos,lXSize,lYSize) ) 

#define IScanControl_get_CallMode(This,pvarXTLibCallMode)	\
    ( (This)->lpVtbl -> get_CallMode(This,pvarXTLibCallMode) ) 

#define IScanControl_put_CallMode(This,varXTLibCallMode)	\
    ( (This)->lpVtbl -> put_CallMode(This,varXTLibCallMode) ) 

#define IScanControl_GetScanFieldSize(This,pdSizeX,pdSizeY)	\
    ( (This)->lpVtbl -> GetScanFieldSize(This,pdSizeX,pdSizeY) ) 

#define IScanControl_SetScanFieldSize(This,dSizeX,dSizeY)	\
    ( (This)->lpVtbl -> SetScanFieldSize(This,dSizeX,dSizeY) ) 

#define IScanControl_get_ScanFieldXRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_ScanFieldXRange(This,varRange,pdRangeValue) ) 

#define IScanControl_get_ScanFieldYRange(This,varRange,pdRangeValue)	\
    ( (This)->lpVtbl -> get_ScanFieldYRange(This,varRange,pdRangeValue) ) 

#define IScanControl_put_Rotation(This,dRotation)	\
    ( (This)->lpVtbl -> put_Rotation(This,dRotation) ) 

#define IScanControl_get_Rotation(This,pdRotation)	\
    ( (This)->lpVtbl -> get_Rotation(This,pdRotation) ) 

#define IScanControl_get_RotationRange(This,varRange,plRangeValue)	\
    ( (This)->lpVtbl -> get_RotationRange(This,varRange,plRangeValue) ) 

#define IScanControl_get_SelectedAreaState(This,pbSAState)	\
    ( (This)->lpVtbl -> get_SelectedAreaState(This,pbSAState) ) 

#define IScanControl_put_SelectedAreaState(This,bSAState)	\
    ( (This)->lpVtbl -> put_SelectedAreaState(This,bSAState) ) 

#define IScanControl_GetSpot(This,plXPos,plYPos)	\
    ( (This)->lpVtbl -> GetSpot(This,plXPos,plYPos) ) 

#define IScanControl_SetSpot(This,lXPos,lYPos)	\
    ( (This)->lpVtbl -> SetSpot(This,lXPos,lYPos) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScanControl_INTERFACE_DEFINED__ */


#ifndef ___IScanControlEvents_DISPINTERFACE_DEFINED__
#define ___IScanControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IScanControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IScanControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7B34B3F2-8AD9-11D4-A5EF-00B0D03B7B0E")
    _IScanControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IScanControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IScanControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IScanControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IScanControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IScanControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IScanControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IScanControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IScanControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IScanControlEventsVtbl;

    interface _IScanControlEvents
    {
        CONST_VTBL struct _IScanControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IScanControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IScanControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IScanControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IScanControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IScanControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IScanControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IScanControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IScanControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ScanControl;

#ifdef __cplusplus

class DECLSPEC_UUID("7B34B3F1-8AD9-11D4-A5EF-00B0D03B7B0E")
ScanControl;
#endif

#ifndef __IDetectorGroup_INTERFACE_DEFINED__
#define __IDetectorGroup_INTERFACE_DEFINED__

/* interface IDetectorGroup */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDetectorGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4A538350-9475-11D4-A5F8-00B0D03B7B0E")
    IDetectorGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DetectorList( 
            /* [retval][out] */ VARIANT *pvarDetectorList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveDetector( 
            /* [retval][out] */ BSTR *pbstrActiveDetector) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActiveDetector( 
            /* [in] */ BSTR bstrActiveDetector) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDetectorGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDetectorGroup * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDetectorGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDetectorGroup * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDetectorGroup * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDetectorGroup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDetectorGroup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDetectorGroup * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IDetectorGroup * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DetectorList )( 
            IDetectorGroup * This,
            /* [retval][out] */ VARIANT *pvarDetectorList);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDetector )( 
            IDetectorGroup * This,
            /* [retval][out] */ BSTR *pbstrActiveDetector);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveDetector )( 
            IDetectorGroup * This,
            /* [in] */ BSTR bstrActiveDetector);
        
        END_INTERFACE
    } IDetectorGroupVtbl;

    interface IDetectorGroup
    {
        CONST_VTBL struct IDetectorGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDetectorGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDetectorGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDetectorGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDetectorGroup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDetectorGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDetectorGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDetectorGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDetectorGroup_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IDetectorGroup_get_DetectorList(This,pvarDetectorList)	\
    ( (This)->lpVtbl -> get_DetectorList(This,pvarDetectorList) ) 

#define IDetectorGroup_get_ActiveDetector(This,pbstrActiveDetector)	\
    ( (This)->lpVtbl -> get_ActiveDetector(This,pbstrActiveDetector) ) 

#define IDetectorGroup_put_ActiveDetector(This,bstrActiveDetector)	\
    ( (This)->lpVtbl -> put_ActiveDetector(This,bstrActiveDetector) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDetectorGroup_INTERFACE_DEFINED__ */


#ifndef ___IDetectorGroupEvents_DISPINTERFACE_DEFINED__
#define ___IDetectorGroupEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDetectorGroupEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDetectorGroupEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4A538352-9475-11D4-A5F8-00B0D03B7B0E")
    _IDetectorGroupEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDetectorGroupEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDetectorGroupEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDetectorGroupEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDetectorGroupEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDetectorGroupEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDetectorGroupEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDetectorGroupEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDetectorGroupEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDetectorGroupEventsVtbl;

    interface _IDetectorGroupEvents
    {
        CONST_VTBL struct _IDetectorGroupEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDetectorGroupEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDetectorGroupEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDetectorGroupEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDetectorGroupEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDetectorGroupEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDetectorGroupEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDetectorGroupEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDetectorGroupEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DetectorGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("4A538351-9475-11D4-A5F8-00B0D03B7B0E")
DetectorGroup;
#endif

#ifndef __IDetectorGroups_INTERFACE_DEFINED__
#define __IDetectorGroups_INTERFACE_DEFINED__

/* interface IDetectorGroups */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDetectorGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FF084690-945C-11D4-A5F8-00B0D03B7B0E")
    IDetectorGroups : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppDetectorGroup) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varName,
            /* [retval][out] */ IDetectorGroup **pDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *lCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDetectorGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDetectorGroups * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDetectorGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDetectorGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDetectorGroups * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDetectorGroups * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDetectorGroups * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDetectorGroups * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IDetectorGroups * This,
            /* [retval][out] */ IUnknown **ppDetectorGroup);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IDetectorGroups * This,
            /* [in] */ VARIANT varName,
            /* [retval][out] */ IDetectorGroup **pDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            IDetectorGroups * This,
            /* [retval][out] */ long *lCount);
        
        END_INTERFACE
    } IDetectorGroupsVtbl;

    interface IDetectorGroups
    {
        CONST_VTBL struct IDetectorGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDetectorGroups_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDetectorGroups_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDetectorGroups_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDetectorGroups_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDetectorGroups_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDetectorGroups_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDetectorGroups_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDetectorGroups_get__NewEnum(This,ppDetectorGroup)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppDetectorGroup) ) 

#define IDetectorGroups_get_Item(This,varName,pDisp)	\
    ( (This)->lpVtbl -> get_Item(This,varName,pDisp) ) 

#define IDetectorGroups_Count(This,lCount)	\
    ( (This)->lpVtbl -> Count(This,lCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDetectorGroups_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DetectorGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("FF084691-945C-11D4-A5F8-00B0D03B7B0E")
DetectorGroups;
#endif

#ifndef __IChannel_INTERFACE_DEFINED__
#define __IChannel_INTERFACE_DEFINED__

/* interface IChannel */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60A2DBC0-CCE5-11D4-A641-00B0D03B7B0E")
    IChannel : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Contrast( 
            /* [retval][out] */ double *pdContrast) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Contrast( 
            /* [in] */ double dContrast) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Brightness( 
            /* [retval][out] */ double *pdBrightness) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Brightness( 
            /* [in] */ double dBrightness) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilterMode( 
            /* [retval][out] */ XTLibFilterMode *pvarXTLibFilterMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FilterMode( 
            /* [in] */ XTLibFilterMode varXTLibFilterMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilterFrames( 
            /* [retval][out] */ XTLibFilterFrames *pvarXTLibFilterFrames) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FilterFrames( 
            /* [in] */ XTLibFilterFrames varXTLibFrames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveImage( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ XTLibFileFormat varFileFormat,
            long lDatabarHeight,
            BYTE *pbDatabarData,
            BSTR bstrUserText) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoScopeState( 
            /* [retval][out] */ VARIANT_BOOL *pbState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoScopeState( 
            /* [in] */ VARIANT_BOOL bState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoScopeLine( 
            /* [retval][out] */ long *plLineNumber) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoScopeLine( 
            /* [in] */ long lLineNumber) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoScopeData( 
            /* [retval][out] */ VARIANT *pData) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoScopeLineRange( 
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ long *plRangeValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDisplayPosition( 
            /* [ref][out][in] */ long *plXStartPos,
            /* [ref][out][in] */ long *plYStartPos,
            /* [ref][out][in] */ long *plWidth,
            /* [ref][out][in] */ long *plHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDisplayPosition( 
            /* [in] */ long lXStartPos,
            /* [in] */ long lYStartPos,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayState( 
            /* [retval][out] */ VARIANT_BOOL *pbState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayState( 
            /* [in] */ VARIANT_BOOL bState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChannelState( 
            /* [retval][out] */ XTLibChannelState *pvarXTLibChannelState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ChannelState( 
            /* [in] */ XTLibChannelState varXTLibChannelState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoFocus( 
            /* [in] */ XTLibAutoFunctionAction varXTLibAutoFocusAction) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoFocusState( 
            /* [retval][out] */ VARIANT_BOOL *pbState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoCB( 
            /* [in] */ XTLibAutoFunctionAction varXTLibAutoCBAction) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoCBState( 
            /* [retval][out] */ VARIANT_BOOL *pbState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DetectorGroup( 
            IDetectorGroup *pIDetector) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageInfo( 
            /* [retval][out] */ XTLibImageInfo *pvarXTLibImageInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImage( 
            /* [in] */ long lNumberOfBytes,
            /* [size_is][out] */ BYTE *pbImageData) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SelectedDetectorGroups( 
            /* [retval][out] */ VARIANT *pvarGroupNames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TiffPrivateData( 
            /* [in] */ BSTR bstrUserText,
            /* [retval][out] */ BSTR *pbstrPrivateData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChannelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChannel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChannel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChannel * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IChannel * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IChannel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IChannel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IChannel * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Contrast )( 
            IChannel * This,
            /* [retval][out] */ double *pdContrast);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Contrast )( 
            IChannel * This,
            /* [in] */ double dContrast);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            IChannel * This,
            /* [retval][out] */ double *pdBrightness);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            IChannel * This,
            /* [in] */ double dBrightness);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilterMode )( 
            IChannel * This,
            /* [retval][out] */ XTLibFilterMode *pvarXTLibFilterMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FilterMode )( 
            IChannel * This,
            /* [in] */ XTLibFilterMode varXTLibFilterMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilterFrames )( 
            IChannel * This,
            /* [retval][out] */ XTLibFilterFrames *pvarXTLibFilterFrames);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FilterFrames )( 
            IChannel * This,
            /* [in] */ XTLibFilterFrames varXTLibFrames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveImage )( 
            IChannel * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ XTLibFileFormat varFileFormat,
            long lDatabarHeight,
            BYTE *pbDatabarData,
            BSTR bstrUserText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoScopeState )( 
            IChannel * This,
            /* [retval][out] */ VARIANT_BOOL *pbState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoScopeState )( 
            IChannel * This,
            /* [in] */ VARIANT_BOOL bState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoScopeLine )( 
            IChannel * This,
            /* [retval][out] */ long *plLineNumber);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoScopeLine )( 
            IChannel * This,
            /* [in] */ long lLineNumber);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoScopeData )( 
            IChannel * This,
            /* [retval][out] */ VARIANT *pData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoScopeLineRange )( 
            IChannel * This,
            /* [in] */ XTLibRange varRange,
            /* [retval][out] */ long *plRangeValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDisplayPosition )( 
            IChannel * This,
            /* [ref][out][in] */ long *plXStartPos,
            /* [ref][out][in] */ long *plYStartPos,
            /* [ref][out][in] */ long *plWidth,
            /* [ref][out][in] */ long *plHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDisplayPosition )( 
            IChannel * This,
            /* [in] */ long lXStartPos,
            /* [in] */ long lYStartPos,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayState )( 
            IChannel * This,
            /* [retval][out] */ VARIANT_BOOL *pbState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayState )( 
            IChannel * This,
            /* [in] */ VARIANT_BOOL bState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelState )( 
            IChannel * This,
            /* [retval][out] */ XTLibChannelState *pvarXTLibChannelState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChannelState )( 
            IChannel * This,
            /* [in] */ XTLibChannelState varXTLibChannelState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoFocus )( 
            IChannel * This,
            /* [in] */ XTLibAutoFunctionAction varXTLibAutoFocusAction);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoFocusState )( 
            IChannel * This,
            /* [retval][out] */ VARIANT_BOOL *pbState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoCB )( 
            IChannel * This,
            /* [in] */ XTLibAutoFunctionAction varXTLibAutoCBAction);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoCBState )( 
            IChannel * This,
            /* [retval][out] */ VARIANT_BOOL *pbState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DetectorGroup )( 
            IChannel * This,
            IDetectorGroup *pIDetector);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageInfo )( 
            IChannel * This,
            /* [retval][out] */ XTLibImageInfo *pvarXTLibImageInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            IChannel * This,
            /* [in] */ long lNumberOfBytes,
            /* [size_is][out] */ BYTE *pbImageData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SelectedDetectorGroups )( 
            IChannel * This,
            /* [retval][out] */ VARIANT *pvarGroupNames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TiffPrivateData )( 
            IChannel * This,
            /* [in] */ BSTR bstrUserText,
            /* [retval][out] */ BSTR *pbstrPrivateData);
        
        END_INTERFACE
    } IChannelVtbl;

    interface IChannel
    {
        CONST_VTBL struct IChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChannel_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IChannel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IChannel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IChannel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IChannel_get_Contrast(This,pdContrast)	\
    ( (This)->lpVtbl -> get_Contrast(This,pdContrast) ) 

#define IChannel_put_Contrast(This,dContrast)	\
    ( (This)->lpVtbl -> put_Contrast(This,dContrast) ) 

#define IChannel_get_Brightness(This,pdBrightness)	\
    ( (This)->lpVtbl -> get_Brightness(This,pdBrightness) ) 

#define IChannel_put_Brightness(This,dBrightness)	\
    ( (This)->lpVtbl -> put_Brightness(This,dBrightness) ) 

#define IChannel_get_FilterMode(This,pvarXTLibFilterMode)	\
    ( (This)->lpVtbl -> get_FilterMode(This,pvarXTLibFilterMode) ) 

#define IChannel_put_FilterMode(This,varXTLibFilterMode)	\
    ( (This)->lpVtbl -> put_FilterMode(This,varXTLibFilterMode) ) 

#define IChannel_get_FilterFrames(This,pvarXTLibFilterFrames)	\
    ( (This)->lpVtbl -> get_FilterFrames(This,pvarXTLibFilterFrames) ) 

#define IChannel_put_FilterFrames(This,varXTLibFrames)	\
    ( (This)->lpVtbl -> put_FilterFrames(This,varXTLibFrames) ) 

#define IChannel_SaveImage(This,bstrFileName,varFileFormat,lDatabarHeight,pbDatabarData,bstrUserText)	\
    ( (This)->lpVtbl -> SaveImage(This,bstrFileName,varFileFormat,lDatabarHeight,pbDatabarData,bstrUserText) ) 

#define IChannel_get_VideoScopeState(This,pbState)	\
    ( (This)->lpVtbl -> get_VideoScopeState(This,pbState) ) 

#define IChannel_put_VideoScopeState(This,bState)	\
    ( (This)->lpVtbl -> put_VideoScopeState(This,bState) ) 

#define IChannel_get_VideoScopeLine(This,plLineNumber)	\
    ( (This)->lpVtbl -> get_VideoScopeLine(This,plLineNumber) ) 

#define IChannel_put_VideoScopeLine(This,lLineNumber)	\
    ( (This)->lpVtbl -> put_VideoScopeLine(This,lLineNumber) ) 

#define IChannel_get_VideoScopeData(This,pData)	\
    ( (This)->lpVtbl -> get_VideoScopeData(This,pData) ) 

#define IChannel_get_VideoScopeLineRange(This,varRange,plRangeValue)	\
    ( (This)->lpVtbl -> get_VideoScopeLineRange(This,varRange,plRangeValue) ) 

#define IChannel_GetDisplayPosition(This,plXStartPos,plYStartPos,plWidth,plHeight)	\
    ( (This)->lpVtbl -> GetDisplayPosition(This,plXStartPos,plYStartPos,plWidth,plHeight) ) 

#define IChannel_SetDisplayPosition(This,lXStartPos,lYStartPos,lWidth,lHeight)	\
    ( (This)->lpVtbl -> SetDisplayPosition(This,lXStartPos,lYStartPos,lWidth,lHeight) ) 

#define IChannel_get_DisplayState(This,pbState)	\
    ( (This)->lpVtbl -> get_DisplayState(This,pbState) ) 

#define IChannel_put_DisplayState(This,bState)	\
    ( (This)->lpVtbl -> put_DisplayState(This,bState) ) 

#define IChannel_get_ChannelState(This,pvarXTLibChannelState)	\
    ( (This)->lpVtbl -> get_ChannelState(This,pvarXTLibChannelState) ) 

#define IChannel_put_ChannelState(This,varXTLibChannelState)	\
    ( (This)->lpVtbl -> put_ChannelState(This,varXTLibChannelState) ) 

#define IChannel_put_AutoFocus(This,varXTLibAutoFocusAction)	\
    ( (This)->lpVtbl -> put_AutoFocus(This,varXTLibAutoFocusAction) ) 

#define IChannel_get_AutoFocusState(This,pbState)	\
    ( (This)->lpVtbl -> get_AutoFocusState(This,pbState) ) 

#define IChannel_put_AutoCB(This,varXTLibAutoCBAction)	\
    ( (This)->lpVtbl -> put_AutoCB(This,varXTLibAutoCBAction) ) 

#define IChannel_get_AutoCBState(This,pbState)	\
    ( (This)->lpVtbl -> get_AutoCBState(This,pbState) ) 

#define IChannel_put_DetectorGroup(This,pIDetector)	\
    ( (This)->lpVtbl -> put_DetectorGroup(This,pIDetector) ) 

#define IChannel_get_ImageInfo(This,pvarXTLibImageInfo)	\
    ( (This)->lpVtbl -> get_ImageInfo(This,pvarXTLibImageInfo) ) 

#define IChannel_GetImage(This,lNumberOfBytes,pbImageData)	\
    ( (This)->lpVtbl -> GetImage(This,lNumberOfBytes,pbImageData) ) 

#define IChannel_get_SelectedDetectorGroups(This,pvarGroupNames)	\
    ( (This)->lpVtbl -> get_SelectedDetectorGroups(This,pvarGroupNames) ) 

#define IChannel_get_TiffPrivateData(This,bstrUserText,pbstrPrivateData)	\
    ( (This)->lpVtbl -> get_TiffPrivateData(This,bstrUserText,pbstrPrivateData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChannel_INTERFACE_DEFINED__ */


#ifndef ___IChannelEvents_DISPINTERFACE_DEFINED__
#define ___IChannelEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IChannelEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IChannelEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("60A2DBC2-CCE5-11D4-A641-00B0D03B7B0E")
    _IChannelEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IChannelEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IChannelEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IChannelEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IChannelEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IChannelEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IChannelEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IChannelEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IChannelEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IChannelEventsVtbl;

    interface _IChannelEvents
    {
        CONST_VTBL struct _IChannelEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IChannelEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IChannelEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IChannelEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IChannelEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IChannelEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IChannelEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IChannelEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IChannelEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Channel;

#ifdef __cplusplus

class DECLSPEC_UUID("60A2DBC1-CCE5-11D4-A641-00B0D03B7B0E")
Channel;
#endif

#ifndef __ICCDChannel_INTERFACE_DEFINED__
#define __ICCDChannel_INTERFACE_DEFINED__

/* interface ICCDChannel */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICCDChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2939A928-3F97-4d8a-82E1-61A618C83581")
    ICCDChannel : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveImage( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ XTLibFileFormat varFileFormat,
            long lDatabarHeight,
            BYTE *pbDatabarData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDisplayPosition( 
            /* [ref][out][in] */ long *plXStartPos,
            /* [ref][out][in] */ long *plYStartPos,
            /* [ref][out][in] */ long *plWidth,
            /* [ref][out][in] */ long *plHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDisplayPosition( 
            /* [in] */ long lXStartPos,
            /* [in] */ long lYStartPos,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayState( 
            /* [retval][out] */ VARIANT_BOOL *pbState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayState( 
            /* [in] */ VARIANT_BOOL bState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChannelState( 
            /* [retval][out] */ XTLibChannelState *pvarXTLibChannelState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ChannelState( 
            /* [in] */ XTLibChannelState varXTLibChannelState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageInfo( 
            /* [retval][out] */ XTLibImageInfo *pvarXTLibImageInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImage( 
            /* [in] */ long lNumberOfBytes,
            /* [size_is][out] */ BYTE *pbImageData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICCDChannelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICCDChannel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICCDChannel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICCDChannel * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICCDChannel * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICCDChannel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICCDChannel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICCDChannel * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveImage )( 
            ICCDChannel * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ XTLibFileFormat varFileFormat,
            long lDatabarHeight,
            BYTE *pbDatabarData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDisplayPosition )( 
            ICCDChannel * This,
            /* [ref][out][in] */ long *plXStartPos,
            /* [ref][out][in] */ long *plYStartPos,
            /* [ref][out][in] */ long *plWidth,
            /* [ref][out][in] */ long *plHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDisplayPosition )( 
            ICCDChannel * This,
            /* [in] */ long lXStartPos,
            /* [in] */ long lYStartPos,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayState )( 
            ICCDChannel * This,
            /* [retval][out] */ VARIANT_BOOL *pbState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayState )( 
            ICCDChannel * This,
            /* [in] */ VARIANT_BOOL bState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelState )( 
            ICCDChannel * This,
            /* [retval][out] */ XTLibChannelState *pvarXTLibChannelState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChannelState )( 
            ICCDChannel * This,
            /* [in] */ XTLibChannelState varXTLibChannelState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageInfo )( 
            ICCDChannel * This,
            /* [retval][out] */ XTLibImageInfo *pvarXTLibImageInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            ICCDChannel * This,
            /* [in] */ long lNumberOfBytes,
            /* [size_is][out] */ BYTE *pbImageData);
        
        END_INTERFACE
    } ICCDChannelVtbl;

    interface ICCDChannel
    {
        CONST_VTBL struct ICCDChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICCDChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICCDChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICCDChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICCDChannel_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICCDChannel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICCDChannel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICCDChannel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICCDChannel_SaveImage(This,bstrFileName,varFileFormat,lDatabarHeight,pbDatabarData)	\
    ( (This)->lpVtbl -> SaveImage(This,bstrFileName,varFileFormat,lDatabarHeight,pbDatabarData) ) 

#define ICCDChannel_GetDisplayPosition(This,plXStartPos,plYStartPos,plWidth,plHeight)	\
    ( (This)->lpVtbl -> GetDisplayPosition(This,plXStartPos,plYStartPos,plWidth,plHeight) ) 

#define ICCDChannel_SetDisplayPosition(This,lXStartPos,lYStartPos,lWidth,lHeight)	\
    ( (This)->lpVtbl -> SetDisplayPosition(This,lXStartPos,lYStartPos,lWidth,lHeight) ) 

#define ICCDChannel_get_DisplayState(This,pbState)	\
    ( (This)->lpVtbl -> get_DisplayState(This,pbState) ) 

#define ICCDChannel_put_DisplayState(This,bState)	\
    ( (This)->lpVtbl -> put_DisplayState(This,bState) ) 

#define ICCDChannel_get_ChannelState(This,pvarXTLibChannelState)	\
    ( (This)->lpVtbl -> get_ChannelState(This,pvarXTLibChannelState) ) 

#define ICCDChannel_put_ChannelState(This,varXTLibChannelState)	\
    ( (This)->lpVtbl -> put_ChannelState(This,varXTLibChannelState) ) 

#define ICCDChannel_get_ImageInfo(This,pvarXTLibImageInfo)	\
    ( (This)->lpVtbl -> get_ImageInfo(This,pvarXTLibImageInfo) ) 

#define ICCDChannel_GetImage(This,lNumberOfBytes,pbImageData)	\
    ( (This)->lpVtbl -> GetImage(This,lNumberOfBytes,pbImageData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICCDChannel_INTERFACE_DEFINED__ */


#ifndef ___ICCDChannelEvents_DISPINTERFACE_DEFINED__
#define ___ICCDChannelEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICCDChannelEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ICCDChannelEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9F9185D9-12F1-4c8a-81CB-3455F27B5AEF")
    _ICCDChannelEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICCDChannelEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ICCDChannelEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ICCDChannelEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ICCDChannelEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ICCDChannelEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ICCDChannelEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ICCDChannelEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ICCDChannelEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ICCDChannelEventsVtbl;

    interface _ICCDChannelEvents
    {
        CONST_VTBL struct _ICCDChannelEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICCDChannelEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ICCDChannelEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ICCDChannelEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ICCDChannelEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ICCDChannelEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ICCDChannelEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ICCDChannelEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICCDChannelEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CCDChannel;

#ifdef __cplusplus

class DECLSPEC_UUID("14C1FCD3-1AA6-45e0-A7F8-0FB48A158847")
CCDChannel;
#endif

#ifndef __IChannels_INTERFACE_DEFINED__
#define __IChannels_INTERFACE_DEFINED__

/* interface IChannels */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IChannels;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D8F99D0-CC5B-11D4-A640-00B0D03B7B0E")
    IChannels : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppChannel) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varName,
            /* [retval][out] */ IChannel **pDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *lCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveChannel( 
            /* [retval][out] */ XTLibActiveChannel *pvarXTLibActiveChannel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CCDChannel( 
            /* [retval][out] */ ICCDChannel **ppChannel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChannelsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChannels * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChannels * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChannels * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IChannels * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IChannels * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IChannels * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IChannels * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IChannels * This,
            /* [retval][out] */ IUnknown **ppChannel);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IChannels * This,
            /* [in] */ VARIANT varName,
            /* [retval][out] */ IChannel **pDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            IChannels * This,
            /* [retval][out] */ long *lCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveChannel )( 
            IChannels * This,
            /* [retval][out] */ XTLibActiveChannel *pvarXTLibActiveChannel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CCDChannel )( 
            IChannels * This,
            /* [retval][out] */ ICCDChannel **ppChannel);
        
        END_INTERFACE
    } IChannelsVtbl;

    interface IChannels
    {
        CONST_VTBL struct IChannelsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChannels_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChannels_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChannels_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChannels_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IChannels_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IChannels_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IChannels_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IChannels_get__NewEnum(This,ppChannel)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppChannel) ) 

#define IChannels_get_Item(This,varName,pDisp)	\
    ( (This)->lpVtbl -> get_Item(This,varName,pDisp) ) 

#define IChannels_Count(This,lCount)	\
    ( (This)->lpVtbl -> Count(This,lCount) ) 

#define IChannels_get_ActiveChannel(This,pvarXTLibActiveChannel)	\
    ( (This)->lpVtbl -> get_ActiveChannel(This,pvarXTLibActiveChannel) ) 

#define IChannels_get_CCDChannel(This,ppChannel)	\
    ( (This)->lpVtbl -> get_CCDChannel(This,ppChannel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChannels_INTERFACE_DEFINED__ */


#ifndef ___IChannelsEvents_DISPINTERFACE_DEFINED__
#define ___IChannelsEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IChannelsEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IChannelsEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3720D594-0D38-4975-8A94-9D79D7EEE3AC")
    _IChannelsEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IChannelsEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IChannelsEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IChannelsEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IChannelsEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IChannelsEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IChannelsEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IChannelsEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IChannelsEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IChannelsEventsVtbl;

    interface _IChannelsEvents
    {
        CONST_VTBL struct _IChannelsEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IChannelsEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IChannelsEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IChannelsEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IChannelsEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IChannelsEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IChannelsEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IChannelsEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IChannelsEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Channels;

#ifdef __cplusplus

class DECLSPEC_UUID("6D8F99D1-CC5B-11D4-A640-00B0D03B7B0E")
Channels;
#endif

#ifndef __IVideoControl_INTERFACE_DEFINED__
#define __IVideoControl_INTERFACE_DEFINED__

/* interface IVideoControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IVideoControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0EDEED1-C9F7-11D4-A63C-00B0D03B7B0E")
    IVideoControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DetectorGroups( 
            /* [retval][out] */ IDetectorGroups **ppDetectorGroups) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Channels( 
            /* [retval][out] */ IChannels **ppChannels) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallMode( 
            /* [retval][out] */ long *pvarXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallMode( 
            /* [in] */ XTLibCallMode varXTLibCallMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVideoControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVideoControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVideoControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVideoControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVideoControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVideoControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVideoControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVideoControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DetectorGroups )( 
            IVideoControl * This,
            /* [retval][out] */ IDetectorGroups **ppDetectorGroups);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Channels )( 
            IVideoControl * This,
            /* [retval][out] */ IChannels **ppChannels);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallMode )( 
            IVideoControl * This,
            /* [retval][out] */ long *pvarXTLibCallMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallMode )( 
            IVideoControl * This,
            /* [in] */ XTLibCallMode varXTLibCallMode);
        
        END_INTERFACE
    } IVideoControlVtbl;

    interface IVideoControl
    {
        CONST_VTBL struct IVideoControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVideoControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVideoControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVideoControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVideoControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVideoControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVideoControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVideoControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVideoControl_DetectorGroups(This,ppDetectorGroups)	\
    ( (This)->lpVtbl -> DetectorGroups(This,ppDetectorGroups) ) 

#define IVideoControl_Channels(This,ppChannels)	\
    ( (This)->lpVtbl -> Channels(This,ppChannels) ) 

#define IVideoControl_get_CallMode(This,pvarXTLibCallMode)	\
    ( (This)->lpVtbl -> get_CallMode(This,pvarXTLibCallMode) ) 

#define IVideoControl_put_CallMode(This,varXTLibCallMode)	\
    ( (This)->lpVtbl -> put_CallMode(This,varXTLibCallMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVideoControl_INTERFACE_DEFINED__ */


#ifndef ___IVideoControlEvents_DISPINTERFACE_DEFINED__
#define ___IVideoControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IVideoControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IVideoControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F0EDEED3-C9F7-11D4-A63C-00B0D03B7B0E")
    _IVideoControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IVideoControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IVideoControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IVideoControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IVideoControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IVideoControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IVideoControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IVideoControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IVideoControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IVideoControlEventsVtbl;

    interface _IVideoControlEvents
    {
        CONST_VTBL struct _IVideoControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IVideoControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IVideoControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IVideoControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IVideoControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IVideoControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IVideoControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IVideoControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IVideoControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VideoControl;

#ifdef __cplusplus

class DECLSPEC_UUID("F0EDEED2-C9F7-11D4-A63C-00B0D03B7B0E")
VideoControl;
#endif

#ifndef __IMicroscopeControl_INTERFACE_DEFINED__
#define __IMicroscopeControl_INTERFACE_DEFINED__

/* interface IMicroscopeControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMicroscopeControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8B50627E-8A1D-11D4-A5EE-00B0D03B7B0E")
    IMicroscopeControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VacSystemControl( 
            /* [retval][out] */ IVacSystemControl **ppVacSystemControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeamControl( 
            /* [retval][out] */ IBeamControl **ppBeamControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StageControl( 
            /* [retval][out] */ IStageControl **ppStageControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ScanControl( 
            /* [retval][out] */ IScanControl **ppScanControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VideoControl( 
            /* [retval][out] */ IVideoControl **ppVideoControl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mode( 
            /* [retval][out] */ long *pvarXTLibMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Mode( 
            /* [in] */ XTLibMode varXTLibMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallMode( 
            /* [retval][out] */ long *pvarXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallMode( 
            /* [in] */ XTLibCallMode varXTLibCallMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InstrumentID( 
            /* [retval][out] */ BSTR *pbstrInstrumentID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ BSTR strMachineName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [retval][out] */ VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DatabarAvailable( 
            /* [retval][out] */ BSTR *pbstrDatabarAvailable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DatabarSelected( 
            /* [retval][out] */ BSTR *pbstrDatabarSelected) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMicroscopeControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMicroscopeControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMicroscopeControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMicroscopeControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMicroscopeControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMicroscopeControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMicroscopeControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMicroscopeControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VacSystemControl )( 
            IMicroscopeControl * This,
            /* [retval][out] */ IVacSystemControl **ppVacSystemControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeamControl )( 
            IMicroscopeControl * This,
            /* [retval][out] */ IBeamControl **ppBeamControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StageControl )( 
            IMicroscopeControl * This,
            /* [retval][out] */ IStageControl **ppStageControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScanControl )( 
            IMicroscopeControl * This,
            /* [retval][out] */ IScanControl **ppScanControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VideoControl )( 
            IMicroscopeControl * This,
            /* [retval][out] */ IVideoControl **ppVideoControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mode )( 
            IMicroscopeControl * This,
            /* [retval][out] */ long *pvarXTLibMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Mode )( 
            IMicroscopeControl * This,
            /* [in] */ XTLibMode varXTLibMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallMode )( 
            IMicroscopeControl * This,
            /* [retval][out] */ long *pvarXTLibCallMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallMode )( 
            IMicroscopeControl * This,
            /* [in] */ XTLibCallMode varXTLibCallMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InstrumentID )( 
            IMicroscopeControl * This,
            /* [retval][out] */ BSTR *pbstrInstrumentID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IMicroscopeControl * This,
            /* [in] */ BSTR strMachineName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IMicroscopeControl * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            IMicroscopeControl * This,
            /* [retval][out] */ VARIANT_BOOL *pbIsConnected);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DatabarAvailable )( 
            IMicroscopeControl * This,
            /* [retval][out] */ BSTR *pbstrDatabarAvailable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DatabarSelected )( 
            IMicroscopeControl * This,
            /* [retval][out] */ BSTR *pbstrDatabarSelected);
        
        END_INTERFACE
    } IMicroscopeControlVtbl;

    interface IMicroscopeControl
    {
        CONST_VTBL struct IMicroscopeControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMicroscopeControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMicroscopeControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMicroscopeControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMicroscopeControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMicroscopeControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMicroscopeControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMicroscopeControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMicroscopeControl_VacSystemControl(This,ppVacSystemControl)	\
    ( (This)->lpVtbl -> VacSystemControl(This,ppVacSystemControl) ) 

#define IMicroscopeControl_BeamControl(This,ppBeamControl)	\
    ( (This)->lpVtbl -> BeamControl(This,ppBeamControl) ) 

#define IMicroscopeControl_StageControl(This,ppStageControl)	\
    ( (This)->lpVtbl -> StageControl(This,ppStageControl) ) 

#define IMicroscopeControl_ScanControl(This,ppScanControl)	\
    ( (This)->lpVtbl -> ScanControl(This,ppScanControl) ) 

#define IMicroscopeControl_VideoControl(This,ppVideoControl)	\
    ( (This)->lpVtbl -> VideoControl(This,ppVideoControl) ) 

#define IMicroscopeControl_get_Mode(This,pvarXTLibMode)	\
    ( (This)->lpVtbl -> get_Mode(This,pvarXTLibMode) ) 

#define IMicroscopeControl_put_Mode(This,varXTLibMode)	\
    ( (This)->lpVtbl -> put_Mode(This,varXTLibMode) ) 

#define IMicroscopeControl_get_CallMode(This,pvarXTLibCallMode)	\
    ( (This)->lpVtbl -> get_CallMode(This,pvarXTLibCallMode) ) 

#define IMicroscopeControl_put_CallMode(This,varXTLibCallMode)	\
    ( (This)->lpVtbl -> put_CallMode(This,varXTLibCallMode) ) 

#define IMicroscopeControl_get_InstrumentID(This,pbstrInstrumentID)	\
    ( (This)->lpVtbl -> get_InstrumentID(This,pbstrInstrumentID) ) 

#define IMicroscopeControl_Connect(This,strMachineName)	\
    ( (This)->lpVtbl -> Connect(This,strMachineName) ) 

#define IMicroscopeControl_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define IMicroscopeControl_get_IsConnected(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pbIsConnected) ) 

#define IMicroscopeControl_get_DatabarAvailable(This,pbstrDatabarAvailable)	\
    ( (This)->lpVtbl -> get_DatabarAvailable(This,pbstrDatabarAvailable) ) 

#define IMicroscopeControl_get_DatabarSelected(This,pbstrDatabarSelected)	\
    ( (This)->lpVtbl -> get_DatabarSelected(This,pbstrDatabarSelected) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMicroscopeControl_INTERFACE_DEFINED__ */


#ifndef ___IMicroscopeControlEvents_DISPINTERFACE_DEFINED__
#define ___IMicroscopeControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IMicroscopeControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IMicroscopeControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8B50627F-8A1D-11D4-A5EE-00B0D03B7B0E")
    _IMicroscopeControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IMicroscopeControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IMicroscopeControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IMicroscopeControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IMicroscopeControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IMicroscopeControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IMicroscopeControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IMicroscopeControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IMicroscopeControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IMicroscopeControlEventsVtbl;

    interface _IMicroscopeControlEvents
    {
        CONST_VTBL struct _IMicroscopeControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IMicroscopeControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IMicroscopeControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IMicroscopeControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IMicroscopeControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IMicroscopeControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IMicroscopeControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IMicroscopeControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IMicroscopeControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MicroscopeControl;

#ifdef __cplusplus

class DECLSPEC_UUID("A91CF32D-895D-11D4-A5ED-00B0D03B7B0E")
MicroscopeControl;
#endif

#ifndef __IElectronBeamControl2_INTERFACE_DEFINED__
#define __IElectronBeamControl2_INTERFACE_DEFINED__

/* interface IElectronBeamControl2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IElectronBeamControl2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D4888210-B50E-4c37-9C3B-8464829133FC")
    IElectronBeamControl2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ZFWDCoupling( 
            /* [retval][out] */ VARIANT_BOOL *pbZFWDCoupling) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ZFWDCoupling( 
            /* [in] */ VARIANT_BOOL bZFWDCoupling) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FWDFollowsZ( 
            /* [retval][out] */ VARIANT_BOOL *pbFWDFollowsZ) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FWDFollowsZ( 
            /* [in] */ VARIANT_BOOL bFWDFollowsZ) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EmissionCurrent( 
            /* [retval][out] */ double *dEmissionCurrent) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceBroken( 
            /* [retval][out] */ VARIANT_BOOL *dSourceBroken) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IElectronBeamControl2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IElectronBeamControl2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IElectronBeamControl2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IElectronBeamControl2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IElectronBeamControl2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IElectronBeamControl2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IElectronBeamControl2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IElectronBeamControl2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ZFWDCoupling )( 
            IElectronBeamControl2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbZFWDCoupling);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ZFWDCoupling )( 
            IElectronBeamControl2 * This,
            /* [in] */ VARIANT_BOOL bZFWDCoupling);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FWDFollowsZ )( 
            IElectronBeamControl2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbFWDFollowsZ);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FWDFollowsZ )( 
            IElectronBeamControl2 * This,
            /* [in] */ VARIANT_BOOL bFWDFollowsZ);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EmissionCurrent )( 
            IElectronBeamControl2 * This,
            /* [retval][out] */ double *dEmissionCurrent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceBroken )( 
            IElectronBeamControl2 * This,
            /* [retval][out] */ VARIANT_BOOL *dSourceBroken);
        
        END_INTERFACE
    } IElectronBeamControl2Vtbl;

    interface IElectronBeamControl2
    {
        CONST_VTBL struct IElectronBeamControl2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IElectronBeamControl2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IElectronBeamControl2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IElectronBeamControl2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IElectronBeamControl2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IElectronBeamControl2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IElectronBeamControl2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IElectronBeamControl2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IElectronBeamControl2_get_ZFWDCoupling(This,pbZFWDCoupling)	\
    ( (This)->lpVtbl -> get_ZFWDCoupling(This,pbZFWDCoupling) ) 

#define IElectronBeamControl2_put_ZFWDCoupling(This,bZFWDCoupling)	\
    ( (This)->lpVtbl -> put_ZFWDCoupling(This,bZFWDCoupling) ) 

#define IElectronBeamControl2_get_FWDFollowsZ(This,pbFWDFollowsZ)	\
    ( (This)->lpVtbl -> get_FWDFollowsZ(This,pbFWDFollowsZ) ) 

#define IElectronBeamControl2_put_FWDFollowsZ(This,bFWDFollowsZ)	\
    ( (This)->lpVtbl -> put_FWDFollowsZ(This,bFWDFollowsZ) ) 

#define IElectronBeamControl2_get_EmissionCurrent(This,dEmissionCurrent)	\
    ( (This)->lpVtbl -> get_EmissionCurrent(This,dEmissionCurrent) ) 

#define IElectronBeamControl2_get_SourceBroken(This,dSourceBroken)	\
    ( (This)->lpVtbl -> get_SourceBroken(This,dSourceBroken) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IElectronBeamControl2_INTERFACE_DEFINED__ */


#ifndef ___IElectronBeamControl2Events_DISPINTERFACE_DEFINED__
#define ___IElectronBeamControl2Events_DISPINTERFACE_DEFINED__

/* dispinterface _IElectronBeamControl2Events */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IElectronBeamControl2Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BC6BD640-D40D-463b-87FE-031042DCADCD")
    _IElectronBeamControl2Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IElectronBeamControl2EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IElectronBeamControl2Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IElectronBeamControl2Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IElectronBeamControl2Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IElectronBeamControl2Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IElectronBeamControl2Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IElectronBeamControl2Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IElectronBeamControl2Events * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IElectronBeamControl2EventsVtbl;

    interface _IElectronBeamControl2Events
    {
        CONST_VTBL struct _IElectronBeamControl2EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IElectronBeamControl2Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IElectronBeamControl2Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IElectronBeamControl2Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IElectronBeamControl2Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IElectronBeamControl2Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IElectronBeamControl2Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IElectronBeamControl2Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IElectronBeamControl2Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ElectronBeamControl2;

#ifdef __cplusplus

class DECLSPEC_UUID("F977B0E1-9F5E-4325-9392-41458CCAB020")
ElectronBeamControl2;
#endif

#ifndef __IBeamControl2_INTERFACE_DEFINED__
#define __IBeamControl2_INTERFACE_DEFINED__

/* interface IBeamControl2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IBeamControl2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0AF6FE79-3DA5-42c7-ACF7-059B04125DFE")
    IBeamControl2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ElectronBeamControl2( 
            /* [retval][out] */ IElectronBeamControl2 **ppElectronBeamControl2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBeamControl2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBeamControl2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBeamControl2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBeamControl2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBeamControl2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBeamControl2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBeamControl2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBeamControl2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ElectronBeamControl2 )( 
            IBeamControl2 * This,
            /* [retval][out] */ IElectronBeamControl2 **ppElectronBeamControl2);
        
        END_INTERFACE
    } IBeamControl2Vtbl;

    interface IBeamControl2
    {
        CONST_VTBL struct IBeamControl2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBeamControl2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBeamControl2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBeamControl2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBeamControl2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBeamControl2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBeamControl2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBeamControl2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBeamControl2_ElectronBeamControl2(This,ppElectronBeamControl2)	\
    ( (This)->lpVtbl -> ElectronBeamControl2(This,ppElectronBeamControl2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBeamControl2_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BeamControl2;

#ifdef __cplusplus

class DECLSPEC_UUID("9E3BFFDA-7778-4cd4-B419-B1553FF406BA")
BeamControl2;
#endif

#ifndef __IStageControl2_INTERFACE_DEFINED__
#define __IStageControl2_INTERFACE_DEFINED__

/* interface IStageControl2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStageControl2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3467ABEF-A07D-420f-B03C-A0C87B484B68")
    IStageControl2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RawCoordinateSystem( 
            /* [retval][out] */ VARIANT_BOOL *pbRawCoordinateSystem) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RawCoordinateSystem( 
            /* [in] */ VARIANT_BOOL bRawCoordinateSystem) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Homed( 
            /* [retval][out] */ VARIANT_BOOL *pbHomed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStageControl2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStageControl2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStageControl2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStageControl2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStageControl2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStageControl2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStageControl2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStageControl2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RawCoordinateSystem )( 
            IStageControl2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbRawCoordinateSystem);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RawCoordinateSystem )( 
            IStageControl2 * This,
            /* [in] */ VARIANT_BOOL bRawCoordinateSystem);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Homed )( 
            IStageControl2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbHomed);
        
        END_INTERFACE
    } IStageControl2Vtbl;

    interface IStageControl2
    {
        CONST_VTBL struct IStageControl2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStageControl2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStageControl2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStageControl2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStageControl2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IStageControl2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IStageControl2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IStageControl2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IStageControl2_get_RawCoordinateSystem(This,pbRawCoordinateSystem)	\
    ( (This)->lpVtbl -> get_RawCoordinateSystem(This,pbRawCoordinateSystem) ) 

#define IStageControl2_put_RawCoordinateSystem(This,bRawCoordinateSystem)	\
    ( (This)->lpVtbl -> put_RawCoordinateSystem(This,bRawCoordinateSystem) ) 

#define IStageControl2_get_Homed(This,pbHomed)	\
    ( (This)->lpVtbl -> get_Homed(This,pbHomed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStageControl2_INTERFACE_DEFINED__ */


#ifndef ___IStageControl2Events_DISPINTERFACE_DEFINED__
#define ___IStageControl2Events_DISPINTERFACE_DEFINED__

/* dispinterface _IStageControl2Events */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IStageControl2Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B78EEEA0-8DF4-4b03-ABE5-4E66F9D216F3")
    _IStageControl2Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IStageControl2EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IStageControl2Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IStageControl2Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IStageControl2Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IStageControl2Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IStageControl2Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IStageControl2Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IStageControl2Events * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IStageControl2EventsVtbl;

    interface _IStageControl2Events
    {
        CONST_VTBL struct _IStageControl2EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IStageControl2Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IStageControl2Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IStageControl2Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IStageControl2Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IStageControl2Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IStageControl2Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IStageControl2Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IStageControl2Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_StageControl2;

#ifdef __cplusplus

class DECLSPEC_UUID("5CB2BA00-95B3-419f-B91A-1AD742382EB7")
StageControl2;
#endif

#ifndef __IMicroscopeControl2_INTERFACE_DEFINED__
#define __IMicroscopeControl2_INTERFACE_DEFINED__

/* interface IMicroscopeControl2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMicroscopeControl2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F3181E4-6611-4a26-A66D-4B0E1E9658A0")
    IMicroscopeControl2 : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeamControl2( 
            /* [retval][out] */ IBeamControl2 **ppBeamControl2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StageControl2( 
            /* [retval][out] */ IStageControl2 **ppStageControl2) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventRegistration( 
            /* [retval][out] */ VARIANT_BOOL *pvarXTLibEventRegistration) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EventRegistration( 
            /* [in] */ VARIANT_BOOL varXTLibEventRegistration) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Software( 
            /* [retval][out] */ BSTR *sSoftware) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BuildNr( 
            /* [retval][out] */ BSTR *sBuildNr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SystemType( 
            /* [retval][out] */ BSTR *sSystemType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayWidth( 
            /* [retval][out] */ double *DisplayWidth) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayHeight( 
            /* [retval][out] */ double *DisplayHeight) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMicroscopeControl2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMicroscopeControl2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMicroscopeControl2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMicroscopeControl2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeamControl2 )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ IBeamControl2 **ppBeamControl2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StageControl2 )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ IStageControl2 **ppStageControl2);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventRegistration )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ VARIANT_BOOL *pvarXTLibEventRegistration);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventRegistration )( 
            IMicroscopeControl2 * This,
            /* [in] */ VARIANT_BOOL varXTLibEventRegistration);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Software )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ BSTR *sSoftware);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BuildNr )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ BSTR *sBuildNr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SystemType )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ BSTR *sSystemType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayWidth )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ double *DisplayWidth);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayHeight )( 
            IMicroscopeControl2 * This,
            /* [retval][out] */ double *DisplayHeight);
        
        END_INTERFACE
    } IMicroscopeControl2Vtbl;

    interface IMicroscopeControl2
    {
        CONST_VTBL struct IMicroscopeControl2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMicroscopeControl2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMicroscopeControl2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMicroscopeControl2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMicroscopeControl2_BeamControl2(This,ppBeamControl2)	\
    ( (This)->lpVtbl -> BeamControl2(This,ppBeamControl2) ) 

#define IMicroscopeControl2_StageControl2(This,ppStageControl2)	\
    ( (This)->lpVtbl -> StageControl2(This,ppStageControl2) ) 

#define IMicroscopeControl2_get_EventRegistration(This,pvarXTLibEventRegistration)	\
    ( (This)->lpVtbl -> get_EventRegistration(This,pvarXTLibEventRegistration) ) 

#define IMicroscopeControl2_put_EventRegistration(This,varXTLibEventRegistration)	\
    ( (This)->lpVtbl -> put_EventRegistration(This,varXTLibEventRegistration) ) 

#define IMicroscopeControl2_get_Software(This,sSoftware)	\
    ( (This)->lpVtbl -> get_Software(This,sSoftware) ) 

#define IMicroscopeControl2_get_BuildNr(This,sBuildNr)	\
    ( (This)->lpVtbl -> get_BuildNr(This,sBuildNr) ) 

#define IMicroscopeControl2_get_SystemType(This,sSystemType)	\
    ( (This)->lpVtbl -> get_SystemType(This,sSystemType) ) 

#define IMicroscopeControl2_get_DisplayWidth(This,DisplayWidth)	\
    ( (This)->lpVtbl -> get_DisplayWidth(This,DisplayWidth) ) 

#define IMicroscopeControl2_get_DisplayHeight(This,DisplayHeight)	\
    ( (This)->lpVtbl -> get_DisplayHeight(This,DisplayHeight) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMicroscopeControl2_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MicroscopeControl2;

#ifdef __cplusplus

class DECLSPEC_UUID("3DF9D2F0-1187-4907-AF4F-9DE5B89F07DE")
MicroscopeControl2;
#endif

#ifndef __IScanControl2_INTERFACE_DEFINED__
#define __IScanControl2_INTERFACE_DEFINED__

/* interface IScanControl2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IScanControl2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18EF1D8B-B204-48a2-B393-014AA1963FD7")
    IScanControl2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MagnificationCanvasWidth( 
            /* [retval][out] */ double *pdMagnificationCanvasWidth) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScanControl2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScanControl2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScanControl2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScanControl2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScanControl2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScanControl2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScanControl2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScanControl2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MagnificationCanvasWidth )( 
            IScanControl2 * This,
            /* [retval][out] */ double *pdMagnificationCanvasWidth);
        
        END_INTERFACE
    } IScanControl2Vtbl;

    interface IScanControl2
    {
        CONST_VTBL struct IScanControl2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScanControl2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScanControl2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScanControl2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScanControl2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScanControl2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScanControl2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScanControl2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScanControl2_get_MagnificationCanvasWidth(This,pdMagnificationCanvasWidth)	\
    ( (This)->lpVtbl -> get_MagnificationCanvasWidth(This,pdMagnificationCanvasWidth) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScanControl2_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ScanControl2;

#ifdef __cplusplus

class DECLSPEC_UUID("EDA367DC-4DE1-4a7e-8B1D-EEA69FE62E4C")
ScanControl2;
#endif

#ifndef __IStageControl3_INTERFACE_DEFINED__
#define __IStageControl3_INTERFACE_DEFINED__

/* interface IStageControl3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStageControl3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7E1FD948-219D-4403-85BC-4DD75660CD38")
    IStageControl3 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HomeAxis( 
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ VARIANT_BOOL bSynchronous) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStageControl3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStageControl3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStageControl3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStageControl3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStageControl3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStageControl3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStageControl3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStageControl3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HomeAxis )( 
            IStageControl3 * This,
            /* [in] */ StageAxisMask AxisMask,
            /* [in] */ VARIANT_BOOL bSynchronous);
        
        END_INTERFACE
    } IStageControl3Vtbl;

    interface IStageControl3
    {
        CONST_VTBL struct IStageControl3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStageControl3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStageControl3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStageControl3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStageControl3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IStageControl3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IStageControl3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IStageControl3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IStageControl3_HomeAxis(This,AxisMask,bSynchronous)	\
    ( (This)->lpVtbl -> HomeAxis(This,AxisMask,bSynchronous) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStageControl3_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_StageControl3;

#ifdef __cplusplus

class DECLSPEC_UUID("05073A06-6429-4db0-9B13-A295984B9762")
StageControl3;
#endif

#ifndef __IMicroscopeControl3_INTERFACE_DEFINED__
#define __IMicroscopeControl3_INTERFACE_DEFINED__

/* interface IMicroscopeControl3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMicroscopeControl3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1CE69D1-6668-4b01-8357-4EF07378FBF6")
    IMicroscopeControl3 : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ScanControl2( 
            /* [retval][out] */ IScanControl2 **ppScanControl2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StageControl3( 
            /* [retval][out] */ IStageControl3 **ppStageControl3) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMicroscopeControl3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMicroscopeControl3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMicroscopeControl3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMicroscopeControl3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScanControl2 )( 
            IMicroscopeControl3 * This,
            /* [retval][out] */ IScanControl2 **ppScanControl2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StageControl3 )( 
            IMicroscopeControl3 * This,
            /* [retval][out] */ IStageControl3 **ppStageControl3);
        
        END_INTERFACE
    } IMicroscopeControl3Vtbl;

    interface IMicroscopeControl3
    {
        CONST_VTBL struct IMicroscopeControl3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMicroscopeControl3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMicroscopeControl3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMicroscopeControl3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMicroscopeControl3_ScanControl2(This,ppScanControl2)	\
    ( (This)->lpVtbl -> ScanControl2(This,ppScanControl2) ) 

#define IMicroscopeControl3_StageControl3(This,ppStageControl3)	\
    ( (This)->lpVtbl -> StageControl3(This,ppStageControl3) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMicroscopeControl3_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MicroscopeControl3;

#ifdef __cplusplus

class DECLSPEC_UUID("4BE9350E-12C1-43c8-BD49-D7B83747FA93")
MicroscopeControl3;
#endif

#ifndef __IElectronBeamControl3_INTERFACE_DEFINED__
#define __IElectronBeamControl3_INTERFACE_DEFINED__

/* interface IElectronBeamControl3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IElectronBeamControl3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F4B2941-7928-4e91-A766-E564212C7FA9")
    IElectronBeamControl3 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LandingEnergy( 
            /* [retval][out] */ double *pdLandingEnergy) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LandingEnergy( 
            /* [in] */ double dLandingEnergy) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StageBias( 
            /* [retval][out] */ double *pdStageBias) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StageBias( 
            /* [in] */ double dStageBias) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BeamDeceleration( 
            /* [retval][out] */ VARIANT_BOOL *pbBdIsOn) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BeamDeceleration( 
            /* [in] */ VARIANT_BOOL bBdIsOn) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LensMode( 
            /* [retval][out] */ LensMode *pLensMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LensMode( 
            /* [in] */ LensMode lensMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IElectronBeamControl3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IElectronBeamControl3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IElectronBeamControl3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IElectronBeamControl3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IElectronBeamControl3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IElectronBeamControl3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IElectronBeamControl3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IElectronBeamControl3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LandingEnergy )( 
            IElectronBeamControl3 * This,
            /* [retval][out] */ double *pdLandingEnergy);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LandingEnergy )( 
            IElectronBeamControl3 * This,
            /* [in] */ double dLandingEnergy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StageBias )( 
            IElectronBeamControl3 * This,
            /* [retval][out] */ double *pdStageBias);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StageBias )( 
            IElectronBeamControl3 * This,
            /* [in] */ double dStageBias);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BeamDeceleration )( 
            IElectronBeamControl3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbBdIsOn);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BeamDeceleration )( 
            IElectronBeamControl3 * This,
            /* [in] */ VARIANT_BOOL bBdIsOn);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LensMode )( 
            IElectronBeamControl3 * This,
            /* [retval][out] */ LensMode *pLensMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LensMode )( 
            IElectronBeamControl3 * This,
            /* [in] */ LensMode lensMode);
        
        END_INTERFACE
    } IElectronBeamControl3Vtbl;

    interface IElectronBeamControl3
    {
        CONST_VTBL struct IElectronBeamControl3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IElectronBeamControl3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IElectronBeamControl3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IElectronBeamControl3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IElectronBeamControl3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IElectronBeamControl3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IElectronBeamControl3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IElectronBeamControl3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IElectronBeamControl3_get_LandingEnergy(This,pdLandingEnergy)	\
    ( (This)->lpVtbl -> get_LandingEnergy(This,pdLandingEnergy) ) 

#define IElectronBeamControl3_put_LandingEnergy(This,dLandingEnergy)	\
    ( (This)->lpVtbl -> put_LandingEnergy(This,dLandingEnergy) ) 

#define IElectronBeamControl3_get_StageBias(This,pdStageBias)	\
    ( (This)->lpVtbl -> get_StageBias(This,pdStageBias) ) 

#define IElectronBeamControl3_put_StageBias(This,dStageBias)	\
    ( (This)->lpVtbl -> put_StageBias(This,dStageBias) ) 

#define IElectronBeamControl3_get_BeamDeceleration(This,pbBdIsOn)	\
    ( (This)->lpVtbl -> get_BeamDeceleration(This,pbBdIsOn) ) 

#define IElectronBeamControl3_put_BeamDeceleration(This,bBdIsOn)	\
    ( (This)->lpVtbl -> put_BeamDeceleration(This,bBdIsOn) ) 

#define IElectronBeamControl3_get_LensMode(This,pLensMode)	\
    ( (This)->lpVtbl -> get_LensMode(This,pLensMode) ) 

#define IElectronBeamControl3_put_LensMode(This,lensMode)	\
    ( (This)->lpVtbl -> put_LensMode(This,lensMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IElectronBeamControl3_INTERFACE_DEFINED__ */


#ifndef ___IElectronBeamControl3Events_DISPINTERFACE_DEFINED__
#define ___IElectronBeamControl3Events_DISPINTERFACE_DEFINED__

/* dispinterface _IElectronBeamControl3Events */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IElectronBeamControl3Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F781EAFF-5370-49e1-B3E5-E58B81649B9E")
    _IElectronBeamControl3Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IElectronBeamControl3EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IElectronBeamControl3Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IElectronBeamControl3Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IElectronBeamControl3Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IElectronBeamControl3Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IElectronBeamControl3Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IElectronBeamControl3Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IElectronBeamControl3Events * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IElectronBeamControl3EventsVtbl;

    interface _IElectronBeamControl3Events
    {
        CONST_VTBL struct _IElectronBeamControl3EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IElectronBeamControl3Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IElectronBeamControl3Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IElectronBeamControl3Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IElectronBeamControl3Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IElectronBeamControl3Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IElectronBeamControl3Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IElectronBeamControl3Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IElectronBeamControl3Events_DISPINTERFACE_DEFINED__ */


#ifndef __IConsoleControl_INTERFACE_DEFINED__
#define __IConsoleControl_INTERFACE_DEFINED__

/* interface IConsoleControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IConsoleControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E5EF03A-22DA-4a80-9227-4FB6A5C864F9")
    IConsoleControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LevelingState( 
            /* [retval][out] */ LevelingState *pLevelingState) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LevelingState( 
            /* [in] */ LevelingState levelingState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConsoleControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConsoleControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConsoleControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConsoleControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IConsoleControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IConsoleControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IConsoleControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IConsoleControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LevelingState )( 
            IConsoleControl * This,
            /* [retval][out] */ LevelingState *pLevelingState);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LevelingState )( 
            IConsoleControl * This,
            /* [in] */ LevelingState levelingState);
        
        END_INTERFACE
    } IConsoleControlVtbl;

    interface IConsoleControl
    {
        CONST_VTBL struct IConsoleControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConsoleControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConsoleControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConsoleControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConsoleControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IConsoleControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IConsoleControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IConsoleControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IConsoleControl_get_LevelingState(This,pLevelingState)	\
    ( (This)->lpVtbl -> get_LevelingState(This,pLevelingState) ) 

#define IConsoleControl_put_LevelingState(This,levelingState)	\
    ( (This)->lpVtbl -> put_LevelingState(This,levelingState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConsoleControl_INTERFACE_DEFINED__ */


#ifndef ___IConsoleControlEvents_DISPINTERFACE_DEFINED__
#define ___IConsoleControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IConsoleControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IConsoleControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F2A02F81-4F6A-4120-AFD6-4DA48B19AFDE")
    _IConsoleControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IConsoleControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IConsoleControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IConsoleControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IConsoleControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IConsoleControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IConsoleControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IConsoleControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IConsoleControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IConsoleControlEventsVtbl;

    interface _IConsoleControlEvents
    {
        CONST_VTBL struct _IConsoleControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IConsoleControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IConsoleControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IConsoleControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IConsoleControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IConsoleControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IConsoleControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IConsoleControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IConsoleControlEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IMicroscopeControl4_INTERFACE_DEFINED__
#define __IMicroscopeControl4_INTERFACE_DEFINED__

/* interface IMicroscopeControl4 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMicroscopeControl4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2DAC0F8A-2068-4e8b-B942-E31AACF6AD44")
    IMicroscopeControl4 : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ElectronBeamControl3( 
            /* [retval][out] */ IElectronBeamControl3 **ppEBeamControl3) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConsoleControl( 
            /* [retval][out] */ IConsoleControl **ppConsoleControl3) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMicroscopeControl4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMicroscopeControl4 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMicroscopeControl4 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMicroscopeControl4 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ElectronBeamControl3 )( 
            IMicroscopeControl4 * This,
            /* [retval][out] */ IElectronBeamControl3 **ppEBeamControl3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConsoleControl )( 
            IMicroscopeControl4 * This,
            /* [retval][out] */ IConsoleControl **ppConsoleControl3);
        
        END_INTERFACE
    } IMicroscopeControl4Vtbl;

    interface IMicroscopeControl4
    {
        CONST_VTBL struct IMicroscopeControl4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMicroscopeControl4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMicroscopeControl4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMicroscopeControl4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMicroscopeControl4_ElectronBeamControl3(This,ppEBeamControl3)	\
    ( (This)->lpVtbl -> ElectronBeamControl3(This,ppEBeamControl3) ) 

#define IMicroscopeControl4_ConsoleControl(This,ppConsoleControl3)	\
    ( (This)->lpVtbl -> ConsoleControl(This,ppConsoleControl3) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMicroscopeControl4_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ElectronBeamControl3;

#ifdef __cplusplus

class DECLSPEC_UUID("710B9504-C573-4c51-B97A-19720A9392AB")
ElectronBeamControl3;
#endif

EXTERN_C const CLSID CLSID_ConsoleControl;

#ifdef __cplusplus

class DECLSPEC_UUID("6495B6DC-55AB-4934-82DA-F14D2964F4CC")
ConsoleControl;
#endif

EXTERN_C const CLSID CLSID_MicroscopeControl4;

#ifdef __cplusplus

class DECLSPEC_UUID("8BDC7AB9-6051-4394-90C2-F738521D8447")
MicroscopeControl4;
#endif

#ifndef __IBeamAperture_INTERFACE_DEFINED__
#define __IBeamAperture_INTERFACE_DEFINED__

/* interface IBeamAperture */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IBeamAperture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF50E77D-FCEC-4037-A336-D79325AC1DD1")
    IBeamAperture : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ long *pnIndex) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Diameter( 
            /* [retval][out] */ double *pdDiameter) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Allowed( 
            /* [retval][out] */ VARIANT_BOOL *pbAllowed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBeamApertureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBeamAperture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBeamAperture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBeamAperture * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBeamAperture * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBeamAperture * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBeamAperture * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBeamAperture * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IBeamAperture * This,
            /* [retval][out] */ long *pnIndex);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Diameter )( 
            IBeamAperture * This,
            /* [retval][out] */ double *pdDiameter);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Allowed )( 
            IBeamAperture * This,
            /* [retval][out] */ VARIANT_BOOL *pbAllowed);
        
        END_INTERFACE
    } IBeamApertureVtbl;

    interface IBeamAperture
    {
        CONST_VTBL struct IBeamApertureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBeamAperture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBeamAperture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBeamAperture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBeamAperture_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBeamAperture_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBeamAperture_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBeamAperture_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBeamAperture_get_Index(This,pnIndex)	\
    ( (This)->lpVtbl -> get_Index(This,pnIndex) ) 

#define IBeamAperture_get_Diameter(This,pdDiameter)	\
    ( (This)->lpVtbl -> get_Diameter(This,pdDiameter) ) 

#define IBeamAperture_get_Allowed(This,pbAllowed)	\
    ( (This)->lpVtbl -> get_Allowed(This,pbAllowed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBeamAperture_INTERFACE_DEFINED__ */


#ifndef __IBeamApertures_INTERFACE_DEFINED__
#define __IBeamApertures_INTERFACE_DEFINED__

/* interface IBeamApertures */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IBeamApertures;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7DA548A7-41CD-43FE-A9E3-360EEE1CE893")
    IBeamApertures : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppAperture) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varName,
            /* [retval][out] */ IBeamAperture **pDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *lCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBeamAperturesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBeamApertures * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBeamApertures * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBeamApertures * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBeamApertures * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBeamApertures * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBeamApertures * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBeamApertures * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IBeamApertures * This,
            /* [retval][out] */ IUnknown **ppAperture);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IBeamApertures * This,
            /* [in] */ VARIANT varName,
            /* [retval][out] */ IBeamAperture **pDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            IBeamApertures * This,
            /* [retval][out] */ long *lCount);
        
        END_INTERFACE
    } IBeamAperturesVtbl;

    interface IBeamApertures
    {
        CONST_VTBL struct IBeamAperturesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBeamApertures_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBeamApertures_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBeamApertures_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBeamApertures_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBeamApertures_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBeamApertures_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBeamApertures_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBeamApertures_get__NewEnum(This,ppAperture)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppAperture) ) 

#define IBeamApertures_get_Item(This,varName,pDisp)	\
    ( (This)->lpVtbl -> get_Item(This,varName,pDisp) ) 

#define IBeamApertures_Count(This,lCount)	\
    ( (This)->lpVtbl -> Count(This,lCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBeamApertures_INTERFACE_DEFINED__ */


#ifndef __IElectronBeamControl4_INTERFACE_DEFINED__
#define __IElectronBeamControl4_INTERFACE_DEFINED__

/* interface IElectronBeamControl4 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IElectronBeamControl4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1785F9BB-0EAF-41AB-9515-C9F337120D70")
    IElectronBeamControl4 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AllApertures( 
            /* [retval][out] */ IBeamApertures **ppBeamApertures) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveAperture( 
            /* [retval][out] */ IBeamAperture **pAperture) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActiveAperture( 
            /* [in] */ IBeamAperture *pAperture) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalculateBeamCurrent( 
            /* [in] */ IBeamAperture *pAperture,
            /* [retval][out] */ double *pdResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IElectronBeamControl4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IElectronBeamControl4 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IElectronBeamControl4 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IElectronBeamControl4 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IElectronBeamControl4 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IElectronBeamControl4 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IElectronBeamControl4 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IElectronBeamControl4 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AllApertures )( 
            IElectronBeamControl4 * This,
            /* [retval][out] */ IBeamApertures **ppBeamApertures);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveAperture )( 
            IElectronBeamControl4 * This,
            /* [retval][out] */ IBeamAperture **pAperture);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveAperture )( 
            IElectronBeamControl4 * This,
            /* [in] */ IBeamAperture *pAperture);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CalculateBeamCurrent )( 
            IElectronBeamControl4 * This,
            /* [in] */ IBeamAperture *pAperture,
            /* [retval][out] */ double *pdResult);
        
        END_INTERFACE
    } IElectronBeamControl4Vtbl;

    interface IElectronBeamControl4
    {
        CONST_VTBL struct IElectronBeamControl4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IElectronBeamControl4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IElectronBeamControl4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IElectronBeamControl4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IElectronBeamControl4_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IElectronBeamControl4_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IElectronBeamControl4_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IElectronBeamControl4_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IElectronBeamControl4_AllApertures(This,ppBeamApertures)	\
    ( (This)->lpVtbl -> AllApertures(This,ppBeamApertures) ) 

#define IElectronBeamControl4_get_ActiveAperture(This,pAperture)	\
    ( (This)->lpVtbl -> get_ActiveAperture(This,pAperture) ) 

#define IElectronBeamControl4_put_ActiveAperture(This,pAperture)	\
    ( (This)->lpVtbl -> put_ActiveAperture(This,pAperture) ) 

#define IElectronBeamControl4_CalculateBeamCurrent(This,pAperture,pdResult)	\
    ( (This)->lpVtbl -> CalculateBeamCurrent(This,pAperture,pdResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IElectronBeamControl4_INTERFACE_DEFINED__ */


#ifndef ___IElectronBeamControl4Events_DISPINTERFACE_DEFINED__
#define ___IElectronBeamControl4Events_DISPINTERFACE_DEFINED__

/* dispinterface _IElectronBeamControl4Events */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IElectronBeamControl4Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("853B0FAE-0F43-457A-8EF8-6FFD7F8D6BFB")
    _IElectronBeamControl4Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IElectronBeamControl4EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IElectronBeamControl4Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IElectronBeamControl4Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IElectronBeamControl4Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IElectronBeamControl4Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IElectronBeamControl4Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IElectronBeamControl4Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IElectronBeamControl4Events * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IElectronBeamControl4EventsVtbl;

    interface _IElectronBeamControl4Events
    {
        CONST_VTBL struct _IElectronBeamControl4EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IElectronBeamControl4Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IElectronBeamControl4Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IElectronBeamControl4Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IElectronBeamControl4Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IElectronBeamControl4Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IElectronBeamControl4Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IElectronBeamControl4Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IElectronBeamControl4Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BeamAperture;

#ifdef __cplusplus

class DECLSPEC_UUID("CD91B4C3-AB1A-4D2B-9B24-5DF65BB8AA7E")
BeamAperture;
#endif

EXTERN_C const CLSID CLSID_BeamApertures;

#ifdef __cplusplus

class DECLSPEC_UUID("081AC441-3852-421C-864E-AD5CC1A33458")
BeamApertures;
#endif

EXTERN_C const CLSID CLSID_ElectronBeamControl4;

#ifdef __cplusplus

class DECLSPEC_UUID("EB8E11AF-1193-4276-BA70-0B60D5354918")
ElectronBeamControl4;
#endif

#ifndef __IVacSystemControl2_INTERFACE_DEFINED__
#define __IVacSystemControl2_INTERFACE_DEFINED__

/* interface IVacSystemControl2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IVacSystemControl2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F2FDBB4E-6106-4ac4-9A28-2D22766D8390")
    IVacSystemControl2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pump( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Vent( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVacSystemControl2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVacSystemControl2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVacSystemControl2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVacSystemControl2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVacSystemControl2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVacSystemControl2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVacSystemControl2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVacSystemControl2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pump )( 
            IVacSystemControl2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Vent )( 
            IVacSystemControl2 * This);
        
        END_INTERFACE
    } IVacSystemControl2Vtbl;

    interface IVacSystemControl2
    {
        CONST_VTBL struct IVacSystemControl2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVacSystemControl2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVacSystemControl2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVacSystemControl2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVacSystemControl2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVacSystemControl2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVacSystemControl2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVacSystemControl2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVacSystemControl2_Pump(This)	\
    ( (This)->lpVtbl -> Pump(This) ) 

#define IVacSystemControl2_Vent(This)	\
    ( (This)->lpVtbl -> Vent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVacSystemControl2_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VacSystemControl2;

#ifdef __cplusplus

class DECLSPEC_UUID("9CD25EAD-A229-46A2-B54B-66D9008ECA80")
VacSystemControl2;
#endif

#ifndef __IMicroscopeControl5_INTERFACE_DEFINED__
#define __IMicroscopeControl5_INTERFACE_DEFINED__

/* interface IMicroscopeControl5 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMicroscopeControl5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94695FAD-6E5F-4bc0-B478-15EAFCF80E77")
    IMicroscopeControl5 : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ElectronBeamControl4( 
            /* [retval][out] */ IElectronBeamControl4 **ppElectronBeamControl4) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VacSystemControl2( 
            /* [retval][out] */ IVacSystemControl2 **ppVacSystemControl2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMicroscopeControl5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMicroscopeControl5 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMicroscopeControl5 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMicroscopeControl5 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ElectronBeamControl4 )( 
            IMicroscopeControl5 * This,
            /* [retval][out] */ IElectronBeamControl4 **ppElectronBeamControl4);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VacSystemControl2 )( 
            IMicroscopeControl5 * This,
            /* [retval][out] */ IVacSystemControl2 **ppVacSystemControl2);
        
        END_INTERFACE
    } IMicroscopeControl5Vtbl;

    interface IMicroscopeControl5
    {
        CONST_VTBL struct IMicroscopeControl5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMicroscopeControl5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMicroscopeControl5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMicroscopeControl5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMicroscopeControl5_ElectronBeamControl4(This,ppElectronBeamControl4)	\
    ( (This)->lpVtbl -> ElectronBeamControl4(This,ppElectronBeamControl4) ) 

#define IMicroscopeControl5_VacSystemControl2(This,ppVacSystemControl2)	\
    ( (This)->lpVtbl -> VacSystemControl2(This,ppVacSystemControl2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMicroscopeControl5_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MicroscopeControl5;

#ifdef __cplusplus

class DECLSPEC_UUID("42F25D02-2BE8-4b70-8C3F-052F03F35B09")
MicroscopeControl5;
#endif
#endif /* __XTLIBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



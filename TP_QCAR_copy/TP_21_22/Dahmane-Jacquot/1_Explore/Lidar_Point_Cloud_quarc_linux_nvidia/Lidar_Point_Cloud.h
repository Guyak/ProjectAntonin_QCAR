/*
 * Lidar_Point_Cloud.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lidar_Point_Cloud".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 09:00:22 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lidar_Point_Cloud_h_
#define RTW_HEADER_Lidar_Point_Cloud_h_
#include <math.h>
#include <string.h>
#ifndef Lidar_Point_Cloud_COMMON_INCLUDES_
#define Lidar_Point_Cloud_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_ranging_sensor.h"
#include "quanser_messages.h"
#include "quanser_memory.h"
#include "quanser_channel.h"
#include "extmode_support.h"
#include "quanser_time.h"
#include "quanser_extern.h"
#endif                                 /* Lidar_Point_Cloud_COMMON_INCLUDES_ */

#include "Lidar_Point_Cloud_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ()
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ()
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ()
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ()
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  0
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Lidar_Point_Cloud_rtModel      RT_MODEL_Lidar_Point_Cloud_T

/* Block signals (default storage) */
typedef struct {
  real_T RangingSensor1_o1[1300];      /* '<S3>/Ranging Sensor1' */
  real_T RangingSensor1_o2[1300];      /* '<S3>/Ranging Sensor1' */
  real_T RangingSensor1_o3[1300];      /* '<S3>/Ranging Sensor1' */
  real_T RangingSensor1_o4[1300];      /* '<S3>/Ranging Sensor1' */
  real_T Constant1[720];               /* '<S3>/Constant1' */
  real_T temp_heading_data[720];
  real_T pX_data[720];
  real_T Switch2[720];                 /* '<S7>/Switch2' */
  real_T X[720];                       /* '<S5>/findXYContour' */
  real_T Y[720];                       /* '<S5>/findXYContour' */
  real_T actualsampletime;             /* '<S4>/Sample Time' */
  real_T reference;                    /* '<S4>/Constant' */
  real_T computationtime;              /* '<S4>/Computation Time' */
  real_T correctedDistances[720];      /* '<S3>/MATLAB Function' */
  t_channel Channel;                   /* '<Root>/Channel' */
} B_Lidar_Point_Cloud_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_ranging_measurement RangingSensor1_Measurements[1300];/* '<S3>/Ranging Sensor1' */
  t_timeout SampleTime_PreviousTime;   /* '<S4>/Sample Time' */
  t_timeout ComputationTime_BeginTime; /* '<S4>/Computation Time' */
  t_timeout ComputationTime_ComputationTime;/* '<S4>/Computation Time' */
  real_T BodyFramePolarPlot_XBuffer[720];/* '<Root>/Body Frame  Polar Plot' */
  real_T BodyFramePolarPlot_YBuffer[720];/* '<Root>/Body Frame  Polar Plot' */
  real_T PolarFigure_XBuffer[720000];  /* '<Root>/Polar Figure' */
  real_T PolarFigure_YBuffer[720000];  /* '<Root>/Polar Figure' */
  real_T mapInternal[160000];          /* '<S5>/contourToPointCloud' */
  t_ranging_sensor RangingSensor1_Sensor;/* '<S3>/Ranging Sensor1' */
  struct {
    void *Fifo;
  } Channel_PWORK;                     /* '<Root>/Channel' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T SFunction_DIMS2;             /* '<S5>/findXYContour' */
  int32_T SFunction_DIMS3;             /* '<S5>/findXYContour' */
  int_T BodyFramePolarPlot_IWORK[2];   /* '<Root>/Body Frame  Polar Plot' */
  int_T PolarFigure_IWORK[2];          /* '<Root>/Polar Figure' */
  boolean_T BodyFramePolarPlot_IsFull; /* '<Root>/Body Frame  Polar Plot' */
  boolean_T PolarFigure_IsFull;        /* '<Root>/Polar Figure' */
  boolean_T mapInternal_not_empty;     /* '<S5>/contourToPointCloud' */
} DW_Lidar_Point_Cloud_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Lidar_Point_Cloud_B
#define BlockIO                        B_Lidar_Point_Cloud_T
#define rtP                            Lidar_Point_Cloud_P
#define Parameters                     P_Lidar_Point_Cloud_T
#define rtDWork                        Lidar_Point_Cloud_DW
#define D_Work                         DW_Lidar_Point_Cloud_T

/* Parameters (default storage) */
struct P_Lidar_Point_Cloud_T_ {
  real_T BodyFramePolarPlot_maximum_rho;
                               /* Mask Parameter: BodyFramePolarPlot_maximum_rho
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  real_T PolarFigure_maximum_rho;     /* Mask Parameter: PolarFigure_maximum_rho
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  real_T BodyFramePolarPlot_maximum_thet;
                              /* Mask Parameter: BodyFramePolarPlot_maximum_thet
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  real_T PolarFigure_maximum_theta; /* Mask Parameter: PolarFigure_maximum_theta
                                     * Referenced by: '<Root>/Polar Figure'
                                     */
  real_T BodyFramePolarPlot_minimum_rho;
                               /* Mask Parameter: BodyFramePolarPlot_minimum_rho
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  real_T PolarFigure_minimum_rho;     /* Mask Parameter: PolarFigure_minimum_rho
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  real_T BodyFramePolarPlot_minimum_thet;
                              /* Mask Parameter: BodyFramePolarPlot_minimum_thet
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  real_T PolarFigure_minimum_theta; /* Mask Parameter: PolarFigure_minimum_theta
                                     * Referenced by: '<Root>/Polar Figure'
                                     */
  int32_T BodyFramePolarPlot_direction;
                                 /* Mask Parameter: BodyFramePolarPlot_direction
                                  * Referenced by: '<Root>/Body Frame  Polar Plot'
                                  */
  int32_T PolarFigure_direction;       /* Mask Parameter: PolarFigure_direction
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  int32_T BodyFramePolarPlot_update_rate;
                               /* Mask Parameter: BodyFramePolarPlot_update_rate
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  int32_T PolarFigure_update_rate;    /* Mask Parameter: PolarFigure_update_rate
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  int32_T BodyFramePolarPlot_zero_locatio;
                              /* Mask Parameter: BodyFramePolarPlot_zero_locatio
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  int32_T PolarFigure_zero_location;/* Mask Parameter: PolarFigure_zero_location
                                     * Referenced by: '<Root>/Polar Figure'
                                     */
  real_T RangingSensor1_Budget;        /* Expression: timing_budget
                                        * Referenced by: '<S3>/Ranging Sensor1'
                                        */
  real_T RangingSensor1_Period;        /* Expression: measurement_period
                                        * Referenced by: '<S3>/Ranging Sensor1'
                                        */
  real_T RangingSensor1_MaxInterpolation;/* Expression: max_interpolated_distance
                                          * Referenced by: '<S3>/Ranging Sensor1'
                                          */
  real_T RangingSensor1_MaxInterpolati_f;/* Expression: max_interpolated_angle
                                          * Referenced by: '<S3>/Ranging Sensor1'
                                          */
  real_T Constant1_Value[720];         /* Expression: pi*(0:0.5:359.95)/180
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T BodyFramePolarPlot_L1Width;   /* Expression: line1_width
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L1Color[3];/* Expression: line1_color
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L1MSize;   /* Expression: marker1_size
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L1MEdgeColor[3];/* Expression: marker1_edge_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L1MFaceColor[3];/* Expression: marker1_face_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L2Width;   /* Expression: line2_width
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L2Color[3];/* Expression: line2_color
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L2MSize;   /* Expression: marker2_size
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L2MEdgeColor[3];/* Expression: marker2_edge_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L2MFaceColor[3];/* Expression: marker2_face_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L3Width;   /* Expression: line3_width
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L3Color[3];/* Expression: line3_color
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L3MSize;   /* Expression: marker3_size
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L3MEdgeColor[3];/* Expression: marker3_edge_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L3MFaceColor[3];/* Expression: marker3_face_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L4Width;   /* Expression: line4_width
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L4Color[3];/* Expression: line4_color
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L4MSize;   /* Expression: marker4_size
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L4MEdgeColor[3];/* Expression: marker4_edge_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L4MFaceColor[3];/* Expression: marker4_face_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L5Width;   /* Expression: line5_width
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L5Color[3];/* Expression: line5_color
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L5MSize;   /* Expression: marker5_size
                                        * Referenced by: '<Root>/Body Frame  Polar Plot'
                                        */
  real_T BodyFramePolarPlot_L5MEdgeColor[3];/* Expression: marker5_edge_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T BodyFramePolarPlot_L5MFaceColor[3];/* Expression: marker5_face_color
                                             * Referenced by: '<Root>/Body Frame  Polar Plot'
                                             */
  real_T PolarFigure_L1Width;          /* Expression: line1_width
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L1Color[3];       /* Expression: line1_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L1MSize;          /* Expression: marker1_size
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L1MEdgeColor[3];  /* Expression: marker1_edge_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L1MFaceColor[3];  /* Expression: marker1_face_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L2Width;          /* Expression: line2_width
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L2Color[3];       /* Expression: line2_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L2MSize;          /* Expression: marker2_size
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L2MEdgeColor[3];  /* Expression: marker2_edge_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L2MFaceColor[3];  /* Expression: marker2_face_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L3Width;          /* Expression: line3_width
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L3Color[3];       /* Expression: line3_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L3MSize;          /* Expression: marker3_size
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L3MEdgeColor[3];  /* Expression: marker3_edge_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L3MFaceColor[3];  /* Expression: marker3_face_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L4Width;          /* Expression: line4_width
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L4Color[3];       /* Expression: line4_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L4MSize;          /* Expression: marker4_size
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L4MEdgeColor[3];  /* Expression: marker4_edge_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L4MFaceColor[3];  /* Expression: marker4_face_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L5Width;          /* Expression: line5_width
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L5Color[3];       /* Expression: line5_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L5MSize;          /* Expression: marker5_size
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L5MEdgeColor[3];  /* Expression: marker5_edge_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T PolarFigure_L5MFaceColor[3];  /* Expression: marker5_face_color
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
  real_T maximumDistancem_Value;       /* Expression: 4
                                        * Referenced by: '<S5>/maximumDistance (m)'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T decay_Value;                  /* Expression: 0.9
                                        * Referenced by: '<S5>/decay'
                                        */
  real_T Constant_Value;               /* Expression: qc_get_step_size
                                        * Referenced by: '<S4>/Constant'
                                        */
  int32_T BodyFramePolarPlot_L1Style;
                               /* Computed Parameter: BodyFramePolarPlot_L1Style
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  int32_T BodyFramePolarPlot_L1Marker;
                              /* Computed Parameter: BodyFramePolarPlot_L1Marker
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  int32_T BodyFramePolarPlot_L2Style;
                               /* Computed Parameter: BodyFramePolarPlot_L2Style
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  int32_T BodyFramePolarPlot_L2Marker;
                              /* Computed Parameter: BodyFramePolarPlot_L2Marker
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  int32_T BodyFramePolarPlot_L3Style;
                               /* Computed Parameter: BodyFramePolarPlot_L3Style
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  int32_T BodyFramePolarPlot_L3Marker;
                              /* Computed Parameter: BodyFramePolarPlot_L3Marker
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  int32_T BodyFramePolarPlot_L4Style;
                               /* Computed Parameter: BodyFramePolarPlot_L4Style
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  int32_T BodyFramePolarPlot_L4Marker;
                              /* Computed Parameter: BodyFramePolarPlot_L4Marker
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  int32_T BodyFramePolarPlot_L5Style;
                               /* Computed Parameter: BodyFramePolarPlot_L5Style
                                * Referenced by: '<Root>/Body Frame  Polar Plot'
                                */
  int32_T BodyFramePolarPlot_L5Marker;
                              /* Computed Parameter: BodyFramePolarPlot_L5Marker
                               * Referenced by: '<Root>/Body Frame  Polar Plot'
                               */
  int32_T PolarFigure_L1Style;        /* Computed Parameter: PolarFigure_L1Style
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  int32_T PolarFigure_L1Marker;      /* Computed Parameter: PolarFigure_L1Marker
                                      * Referenced by: '<Root>/Polar Figure'
                                      */
  int32_T PolarFigure_L2Style;        /* Computed Parameter: PolarFigure_L2Style
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  int32_T PolarFigure_L2Marker;      /* Computed Parameter: PolarFigure_L2Marker
                                      * Referenced by: '<Root>/Polar Figure'
                                      */
  int32_T PolarFigure_L3Style;        /* Computed Parameter: PolarFigure_L3Style
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  int32_T PolarFigure_L3Marker;      /* Computed Parameter: PolarFigure_L3Marker
                                      * Referenced by: '<Root>/Polar Figure'
                                      */
  int32_T PolarFigure_L4Style;        /* Computed Parameter: PolarFigure_L4Style
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  int32_T PolarFigure_L4Marker;      /* Computed Parameter: PolarFigure_L4Marker
                                      * Referenced by: '<Root>/Polar Figure'
                                      */
  int32_T PolarFigure_L5Style;        /* Computed Parameter: PolarFigure_L5Style
                                       * Referenced by: '<Root>/Polar Figure'
                                       */
  int32_T PolarFigure_L5Marker;      /* Computed Parameter: PolarFigure_L5Marker
                                      * Referenced by: '<Root>/Polar Figure'
                                      */
  uint32_T RangingSensor1_Range;     /* Computed Parameter: RangingSensor1_Range
                                      * Referenced by: '<S3>/Ranging Sensor1'
                                      */
  boolean_T RangingSensor1_Active;  /* Computed Parameter: RangingSensor1_Active
                                     * Referenced by: '<S3>/Ranging Sensor1'
                                     */
  boolean_T VideoDisplay_UseHardware;
                                 /* Computed Parameter: VideoDisplay_UseHardware
                                  * Referenced by: '<Root>/Video Display'
                                  */
  uint8_T BodyFramePolarPlot_Mode;/* Computed Parameter: BodyFramePolarPlot_Mode
                                   * Referenced by: '<Root>/Body Frame  Polar Plot'
                                   */
  uint8_T PolarFigure_Mode;            /* Computed Parameter: PolarFigure_Mode
                                        * Referenced by: '<Root>/Polar Figure'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Lidar_Point_Cloud_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Lidar_Point_Cloud_T Lidar_Point_Cloud_P;

/* Block signals (default storage) */
extern B_Lidar_Point_Cloud_T Lidar_Point_Cloud_B;

/* Block states (default storage) */
extern DW_Lidar_Point_Cloud_T Lidar_Point_Cloud_DW;

/* Model entry point functions */
extern void Lidar_Point_Cloud_initialize(void);
extern void Lidar_Point_Cloud_output(void);
extern void Lidar_Point_Cloud_update(void);
extern void Lidar_Point_Cloud_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Lidar_Point_Cloud_rtModel *Lidar_Point_Cloud(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Lidar_Point_Cloud_T *const Lidar_Point_Cloud_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Lidar_Point_Cloud'
 * '<S1>'   : 'Lidar_Point_Cloud/Powered by QUARC'
 * '<S2>'   : 'Lidar_Point_Cloud/Quanser'
 * '<S3>'   : 'Lidar_Point_Cloud/captureLIDAR'
 * '<S4>'   : 'Lidar_Point_Cloud/monitorTiming '
 * '<S5>'   : 'Lidar_Point_Cloud/pointCloud'
 * '<S6>'   : 'Lidar_Point_Cloud/captureLIDAR/MATLAB Function'
 * '<S7>'   : 'Lidar_Point_Cloud/pointCloud/Saturation Dynamic'
 * '<S8>'   : 'Lidar_Point_Cloud/pointCloud/contourToPointCloud'
 * '<S9>'   : 'Lidar_Point_Cloud/pointCloud/findXYContour'
 */
#endif                                 /* RTW_HEADER_Lidar_Point_Cloud_h_ */
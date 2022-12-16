/*
 * Imaging_360.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Imaging_360".
 *
 * Model version              : 5.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 24 08:57:03 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Imaging_360_h_
#define RTW_HEADER_Imaging_360_h_
#include <string.h>
#ifndef Imaging_360_COMMON_INCLUDES_
#define Imaging_360_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_messages.h"
#include "quanser_memory.h"
#include "quanser_channel.h"
#include "extmode_support.h"
#include "quanser_time.h"
#include "quanser_extern.h"
#include "quanser_video.h"
#include "quanser_string.h"
#endif                                 /* Imaging_360_COMMON_INCLUDES_ */

#include "Imaging_360_types.h"

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
#define Imaging_360_rtModel            RT_MODEL_Imaging_360_T

/* Block signals (default storage) */
typedef struct {
  real_T actualsampletime;             /* '<S5>/Sample Time' */
  real_T reference;                    /* '<S5>/Constant' */
  real_T computationtime;              /* '<S5>/Computation Time' */
  t_channel Channel;                   /* '<S4>/Channel' */
  uint8_T VideoCapture_o1[921600];     /* '<S3>/Video Capture' */
  uint8_T VideoCapture1_o1[921600];    /* '<S3>/Video Capture1' */
  uint8_T VideoCapture2_o1[921600];    /* '<S3>/Video Capture2' */
  uint8_T VideoCapture3_o1[921600];    /* '<S3>/Video Capture3' */
  uint8_T MatrixConcatenate[3686400];  /* '<S6>/Matrix Concatenate' */
} B_Imaging_360_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_timeout SampleTime_PreviousTime;   /* '<S5>/Sample Time' */
  t_timeout ComputationTime_BeginTime; /* '<S5>/Computation Time' */
  t_timeout ComputationTime_ComputationTime;/* '<S5>/Computation Time' */
  t_video_capture VideoCapture_VideoCapture;/* '<S3>/Video Capture' */
  t_video_capture VideoCapture1_VideoCapture;/* '<S3>/Video Capture1' */
  t_video_capture VideoCapture2_VideoCapture;/* '<S3>/Video Capture2' */
  t_video_capture VideoCapture3_VideoCapture;/* '<S3>/Video Capture3' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *Fifo;
  } Channel_PWORK;                     /* '<S4>/Channel' */

  int8_T stich_SubsysRanBC;            /* '<Root>/stich' */
  int8_T display_SubsysRanBC;          /* '<Root>/display' */
} DW_Imaging_360_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Imaging_360_B
#define BlockIO                        B_Imaging_360_T
#define rtP                            Imaging_360_P
#define Parameters                     P_Imaging_360_T
#define rtDWork                        Imaging_360_DW
#define D_Work                         DW_Imaging_360_T

/* Parameters (default storage) */
struct P_Imaging_360_T_ {
  real_T Constant_Value;               /* Expression: qc_get_step_size
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T VideoCapture_Brightness;      /* Expression: d_brightness
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Contrast;        /* Expression: d_contrast
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Hue;             /* Expression: d_hue
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Saturation;      /* Expression: d_saturation
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Sharpness;       /* Expression: d_sharpness
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Gamma;           /* Expression: d_gamma
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_ColorEnable;     /* Expression: d_coloreffect
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_WhiteBalance;    /* Expression: d_whitebalance
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_BacklightCompensat;/* Expression: d_backlightcompensation
                                          * Referenced by: '<S3>/Video Capture'
                                          */
  real_T VideoCapture_Gain;            /* Expression: d_gain
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Pan;             /* Expression: d_pan
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Tilt;            /* Expression: d_tilt
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Roll;            /* Expression: d_roll
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Zoom;            /* Expression: d_zoom
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Exposure;        /* Expression: d_exposure
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Iris;            /* Expression: d_iris
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture_Focus;           /* Expression: d_focus
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  real_T VideoCapture1_Brightness;     /* Expression: d_brightness
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Contrast;       /* Expression: d_contrast
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Hue;            /* Expression: d_hue
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Saturation;     /* Expression: d_saturation
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Sharpness;      /* Expression: d_sharpness
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Gamma;          /* Expression: d_gamma
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_ColorEnable;    /* Expression: d_coloreffect
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_WhiteBalance;   /* Expression: d_whitebalance
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_BacklightCompensa;/* Expression: d_backlightcompensation
                                          * Referenced by: '<S3>/Video Capture1'
                                          */
  real_T VideoCapture1_Gain;           /* Expression: d_gain
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Pan;            /* Expression: d_pan
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Tilt;           /* Expression: d_tilt
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Roll;           /* Expression: d_roll
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Zoom;           /* Expression: d_zoom
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Exposure;       /* Expression: d_exposure
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Iris;           /* Expression: d_iris
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture1_Focus;          /* Expression: d_focus
                                        * Referenced by: '<S3>/Video Capture1'
                                        */
  real_T VideoCapture2_Brightness;     /* Expression: d_brightness
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Contrast;       /* Expression: d_contrast
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Hue;            /* Expression: d_hue
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Saturation;     /* Expression: d_saturation
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Sharpness;      /* Expression: d_sharpness
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Gamma;          /* Expression: d_gamma
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_ColorEnable;    /* Expression: d_coloreffect
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_WhiteBalance;   /* Expression: d_whitebalance
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_BacklightCompensa;/* Expression: d_backlightcompensation
                                          * Referenced by: '<S3>/Video Capture2'
                                          */
  real_T VideoCapture2_Gain;           /* Expression: d_gain
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Pan;            /* Expression: d_pan
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Tilt;           /* Expression: d_tilt
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Roll;           /* Expression: d_roll
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Zoom;           /* Expression: d_zoom
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Exposure;       /* Expression: d_exposure
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Iris;           /* Expression: d_iris
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture2_Focus;          /* Expression: d_focus
                                        * Referenced by: '<S3>/Video Capture2'
                                        */
  real_T VideoCapture3_Brightness;     /* Expression: d_brightness
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Contrast;       /* Expression: d_contrast
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Hue;            /* Expression: d_hue
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Saturation;     /* Expression: d_saturation
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Sharpness;      /* Expression: d_sharpness
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Gamma;          /* Expression: d_gamma
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_ColorEnable;    /* Expression: d_coloreffect
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_WhiteBalance;   /* Expression: d_whitebalance
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_BacklightCompensa;/* Expression: d_backlightcompensation
                                          * Referenced by: '<S3>/Video Capture3'
                                          */
  real_T VideoCapture3_Gain;           /* Expression: d_gain
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Pan;            /* Expression: d_pan
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Tilt;           /* Expression: d_tilt
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Roll;           /* Expression: d_roll
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Zoom;           /* Expression: d_zoom
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Exposure;       /* Expression: d_exposure
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Iris;           /* Expression: d_iris
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  real_T VideoCapture3_Focus;          /* Expression: d_focus
                                        * Referenced by: '<S3>/Video Capture3'
                                        */
  boolean_T VideoDisplay_UseHardware;
                                 /* Computed Parameter: VideoDisplay_UseHardware
                                  * Referenced by: '<S4>/Video Display'
                                  */
  boolean_T VideoCapture_OvBrightness;
                                /* Computed Parameter: VideoCapture_OvBrightness
                                 * Referenced by: '<S3>/Video Capture'
                                 */
  boolean_T VideoCapture_OvContrast;
                                  /* Computed Parameter: VideoCapture_OvContrast
                                   * Referenced by: '<S3>/Video Capture'
                                   */
  boolean_T VideoCapture_OvHue;        /* Computed Parameter: VideoCapture_OvHue
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  boolean_T VideoCapture_OvSaturation;
                                /* Computed Parameter: VideoCapture_OvSaturation
                                 * Referenced by: '<S3>/Video Capture'
                                 */
  boolean_T VideoCapture_OvSharpness;
                                 /* Computed Parameter: VideoCapture_OvSharpness
                                  * Referenced by: '<S3>/Video Capture'
                                  */
  boolean_T VideoCapture_OvGamma;    /* Computed Parameter: VideoCapture_OvGamma
                                      * Referenced by: '<S3>/Video Capture'
                                      */
  boolean_T VideoCapture_OvColorEnable;
                               /* Computed Parameter: VideoCapture_OvColorEnable
                                * Referenced by: '<S3>/Video Capture'
                                */
  boolean_T VideoCapture_OvWhiteBalance;
                              /* Computed Parameter: VideoCapture_OvWhiteBalance
                               * Referenced by: '<S3>/Video Capture'
                               */
  boolean_T VideoCapture_OvBacklightCompens;
                          /* Computed Parameter: VideoCapture_OvBacklightCompens
                           * Referenced by: '<S3>/Video Capture'
                           */
  boolean_T VideoCapture_OvGain;      /* Computed Parameter: VideoCapture_OvGain
                                       * Referenced by: '<S3>/Video Capture'
                                       */
  boolean_T VideoCapture_OvPan;        /* Computed Parameter: VideoCapture_OvPan
                                        * Referenced by: '<S3>/Video Capture'
                                        */
  boolean_T VideoCapture_OvTilt;      /* Computed Parameter: VideoCapture_OvTilt
                                       * Referenced by: '<S3>/Video Capture'
                                       */
  boolean_T VideoCapture_OvRoll;      /* Computed Parameter: VideoCapture_OvRoll
                                       * Referenced by: '<S3>/Video Capture'
                                       */
  boolean_T VideoCapture_OvZoom;      /* Computed Parameter: VideoCapture_OvZoom
                                       * Referenced by: '<S3>/Video Capture'
                                       */
  boolean_T VideoCapture_OvExposure;
                                  /* Computed Parameter: VideoCapture_OvExposure
                                   * Referenced by: '<S3>/Video Capture'
                                   */
  boolean_T VideoCapture_OvIris;      /* Computed Parameter: VideoCapture_OvIris
                                       * Referenced by: '<S3>/Video Capture'
                                       */
  boolean_T VideoCapture_OvFocus;    /* Computed Parameter: VideoCapture_OvFocus
                                      * Referenced by: '<S3>/Video Capture'
                                      */
  boolean_T VideoCapture1_OvBrightness;
                               /* Computed Parameter: VideoCapture1_OvBrightness
                                * Referenced by: '<S3>/Video Capture1'
                                */
  boolean_T VideoCapture1_OvContrast;
                                 /* Computed Parameter: VideoCapture1_OvContrast
                                  * Referenced by: '<S3>/Video Capture1'
                                  */
  boolean_T VideoCapture1_OvHue;      /* Computed Parameter: VideoCapture1_OvHue
                                       * Referenced by: '<S3>/Video Capture1'
                                       */
  boolean_T VideoCapture1_OvSaturation;
                               /* Computed Parameter: VideoCapture1_OvSaturation
                                * Referenced by: '<S3>/Video Capture1'
                                */
  boolean_T VideoCapture1_OvSharpness;
                                /* Computed Parameter: VideoCapture1_OvSharpness
                                 * Referenced by: '<S3>/Video Capture1'
                                 */
  boolean_T VideoCapture1_OvGamma;  /* Computed Parameter: VideoCapture1_OvGamma
                                     * Referenced by: '<S3>/Video Capture1'
                                     */
  boolean_T VideoCapture1_OvColorEnable;
                              /* Computed Parameter: VideoCapture1_OvColorEnable
                               * Referenced by: '<S3>/Video Capture1'
                               */
  boolean_T VideoCapture1_OvWhiteBalance;
                             /* Computed Parameter: VideoCapture1_OvWhiteBalance
                              * Referenced by: '<S3>/Video Capture1'
                              */
  boolean_T VideoCapture1_OvBacklightCompen;
                          /* Computed Parameter: VideoCapture1_OvBacklightCompen
                           * Referenced by: '<S3>/Video Capture1'
                           */
  boolean_T VideoCapture1_OvGain;    /* Computed Parameter: VideoCapture1_OvGain
                                      * Referenced by: '<S3>/Video Capture1'
                                      */
  boolean_T VideoCapture1_OvPan;      /* Computed Parameter: VideoCapture1_OvPan
                                       * Referenced by: '<S3>/Video Capture1'
                                       */
  boolean_T VideoCapture1_OvTilt;    /* Computed Parameter: VideoCapture1_OvTilt
                                      * Referenced by: '<S3>/Video Capture1'
                                      */
  boolean_T VideoCapture1_OvRoll;    /* Computed Parameter: VideoCapture1_OvRoll
                                      * Referenced by: '<S3>/Video Capture1'
                                      */
  boolean_T VideoCapture1_OvZoom;    /* Computed Parameter: VideoCapture1_OvZoom
                                      * Referenced by: '<S3>/Video Capture1'
                                      */
  boolean_T VideoCapture1_OvExposure;
                                 /* Computed Parameter: VideoCapture1_OvExposure
                                  * Referenced by: '<S3>/Video Capture1'
                                  */
  boolean_T VideoCapture1_OvIris;    /* Computed Parameter: VideoCapture1_OvIris
                                      * Referenced by: '<S3>/Video Capture1'
                                      */
  boolean_T VideoCapture1_OvFocus;  /* Computed Parameter: VideoCapture1_OvFocus
                                     * Referenced by: '<S3>/Video Capture1'
                                     */
  boolean_T VideoCapture2_OvBrightness;
                               /* Computed Parameter: VideoCapture2_OvBrightness
                                * Referenced by: '<S3>/Video Capture2'
                                */
  boolean_T VideoCapture2_OvContrast;
                                 /* Computed Parameter: VideoCapture2_OvContrast
                                  * Referenced by: '<S3>/Video Capture2'
                                  */
  boolean_T VideoCapture2_OvHue;      /* Computed Parameter: VideoCapture2_OvHue
                                       * Referenced by: '<S3>/Video Capture2'
                                       */
  boolean_T VideoCapture2_OvSaturation;
                               /* Computed Parameter: VideoCapture2_OvSaturation
                                * Referenced by: '<S3>/Video Capture2'
                                */
  boolean_T VideoCapture2_OvSharpness;
                                /* Computed Parameter: VideoCapture2_OvSharpness
                                 * Referenced by: '<S3>/Video Capture2'
                                 */
  boolean_T VideoCapture2_OvGamma;  /* Computed Parameter: VideoCapture2_OvGamma
                                     * Referenced by: '<S3>/Video Capture2'
                                     */
  boolean_T VideoCapture2_OvColorEnable;
                              /* Computed Parameter: VideoCapture2_OvColorEnable
                               * Referenced by: '<S3>/Video Capture2'
                               */
  boolean_T VideoCapture2_OvWhiteBalance;
                             /* Computed Parameter: VideoCapture2_OvWhiteBalance
                              * Referenced by: '<S3>/Video Capture2'
                              */
  boolean_T VideoCapture2_OvBacklightCompen;
                          /* Computed Parameter: VideoCapture2_OvBacklightCompen
                           * Referenced by: '<S3>/Video Capture2'
                           */
  boolean_T VideoCapture2_OvGain;    /* Computed Parameter: VideoCapture2_OvGain
                                      * Referenced by: '<S3>/Video Capture2'
                                      */
  boolean_T VideoCapture2_OvPan;      /* Computed Parameter: VideoCapture2_OvPan
                                       * Referenced by: '<S3>/Video Capture2'
                                       */
  boolean_T VideoCapture2_OvTilt;    /* Computed Parameter: VideoCapture2_OvTilt
                                      * Referenced by: '<S3>/Video Capture2'
                                      */
  boolean_T VideoCapture2_OvRoll;    /* Computed Parameter: VideoCapture2_OvRoll
                                      * Referenced by: '<S3>/Video Capture2'
                                      */
  boolean_T VideoCapture2_OvZoom;    /* Computed Parameter: VideoCapture2_OvZoom
                                      * Referenced by: '<S3>/Video Capture2'
                                      */
  boolean_T VideoCapture2_OvExposure;
                                 /* Computed Parameter: VideoCapture2_OvExposure
                                  * Referenced by: '<S3>/Video Capture2'
                                  */
  boolean_T VideoCapture2_OvIris;    /* Computed Parameter: VideoCapture2_OvIris
                                      * Referenced by: '<S3>/Video Capture2'
                                      */
  boolean_T VideoCapture2_OvFocus;  /* Computed Parameter: VideoCapture2_OvFocus
                                     * Referenced by: '<S3>/Video Capture2'
                                     */
  boolean_T VideoCapture3_OvBrightness;
                               /* Computed Parameter: VideoCapture3_OvBrightness
                                * Referenced by: '<S3>/Video Capture3'
                                */
  boolean_T VideoCapture3_OvContrast;
                                 /* Computed Parameter: VideoCapture3_OvContrast
                                  * Referenced by: '<S3>/Video Capture3'
                                  */
  boolean_T VideoCapture3_OvHue;      /* Computed Parameter: VideoCapture3_OvHue
                                       * Referenced by: '<S3>/Video Capture3'
                                       */
  boolean_T VideoCapture3_OvSaturation;
                               /* Computed Parameter: VideoCapture3_OvSaturation
                                * Referenced by: '<S3>/Video Capture3'
                                */
  boolean_T VideoCapture3_OvSharpness;
                                /* Computed Parameter: VideoCapture3_OvSharpness
                                 * Referenced by: '<S3>/Video Capture3'
                                 */
  boolean_T VideoCapture3_OvGamma;  /* Computed Parameter: VideoCapture3_OvGamma
                                     * Referenced by: '<S3>/Video Capture3'
                                     */
  boolean_T VideoCapture3_OvColorEnable;
                              /* Computed Parameter: VideoCapture3_OvColorEnable
                               * Referenced by: '<S3>/Video Capture3'
                               */
  boolean_T VideoCapture3_OvWhiteBalance;
                             /* Computed Parameter: VideoCapture3_OvWhiteBalance
                              * Referenced by: '<S3>/Video Capture3'
                              */
  boolean_T VideoCapture3_OvBacklightCompen;
                          /* Computed Parameter: VideoCapture3_OvBacklightCompen
                           * Referenced by: '<S3>/Video Capture3'
                           */
  boolean_T VideoCapture3_OvGain;    /* Computed Parameter: VideoCapture3_OvGain
                                      * Referenced by: '<S3>/Video Capture3'
                                      */
  boolean_T VideoCapture3_OvPan;      /* Computed Parameter: VideoCapture3_OvPan
                                       * Referenced by: '<S3>/Video Capture3'
                                       */
  boolean_T VideoCapture3_OvTilt;    /* Computed Parameter: VideoCapture3_OvTilt
                                      * Referenced by: '<S3>/Video Capture3'
                                      */
  boolean_T VideoCapture3_OvRoll;    /* Computed Parameter: VideoCapture3_OvRoll
                                      * Referenced by: '<S3>/Video Capture3'
                                      */
  boolean_T VideoCapture3_OvZoom;    /* Computed Parameter: VideoCapture3_OvZoom
                                      * Referenced by: '<S3>/Video Capture3'
                                      */
  boolean_T VideoCapture3_OvExposure;
                                 /* Computed Parameter: VideoCapture3_OvExposure
                                  * Referenced by: '<S3>/Video Capture3'
                                  */
  boolean_T VideoCapture3_OvIris;    /* Computed Parameter: VideoCapture3_OvIris
                                      * Referenced by: '<S3>/Video Capture3'
                                      */
  boolean_T VideoCapture3_OvFocus;  /* Computed Parameter: VideoCapture3_OvFocus
                                     * Referenced by: '<S3>/Video Capture3'
                                     */
  uint8_T u60view_Y0;                  /* Computed Parameter: u60view_Y0
                                        * Referenced by: '<S6>/360 view'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Imaging_360_T {
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
extern P_Imaging_360_T Imaging_360_P;

/* Block signals (default storage) */
extern B_Imaging_360_T Imaging_360_B;

/* Block states (default storage) */
extern DW_Imaging_360_T Imaging_360_DW;

/* Model entry point functions */
extern void Imaging_360_initialize(void);
extern void Imaging_360_output(void);
extern void Imaging_360_update(void);
extern void Imaging_360_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Imaging_360_rtModel *Imaging_360(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Imaging_360_T *const Imaging_360_M;

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
 * '<Root>' : 'Imaging_360'
 * '<S1>'   : 'Imaging_360/Powered by QUARC'
 * '<S2>'   : 'Imaging_360/Quanser'
 * '<S3>'   : 'Imaging_360/capture360'
 * '<S4>'   : 'Imaging_360/display'
 * '<S5>'   : 'Imaging_360/monitorTiming '
 * '<S6>'   : 'Imaging_360/stich'
 */
#endif                                 /* RTW_HEADER_Imaging_360_h_ */

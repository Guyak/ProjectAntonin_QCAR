/*
 * RGBD_Imaging.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RGBD_Imaging".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 17 17:29:53 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RGBD_Imaging_h_
#define RTW_HEADER_RGBD_Imaging_h_
#include <math.h>
#include <string.h>
#ifndef RGBD_Imaging_COMMON_INCLUDES_
#define RGBD_Imaging_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_image_processing.h"
#include "quanser_messages.h"
#include "quanser_memory.h"
#include "quanser_channel.h"
#include "extmode_support.h"
#include "quanser_video3d.h"
#include "quanser_string.h"
#include "quanser_types.h"
#include "quanser_time.h"
#include "quanser_extern.h"
#endif                                 /* RGBD_Imaging_COMMON_INCLUDES_ */

#include "RGBD_Imaging_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

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
#define rtmGetFirstInitCondFlag(rtm)   ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
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

#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
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
#define RGBD_Imaging_rtModel           RT_MODEL_RGBD_Imaging_T

/* Block signals (default storage) */
typedef struct {
  t_uint64 Depth_o2;                   /* '<S3>/Depth' */
  t_uint64 RGB_o2;                     /* '<S3>/RGB' */
  real_T Depth_o3;                     /* '<S3>/Depth' */
  real_T RGB_o3;                       /* '<S3>/RGB' */
  real_T actualsampletime;             /* '<S6>/Sample Time' */
  real_T reference;                    /* '<S6>/Constant' */
  real_T computationtime;              /* '<S6>/Computation Time' */
  real_T Constant;                     /* '<S5>/Constant' */
  real_T Subtract[2];                  /* '<S5>/Subtract' */
  t_channel Channel;                   /* '<S8>/Channel' */
  t_channel Channel_o;                 /* '<S10>/Channel' */
  t_channel Channel_a;                 /* '<S7>/Channel' */
  real32_T Depth_o1[921600];           /* '<S3>/Depth' */
  real32_T Selector;                   /* '<S4>/Selector' */
  uint8_T RGB_o1[2764800];             /* '<S3>/RGB' */
  uint8_T ImageCompress[921600];       /* '<S8>/Image Compress' */
  uint8_T ImageCompress_g[2764800];    /* '<S10>/Image Compress' */
  uint8_T ImageTransform[2764800];     /* '<S11>/Image Transform' */
  uint8_T ImageCompress_c[921600];     /* '<S7>/Image Compress' */
  uint8_T HSVColorThresholding[921600];/* '<S11>/HSV Color Thresholding' */
  boolean_T RGB_o4;                    /* '<S3>/RGB' */
  boolean_T Compare;                   /* '<S9>/Compare' */
} B_RGBD_Imaging_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_timeout SampleTime_PreviousTime;   /* '<S6>/Sample Time' */
  t_timeout ComputationTime_BeginTime; /* '<S6>/Computation Time' */
  t_timeout ComputationTime_ComputationTime;/* '<S6>/Computation Time' */
  t_video3d Video3DInitialize_Video3D; /* '<S3>/Video3D Initialize' */
  t_video3d Depth_Video3D;             /* '<S3>/Depth' */
  t_video3d RGB_Video3D;               /* '<S3>/RGB' */
  t_video3d_stream Depth_Stream;       /* '<S3>/Depth' */
  t_video3d_stream RGB_Stream;         /* '<S3>/RGB' */
  t_jpeg_compress ImageCompress_Compress;/* '<S8>/Image Compress' */
  t_jpeg_compress ImageCompress_Compress_c;/* '<S10>/Image Compress' */
  t_jpeg_compress ImageCompress_Compress_g;/* '<S7>/Image Compress' */
  t_find_blobs ImageFindObjects_FindHandle;/* '<S5>/Image Find Objects' */
  t_image_rgb_to_hsv ImageTransform_AlgHandle;/* '<S11>/Image Transform' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *Fifo;
  } Channel_PWORK;                     /* '<S8>/Channel' */

  struct {
    void *Fifo;
  } Channel_PWORK_d;                   /* '<S10>/Channel' */

  struct {
    void *Fifo;
  } Channel_PWORK_f;                   /* '<S7>/Channel' */

  int32_T ImageCompress_DIMS1;         /* '<S8>/Image Compress' */
  int32_T ImageCompress_DIMS1_l;       /* '<S10>/Image Compress' */
  int32_T ImageCompress_DIMS1_e;       /* '<S7>/Image Compress' */
  int8_T findStopSignLocation_SubsysRanB;/* '<Root>/findStopSignLocation' */
  int8_T findStopSignDistance_SubsysRanB;/* '<Root>/findStopSignDistance' */
  uint8_T ImageCompress_ScanLine[10240];/* '<S8>/Image Compress' */
  uint8_T ImageCompress_ScanLine_a[30720];/* '<S10>/Image Compress' */
  uint8_T ImageCompress_ScanLine_c[10240];/* '<S7>/Image Compress' */
} DW_RGBD_Imaging_T;

/* Backward compatible GRT Identifiers */
#define rtB                            RGBD_Imaging_B
#define BlockIO                        B_RGBD_Imaging_T
#define rtP                            RGBD_Imaging_P
#define Parameters                     P_RGBD_Imaging_T
#define rtDWork                        RGBD_Imaging_DW
#define D_Work                         DW_RGBD_Imaging_T

/* Parameters (default storage) */
struct P_RGBD_Imaging_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S12>/Constant'
                                       */
  int32_T HSVColorThresholding_b_comparis;
                              /* Mask Parameter: HSVColorThresholding_b_comparis
                               * Referenced by: '<S11>/HSV Color Thresholding'
                               */
  int32_T ImageFindObjects_connectivity;
                                /* Mask Parameter: ImageFindObjects_connectivity
                                 * Referenced by: '<S5>/Image Find Objects'
                                 */
  int32_T HSVColorThresholding_g_comparis;
                              /* Mask Parameter: HSVColorThresholding_g_comparis
                               * Referenced by: '<S11>/HSV Color Thresholding'
                               */
  int32_T HSVColorThresholding_r_comparis;
                              /* Mask Parameter: HSVColorThresholding_r_comparis
                               * Referenced by: '<S11>/HSV Color Thresholding'
                               */
  int32_T ImageFindObjects_sort_order;
                                  /* Mask Parameter: ImageFindObjects_sort_order
                                   * Referenced by: '<S5>/Image Find Objects'
                                   */
  uint32_T CompareToConstant_const_h;
                                    /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S9>/Constant'
                                     */
  uint32_T ImageFindObjects_max_pixels;
                                  /* Mask Parameter: ImageFindObjects_max_pixels
                                   * Referenced by: '<S5>/Image Find Objects'
                                   */
  uint32_T ImageFindObjects_min_pixels;
                                  /* Mask Parameter: ImageFindObjects_min_pixels
                                   * Referenced by: '<S5>/Image Find Objects'
                                   */
  uint32_T Depth_stream_index;         /* Mask Parameter: Depth_stream_index
                                        * Referenced by: '<S3>/Depth'
                                        */
  uint32_T RGB_stream_index;           /* Mask Parameter: RGB_stream_index
                                        * Referenced by: '<S3>/RGB'
                                        */
  boolean_T Video3DInitialize_active;/* Mask Parameter: Video3DInitialize_active
                                      * Referenced by: '<S3>/Video3D Initialize'
                                      */
  boolean_T ImageFindObjects_exclude_at_edg;
                              /* Mask Parameter: ImageFindObjects_exclude_at_edg
                               * Referenced by: '<S5>/Image Find Objects'
                               */
  boolean_T ImageFindObjects_largest;/* Mask Parameter: ImageFindObjects_largest
                                      * Referenced by: '<S5>/Image Find Objects'
                                      */
  real_T Constant_Value;               /* Expression: 720/2
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T AdjustforVFOV_Gain;           /* Expression: 42.5/57
                                        * Referenced by: '<S4>/Adjust for V-FOV'
                                        */
  real_T AdjustforHFOV_Gain;           /* Expression: 69.4/86
                                        * Referenced by: '<S4>/Adjust for H-FOV'
                                        */
  real_T Constant1_Value;              /* Expression: 1280/2
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 255
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T blobLocationpx2_Y0;           /* Computed Parameter: blobLocationpx2_Y0
                                        * Referenced by: '<S5>/blobLocation (px) [2]'
                                        */
  real_T ImageTransform_MinPixel;      /* Expression: min_pixel
                                        * Referenced by: '<S11>/Image Transform'
                                        */
  real_T ImageTransform_MaxPixel;      /* Expression: max_pixel
                                        * Referenced by: '<S11>/Image Transform'
                                        */
  real_T ImageTransform_FocalLen;      /* Expression: focal_length
                                        * Referenced by: '<S11>/Image Transform'
                                        */
  real_T ImageTransform_Extrapolated;  /* Expression: extrapolated
                                        * Referenced by: '<S11>/Image Transform'
                                        */
  real_T ImageTransform_Angle;         /* Expression: angle
                                        * Referenced by: '<S11>/Image Transform'
                                        */
  real_T ImageTransform_RCoeff[2];     /* Expression: radial_coeffs
                                        * Referenced by: '<S11>/Image Transform'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T HueThreshold_Value;           /* Expression: 20
                                        * Referenced by: '<S11>/Hue Threshold'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/360
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Constant1_Value_a[2];         /* Expression: [100, 100]
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value[2];           /* Expression: [255, 255]
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T HSVColorThresholding_Channel0Mi;/* Expression: r_min
                                          * Referenced by: '<S11>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel0Ma;/* Expression: r_max
                                          * Referenced by: '<S11>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel1Mi;/* Expression: g_min
                                          * Referenced by: '<S11>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel1Ma;/* Expression: g_max
                                          * Referenced by: '<S11>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel2Mi;/* Expression: b_min
                                          * Referenced by: '<S11>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel2Ma;/* Expression: b_max
                                          * Referenced by: '<S11>/HSV Color Thresholding'
                                          */
  real_T Constant3_Value[2];           /* Expression: [720/2, 1280/2]
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Depth_Brightness;             /* Expression: d_brightness
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Contrast;               /* Expression: d_contrast
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Hue;                    /* Expression: d_hue
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Saturation;             /* Expression: d_saturation
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Sharpness;              /* Expression: d_sharpness
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Gamma;                  /* Expression: d_gamma
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_WhiteBalance;           /* Expression: d_whitebalance
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_BacklightCompensation;  /* Expression: d_backlightcompensation
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Gain;                   /* Expression: d_gain
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Exposure;               /* Expression: d_exposure
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T Depth_Emitter;                /* Expression: emitter
                                        * Referenced by: '<S3>/Depth'
                                        */
  real_T RGB_Brightness;               /* Expression: d_brightness
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Contrast;                 /* Expression: d_contrast
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Hue;                      /* Expression: d_hue
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Saturation;               /* Expression: d_saturation
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Sharpness;                /* Expression: d_sharpness
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Gamma;                    /* Expression: d_gamma
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_WhiteBalance;             /* Expression: d_whitebalance
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_BacklightCompensation;    /* Expression: d_backlightcompensation
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Gain;                     /* Expression: d_gain
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Exposure;                 /* Expression: d_exposure
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T RGB_Emitter;                  /* Expression: emitter
                                        * Referenced by: '<S3>/RGB'
                                        */
  real_T Constant_Value_e;             /* Expression: qc_get_step_size
                                        * Referenced by: '<S6>/Constant'
                                        */
  int32_T ImageTransform_PrPoint[2];
                                   /* Computed Parameter: ImageTransform_PrPoint
                                    * Referenced by: '<S11>/Image Transform'
                                    */
  int32_T ImageTransform_Interpolation;
                             /* Computed Parameter: ImageTransform_Interpolation
                              * Referenced by: '<S11>/Image Transform'
                              */
  int32_T ImageTransform_Origin[2]; /* Computed Parameter: ImageTransform_Origin
                                     * Referenced by: '<S11>/Image Transform'
                                     */
  int32_T ImageTransform_OOrigin[2];
                                   /* Computed Parameter: ImageTransform_OOrigin
                                    * Referenced by: '<S11>/Image Transform'
                                    */
  real32_T distanceToSignm_Y0;         /* Computed Parameter: distanceToSignm_Y0
                                        * Referenced by: '<S4>/distanceToSign (m)'
                                        */
  uint32_T ImageCompress_Quality;   /* Computed Parameter: ImageCompress_Quality
                                     * Referenced by: '<S7>/Image Compress'
                                     */
  uint32_T ImageTransform_ColorTheme;
                                /* Computed Parameter: ImageTransform_ColorTheme
                                 * Referenced by: '<S11>/Image Transform'
                                 */
  uint32_T ImageCompress_Quality_o;
                                  /* Computed Parameter: ImageCompress_Quality_o
                                   * Referenced by: '<S8>/Image Compress'
                                   */
  uint32_T ImageCompress_Quality_f;
                                  /* Computed Parameter: ImageCompress_Quality_f
                                   * Referenced by: '<S10>/Image Compress'
                                   */
  uint32_T Depth_Preset;               /* Computed Parameter: Depth_Preset
                                        * Referenced by: '<S3>/Depth'
                                        */
  uint32_T RGB_Preset;                 /* Computed Parameter: RGB_Preset
                                        * Referenced by: '<S3>/RGB'
                                        */
  boolean_T VideoDisplay_UseHardware;
                                 /* Computed Parameter: VideoDisplay_UseHardware
                                  * Referenced by: '<S7>/Video Display'
                                  */
  boolean_T blobFound_Y0;              /* Computed Parameter: blobFound_Y0
                                        * Referenced by: '<S5>/blobFound?'
                                        */
  boolean_T VideoDisplay_UseHardware_g;
                               /* Computed Parameter: VideoDisplay_UseHardware_g
                                * Referenced by: '<S8>/Video Display'
                                */
  boolean_T VideoDisplay_UseHardware_d;
                               /* Computed Parameter: VideoDisplay_UseHardware_d
                                * Referenced by: '<S10>/Video Display'
                                */
};

/* Real-time Model Data Structure */
struct tag_RTM_RGBD_Imaging_T {
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
    boolean_T firstInitCondFlag;
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
extern P_RGBD_Imaging_T RGBD_Imaging_P;

/* Block signals (default storage) */
extern B_RGBD_Imaging_T RGBD_Imaging_B;

/* Block states (default storage) */
extern DW_RGBD_Imaging_T RGBD_Imaging_DW;

/* Model entry point functions */
extern void RGBD_Imaging_initialize(void);
extern void RGBD_Imaging_output(void);
extern void RGBD_Imaging_update(void);
extern void RGBD_Imaging_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern RGBD_Imaging_rtModel *RGBD_Imaging(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_RGBD_Imaging_T *const RGBD_Imaging_M;

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
 * '<Root>' : 'RGBD_Imaging'
 * '<S1>'   : 'RGBD_Imaging/Powered by QUARC'
 * '<S2>'   : 'RGBD_Imaging/Quanser'
 * '<S3>'   : 'RGBD_Imaging/captureRGBD'
 * '<S4>'   : 'RGBD_Imaging/findStopSignDistance'
 * '<S5>'   : 'RGBD_Imaging/findStopSignLocation'
 * '<S6>'   : 'RGBD_Imaging/monitorTiming '
 * '<S7>'   : 'RGBD_Imaging/findStopSignDistance/Depth Image (m)'
 * '<S8>'   : 'RGBD_Imaging/findStopSignLocation/Binary showing blob found'
 * '<S9>'   : 'RGBD_Imaging/findStopSignLocation/Compare To Constant'
 * '<S10>'  : 'RGBD_Imaging/findStopSignLocation/Raw RGB'
 * '<S11>'  : 'RGBD_Imaging/findStopSignLocation/colorThresholdingHSV'
 * '<S12>'  : 'RGBD_Imaging/findStopSignLocation/colorThresholdingHSV/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_RGBD_Imaging_h_ */

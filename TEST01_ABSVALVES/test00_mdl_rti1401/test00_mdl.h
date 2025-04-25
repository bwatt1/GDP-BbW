/*
 * test00_mdl.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test00_mdl".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Apr 23 19:06:31 2025
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef test00_mdl_h_
#define test00_mdl_h_
#ifndef test00_mdl_COMMON_INCLUDES_
#define test00_mdl_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rti_sim_engine_exp.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* test00_mdl_COMMON_INCLUDES_ */

#include "test00_mdl_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunction1;                   /* '<S1>/S-Function1' */
  real_T Add;                          /* '<Root>/Add' */
  real_T MathFunction;                 /* '<Root>/Math Function' */
  real_T SignalGenerator;              /* '<Root>/Signal Generator' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T MathFunction1;                /* '<Root>/Math Function1' */
} B_test00_mdl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_test00_mdl_T;

/* Parameters (default storage) */
struct P_test00_mdl_T_ {
  real_T Calib_Psens1_Offset_Value;    /* Expression: 1
                                        * Referenced by: '<Root>/Calib_Psens1_Offset'
                                        */
  real_T Calib_Psens1_Gradient_Gain;   /* Expression: 1
                                        * Referenced by: '<Root>/Calib_Psens1_Gradient'
                                        */
  real_T Ctrl_BValve_PWMFreq_Value;    /* Expression: 5
                                        * Referenced by: '<Root>/Ctrl_BValve_PWMFreq'
                                        */
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T SignalGenerator_Amplitude;    /* Expression: 0.5
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T SignalGenerator_Frequency;
                                /* Computed Parameter: SignalGenerator_Frequency
                                 * Referenced by: '<Root>/Signal Generator'
                                 */
  real_T Ctrl_DValve_PWMFreq_Value;    /* Expression: 5
                                        * Referenced by: '<Root>/Ctrl_DValve_PWMFreq'
                                        */
  real_T Ctrl_DValve_PWMDuty_Value;    /* Expression: 0
                                        * Referenced by: '<Root>/Ctrl_DValve_PWMDuty'
                                        */
  real_T Ctrl_MABx_StopCmd_Value;      /* Expression: 0
                                        * Referenced by: '<Root>/Ctrl_MABx_StopCmd'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test00_mdl_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_test00_mdl_T test00_mdl_P;

/* Block signals (default storage) */
extern B_test00_mdl_T test00_mdl_B;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_test00_mdl_T test00_mdl_Y;

/* Model entry point functions */
extern void test00_mdl_initialize(void);
extern void test00_mdl_output(void);
extern void test00_mdl_update(void);
extern void test00_mdl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test00_mdl_T *const test00_mdl_M;

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
 * '<Root>' : 'test00_mdl'
 * '<S1>'   : 'test00_mdl/ADC_TYPE4_BL1'
 * '<S2>'   : 'test00_mdl/DIO_TYPE3_PWM_BL1'
 * '<S3>'   : 'test00_mdl/DIO_TYPE3_PWM_BL2'
 * '<S4>'   : 'test00_mdl/DS1401_POWER_DOWN'
 * '<S5>'   : 'test00_mdl/RTI Data'
 * '<S6>'   : 'test00_mdl/RTI Data/RTI Data Store'
 * '<S7>'   : 'test00_mdl/RTI Data/RTI Data Store/RTI Data Store'
 * '<S8>'   : 'test00_mdl/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* test00_mdl_h_ */

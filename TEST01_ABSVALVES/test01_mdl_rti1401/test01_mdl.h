/*
 * test01_mdl.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test01_mdl".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Fri Apr 25 15:48:46 2025
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef test01_mdl_h_
#define test01_mdl_h_
#ifndef test01_mdl_COMMON_INCLUDES_
#define test01_mdl_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* test01_mdl_COMMON_INCLUDES_ */

#include "test01_mdl_types.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunction1;                   /* '<S1>/S-Function1' */
  real_T Add;                          /* '<Root>/Add' */
  real_T MathFunction;                 /* '<Root>/Math Function' */
  real_T MathFunction1;                /* '<Root>/Math Function1' */
  real_T MathFunction2;                /* '<Root>/Math Function2' */
  real_T MathFunction3;                /* '<Root>/Math Function3' */
} B_test01_mdl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_test01_mdl_T;

/* Parameters (default storage) */
struct P_test01_mdl_T_ {
  real_T Calib_Psens1_Offset_Value;    /* Expression: 0
                                        * Referenced by: '<Root>/Calib_Psens1_Offset'
                                        */
  real_T Calib_Psens1_Gradient_Gain;   /* Expression: 1
                                        * Referenced by: '<Root>/Calib_Psens1_Gradient'
                                        */
  real_T Ctrl_BValve1_PWMFreq_Value;   /* Expression: 100
                                        * Referenced by: '<Root>/Ctrl_BValve1_PWMFreq'
                                        */
  real_T Ctrl_BValve1_PWMDuty_Value;   /* Expression: 0
                                        * Referenced by: '<Root>/Ctrl_BValve1_PWMDuty'
                                        */
  real_T Ctrl_BValve2_PWMFreq_Value;   /* Expression: 100
                                        * Referenced by: '<Root>/Ctrl_BValve2_PWMFreq'
                                        */
  real_T Ctrl_BValve2_PWMDuty_Value;   /* Expression: 0
                                        * Referenced by: '<Root>/Ctrl_BValve2_PWMDuty'
                                        */
  real_T Ctrl_DValve1_PWMFreq_Value;   /* Expression: 100
                                        * Referenced by: '<Root>/Ctrl_DValve1_PWMFreq'
                                        */
  real_T Ctrl_DValve_PWMDuty_Value;    /* Expression: 0
                                        * Referenced by: '<Root>/Ctrl_DValve_PWMDuty'
                                        */
  real_T Ctrl_DValve2_PWMFreq_Value;   /* Expression: 100
                                        * Referenced by: '<Root>/Ctrl_DValve2_PWMFreq'
                                        */
  real_T Ctrl_DValve2_PWMDuty_Value;   /* Expression: 0
                                        * Referenced by: '<Root>/Ctrl_DValve2_PWMDuty'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test01_mdl_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_test01_mdl_T test01_mdl_P;

/* Block signals (default storage) */
extern B_test01_mdl_T test01_mdl_B;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_test01_mdl_T test01_mdl_Y;

/* Model entry point functions */
extern void test01_mdl_initialize(void);
extern void test01_mdl_output(void);
extern void test01_mdl_update(void);
extern void test01_mdl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test01_mdl_T *const test01_mdl_M;

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
 * '<Root>' : 'test01_mdl'
 * '<S1>'   : 'test01_mdl/ADC_TYPE4_BL1'
 * '<S2>'   : 'test01_mdl/DIO_TYPE3_PWM_BL1'
 * '<S3>'   : 'test01_mdl/DIO_TYPE3_PWM_BL2'
 * '<S4>'   : 'test01_mdl/DIO_TYPE3_PWM_BL3'
 * '<S5>'   : 'test01_mdl/DIO_TYPE3_PWM_BL4'
 * '<S6>'   : 'test01_mdl/RTI Data'
 * '<S7>'   : 'test01_mdl/RTI Data/RTI Data Store'
 * '<S8>'   : 'test01_mdl/RTI Data/RTI Data Store/RTI Data Store'
 * '<S9>'   : 'test01_mdl/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* test01_mdl_h_ */

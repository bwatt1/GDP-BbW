/*
 * test00_mdl.c
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

#include "test00_mdl_trc_ptr.h"
#include "test00_mdl.h"
#include <math.h>
#include "rtwtypes.h"
#include "test00_mdl_private.h"

/* Block signals (default storage) */
B_test00_mdl_T test00_mdl_B;

/* External outputs (root outports fed by signals with default storage) */
ExtY_test00_mdl_T test00_mdl_Y;

/* Real-time model */
static RT_MODEL_test00_mdl_T test00_mdl_M_;
RT_MODEL_test00_mdl_T *const test00_mdl_M = &test00_mdl_M_;

/* Model output function */
void test00_mdl_output(void)
{
  real_T temp;

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */
  {
    /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
    adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
      ADC_TP4_CH1,
      (dsfloat *)&test00_mdl_B.SFunction1);
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Calib_Psens1_Offset'
   */
  test00_mdl_B.Add = test00_mdl_P.Calib_Psens1_Offset_Value +
    test00_mdl_B.SFunction1;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Calib_Psens1_Gradient'
   */
  test00_mdl_Y.Out1 = test00_mdl_P.Calib_Psens1_Gradient_Gain * test00_mdl_B.Add;

  /* Math: '<Root>/Math Function' incorporates:
   *  Constant: '<Root>/Ctrl_BValve_PWMFreq'
   *
   * About '<Root>/Math Function':
   *  Operator: reciprocal
   */
  temp = test00_mdl_P.Ctrl_BValve_PWMFreq_Value;

  /* Math: '<Root>/Math Function'
   *
   * About '<Root>/Math Function':
   *  Operator: reciprocal
   */
  test00_mdl_B.MathFunction = 1.0 / temp;

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = test00_mdl_P.SignalGenerator_Frequency * test00_mdl_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    /* SignalGenerator: '<Root>/Signal Generator' */
    test00_mdl_B.SignalGenerator = test00_mdl_P.SignalGenerator_Amplitude;
  } else {
    /* SignalGenerator: '<Root>/Signal Generator' */
    test00_mdl_B.SignalGenerator = -test00_mdl_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  test00_mdl_B.Add1 = test00_mdl_P.Constant_Value + test00_mdl_B.SignalGenerator;

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 4 on port 2 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 2, 4, (real_T)
                     test00_mdl_B.MathFunction, (real_T) test00_mdl_B.Add1);

  /* Math: '<Root>/Math Function1' incorporates:
   *  Constant: '<Root>/Ctrl_DValve_PWMFreq'
   *
   * About '<Root>/Math Function1':
   *  Operator: reciprocal
   */
  temp = test00_mdl_P.Ctrl_DValve_PWMFreq_Value;

  /* Math: '<Root>/Math Function1'
   *
   * About '<Root>/Math Function1':
   *  Operator: reciprocal
   */
  test00_mdl_B.MathFunction1 = 1.0 / temp;

  /* S-Function (rti_commonblock): '<S3>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_DValve_PWMDuty'
   */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 4 on port 3 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 3, 4, (real_T)
                     test00_mdl_B.MathFunction1, (real_T)
                     test00_mdl_P.Ctrl_DValve_PWMDuty_Value);

  /* S-Function (rti_commonblock): '<S4>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_MABx_StopCmd'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1401BASE #1 Unit:POWER */
  if (test00_mdl_P.Ctrl_MABx_StopCmd_Value == 1) {
    simState = 0;                      /* stop */
  }
}

/* Model update function */
void test00_mdl_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test00_mdl_M->Timing.clockTick0)) {
    ++test00_mdl_M->Timing.clockTickH0;
  }

  test00_mdl_M->Timing.t[0] = test00_mdl_M->Timing.clockTick0 *
    test00_mdl_M->Timing.stepSize0 + test00_mdl_M->Timing.clockTickH0 *
    test00_mdl_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    test00_mdl_M->Timing.clockTick1++;
    if (!test00_mdl_M->Timing.clockTick1) {
      test00_mdl_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void test00_mdl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test00_mdl_M, 0,
                sizeof(RT_MODEL_test00_mdl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test00_mdl_M->solverInfo,
                          &test00_mdl_M->Timing.simTimeStep);
    rtsiSetTPtr(&test00_mdl_M->solverInfo, &rtmGetTPtr(test00_mdl_M));
    rtsiSetStepSizePtr(&test00_mdl_M->solverInfo,
                       &test00_mdl_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test00_mdl_M->solverInfo, (&rtmGetErrorStatus
      (test00_mdl_M)));
    rtsiSetRTModelPtr(&test00_mdl_M->solverInfo, test00_mdl_M);
  }

  rtsiSetSimTimeStep(&test00_mdl_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&test00_mdl_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&test00_mdl_M->solverInfo, false);
  rtsiSetSolverName(&test00_mdl_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(test00_mdl_M, &test00_mdl_M->Timing.tArray[0]);
  test00_mdl_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &test00_mdl_B), 0,
                sizeof(B_test00_mdl_T));

  /* external outputs */
  test00_mdl_Y.Out1 = 0.0;

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    test00_mdl_rti_init_trc_pointers();
  }

  /* user code (Start function Trailer) */

  /* Level 5: Final initialization of RPCU systems  */
}

/* Model terminate function */
void test00_mdl_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S2>/S-Function1' */

  /* disable digital output channel 4 on port 2 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH4,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_DValve_PWMDuty'
   */

  /* disable digital output channel 4 on port 3 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 3, DIO_TP3_MASK_CH4,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* user code (Terminate function Trailer) */

  /* Level 6: Final termination of RPCU systems  */
  if (test00_mdl_P.Ctrl_MABx_StopCmd_Value == 1) {
    ds1401_power_hold_off();           /* MABX power down */
  }
}

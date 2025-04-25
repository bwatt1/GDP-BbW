/*
 * test01_mdl.c
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

#include "test01_mdl_trc_ptr.h"
#include "test01_mdl.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_test01_mdl_T test01_mdl_B;

/* External outputs (root outports fed by signals with default storage) */
ExtY_test01_mdl_T test01_mdl_Y;

/* Real-time model */
static RT_MODEL_test01_mdl_T test01_mdl_M_;
RT_MODEL_test01_mdl_T *const test01_mdl_M = &test01_mdl_M_;

/* Model output function */
void test01_mdl_output(void)
{
  real_T tmp;

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */
  {
    /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
    adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
      ADC_TP4_CH1,
      (dsfloat *)&test01_mdl_B.SFunction1);
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Calib_Psens1_Offset'
   */
  test01_mdl_B.Add = test01_mdl_P.Calib_Psens1_Offset_Value +
    test01_mdl_B.SFunction1;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Calib_Psens1_Gradient'
   */
  test01_mdl_Y.Out1 = test01_mdl_P.Calib_Psens1_Gradient_Gain * test01_mdl_B.Add;

  /* Math: '<Root>/Math Function' incorporates:
   *  Constant: '<Root>/Ctrl_BValve1_PWMFreq'
   *
   * About '<Root>/Math Function':
   *  Operator: reciprocal
   */
  tmp = test01_mdl_P.Ctrl_BValve1_PWMFreq_Value;

  /* Math: '<Root>/Math Function'
   *
   * About '<Root>/Math Function':
   *  Operator: reciprocal
   */
  test01_mdl_B.MathFunction = 1.0 / tmp;

  /* S-Function (rti_commonblock): '<S2>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_BValve1_PWMDuty'
   */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 4 on port 2 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 2, 4, (real_T)
                     test01_mdl_B.MathFunction, (real_T)
                     test01_mdl_P.Ctrl_BValve1_PWMDuty_Value);

  /* Math: '<Root>/Math Function1' incorporates:
   *  Constant: '<Root>/Ctrl_BValve2_PWMFreq'
   *
   * About '<Root>/Math Function1':
   *  Operator: reciprocal
   */
  tmp = test01_mdl_P.Ctrl_BValve2_PWMFreq_Value;

  /* Math: '<Root>/Math Function1'
   *
   * About '<Root>/Math Function1':
   *  Operator: reciprocal
   */
  test01_mdl_B.MathFunction1 = 1.0 / tmp;

  /* S-Function (rti_commonblock): '<S3>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_BValve2_PWMDuty'
   */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 4 on port 3 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 3, 4, (real_T)
                     test01_mdl_B.MathFunction1, (real_T)
                     test01_mdl_P.Ctrl_BValve2_PWMDuty_Value);

  /* Math: '<Root>/Math Function2' incorporates:
   *  Constant: '<Root>/Ctrl_DValve1_PWMFreq'
   *
   * About '<Root>/Math Function2':
   *  Operator: reciprocal
   */
  tmp = test01_mdl_P.Ctrl_DValve1_PWMFreq_Value;

  /* Math: '<Root>/Math Function2'
   *
   * About '<Root>/Math Function2':
   *  Operator: reciprocal
   */
  test01_mdl_B.MathFunction2 = 1.0 / tmp;

  /* S-Function (rti_commonblock): '<S4>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_DValve_PWMDuty'
   */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 9 on port 2 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 2, 9, (real_T)
                     test01_mdl_B.MathFunction2, (real_T)
                     test01_mdl_P.Ctrl_DValve_PWMDuty_Value);

  /* Math: '<Root>/Math Function3' incorporates:
   *  Constant: '<Root>/Ctrl_DValve2_PWMFreq'
   *
   * About '<Root>/Math Function3':
   *  Operator: reciprocal
   */
  tmp = test01_mdl_P.Ctrl_DValve2_PWMFreq_Value;

  /* Math: '<Root>/Math Function3'
   *
   * About '<Root>/Math Function3':
   *  Operator: reciprocal
   */
  test01_mdl_B.MathFunction3 = 1.0 / tmp;

  /* S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_DValve2_PWMDuty'
   */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 9 on port 1 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 1, 9, (real_T)
                     test01_mdl_B.MathFunction3, (real_T)
                     test01_mdl_P.Ctrl_DValve2_PWMDuty_Value);
}

/* Model update function */
void test01_mdl_update(void)
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
  if (!(++test01_mdl_M->Timing.clockTick0)) {
    ++test01_mdl_M->Timing.clockTickH0;
  }

  test01_mdl_M->Timing.taskTime0 = test01_mdl_M->Timing.clockTick0 *
    test01_mdl_M->Timing.stepSize0 + test01_mdl_M->Timing.clockTickH0 *
    test01_mdl_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void test01_mdl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test01_mdl_M, 0,
                sizeof(RT_MODEL_test01_mdl_T));
  test01_mdl_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &test01_mdl_B), 0,
                sizeof(B_test01_mdl_T));

  /* external outputs */
  test01_mdl_Y.Out1 = 0.0;

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    test01_mdl_rti_init_trc_pointers();
  }
}

/* Model terminate function */
void test01_mdl_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S2>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_BValve1_PWMDuty'
   */

  /* disable digital output channel 4 on port 2 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH4,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_BValve2_PWMDuty'
   */

  /* disable digital output channel 4 on port 3 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 3, DIO_TP3_MASK_CH4,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_DValve_PWMDuty'
   */

  /* disable digital output channel 9 on port 2 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH9,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
   *  Constant: '<Root>/Ctrl_DValve2_PWMDuty'
   */

  /* disable digital output channel 9 on port 1 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 1, DIO_TP3_MASK_CH9,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);
}

/*
 * test02_mdl.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test02_mdl".
 *
 * Model version              : 1.13
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Fri Apr 25 16:39:13 2025
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test02_mdl_trc_ptr.h"
#include "test02_mdl.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_test02_mdl_T test02_mdl_B;

/* External outputs (root outports fed by signals with default storage) */
ExtY_test02_mdl_T test02_mdl_Y;

/* Real-time model */
static RT_MODEL_test02_mdl_T test02_mdl_M_;
RT_MODEL_test02_mdl_T *const test02_mdl_M = &test02_mdl_M_;

/* Model output function */
void test02_mdl_output(void)
{
  real_T tmp;

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */
  {
    /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
    adc_tp4_single_new_read(ADC_TP4_1_MODULE_ADDR,
      ADC_TP4_CH1,
      (dsfloat *)&test02_mdl_B.SFunction1);
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Calib_Psens1_Offset'
   */
  test02_mdl_B.Add = test02_mdl_P.Calib_Psens1_Offset_Value +
    test02_mdl_B.SFunction1;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Calib_Psens1_Gradient'
   */
  test02_mdl_Y.Out1 = test02_mdl_P.Calib_Psens1_Gradient_Gain * test02_mdl_B.Add;

  /* Math: '<Root>/Math Function' incorporates:
   *  Constant: '<Root>/Ctrl_BValve1_PWMFreq'
   *
   * About '<Root>/Math Function':
   *  Operator: reciprocal
   */
  tmp = test02_mdl_P.Ctrl_BValve1_PWMFreq_Value;

  /* Math: '<Root>/Math Function'
   *
   * About '<Root>/Math Function':
   *  Operator: reciprocal
   */
  test02_mdl_B.MathFunction = 1.0 / tmp;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Outport: '<Root>/Out1'
   */
  if (test02_mdl_Y.Out1 > test02_mdl_P.Switch1_Threshold) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    test02_mdl_B.Switch1 = test02_mdl_P.Constant_Value;
  } else {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    test02_mdl_B.Switch1 = test02_mdl_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Logic: '<Root>/NOT' */
  test02_mdl_B.NOT = !(test02_mdl_B.Switch1 != 0.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  test02_mdl_B.DataTypeConversion = test02_mdl_B.NOT;

  /* Gain: '<Root>/BV1_DutyGain' */
  test02_mdl_B.BV1_DutyGain = test02_mdl_P.BV1_DutyGain_Gain *
    test02_mdl_B.DataTypeConversion;

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 4 on port 2 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 2, 4, (real_T)
                     test02_mdl_B.MathFunction, (real_T)
                     test02_mdl_B.BV1_DutyGain);

  /* Math: '<Root>/Math Function2' incorporates:
   *  Constant: '<Root>/Ctrl_DValve1_PWMFreq'
   *
   * About '<Root>/Math Function2':
   *  Operator: reciprocal
   */
  tmp = test02_mdl_P.Ctrl_DValve1_PWMFreq_Value;

  /* Math: '<Root>/Math Function2'
   *
   * About '<Root>/Math Function2':
   *  Operator: reciprocal
   */
  test02_mdl_B.MathFunction2 = 1.0 / tmp;

  /* Switch: '<Root>/Switch' incorporates:
   *  Outport: '<Root>/Out1'
   */
  if (test02_mdl_Y.Out1 > test02_mdl_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    test02_mdl_B.Switch = test02_mdl_P.Constant1_Value;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    test02_mdl_B.Switch = test02_mdl_P.Constant_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Gain: '<Root>/DV1_DutyGain' */
  test02_mdl_B.DV1_DutyGain = test02_mdl_P.DV1_DutyGain_Gain *
    test02_mdl_B.Switch;

  /* S-Function (rti_commonblock): '<S4>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 9 on port 2 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 2, 9, (real_T)
                     test02_mdl_B.MathFunction2, (real_T)
                     test02_mdl_B.DV1_DutyGain);

  /* Math: '<Root>/Math Function3' incorporates:
   *  Constant: '<Root>/Ctrl_DValve2_PWMFreq'
   *
   * About '<Root>/Math Function3':
   *  Operator: reciprocal
   */
  tmp = test02_mdl_P.Ctrl_DValve2_PWMFreq_Value;

  /* Math: '<Root>/Math Function3'
   *
   * About '<Root>/Math Function3':
   *  Operator: reciprocal
   */
  test02_mdl_B.MathFunction3 = 1.0 / tmp;

  /* Gain: '<Root>/DV2_DutyGain' */
  test02_mdl_B.DV2_DutyGain = test02_mdl_P.DV2_DutyGain_Gain *
    test02_mdl_B.Switch;

  /* S-Function (rti_commonblock): '<S5>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 9 on port 1 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 1, 9, (real_T)
                     test02_mdl_B.MathFunction3, (real_T)
                     test02_mdl_B.DV2_DutyGain);

  /* Math: '<Root>/Math Function1' incorporates:
   *  Constant: '<Root>/Ctrl_BValve2_PWMFreq'
   *
   * About '<Root>/Math Function1':
   *  Operator: reciprocal
   */
  tmp = test02_mdl_P.Ctrl_BValve2_PWMFreq_Value;

  /* Math: '<Root>/Math Function1'
   *
   * About '<Root>/Math Function1':
   *  Operator: reciprocal
   */
  test02_mdl_B.MathFunction1 = 1.0 / tmp;

  /* Gain: '<Root>/BV2_DutyGain' incorporates:
   *  Constant: '<Root>/Ctrl_BValve2_PWMDuty'
   */
  test02_mdl_B.BV2_DutyGain = test02_mdl_P.BV2_DutyGain_Gain *
    test02_mdl_P.Ctrl_BValve2_PWMDuty_Value;

  /* S-Function (rti_commonblock): '<S3>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* write PWM Period and DutyCycle for output channel 4 on port 3 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 3, 4, (real_T)
                     test02_mdl_B.MathFunction1, (real_T)
                     test02_mdl_B.BV2_DutyGain);
}

/* Model update function */
void test02_mdl_update(void)
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
  if (!(++test02_mdl_M->Timing.clockTick0)) {
    ++test02_mdl_M->Timing.clockTickH0;
  }

  test02_mdl_M->Timing.taskTime0 = test02_mdl_M->Timing.clockTick0 *
    test02_mdl_M->Timing.stepSize0 + test02_mdl_M->Timing.clockTickH0 *
    test02_mdl_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void test02_mdl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test02_mdl_M, 0,
                sizeof(RT_MODEL_test02_mdl_T));
  test02_mdl_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &test02_mdl_B), 0,
                sizeof(B_test02_mdl_T));

  /* external outputs */
  test02_mdl_Y.Out1 = 0.0;

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    test02_mdl_rti_init_trc_pointers();
  }
}

/* Model terminate function */
void test02_mdl_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S2>/S-Function1' */

  /* disable digital output channel 4 on port 2 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH4,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function1' */

  /* disable digital output channel 9 on port 2 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH9,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function1' */

  /* disable digital output channel 9 on port 1 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 1, DIO_TP3_MASK_CH9,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);

  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' */

  /* disable digital output channel 4 on port 3 *
   * (set to high-impedance), when the simulation terminates */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 3, DIO_TP3_MASK_CH4,
                   DIO_TP3_LS_DISABLE, DIO_TP3_HS_DISABLE, DIO_TP3_TIMING_RANGE7,
                   DIO_TP3_PWM);
}

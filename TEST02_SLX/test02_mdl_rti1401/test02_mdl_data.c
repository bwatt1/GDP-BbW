/*
 * test02_mdl_data.c
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

#include "test02_mdl.h"

/* Block parameters (default storage) */
P_test02_mdl_T test02_mdl_P = {
  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Calib_Psens1_Offset'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Calib_Psens1_Gradient'
   */
  1.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Ctrl_BValve1_PWMFreq'
   */
  10000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0.035
   * Referenced by: '<Root>/Switch1'
   */
  0.035,

  /* Expression: 0.3
   * Referenced by: '<Root>/BV1_DutyGain'
   */
  0.3,

  /* Expression: 10000
   * Referenced by: '<Root>/Ctrl_DValve1_PWMFreq'
   */
  10000.0,

  /* Expression: 0.055
   * Referenced by: '<Root>/Switch'
   */
  0.055,

  /* Expression: 0.3
   * Referenced by: '<Root>/DV1_DutyGain'
   */
  0.3,

  /* Expression: 10000
   * Referenced by: '<Root>/Ctrl_DValve2_PWMFreq'
   */
  10000.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/DV2_DutyGain'
   */
  0.3,

  /* Expression: 10000
   * Referenced by: '<Root>/Ctrl_BValve2_PWMFreq'
   */
  10000.0,

  /* Expression: 1
   * Referenced by: '<Root>/Ctrl_BValve2_PWMDuty'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/BV2_DutyGain'
   */
  0.3
};

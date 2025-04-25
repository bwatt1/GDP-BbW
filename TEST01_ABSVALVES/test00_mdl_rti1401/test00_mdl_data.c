/*
 * test00_mdl_data.c
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

#include "test00_mdl.h"

/* Block parameters (default storage) */
P_test00_mdl_T test00_mdl_P = {
  /* Expression: 1
   * Referenced by: '<Root>/Calib_Psens1_Offset'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Calib_Psens1_Gradient'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<Root>/Ctrl_BValve_PWMFreq'
   */
  5.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Constant'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<Root>/Signal Generator'
   */
  0.5,

  /* Computed Parameter: SignalGenerator_Frequency
   * Referenced by: '<Root>/Signal Generator'
   */
  0.15915494309189535,

  /* Expression: 5
   * Referenced by: '<Root>/Ctrl_DValve_PWMFreq'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Ctrl_DValve_PWMDuty'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Ctrl_MABx_StopCmd'
   */
  0.0
};

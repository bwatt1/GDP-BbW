/*********************** dSPACE target specific file *************************

   Include file test02_mdl_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1401 24.1 (02-May-2024)
   Fri Apr 25 16:39:13 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "test02_mdl.h"
#include "test02_mdl_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             test02_mdl_B
#define RTP_STRUCTURE_NAME             test02_mdl_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   1
#endif

#ifndef dsRtmSetTaskTime
#define dsRtmSetTaskTime(rtm, sti, val) (((rtm)->Timing.taskTime0) = (val))
#endif

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Definition of interface functions for simulation engine =========== */
#if GRTINTERFACE == 1
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        1
#endif

#else
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

# define dsIsSampleHit(RTM,sti)        rtmStepTask(RTM, sti)
#endif

#undef __INLINE
#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

/*Define additional variables*/
static time_T dsTFinal = -1.0;

#define dsGetTFinal(rtm)               (dsTFinal)

static time_T dsStepSize = 0.0001;

# define dsGetStepSize(rtm)            (dsStepSize)

static void rti_mdl_initialize_host_services(void)
{
  ts_timestamp_type ts = { 0, 0 };

  host_service(1, &ts);
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1401, (void *) 0,
                        VCM_TXT_RTI1401, 24, 1, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 24, 1, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 24, 1, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 24, 1, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS1401STDADCT4 #1 */
  adc_tp4_init(ADC_TP4_1_MODULE_ADDR);

  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC */
  adc_tp4_single_init2(ADC_TP4_1_MODULE_ADDR,
                       ADC_TP4_CH1,
                       ADC_TP4_INPUT_VOLTAGE_RANGE_1,
                       ADC_TP4_TRIG_SW,
                       0.0);

  /* dSPACE I/O Board DS1401STDDIOT3 #1 */
  /* main init for DIO TP3 Module 1 */
  dio_tp3_init(DIO_TP3_1_MODULE_ADDR);

  /* dSPACE I/O Board DS1401STDDIOT3 #1 Unit:DIGOUT */
  /* PWM generation setup for channel 4 on port 2 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH4, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);

  /* PWM generation setup for channel 9 on port 2 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH9, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);

  /* PWM generation setup for channel 9 on port 1 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 1, DIO_TP3_MASK_CH9, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);

  /* PWM generation setup for channel 4 on port 3 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 3, DIO_TP3_MASK_CH4, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1401STDDIOT3 #1 Unit:DIGOUT */
  /* re-adjustment: PWM generation setup for channel 4 on port 2 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH4, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);

  /* write initial values of PWM Period and DutyCycle for output channel 4 on port 2 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 2, 4, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* re-adjustment: PWM generation setup for channel 9 on port 2 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 2, DIO_TP3_MASK_CH9, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);

  /* write initial values of PWM Period and DutyCycle for output channel 9 on port 2 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 2, 9, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* re-adjustment: PWM generation setup for channel 9 on port 1 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 1, DIO_TP3_MASK_CH9, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);

  /* write initial values of PWM Period and DutyCycle for output channel 9 on port 1 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 1, 9, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* re-adjustment: PWM generation setup for channel 4 on port 3 */
  dio_tp3_pwm_init(DIO_TP3_1_MODULE_ADDR, 3, DIO_TP3_MASK_CH4, 1, 1,
                   DIO_TP3_TIMING_RANGE7, DIO_TP3_PWM);

  /* write initial values of PWM Period and DutyCycle for output channel 4 on port 3 */
  dio_tp3_pwm_update(DIO_TP3_1_MODULE_ADDR , 3, 4, (dsfloat) 5.0E-5, (dsfloat) 0);

  /* dSPACE I/O Board DS1401STDDIOT3 #1 Unit:DIGOUT Group:PWM */
  /* enable all digital output ports (no port wise Dis-Enabling supported) */
  /* called once per module for all dig output ports */
  dio_tp3_digout_mode_set(DIO_TP3_1_MODULE_ADDR, DIO_TP3_DIGOUT_ENABLE);
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.0001, 0.0] */
  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC */

  /* dSPACE I/O Board DS1401STDADCT4 #1 Unit:ADC Group:ADC */
  adc_tp4_sw_trigger(ADC_TP4_1_MODULE_ADDR, ADC_TP4_CONV_START_1);
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  host_service(1, rtk_current_task_absolute_time_ptr_get());
  DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/

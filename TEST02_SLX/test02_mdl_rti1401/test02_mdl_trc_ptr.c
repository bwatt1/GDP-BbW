/***************************************************************************

   Source file test02_mdl_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 24.1 (02-May-2024)
   Fri Apr 25 16:39:13 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "test02_mdl_trc_ptr.h"
#include "test02_mdl.h"
#include "test02_mdl_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_test02_mdl_real_T_0 = NULL;
volatile boolean_T *p_0_test02_mdl_boolean_T_1 = NULL;
volatile real_T *p_1_test02_mdl_real_T_0 = NULL;
volatile real_T *p_2_test02_mdl_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_test02_mdl_real_T_0 = &test02_mdl_B.SFunction1;
  p_0_test02_mdl_boolean_T_1 = &test02_mdl_B.NOT;
  p_1_test02_mdl_real_T_0 = &test02_mdl_P.Constant2_Value;
  p_2_test02_mdl_real_T_0 = &test02_mdl_Y.Out1;
}

void test02_mdl_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}

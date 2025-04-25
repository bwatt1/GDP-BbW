/*********************** dSPACE target specific file *************************

   Header file test00_mdl_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 24.1 (02-May-2024)
   Wed Apr 23 19:06:31 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_test00_mdl_trc_ptr_h_
#define RTI_HEADER_test00_mdl_trc_ptr_h_

/* Include the model header file. */
#include "test00_mdl.h"
#include "test00_mdl_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_test00_mdl_real_T_0;
EXTERN_C volatile real_T *p_1_test00_mdl_real_T_0;
EXTERN_C volatile real_T *p_2_test00_mdl_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void test00_mdl_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_test00_mdl_trc_ptr_h_ */

/* Copyright 1994-2010 The MathWorks, Inc.
 *
 * File: rt_matmultcc_dbl.c     
 *
 * Abstract:
 *      Simulink Coder support routine for matrix multiplication
 *      Two complex double precision float operands
 *
 */

#include "rt_matrixlib.h"

/*
 * Function: rt_MatMultCC_Dbl
 * Abstract:
 *      2-input matrix multiply function
 *      Input 1: Complex, double-precision
 *      Input 2: Complex, double-precision
 */
#ifdef CREAL_T
void rt_MatMultCC_Dbl(creal_T       *y,
                      const creal_T *A,
                      const creal_T *B,
                      const int_T     dims[3])
{
  int_T k;
  for(k=dims[2]; k-- > 0; ) {
    const creal_T *A1 = A;
    int_T i;
    for(i=dims[0]; i-- > 0; ) {
      const creal_T *A2 = A1;
      const creal_T *B1 = B;
      creal_T acc;
      int_T j;
      A1++;
      acc.re = (real_T)0.0;
      acc.im = (real_T)0.0;
      for(j=dims[1]; j-- > 0; ) {
        creal_T c;
        rt_ComplexTimes_Dbl(&c, *A2, *B1);
        acc.re += c.re;
        acc.im += c.im;
        B1++;
        A2 += dims[0];
      }
      *y++ = acc;
    }
    B += dims[1];
  }
}
#endif
/* [EOF] rt_matmultcc_dbl.c */

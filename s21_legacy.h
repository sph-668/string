// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *s21_ecvt(double arg, int ndigits, int *decpt, int *sign);
char *s21_fcvt(double arg, int ndigits, int *decpt, int *sign);
char *s21_gcvt(double f, int ndigit, char *buf);
static char *cvt(double arg, int ndigits, int *decpt, int *sign, char *buf, int eflag);
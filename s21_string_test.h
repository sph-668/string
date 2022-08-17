// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include "s21_string.h"
#include "s21_sscanf.h"
#include "s21_sprintf.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s21_fcvt(double arg, int ndigits, int *decpt, int *sign);
char *s21_gcvt(double f, size_t ndigit, char * buf);


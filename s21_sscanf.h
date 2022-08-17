// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...);
int read_arg(const char *str, int *flags, va_list *vargs);
int set_string(const char *str, int *flags, va_list *vargs);
int str_len(const char *str);
int set_char(const char *str, int *flags, va_list *vargs);
int set_float(const char *str, int *flags, va_list *vargs);
long double read_float(const char *str, int *flags);
int set_int(const char *str, int *flags, va_list *vargs);
long long int read_int(const char *str, int *flags);
int float_len(const char *str);
int int_len(const char *str);
long int s21_read_spec(const char *str, int *flags);
int read_flags(const char *str, int *flags);
unsigned long long int atoi_anybase(const char *str, int base, int *flags,
                                    int *len_int);
void s21_init_flags(int *flags); 

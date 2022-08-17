// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

char *itoa_anybase(long long int number, char *buffer, int base, int *flags);
void place_dot(char *str, int dot_i);
void init_flags(int *flags);
long int read_flag(const char *str, int *flags, va_list *vargs);
long int read_spec(const char *str, int *flags);
char *generate_buffer(int *flags, va_list *vargs);
void process_buffer(char *buff, int *flags);
int append_buffer(char *str, const char *buff);
char *generate_integer(char *str, int *flags, va_list *vargs);
char *generate_float(char *str, int *flags, va_list *vargs);
char *generate_efloat(char *str);
char *s21_ecvt(double arg, int ndigits, int *decpt, int *sign);
char *s21_fcvt(double arg, int ndigits, int *decpt, int *sign);
char *s21_gcvt(double f, size_t ndigit, char * buf);
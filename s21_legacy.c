// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include "s21_legacy.h"

#define PLUS 1
#define SPACE 2
#define CVTBUFSIZE 128
static char CVTBUF[CVTBUFSIZE];

static char *cvt(double arg, int ndigits, int *decpt, int *sign, char *buf,
                 int eflag) {
  int r2;
  double fi, fj;
  char *p, *p1;

  if (ndigits < 0) ndigits = 0;
  if (ndigits >= CVTBUFSIZE - 1) ndigits = CVTBUFSIZE - 2;
  r2 = 0;
  *sign = 0;
  p = &buf[0];
  if (arg < 0) {
    *sign = 1;
    arg = -arg;
  }
  arg = modf(arg, &fi);
  p1 = &buf[CVTBUFSIZE];

  if (fi != 0) {
    p1 = &buf[CVTBUFSIZE];
    while (fi != 0) {
      fj = modf(fi / 10, &fi);
      int dlb = (int)((fj + .03) * 10);
      *(--p1) = (char)(dlb + '0');
      r2++;
    }
    while (p1 < &buf[CVTBUFSIZE]) *p++ = *p1++;
  } else if (arg > 0) {
    while ((fj = arg * 10) < 1) {
      arg = fj;
      r2--;
    }
  }
  p1 = &buf[ndigits];
  if (eflag == 0) p1 += r2;
  *decpt = r2;
  if (p1 < &buf[0]) {
    buf[0] = '\0';
    return buf;
  }
  while (p <= p1 && p < &buf[CVTBUFSIZE]) {
    arg *= 10;
    arg = modf(arg, &fj);
    *p++ = (char)((int)fj + '0');
  }
  if (p1 >= &buf[CVTBUFSIZE]) {
    buf[CVTBUFSIZE - 1] = '\0';
    return buf;
  }
  p = p1;
  char five = 5;
  *p1 = (char)(*p1 + five);
  while (*p1 > '9') {
    *p1 = '0';
    if (p1 > buf) {
      ++*--p1;
    } else {
      *p1 = '1';
      (*decpt)++;
      if (eflag == 0) {
        if (p > buf) *p = '0';
        p++;
      }
    }
  }
  *p = '\0';
  return buf;
}

char *s21_gcvt(double number, int ndigit, char *buf) {
  int sign, decpt;
  register char *p1, *p2;
  int i;

  p1 = s21_ecvt(number, ndigit, &decpt, &sign);
  p2 = buf;

  if (sign) *p2++ = '-';
  for (i = ndigit - 1; i > 0 && p1[i] == '0'; i--) ndigit--;
  if ((decpt >= 0 && decpt - ndigit > 4) || (decpt < 0 && decpt < -3)) {
    decpt--;
    *p2++ = *p1++;
    *p2++ = '.';
    for (i = 1; i < ndigit; i++) {
      *p2++ = *p1++;
    }
    *p2++ = 'e';
    if (decpt < 0) {
      decpt = -decpt;
      *p2++ = '-';
    } else {
      *p2++ = '+';
    }
    *p2++ = (char)(decpt / 10 + '0');
    *p2++ = (char)(decpt % 10 + '0');
  } else {
    if (decpt <= 0) {
      if (*p1 != '0') *p2++ = '.';
      while (decpt < 0) {
        decpt++;
        *p2++ = '0';
      }
    }
    for (i = 1; i <= ndigit; i++) {
      *p2++ = *p1++;
      if (i == decpt) {
        *p2++ = '.';
      }
    }
    if (ndigit < decpt) {
      while (ndigit++ < decpt) *p2++ = '0';
      *p2++ = '.';
    }
  }
  if (p2[-1] == '.') p2--;
  *p2 = '\0';
  return (buf);
}

char *s21_ecvt(double arg, int ndigits, int *decpt, int *sign) {
  return cvt(arg, ndigits, decpt, sign, CVTBUF, 1);
}

char *s21_fcvt(double arg, int ndigits, int *decpt, int *sign) {
  return cvt(arg, ndigits, decpt, sign, CVTBUF, 0);
}

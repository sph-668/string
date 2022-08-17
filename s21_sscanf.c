// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include "s21_sscanf.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif

void s21_init_flags(int *flags) {
  for (int i = 0; i < 8; ++i) {
    flags[i] = 0;
  }
  flags[0] = 1;
  flags[1] = 1;
  flags[3] = -1;
  flags[4] = 1;
}

unsigned long long int atoi_anybase(const char *str, int base, int *flags,
                                    int *len_int) {
  int len = 0;
  while (('0' <= str[len] && str[len] <= '9') || str[len] == '+' ||
         str[len] == '-' ||
         (base > 10 && 'A' <= flags[5] && flags[5] < 'Z' && 'A' <= str[len] &&
          str[len] < 'A' + base - 10) ||
         (base > 10 && 'a' <= flags[5] && flags[5] < 'z' && 'a' <= str[len] &&
          str[len] < 'a' + base - 10)) {
    ++len;
  }
  *len_int = len;

  unsigned long long int num = 0, bpow = 1;
  for (int i = len - 1; i >= 0; --i) {
    int baseval = (int)bpow;
    if ('A' <= str[i] && str[i] <= 'Z') {
      baseval *= str[i] - 'A' + 10;
    } else if ('a' <= str[i] && str[i] <= 'z') {
      baseval *= str[i] - 'a' + 10;
    } else {
      baseval *= str[i] - '0';
    }
    num += (unsigned long long int)baseval;
    bpow *= (unsigned long long int)base;
  }
  return num;
}

int read_flags(const char *str, int *flags) {
  int is = 0;
  if (str[is] == '*') {
    flags[2] = 1;
    ++is;
  } else if ('1' <= str[is] && str[is] <= '9') {
    flags[3] = atoi(str + is);
    while ('1' <= str[is] && str[is] <= '9') {
      ++is;
    }
  } else if (str[is] == 'l') {
    if (flags[4] == 1)
      flags[4] = 2;
    else if (flags[4] == 2)
      flags[4] = 3;
    ++is;
  } else if (str[is] == 'h') {
    if (flags[4] == 1) flags[4] = 0;
    ++is;
  } else if (str[is] == 'L') {
    flags[7] = 1;
    ++is;
  }
  return is;
}

long int s21_read_spec(const char *str, int *flags) {
  const char *cur = str;
  if (s21_strchr("cdeEfgGosxXiupn%", *cur)) {
    flags[5] = *cur;
    flags[1] = 0;
    cur++;
  }
  return cur - str;
}

int int_len(const char *str) {
  int len = 0;
  if (str[len] == '+' || str[len] == '-') ++len;
  while ('0' <= str[len] && str[len] <= '9') {
    ++len;
  }
  return len;
}

int float_len(const char *str) {
  int len = 0, point_seen = 0;
  if (str[len] == '+' || str[len] == '-') ++len;
  while (('0' <= str[len] && str[len] <= '9') ||
         (str[len] == '.' && !point_seen)) {
    if (str[len] == '.') point_seen = 1;
    ++len;
  }
  return len;
}

long long int read_int(const char *str, int *flags) {
  long long int num = 0;
  int len = 0;
  if (flags[5] == 'd' || flags[5] == 'i' || flags[5] == 'u') {
    num = atoll(str);
    len = int_len(str);
  } else if (flags[5] == 'n') {
    num = flags[6];
  } else {
    int base = 10;
    if (flags[5] == 'o') {
      base = 8;
    } else if (flags[5] == 'X' || flags[5] == 'x') {
      base = 16;
    }
    num = (long long)atoi_anybase(str, base, flags, &len);
  }
  flags[6] += len;
  return num;
}

int set_int(const char *str, int *flags, va_list *vargs) {
  long long int num = read_int(str, flags);
  int scanned = 1;
  if (flags[5] == 'n') {
    scanned = 0;
  }
  if (flags[5] == 'd' || flags[5] == 'i' || flags[5] == 'n') {
    if (flags[4] == 0) {
      short *ptr = va_arg(*vargs, short *);
      *ptr = (short)num;
    } else if (flags[4] == 1) {
      int *ptr = va_arg(*vargs, int *);
      *ptr = (int)num;
    } else if (flags[4] == 2) {
      long int *ptr = va_arg(*vargs, long int *);
      *ptr = (long int)num;
    } else {
      long long int *ptr = va_arg(*vargs, long long int *);
      *ptr = num;
    }
  } else {
    if (flags[4] == 0) {
      unsigned short *ptr = va_arg(*vargs, unsigned short *);
      *ptr = (unsigned short)num;
    } else if (flags[4] == 1) {
      unsigned int *ptr = va_arg(*vargs, unsigned int *);
      *ptr = (unsigned int)num;
    } else if (flags[4] == 2) {
      unsigned long int *ptr = va_arg(*vargs, unsigned long int *);
      *ptr = (unsigned long int)num;
    } else {
      unsigned long long int *ptr = va_arg(*vargs, unsigned long long int *);
      *ptr = (unsigned long long int)num;
    }
  }
  return scanned;
}

long double read_float(const char *str, int *flags) {
  long double num = 0;
  int len = float_len(str);
  num = atof(str);
  flags[6] += len;
  return num;
}

int set_float(const char *str, int *flags, va_list *vargs) {
  long double num = read_float(str, flags);
  if (flags[7] == 1) {
    long double *ptr = va_arg(*vargs, long double *);
    *ptr = num;
  } else {
    double *ptr = va_arg(*vargs, double *);
    *ptr = (double)num;
    num = 0;
  }
  return 1;
}

int set_char(const char *str, int *flags, va_list *vargs) {
  int scanned = 0;
  if (*str) {
    char *ptr = va_arg(*vargs, char *);
    *ptr = *str;
    scanned = 1;
  } else {
    flags[0] = 0;
  }
  ++flags[6];
  return scanned;
}

int str_len(const char *str) {
  int len = 0;
  while (str[len] != '\0' && str[len] != ' ') {
    ++len;
  }
  return len;
}

int set_string(const char *str, int *flags, va_list *vargs) {
  int scanned = 0;
  if (*str) {
    size_t len = (size_t)str_len(str);
    char *ptr = va_arg(*vargs, char *);
    s21_strncpy(ptr, str, len);
    ptr[len] = '\0';
    scanned = 1;
    flags[6] += (int)len;
  }
  return scanned;
}

int read_arg(const char *str, int *flags, va_list *vargs) {
  int scanned = 0;
  if (flags[2] == 0) {
    if (s21_strchr("diuxXoun", flags[5])) {
      scanned += set_int(str, flags, vargs);
    } else if (s21_strchr("eEfgG", flags[5])) {
      scanned += set_float(str, flags, vargs);
    } else if (flags[5] == 'c') {
      scanned += set_char(str, flags, vargs);
    } else if (flags[5] == 's') {
      scanned += set_string(str, flags, vargs);
    }
  }
  return scanned;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int is = 0, ifo = 0, scanned = 0;
  //             0  1  2  3  4  5  6  7
  //            go  %  * wi  l sp is  L
  int flags[] = {1, 0, 0, -1, 1, 0, 0, 0};
  while (format[ifo] != '\0' && flags[0] == 1) {
    if (format[ifo] == ' ') {
      if (str[is] != ' ') {
        int check_space = 1;
        while (format[ifo + check_space] == ' ') ++check_space;
        if (format[ifo + check_space] != '%') {
          flags[0] = 0;
        } else {
          while (str[is] == ' ') {
            is++;
          }
        }
      } else {
        ++is;
      }
      ++ifo;
    } else if (format[ifo] != '%') {
      if (str[is] != format[ifo]) {
        flags[0] = 0;
      } else {
        ++ifo;
        ++is;
      }
    } else {
      s21_init_flags(flags);
      ++ifo;
      while (flags[1]) {
        ifo += read_flags(format + ifo, flags);
        ifo += (int)s21_read_spec(format + ifo, flags);
      }
      if (flags[5] != 'c' && flags[5] != 'n') {
        while (str[is] == ' ') ++is;
      }
      char temp[BUFFER_SIZE];
      if (flags[3] == -1) {
        s21_strcpy(temp, str + is);
      } else {
        s21_strncpy(temp, str + is, (size_t)flags[3]);
        temp[flags[3]] = '\0';
      }
      flags[6] = is;
      scanned += read_arg(temp, flags, &args);
      is = flags[6];
    }
  }

  va_end(args);
  return scanned;
}

// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include "s21_sprintf.h"

#define BUFFER_SIZE 512

char *itoa_anybase(long long int number, char *buffer, int base, int *flags) {
  int curr = 0;
  long long int num = 0;
  long long int limits[4] = {SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX};

  if (number == 0) {
    buffer[curr++] = '0';
    buffer[curr] = '\0';

  } else {
    int num_digits = 0;

    if (number < 0) {
      if (base == 10 && flags[11] != 'u') {
        num = -number;
        flags[1] = 1;
      } else {
        num = limits[flags[6] + 1] + number + limits[flags[6] + 1] + 2;
      }
    } else {
      num = number;
    }

    num_digits += (int)floor((double)(log10l(num) / log10l(base))) + 1;

    while (curr < num_digits) {
      long long int base_val = (long long int)pow(base, num_digits - 1 - curr);
      long long int num_val = num / base_val;

      char value;
      if (num_val < 10) {
        value = (char)(num_val + '0');
      } else if (flags[11] >= 'A' && flags[11] <= 'Z') {
        value = (char)(num_val - 10 + 'A');
      } else {
        value = (char)(num_val - 10 + 'a');
      }
      buffer[curr] = value;

      curr++;
      num -= base_val * num_val;
    }
    buffer[curr] = '\0';
  }
  return buffer;
}

void place_dot(char *str, int dot_i) {
  char tmp = '.', tmp_2 = '\0';
  size_t len = s21_strlen(str) + 2;
  for (size_t i = (size_t)dot_i; i < len; ++i) {
    tmp_2 = str[i];
    str[i] = tmp;
    tmp = tmp_2;
  }
}

void init_flags(int *flags) {
  for (int i = 0; i < 13; ++i) {
    flags[i] = 0;
  }
  flags[0] = 1;
  flags[10] = -1;
}

long int read_flag(const char *str, int *flags, va_list *vargs) {
  const char *cur = str;
  if (*cur == '-') {
    flags[9] = 1;
    ++cur;
  } else if (*cur == '+') {
    flags[2] = 1;
    ++cur;
  } else if (*cur == ' ') {
    flags[3] = 1;
    ++cur;
  } else if (*cur == '#') {
    flags[4] = 1;
    ++cur;
  } else if (*cur == '0') {
    flags[5] = 1;
    ++cur;
  } else if (*cur == 'h' && flags[6] == 0) {
    flags[6] = -1;
    ++cur;
  } else if (*cur == 'l' && flags[6] == 0) {
    ++flags[6];
    ++cur;
    if (*cur == 'l') {
      ++flags[6];
      ++cur;
    }
  } else if (*cur == 'L') {
    flags[7] = 1;
    ++cur;
  } else if (*cur == '.') {
    ++cur;
    if (*cur == '*') {
      int dec = va_arg(*vargs, int);
      if (dec >= 0) flags[10] = dec;
      ++cur;
    } else if ('1' <= *cur && *cur <= '9') {
      flags[10] = atoi(cur);
      while ('1' <= *cur && *cur <= '9') {
        ++cur;
      }
    }
  } else if ('1' <= *cur && *cur <= '9') {
    flags[8] = atoi(cur);
    while ('0' <= *(cur) && *(cur) <= '9') {
      ++cur;
    }
  } else if (*cur == '*') {
    int width = va_arg(*vargs, int);
    if (width >= 0) flags[8] = width;
    ++cur;
  }

  return cur - str;
}

long int read_spec(const char *str, int *flags) {
  const char *cur = str;
  if (s21_strchr("cdeEfgGosxXiupn%", *cur)) {
    flags[11] = *cur;
    flags[0] = 0;
    cur++;
  }
  return cur - str;
}

char *point_integer(char *buffer, int *flags) {
  int len = (int)s21_strlen(buffer);
  char tmp[BUFFER_SIZE] = "";
  int i = 0;
  for (; i < flags[10] - len; ++i) {
    tmp[i] = '0';
  }
  tmp[i] = '\0';
  s21_strcat(tmp, buffer);
  s21_strcpy(buffer, tmp);
  return buffer;
}

char *generate_buffer(int *flags, va_list *vargs) {
  char *buffer = (char *)malloc(BUFFER_SIZE);
  buffer[0] = '\0';
  if (flags[11] == '%') {
    buffer[0] = '%';
    buffer[1] = '\0';
  } else if (flags[11] == 'c') {
    buffer[0] = (char)va_arg(*vargs, int);
    buffer[1] = '\0';
  } else if (flags[11] == 's') {
    char *str = va_arg(*vargs, char *);
    if (!str) str = "(null)";
    s21_strcpy(buffer, str);
  } else if (s21_strchr("dioxXu", flags[11])) {
    generate_integer(buffer, flags, vargs);
    point_integer(buffer, flags);
  } else if (s21_strchr("feEgG", flags[11])) {
    generate_float(buffer, flags, vargs);
  } else if (flags[11] == 'p') {
    s21_sprintf(buffer, "%#016x", va_arg(*vargs, void *));
  } else if (flags[11] == 'n') {
    int *ptr = va_arg(*vargs, int *);
    *ptr = flags[12];
  }
  return buffer;
}

char *generate_integer(char *str, int *flags, va_list *vargs) {
  long long int num;
  int base = 10;
  if (flags[11] != 'n') {
    if (flags[6] == -1)
      num = (short)va_arg(*vargs, int);
    else if (flags[6] == 0)
      num = va_arg(*vargs, int);
    else if (flags[6] == 1)
      num = va_arg(*vargs, long);
    else if (flags[6] == 2)
      num = va_arg(*vargs, long long int);
  } else {
    num = flags[12];
  }
  if (flags[11] == 'o')
    base = 8;
  else if (flags[11] == 'x' || flags[11] == 'X')
    base = 16;
  itoa_anybase(num, str, base, flags);
  return str;
}

char *cvttoa(char *str, int dec, int *flags) {
  char temp[BUFFER_SIZE] = "";
  if (flags[11] == 'f') {
    if (dec <= 0) {
      s21_strcpy(temp, str);
      s21_strcpy(str, "0.");
      for (int i = 2; i < 2 - dec; ++i) {
        str[i] = '0';
      }
      str[2 - dec] = '\0';
      s21_strcat(str, temp);
    } else {
      place_dot(str, dec);
    }
  } else {
    if (flags[10] > 0 || (flags[10] == 0 && flags[4])) place_dot(str, 1);
    int len = (int)s21_strlen(str);
    str[len] = (char)flags[11];
    str[len + 1] = '\0';
    s21_sprintf(str + len + 1, "%+03d", dec - 1);
  }
  return str;
}

char *minus_to_flags(char *str, int *flags) {
  if (str[0] == '-') {
    flags[1] = 1;
    for (int i = 1; str[i - 1] != '\0'; ++i) {
      str[i - 1] = str[i];
    }
  }
  return str;
}

char *generate_float(char *str, int *flags, va_list *vargs) {
  double num;
  if (flags[7]) {
    num = (double)va_arg(*vargs, long double);
  } else {
    num = (double)va_arg(*vargs, double);
  }
  int dec = 0;
  if (flags[10] == -1) flags[10] = 6;
  if (flags[11] == 'f') {
    s21_strcpy(str, s21_fcvt(num, flags[10], &dec, flags + 1));
    cvttoa(str, dec, flags);
  } else if (flags[11] == 'e' || flags[11] == 'E') {
    s21_strcpy(str, s21_ecvt(num, flags[10] + 1, &dec, flags + 1));
    if (num == 0) dec = 1;
    cvttoa(str, dec, flags);
  } else {
    s21_gcvt(num, (size_t)flags[10], str);
    minus_to_flags(str, flags);
  }
  return str;
}

int add_sign(char *str, int *flags) {
  int sign_added = 0;
  if (flags[1]) {
    str[0] = '-';
    ++sign_added;
  } else if (s21_strchr("dieEfgGu", flags[11])) {
    if (flags[2]) {
      str[0] = '+';
      ++sign_added;
    } else if (flags[3]) {
      str[0] = ' ';
      ++sign_added;
    }
  } else if (flags[4]) {
    if (flags[11] == 'o') {
      str[0] = '0';
      ++sign_added;
    } else if (flags[11] == 'x' || flags[11] == 'X') {
      str[0] = '0';
      str[1] = (char)flags[11];
      sign_added += 2;
    }
  }
  str[sign_added] = '\0';
  return sign_added;
}

char *fill_width(char *str, int *flags) {
  char sym = ' ';
  if (flags[5] && !flags[9] && s21_strchr("dieEfgGouxXp%", flags[11]))
    sym = '0';
  for (int i = 0; i < flags[8]; ++i) {
    str[i] = sym;
  }
  return str;
}

char *reform_buffer_r(char *buff, int *flags) {
  char temp[BUFFER_SIZE] = "";
  flags[8] -= add_sign(temp, flags);
  s21_strcat(temp, buff);
  flags[8] -= (int)s21_strlen(buff);
  fill_width(temp + s21_strlen(temp), flags);
  s21_strcpy(buff, temp);
  return buff;
}

char *reform_buffer_l(char *buff, int *flags) {
  char temp[BUFFER_SIZE] = "";
  if (flags[5] && s21_strchr("dieEfgGouxXp", flags[11])) {
    flags[8] -= add_sign(temp, flags);
    flags[8] -= (int)s21_strlen(buff);
    fill_width(temp + s21_strlen(temp), flags);
  } else {
    flags[8] -= (int)s21_strlen(buff);
    if (flags[1] ||
        ((flags[2] || flags[3]) && s21_strchr("dieEfgGu", flags[11])) ||
        (flags[11] == 'o' && flags[4])) {
      flags[8] -= 1;
    } else if ((flags[11] == 'x' || flags[11] == 'X') && flags[4]) {
      flags[8] -= 2;
    }
    fill_width(temp + s21_strlen(temp), flags);
    add_sign(temp + s21_strlen(temp), flags);
  }
  s21_strcat(temp, buff);
  s21_strcpy(buff, temp);
  return buff;
}

void process_buffer(char *buff, int *flags) {
  if (flags[9]) {
    reform_buffer_r(buff, flags);
  } else {
    reform_buffer_l(buff, flags);
  }
}

int append_buffer(char *str, const char *buff) {
  *(str) = '\0';
  s21_strcat(str, buff);
  return (int)s21_strlen(str);
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int si = 0;
  //               0  1  2  3  4  5  6  7  8  9 10 11 12
  //               %  -  + ' ' #  0  l  L wi r-  . sp
  int flags[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (long int fi = 0; format[fi];) {
    if (format[fi] != '%') {
      str[si++] = format[fi++];
    } else {
      init_flags(flags);
      fi++;
      while (flags[0]) {
        fi += read_flag(format + fi, flags, &args);
        fi += read_spec(format + fi, flags);
      }
      flags[12] = si;
      char *buff = generate_buffer(flags, &args);

      process_buffer(buff, flags);

      si += append_buffer(str + si, buff);
      free(buff);
    }
  }
  str[si] = '\0';
  va_end(args);
  return (si);
}

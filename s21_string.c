// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include "s21_string.h"
#define DICT_LEN 256

#if defined(__APPLE__)
char *errlist[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
    "Unknown error: ",
};
int all_errors = 106;
char buffer[100];

#elif __linux__
char *errlist[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error",
    "Unknown error: ",
};
int all_errors = 133;
char buffer[100];
#endif

// group 1 rmarchel

size_t s21_strlen(const char *str) {
  size_t res;
  for (res = 0; str[res] != '\0'; res++) {
  }
  return res;
}

int my_itoa(int num, char buf[11]) {
  int ind = 9;
  buf[10] = 0;
  num = abs(num);
  for (int i = num; i != 0; i /= 10, ind--) {
    buf[ind] = (char)(i % 10 + '0');
  }
  return ind + 1;
}

char *s21_strerror(int errnum) {
  char *tmp = "Unknown error: ", buf[512];
  int i = 0, str_num;
  for (i = 0; i < 16; i++) buffer[i] = tmp[i];
  str_num = my_itoa(errnum, buf);
  if (errnum < 0) {
    buf[str_num - 1] = '-';
    str_num--;
  }
  i = str_num;
  while (buf[i]) i++;
  for (int j = 15; j < i + 15; j++, str_num++) buffer[j] = buf[str_num];
  return (errnum < all_errors) && (errnum >= 0) ? errlist[errnum] : buffer;
}

// group 2 mcheyk

void *s21_memchr(const void *array__pointer, int symbol__code,
                 size_t array__size) {
  unsigned char *pointer = (unsigned char *)array__pointer, *answer;
  int flag = 0;
  while (!flag && array__size--) {
    if (*pointer != (unsigned char)symbol__code)
      pointer++;
    else
      flag = 1;
  }
  if (flag)
    answer = pointer;
  else
    answer = NULL;
  return answer;
}

char *s21_strchr(const char *array__string, int symbol__code) {
  const char *answer = array__string;
  while (answer && *array__string != (char)symbol__code) {
    if (!*array__string++) {
      answer = NULL;
    }
  }
  if (answer != NULL) answer = (char *)array__string;
  return (char *)answer;
}

char *s21_strrchr(const char *array__string, int symbol__code) {
  const char *ret = NULL;
  do {
    if (*array__string == (char)symbol__code) {
      ret = array__string;
    }
  } while (*array__string++);
  return (char *)ret;
}

char *s21_strpbrk(const char *array__string, const char *array__string__find) {
  char *answer = NULL;
  while (!answer && *array__string) {
    if (s21_strchr(array__string__find, *array__string++)) {
      answer = (char *)--array__string;
    }
  }
  return answer;
}

// group 3 rmarchel

int s21_memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1, *p2 = s2;
  while (n--)
    if (*p1 != *p2)
      return *p1 - *p2;
    else
      p1++, p2++;
  return 0;
}

// group 2 mcheyk
char *s21_strstr(char *array__string, const char *array__string__found) {
  size_t n = s21_strlen(array__string__found);
  char *answer = NULL;
  while (!answer && *array__string) {
    if (!s21_memcmp(array__string++, array__string__found, n)) {
      answer = array__string - 1;
    }
  }
  return answer;
}

// group 3 rmarchel

int s21_strcmp(const char *first_string, const char *second_string) {
  int check = 0, i = 0;
  while ((first_string[i] != '\0' || second_string[i] != '\0') && !check) {
    check = first_string[i] - second_string[i];
    i++;
  }
  return check;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int check = 0;
  for (int i = 0; i < (int)n && !check; i++) check = str1[i] - str2[i];
  return check;
}

// group 4 rbabara

char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strcpynull(char *dest, const char *src) {
  if (src) {
    int i = 0;
    while (src[i] != '\0') {
      dest[i] = src[i];
      i++;
    }
    dest[i] = '\0';
  } else {
    dest[0] = '\0';
  }
  return dest;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *sorce = (char *)src, *result = dest;
  for (size_t i = 0; i < n; i++) {
    result[i] = sorce[i];
  }
  return result;
}

void *s21_memmove(void *dest, const void *src, size_t n) {
  char *sorce = (char *)src, *result = dest;
  for (size_t i = 0; i < n; i++) {
    result[i] = sorce[i];
  }
  return (void *)result;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *sorce = (char *)src, *result = dest;
  for (size_t i = 0; i < n && sorce[i] != '\0'; i++) {
    result[i] = sorce[i];
  }
  return result;
}

void *s21_memset(void *str, int c, size_t n) {
  char *result = str;
  if (str == NULL) {
    result = NULL;
  } else {
    for (size_t i = 0; i < n; i++) {
      result[i] = (char)c;
    }
  }
  return (void *)result;
}

// group 5 rmarchel

char *s21_strcat(char *dest, const char *src) {
  size_t size = s21_strlen(dest), i = 0;
  for (; i < size && dest; i++) {
    if (&dest[i] == src) dest = NULL;
  }
  for (size_t j = 0, size = s21_strlen(src); j < size + 1 && dest; j++, i++)
    dest[i] = src[j];
  return dest;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  size_t size = s21_strlen(dest), i = 0;
  for (; i < size; i++) {
    if (&dest[i] == src) dest = NULL;
  }
  size = n < s21_strlen(src) ? n : s21_strlen(src);
  for (int j = 0; j < (int)n && src[j] != '\0'; j++, i++) dest[i] = src[j];
  dest[++i] = '\0';
  return dest;
}

// group 6 mcheyk

size_t s21_strcspn(const char *current__string,
                   const char *string__with__char) {
  size_t length = 0;
  if (current__string && string__with__char) {
    while (*current__string &&
           !s21_strchr(string__with__char, *current__string++)) {
      length++;
    }
  }
  return length;
}

size_t s21_strspn(const char *current__string, const char *string__with__char) {
  size_t length = 0;
  if (current__string && string__with__char) {
    while (*current__string &&
           s21_strchr(string__with__char, *current__string++)) {
      length++;
    }
  }
  return length;
}

// group 7 mcheyk

char *s21_strtok(char *str, const char *tokens) {
  static size_t si = 0;
  static char temp[1024];
  int flag = 1, notnull = 1, first_time = 0;
  if (str == NULL) {
    if (si == 0) notnull = 0;
  } else {
    s21_strcpy(temp, str);
    si = 0;
    first_time = 1;
  }

  size_t tok_len = s21_strlen(tokens), start_idx = si;
  if (notnull) {
    while (flag && temp[si] != '\0') {
      for (size_t i = 0; i < tok_len; ++i) {
        if (temp[si] == tokens[i]) {
          temp[si] = '\0';
          flag = 0;
        }
      }

      ++si;
    }
  }

  char *ans = temp + start_idx;
  if ((flag == 1 && !first_time) || notnull == 0) ans = NULL;

  return ans;
}

// group 8 jjalikak
// group 9 jjalikak
// group 10 rbabara

void *s21_to_upper(const char *str) {
  char flag = 0;
  char *result;
  int i = 0;
  if (str == NULL) {
    flag = 1;
  } else {
    result = (char *)malloc((s21_strlen(str) + 1) * (sizeof(char)));
    if (result == NULL) {
      flag = 1;
    }
    while (str[i] != '\0' && !flag) {
      if ((int)str[i] >= 97 && (int)str[i] <= 122) {
        result[i] = (char)(str[i] - 32);
      } else {
        result[i] = str[i];
      }
      i++;
    }
    result[i] = '\0';
  }
  if (flag) {
    result = NULL;
  }
  return (void *)result;
}

void *s21_to_lower(const char *str) {  // NEEDS TO FREE MEMEORY ALLOCATED
  char flag = 0;
  char *result;
  if (str == NULL) {
    flag = 1;  // in case of NULL string
  } else {
    int i = 0;
    result = (char *)malloc((s21_strlen(str) + 1) * (sizeof(char)));
    if (result == NULL) {
      flag = 1;  // in case of problems with memory allocation
    }
    while (str[i] != '\0' && !flag) {
      if ((int)str[i] >= 65 && (int)str[i] <= 90) {
        result[i] = (char)(str[i] + 32);
      } else {
        result[i] = str[i];
      }
      i++;
    }
    result[i] = '\0';
  }
  if (flag) {
    result = NULL;
  }
  return (void *)result;
}

void *s21_insert(const char *src, const char *str,
                 size_t start_index) {  // NEEDS TO FREE MEMEORY ALLOCATED
  char *result;
  char flag = 0;
  if (src == NULL || str == NULL || start_index > s21_strlen(src)) {
    flag = 1;  // in case of NULL string
  } else {     // or non-existing position (INCLUDING THE END OF THE STRING)
    size_t i = 0;
    result =
        (char *)malloc((s21_strlen(src) + s21_strlen(str) + 2) * sizeof(char));
    if (result == NULL) flag = 1;  // in case of problems with memory allocation
    while (i < start_index && src[i] != '\0' && flag == 0) {
      result[i] = src[i];
      i++;
    }
    size_t j = i;
    while (flag == 0 && str[j - i] != '\0') {
      result[j] = str[j - i];
      j++;
    }
    while (flag == 0 && src[i] != '\0') {
      result[j] = src[i];
      i++;
      j++;
    }
    result[j] = '\0';
  }
  if (flag == 1) {
    result = NULL;
  }
  return (void *)result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *result;
  if (src == NULL) {
    result = NULL;
  } else {
    if (trim_chars == NULL) trim_chars = "\n\t ";
    char *copy = (char *)src, *first_position = copy + s21_strlen(copy),
         *cur_position_r, *last_position = copy - 1;
    for (size_t i = 0; i < s21_strlen(trim_chars); i++) {
      cur_position_r = s21_strrchr(copy, trim_chars[i]);
      if (cur_position_r > last_position) last_position = cur_position_r;
    }
    first_position = s21_strpbrk(src, trim_chars);
    if (first_position == NULL) {
      result = copy;
    } else {
      char *first_position_r = first_position, *last_position_l = last_position;
      while (s21_strchr(trim_chars, *(first_position_r)) &&
             first_position_r++ < copy + s21_strlen(copy)) {
      }
      while (s21_strrchr(trim_chars, *(last_position_l)) &&
             last_position_l-- >= copy) {
      }
      first_position_r--;
      last_position_l++;
      result = (char *)malloc((s21_strlen(src) * sizeof(char)));
      char *i = result, *j;
      for (j = copy; j < first_position; j++) {
        *i = *j;
        i++;
      }
      for (j = first_position_r + 1; j < last_position_l; j++) {
        *i = *j;
        i++;
      }
      for (j = last_position + 1; j < copy + s21_strlen(copy); j++) {
        *i = *j;
        i++;
      }
    }
  }

  return (void *)result;
}

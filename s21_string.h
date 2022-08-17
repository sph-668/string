// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *str);
int my_itoa(int num, char buf[11]);
char *s21_strerror(int errnum);
void *s21_memchr(const void *array__pointer, int symbol__code,
                 size_t array__size);
char *s21_strchr(const char *array__string, int symbol__code);
char *s21_strrchr(const char *array__string, int symbol__code);
char *s21_strpbrk(const char *array__string, const char *array__string__find);
int s21_memcmp(const void *s1, const void *s2, size_t n);
char *s21_strstr(char *array__string, const char *array__string__found);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcpynull(char *dest, const char *src);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memmove(void *dest, const void *src, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *current__string, const char *string__with__char);
size_t s21_strspn(const char *current__string, const char *string__with__char);
char *s21_strtok(char *str, const char *tokens);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int s21_sprintf(char *str, const char *format, ...);

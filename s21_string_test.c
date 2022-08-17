// Copyright 2021 mcheyk, mcatrina, rmarchel, jjalikak, rbabara//

#include "s21_string_test.h"

#include <stdio.h>

char common_src[15] = "1234567890";
char common_src_two[15] = "1234567890";
char empty_src[15] = "";
char single_whitespace[15] = " ";
char *null_string = NULL;
char ch = '6';
char sym[10] = "369";
char buf[32];
char *str = "string example";
char *bigStr = "STRING EXAMPLE";
char *dest = "string example";
char whitespace_only[15] = "          ";
char error_string[100] =
    "4bmwzLrMusyVb82eIMy3acyyzKzNh8yq;zZluz\0J3Ml82 "
    "VdsyfzJzMmM:ymzZ,9vzLbMmcywzKBrw6";

START_TEST(strerror_check) {
  char *str = s21_strerror(99);
  char *bigStr = strerror(99);
  char *strMinus = s21_strerror(-99);
  char *bigStrMinus = strerror(-99);
  ck_assert_msg(strcmp(str, bigStr) == 0,
                "Common string. This should succeed.");
  ck_assert_msg(strcmp(strMinus, bigStrMinus) == 0,
                "Common string. This should succeed.");

  char *strError = s21_strerror(276447231);
  char *bigStrError = strerror(276447231);
  ck_assert_msg(strcmp(strError, bigStrError) == 0,
                "Common string. This should succeed.");
}
END_TEST

START_TEST(memchr_check) {
  ck_assert_msg(
      (memchr(common_src, '4', 10)) == (s21_memchr(common_src, '4', 10)),
      "Common string. This should succeed.");
  ck_assert_msg(
      (memchr(empty_src, '4', 10)) == (s21_memchr(empty_src, '4', 10)),
      "Empty string. This should succeed.");
  ck_assert_msg((memchr(whitespace_only, '4', 10)) ==
                    (s21_memchr(whitespace_only, '4', 10)),
                "Empty string. This should succeed.");
  ck_assert_msg((memchr(single_whitespace, '4', 10)) ==
                    (s21_memchr(single_whitespace, '4', 10)),
                "Empty string. This should succeed.");
  ck_assert_msg(
      (memchr(error_string, '4', 10)) == (s21_memchr(error_string, '4', 10)),
      "Empty string. This should succeed.");
}
END_TEST

START_TEST(strchr_check) {
  ck_assert_msg(strchr(common_src, ch) == (s21_strchr(common_src, ch)),
                "Common string. This should succeed.");
  ck_assert_msg(strchr(empty_src, ch) == (s21_strchr(empty_src, ch)),
                "Empty string. This should succeed.");
  ck_assert_msg(
      strchr(whitespace_only, ch) == (s21_strchr(whitespace_only, ch)),
      "Empty string. This should succeed.");
  ck_assert_msg(
      strchr(single_whitespace, ch) == (s21_strchr(single_whitespace, ch)),
      "Empty string. This should succeed.");
  ck_assert_msg(strchr(error_string, ch) == (s21_strchr(error_string, ch)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(strrchr_check) {
  ck_assert_msg(strrchr(common_src, ch) == (s21_strrchr(common_src, ch)),
                "Common string. This should succeed.");
  ck_assert_msg(strrchr(empty_src, ch) == (s21_strrchr(empty_src, ch)),
                "Empty string. This should succeed.");
  ck_assert_msg(
      strrchr(whitespace_only, ch) == (s21_strrchr(whitespace_only, ch)),
      "Empty string. This should succeed.");
  ck_assert_msg(
      strrchr(single_whitespace, ch) == (s21_strrchr(single_whitespace, ch)),
      "Empty string. This should succeed.");
  ck_assert_msg(strrchr(error_string, ch) == (s21_strrchr(error_string, ch)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(strpbrk_check) {
  ck_assert_msg(strpbrk(common_src, sym) == (s21_strpbrk(common_src, sym)),
                "Common string. This should succeed.");
  ck_assert_msg(strpbrk(empty_src, sym) == (s21_strpbrk(empty_src, sym)),
                "Empty string. This should succeed.");
  ck_assert_msg(
      strpbrk(whitespace_only, sym) == (s21_strpbrk(whitespace_only, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(
      strpbrk(single_whitespace, sym) == (s21_strpbrk(single_whitespace, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(strpbrk(error_string, sym) == (s21_strpbrk(error_string, sym)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(strstr_check) {
  ck_assert_msg(strstr(common_src, sym) == (s21_strstr(common_src, sym)),
                "Common string. This should succeed.");
  ck_assert_msg(strstr(empty_src, sym) == (s21_strstr(empty_src, sym)),
                "Empty string. This should succeed.");
  ck_assert_msg(
      strstr(whitespace_only, sym) == (s21_strstr(whitespace_only, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(
      strstr(single_whitespace, sym) == (s21_strstr(single_whitespace, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(strstr(error_string, sym) == (s21_strstr(error_string, sym)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(strcspn_check) {
  ck_assert_msg(strcspn(common_src, sym) == (s21_strcspn(common_src, sym)),
                "Common string. This should succeed.");
  ck_assert_msg(strcspn(empty_src, sym) == (s21_strcspn(empty_src, sym)),
                "Empty string. This should succeed.");
  ck_assert_msg(
      strcspn(whitespace_only, sym) == (s21_strcspn(whitespace_only, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(
      strcspn(single_whitespace, sym) == (s21_strcspn(single_whitespace, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(strcspn(error_string, sym) == (s21_strcspn(error_string, sym)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(strspn_check) {
  char single_symbol[2] = "y";
  ck_assert_msg(strspn(common_src, sym) == (s21_strspn(common_src, sym)),
                "Common string. This should succeed.");
  ck_assert_msg(strspn(empty_src, sym) == (s21_strspn(empty_src, sym)),
                "Empty string. This should succeed.");
  ck_assert_msg(
      strspn(whitespace_only, sym) == (s21_strspn(whitespace_only, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(
      strspn(single_whitespace, sym) == (s21_strspn(single_whitespace, sym)),
      "Empty string. This should succeed.");
  ck_assert_msg(strspn(error_string, single_symbol) ==
                    (s21_strspn(error_string, single_symbol)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(strtok_check) {
  char cs1[50] = "1234567890", cs2[50] = "1234567890";
  char sym[10] = "369";
  char str1[512], str2[512];
  s21_strcpynull(str1, strtok(cs1, sym));
  s21_strcpynull(str2, s21_strtok(cs2, sym));
  ck_assert_msg(s21_strcmp(str1, str2) == 0,
                "Common string. This should succeed.");

  s21_strcpynull(str1, strtok(NULL, sym));
  s21_strcpynull(str2, s21_strtok(NULL, sym));
  ck_assert_msg(s21_strcmp(str1, str2) == 0,
                "Empty string. This should succeed.");

  s21_strcpy(cs1, empty_src);
  s21_strcpy(cs2, empty_src);
  s21_strcpynull(str1, strtok(NULL, sym));
  s21_strcpynull(str2, s21_strtok(NULL, sym));
  ck_assert_msg(s21_strcmp(str1, str2) == 0,
                "Empty string. This should succeed.");

  s21_strcpy(cs1, single_whitespace);
  s21_strcpy(cs2, single_whitespace);
  s21_strcpynull(str1, strtok(cs1, sym));
  s21_strcpynull(str2, s21_strtok(cs2, sym));
  ck_assert_msg(s21_strcmp(str1, str2) == 0,
                "Empty string. This should succeed.");

  s21_strcpynull(str1, strtok(NULL, sym));
  s21_strcpynull(str2, s21_strtok(NULL, sym));
  ck_assert_msg(s21_strcmp(str1, str2) == 0,
                "Empty string. This should succeed.");

  s21_strcpynull(str1, strtok(NULL, sym));
  s21_strcpynull(str2, s21_strtok(NULL, sym));
  ck_assert_msg(s21_strcmp(str1, str2) == 0,
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(strlen_check) {
  ck_assert_msg(strlen(common_src) == (s21_strlen(common_src)),
                "Common string. This should succeed.");
  ck_assert_msg(strlen(empty_src) == (s21_strlen(empty_src)),
                "Empty string. This should succeed.");
  ck_assert_msg(strlen(whitespace_only) == (s21_strlen(whitespace_only)),
                "Empty string. This should succeed.");
  ck_assert_msg(strlen(error_string) == (s21_strlen(error_string)),
                "Empty string. This should succeed.");
  ck_assert_msg(strlen(single_whitespace) == (s21_strlen(single_whitespace)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(memcmp_check) {
  ck_assert_msg(memcmp(common_src, common_src_two, 2) ==
                    (s21_memcmp(common_src, common_src_two, 2)),
                "Common string. This should succeed.");
  ck_assert_msg(
      memcmp(empty_src, empty_src, 2) == (s21_memcmp(empty_src, empty_src, 2)),
      "Common string. This should succeed.");
  ck_assert_msg(memcmp(error_string, common_src, 2) ==
                    (s21_memcmp(error_string, common_src, 2)),
                "Common string. This should succeed.");
  ck_assert_msg(memcmp(whitespace_only, common_src, 2) ==
                    (s21_memcmp(whitespace_only, common_src, 2)),
                "Common string. This should succeed.");
  ck_assert_msg(memcmp(single_whitespace, common_src, 2) ==
                    (s21_memcmp(single_whitespace, common_src, 2)),
                "Common string. This should succeed.");
}
END_TEST

START_TEST(strcmp_check) {
  ck_assert_msg(strcmp(common_src, common_src) ==
                    (s21_strcmp(common_src, common_src)),
                "Common string. This should succeed.");
  ck_assert_msg(
      strcmp(empty_src, empty_src) == (s21_strcmp(empty_src, empty_src)),
      "Empty string. This should succeed.");
  ck_assert_msg(strcmp(whitespace_only, whitespace_only) ==
                    (s21_strcmp(whitespace_only, whitespace_only)),
                "Empty string. This should succeed.");
  ck_assert_msg(strcmp(error_string, error_string) ==
                    (s21_strcmp(error_string, error_string)),
                "Empty string. This should succeed.");
  ck_assert_msg(strcmp(single_whitespace, single_whitespace) ==
                    (s21_strcmp(single_whitespace, single_whitespace)),
                "Empty string. This should succeed.");
}

START_TEST(strncmp_check) {
  ck_assert_msg(strncmp(common_src_two, common_src_two, 5) ==
                    (s21_strncmp(common_src_two, common_src_two, 5)),
                "Common string. This should succeed.");
  ck_assert_msg(strncmp(empty_src, empty_src, 5) ==
                    (s21_strncmp(empty_src, empty_src, 5)),
                "Empty string. This should succeed.");
  ck_assert_msg(strncmp(whitespace_only, whitespace_only, 5) ==
                    (s21_strncmp(whitespace_only, whitespace_only, 5)),
                "Empty string. This should succeed.");
  ck_assert_msg(strncmp(error_string, error_string, 5) ==
                    (s21_strncmp(error_string, error_string, 5)),
                "Empty string. This should succeed.");
  ck_assert_msg(strncmp(single_whitespace, single_whitespace, 5) ==
                    (s21_strncmp(single_whitespace, single_whitespace, 5)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(memcpy_check) {
  ck_assert_msg(memcpy(common_src, common_src_two, 5) ==
                    (s21_memcpy(common_src, common_src_two, 5)),
                "Common string. This should succeed.");
  ck_assert_msg(memcpy(common_src, empty_src, 5) ==
                    (s21_memcpy(common_src, empty_src, 5)),
                "Empty string. This should succeed.");
  ck_assert_msg(memcpy(common_src, whitespace_only, 5) ==
                    (s21_memcpy(common_src, whitespace_only, 5)),
                "Empty string. This should succeed.");
  ck_assert_msg(memcpy(common_src, error_string, 5) ==
                    (s21_memcpy(common_src, error_string, 5)),
                "Empty string. This should succeed.");
  ck_assert_msg(memcpy(common_src, single_whitespace, 5) ==
                    (s21_memcpy(common_src, single_whitespace, 5)),
                "Empty string. This should succeed.");
}
END_TEST

START_TEST(memmove_check) {
  char str[50] = "test";
  char str2[50] = "test";
  char from[50] = "of mem\0move";

  char *test_string = s21_memmove(str, from, 2);
  char *test_string2 = memmove(str2, from, 2);
  ck_assert_msg(strcmp(test_string, test_string2) == 0,
                "Common string. This should succeed.");

  char *test_string_empty = s21_memmove(str, empty_src, 2);
  char *test_string_empty2 = memmove(str2, empty_src, 2);
  ck_assert_msg(strcmp(test_string, test_string2) == 0,
                "Common string. This should succeed.");

  char *test_string_whitespace_only =
           s21_memmove(str, whitespace_only, 2);
  char *test_string_whitespace_only2 =
           memmove(str2, whitespace_only, 2);
  ck_assert_msg(strcmp(test_string_whitespace_only2, test_string2) == 0,
                "Common string. This should succeed.");
}
END_TEST

START_TEST(strcat_check) {
  char *str = (char *)calloc(100, 1);
  ck_assert_msg(strcat(str, "Techie ") == (s21_strcat(str, "Techie ")),
                "Common string. This should succeed.");
  free(str);
}
END_TEST

START_TEST(memset_check) {
  ck_assert_msg(
      memset(common_src, '1', 10) == (s21_memset(common_src, '1', 10)),
      "Common string. This should succeed.");
  ck_assert_msg(memset(empty_src, '1', 10) == (s21_memset(empty_src, '1', 10)),
                "Empty string. This should succeed.");
  ck_assert_msg(memset(whitespace_only, '1', 10) ==
                    (s21_memset(whitespace_only, '1', 10)),
                "Empty string. This should succeed.");
  ck_assert_msg(NULL == (s21_memset(NULL, '1', 10)),
                "Empty string. This should succeed.");
  ck_assert_msg(memset(single_whitespace, '1', 10) ==
                    (s21_memset(single_whitespace, '1', 10)),
                "Common string. This should succeed.");
  ck_assert_msg(
      memset(error_string, '1', 10) == (s21_memset(error_string, '1', 10)),
      "Common string. This should succeed.");
}
END_TEST

START_TEST(strcpy_check) {
  ck_assert_msg(strcpy(buf, str) == (s21_strcpy(buf, str)),
                "Common string. This should succeed.");
  ck_assert_msg(
      strcpy(whitespace_only, str) == (s21_strcpy(whitespace_only, str)),
      "Common string. This should succeed.");
  ck_assert_msg(strcpy(empty_src, str) == (s21_strcpy(empty_src, str)),
                "Common string. This should succeed.");
  ck_assert_msg(strcpy(error_string, str) == (s21_strcpy(error_string, str)),
                "Common string. This should succeed.");
}
END_TEST

START_TEST(to_upper_check) {
  char *str = "string";
  char *bigStr = "STRING";
  char *str_error =
      "4bmwzLrMusyVb82eIMy3acyyzKzNh8yqzZluzJ3Ml82VdsyfzJzMmMymzZ9vzLbMmcywzKBr"
      "w6jN";
  char *bigStr_error =
      "4BMWZLRMUSYVB82EIMY3ACYYZKZNH8YQZZLUZJ3ML82VDSYFZJZMMMYMZZ9VZLBMMCYWZKBR"
      "W6JN";
  ck_assert_msg(strcmp(s21_to_upper(str), bigStr) == 0,
                "Common string. This should succeed.");
  ck_assert_msg(s21_to_upper(NULL) == NULL,
                "Common string. This should succeed.");
  ck_assert_msg(strcmp(s21_to_upper(str_error), bigStr_error) == 0,
                "Common string. This should succeed.");
}
END_TEST

START_TEST(strncat_check) {
  char dest[30];
  strcpy(dest, "Techie ");
  char src[] = "Delight – Implement strncat";
  ck_assert_msg(strncat(dest, src, 7) == (s21_strncat(dest, src, 7)),
                "Common string. This should succeed.");
  puts(dest);
}
END_TEST

START_TEST(strncpy_check) {
  ck_assert_msg(strncpy(buf, str, 7) == (s21_strncpy(buf, str, 7)),
                "Common string. This should succeed.");
}
END_TEST

START_TEST(to_lower_check) {
  char *str = "string";
  char *bigStr = "STRING";
  ck_assert_msg(strcmp(s21_to_lower(bigStr), str) == 0,
                "Common string. This should succeed.");
  ck_assert_msg(s21_to_lower(NULL) == NULL,
                "Common string. This should succeed.");
}
END_TEST

START_TEST(insert_check) {
  char *src = "string";
  char *str = "our";
  char *bigStr = "ourstring";
  size_t start_index = 0;
  ck_assert_msg(strcmp(s21_insert(src, str, start_index), bigStr) == 0,
                "Common string. This should succeed.");
  ck_assert_msg(s21_insert(NULL, str, start_index) == NULL,
                "Common string. This should succeed.");
}
END_TEST

START_TEST(trim_check) {
  char *src = "string";
  char *str = "r";
  char *bigStr = "sting";
  ck_assert_msg(strcmp(s21_trim(src, str), bigStr) == 0,
                "Common string. This should succeed.");
}
END_TEST

START_TEST(sprintf_check) {
  char str[512] = "", str2[512] = "";
  s21_sprintf(str, "test %-f %e %f", 3.12e-2, 3.12e-2, 0.);
  sprintf(str2, "test %-f %e %f", 3.12e-2, 3.12e-2, 0.);

  ck_assert_msg(strcmp(str, str2) == 0, "Common string. This should succeed.");
  s21_sprintf(str, "%c %c %c", 't', 23, '\n');
  sprintf(str2, "%c %c %c", 't', 23, '\n');

  ck_assert_msg(strcmp(str, str2) == 0, "Common string. This should succeed.");
  s21_sprintf(str, "%s %s %s", "test", "more", "MORE!!!");
  sprintf(str2, "%s %s %s", "test", "more", "MORE!!!");

  ck_assert_msg(strcmp(str, str2) == 0, "Common string. This should succeed.");
  s21_sprintf(str, "t %#X %#x %#o %x", -134, -134, 125, 0);
  sprintf(str2, "t %#X %#x %#o %x", -134, -134, 125, 0);

  ck_assert_msg(strcmp(str, str2) == 0, "Common string. This should succeed.");
  s21_sprintf(str, "test %020d %1i", 1, -256);
  sprintf(str2, "test %020d %1i", 1, -256);
  ck_assert_msg(strcmp(str, str2) == 0, "Common string. This should succeed.");

  s21_sprintf(str, "test %020d %1i", 1, -256);
  sprintf(str2, "test %020d %1i", 1, -256);
  ck_assert_msg(strcmp(str, str2) == 0, "Common string. This should succeed.");

  s21_sprintf(str, "test %06g", -2.56);
  sprintf(str2, "test %06g", -2.56);
  ck_assert_msg(strcmp(str, str2) == 0, "Common string. This should succeed.");
}
END_TEST

START_TEST(sscanf_check) {
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, res = 0;
  double fa = 0, fb = 0, fc = 0, fd = 0;
  char test_string[20] = "hHOHOH";
  s21_sscanf("ABOBA 23 -1234", "ABOBA %d %2d%d", &a, &b, &c);
  ck_assert_msg(a == 23 && b == -1 && c == 234,
                "Common string. This should succeed.");
  res = sscanf("   +12.   -23 abcdG 2 3:dick:41", " %i.%d %xG %d %d:dick:%d",
               &a, &b, &c, &d, &e, &f);
  ck_assert_msg(res == 6 && a == 12 && b == -23 && c == 43981,
                "Common string. This should succeed.");
  ck_assert_msg(d == 2 && e == 3 && f == 41,
                "Common string. This should succeed.");
  res = s21_sscanf("   +12.3   -23 abcdG 2 3:dick:41.",
                    " %f %f abcdG %d %f:dick:%f", &fa, &fb, &a, &fc, &fd);

  ck_assert_msg(res == 5 && fa == 12.300000 && fb == -23.000000,
                "Common string. This should succeed.");
  ck_assert_msg(a == 2 && fc == 3.000000 && fd == 41.000000,
                "Common string. This should succeed.");

  res = sscanf(" 12345612, test", " %3d%d, test", &a, &b);
  ck_assert_msg(res == 2 && a == 123 && b == 45612,
                "Common string. This should succeed.");

  res =
  s21_sscanf(" 12345612, test", " %c%c%4d12, tes%c%c", &a, &b, &e, &c,
  &d);
  s21_sscanf(" 12345612, test", " %3u %X %s", &a, &b, test_string);
  s21_sscanf(" 12345612, test", " %3u %X %s", &a, &b, test_string);
  s21_sscanf(" 12345612, test", " %n", &a);
}
END_TEST

START_TEST(legacy_check) {
  int decimal, sign;
  char *buffer2, *buffer = "31415927";
  double source = 3.1415926535;
  buffer2 = s21_fcvt(source, 7, &decimal, &sign);
  ck_assert_msg(strcmp(buffer, buffer2) == 0,
                "Common string. This should succeed.");

  char buffer5[20] = "0000000";
  double zero = 0;
  buffer2 = s21_fcvt(zero, 7, &decimal, &sign);
  ck_assert_msg(strcmp(buffer5, buffer2) == 0,
                "Common string. This should succeed.");
}
END_TEST

START_TEST(legacy_gcvt_check) {
  char buffer[20] = "-1.e+09", buffer2[20];
  double value = -1234567890.123;
  s21_gcvt(value, 1, buffer2);
  ck_assert_msg(strcmp(buffer, buffer2) == 0,
                "Common string. This should succeed.");

  value = -12.34567890123;
  char buffer3[20] = "-12.3456789012";
  s21_gcvt(value, 12, buffer);
  ck_assert_msg(strcmp(buffer3, buffer) == 0,
                "Common string. This should succeed.");

  char buffer4[20] = "-1.23456789012";
  value /= 10;
  s21_gcvt(value, 12, buffer);
  ck_assert_msg(strcmp(buffer4, buffer) == 0,
                "Common string. This should succeed.");

  char buffer5[20] = "0";
  double zero = 0;
  s21_gcvt(zero, 12, buffer);
  ck_assert_msg(strcmp(buffer5, buffer) == 0,
                "Common string. This should succeed.");

  char small_buffer[3];
  char buffer6[20] = "-1";
  s21_gcvt(value, 1, small_buffer);
  ck_assert_msg(strcmp(small_buffer, buffer6) == 0,
                "Common string. This should succeed.");
}
END_TEST

int main(void) {
  Suite *task1_suit = suite_create("String.h. Task 1 tests");
  TCase *task1_test_case = tcase_create("Core");
  SRunner *task1_sr = srunner_create(task1_suit);

  suite_add_tcase(task1_suit, task1_test_case);

  tcase_add_test(task1_test_case, strlen_check);
  tcase_add_test(task1_test_case, strerror_check);

  tcase_add_test(task1_test_case, memchr_check);
  tcase_add_test(task1_test_case, strchr_check);
  tcase_add_test(task1_test_case, strrchr_check);
  tcase_add_test(task1_test_case, strpbrk_check);
  tcase_add_test(task1_test_case, strstr_check);
  tcase_add_test(task1_test_case, strcspn_check);
  tcase_add_test(task1_test_case, strspn_check);
  tcase_add_test(task1_test_case, strtok_check);

  tcase_add_test(task1_test_case, memcmp_check);
  tcase_add_test(task1_test_case, strcmp_check);
  tcase_add_test(task1_test_case, strncmp_check);

  tcase_add_test(task1_test_case, memcpy_check);
  tcase_add_test(task1_test_case, memmove_check);
  tcase_add_test(task1_test_case, memset_check);
  tcase_add_test(task1_test_case, strcpy_check);
  tcase_add_test(task1_test_case, strncpy_check);

  tcase_add_test(task1_test_case, strcat_check);
  tcase_add_test(task1_test_case, strncat_check);

  tcase_add_test(task1_test_case, to_lower_check);
  tcase_add_test(task1_test_case, to_upper_check);
  tcase_add_test(task1_test_case, insert_check);
  tcase_add_test(task1_test_case, trim_check);

  tcase_add_test(task1_test_case, sprintf_check);
  tcase_add_test(task1_test_case, sscanf_check);

  tcase_add_test(task1_test_case, legacy_check);
  tcase_add_test(task1_test_case, legacy_gcvt_check);

  srunner_run_all(task1_sr, CK_ENV);
  srunner_free(task1_sr);

  return 0;
}

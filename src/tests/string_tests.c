#include "string_tests.h"

START_TEST(t_memchr) {
  const char str_str[] = "Hello, World!";
  const char str_sym1 = 'o';
  const char str_sym2 = 'W';
  const char str_sym3 = 'x';
  size_t str_size1 = 10;
  size_t str_size2 = 6;

  ck_assert_ptr_eq(memchr(str_str, str_sym1, str_size1),
                   _memchr(str_str, str_sym1, str_size1));
  ck_assert_ptr_eq(memchr(str_str, str_sym2, str_size2),
                   _memchr(str_str, str_sym2, str_size2));
  ck_assert_ptr_eq(memchr(str_str, str_sym3, str_size1),
                   _memchr(str_str, str_sym3, str_size1));

  int arr_int[5] = {1, 2, 3, 4, 5};
  int finding_int = 2;
  ck_assert_ptr_eq(memchr(arr_int, finding_int, str_size1),
                   _memchr(arr_int, finding_int, str_size1));
}
END_TEST

START_TEST(t_memcmp) {
  char str_G[] = "12345678";
  char str_L[] = "12341";
  char str_EQ[] = "12345678";

  for (int i = 1; i <= 5; i++) {
    ck_assert_int_eq(memcmp(str_L, str_G, i), _memcmp(str_L, str_G, i));
    ck_assert_int_eq(memcmp(str_G, str_L, i), _memcmp(str_G, str_L, i));
    ck_assert_int_eq(memcmp(str_G, str_EQ, i), _memcmp(str_G, str_EQ, i));
  };
}
END_TEST

START_TEST(t_memcpy) {
  char src[15] = "Hello";
  char str_std[25] = "";
  char str_s21[25] = "";

  memcpy(str_std, src, 6);
  _memcpy(str_s21, src, 6);

  for (int i = 0; i < 15; i++) ck_assert_int_eq(str_std[i], str_s21[i]);
}
END_TEST

START_TEST(t_memset) {
  int str_std[25] = {0};
  int str_s21[25] = {0};

  memset(str_std, 25, 24);
  _memset(str_s21, 25, 24);
  for (int i = 0; i < 24; i++) ck_assert_int_eq(str_std[i], str_s21[i]);
}
END_TEST

START_TEST(t_strncat) {
  char a[20] = "DimaLvov";
  char b[20] = "abcdefg";
  ck_assert_str_eq(strncat(a, b, 3), _strncat(a, b, 3));
}
END_TEST

START_TEST(t_strchr) {
  const char str_str[] = "Hello, World!";
  const char str_sym1 = 'o';
  const char str_sym2 = 'W';
  const char str_sym3 = 'x';

  ck_assert_ptr_eq(strchr(str_str, str_sym1), _strchr(str_str, str_sym1));
  ck_assert_ptr_eq(strchr(str_str, str_sym2), _strchr(str_str, str_sym2));
  ck_assert_ptr_eq(strchr(str_str, str_sym3), _strchr(str_str, str_sym3));
}
END_TEST

START_TEST(t_strncmp) {
  char str_G[] = "12345678";
  char str_L[] = "12341";
  char str_EQ[] = "12345678";

  for (int i = 1; i <= 5; i++) {
    ck_assert_int_eq(strncmp(str_L, str_G, i), _strncmp(str_L, str_G, i));
    ck_assert_int_eq(strncmp(str_G, str_L, i), _strncmp(str_G, str_L, i));
    ck_assert_int_eq(strncmp(str_G, str_EQ, i), _strncmp(str_G, str_EQ, i));
  };
}
END_TEST

START_TEST(t_strncpy) {
  char dest[25] = {'\0'};
  const char src[25] = ",Hi, there, people! ";
  for (int i = 1; i < 20; i++) {
    ck_assert_str_eq(strncpy(dest, src, i), _strncpy(dest, src, i));
  }
}
END_TEST

START_TEST(t_strcspn) {
  char a[20] = "Dima000Lv54ov";
  char b[20] = "12345";
  ck_assert_int_eq(strcspn(a, b), _strcspn(a, b));
}
END_TEST

START_TEST(t_strerror) {
  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(strerror(i), _strerror(i));
  }
}
END_TEST

START_TEST(t_strerror_107) { ck_assert_str_eq(strerror(107), _strerror(107)); }
END_TEST

START_TEST(t_strlen) {
  const char zero_str[1] = "";
  const char str_5[6] = "Hello";
  const char str_9[10] = "Hi, there";
  ck_assert_int_eq(strlen(zero_str), _strlen(zero_str));
  ck_assert_int_eq(strlen(str_5), _strlen(str_5));
  ck_assert_int_eq(strlen(str_9), _strlen(str_9));
}
END_TEST

START_TEST(t_strpbrk) {
  const char str[10] = "Hi, there";
  const char del_1[2] = ",";
  const char del_2[2] = " ";
  const char del_3[2] = "t";
  ck_assert_str_eq(strpbrk(str, del_1), _strpbrk(str, del_1));
  ck_assert_str_eq(strpbrk(str, del_2), _strpbrk(str, del_2));
  ck_assert_str_eq(strpbrk(str, del_3), _strpbrk(str, del_3));
}
END_TEST

START_TEST(t_strrchr) {
  const char str_str[] = "Hello, World!";
  const char str_sym1 = 'o';
  const char str_sym2 = 'W';
  const char str_sym3 = 'x';

  ck_assert_ptr_eq(strrchr(str_str, str_sym1), _strrchr(str_str, str_sym1));
  ck_assert_ptr_eq(strrchr(str_str, str_sym2), _strrchr(str_str, str_sym2));
  ck_assert_ptr_eq(strrchr(str_str, str_sym3), _strrchr(str_str, str_sym3));
}
END_TEST

START_TEST(t_strstr) {
  char str_Haystack[] = "Hello, WWWWorld!";
  char str_NEEDLE[] = "Worl";
  char str_EMPTY[] = "";
  char str_MIS[] = "govn";

  ck_assert_ptr_eq(strstr(str_Haystack, str_NEEDLE),
                   _strstr(str_Haystack, str_NEEDLE));
  ck_assert_ptr_eq(strstr(str_Haystack, str_EMPTY),
                   _strstr(str_Haystack, str_EMPTY));
  ck_assert_ptr_eq(strstr(str_Haystack, str_MIS),
                   _strstr(str_Haystack, str_MIS));
}
END_TEST

START_TEST(t_strtok) {
  char str_std[25] = ",Hi, there, people! ";
  char str_s21[25] = ",Hi, there, people! ";
  const char del[4] = " ,!";
  char* lem_std = strtok(str_std, del);
  char* lem_s21 = _strtok(str_s21, del);

  while (lem_std != NULL) {
    ck_assert_str_eq(lem_std, lem_s21);
    lem_std = strtok(NULL, del);
    lem_s21 = _strtok(NULL, del);
  }
}
END_TEST

// Part 2, 3. sprintf
START_TEST(t_sprintf_c) {
  char str_std[10] = {'\0'};
  memset(str_std, '\0', 10);
  char str_s21[10] = {'\0'};
  memset(str_s21, '\0', 10);
  char c = 'a';
  sprintf(str_std, "%5c", c);
  _sprintf(str_s21, "%5c", c);
  ck_assert_str_eq(str_std, str_s21);
}
END_TEST

START_TEST(t_sprintf_n) {
  char str_s21[10] = {'\0'};
  char str_std[10] = {'\0'};
  int a_s21 = 0;
  int a_std = 0;
  _sprintf(str_s21, "Hi%n", &a_s21);
  sprintf(str_std, "Hi%n", &a_std);
  ck_assert_int_eq(a_std, a_s21);
  ck_assert_str_eq(str_std, str_s21);
}
END_TEST

START_TEST(t_simple_int) {
  char str_s21[256] = {'\0'};
  memset(str_s21, '\0', 256);
  char str_std[256] = {'\0'};
  memset(str_std, '\0', 256);

  const char* format = "This is a simple value %d";
  int val = -69;
  ck_assert_int_eq(_sprintf(str_s21, format, val),
                   sprintf(str_std, format, val));

  ck_assert_str_eq(str_s21, str_std);
}
END_TEST

START_TEST(t_precise_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.5i";
  int val = 69;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_width_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%5d";
  int val = 69;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_minus_width_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-5i";
  int val = 69;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_plus_width_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%+12d";
  int val = 69;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_padding_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%012i";
  int val = 69;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_star_width_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%0*d";
  int val = 69;
  ck_assert_int_eq(_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_star_precision_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_many_flags_many_ints) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      _sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_flags_long_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_flags_short_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_flags_another_long_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_zero_precision_zero_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.0d";
  int val = 0;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_space_flag_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "% d";
  int val = 0;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_unsigned_val) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_unsigned_val_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_unsigned_val_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_unsigned_val_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_unsigned_val_many_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_unsigned_val_short) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_unsigned_val_long) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_unsigned_val_many) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      _sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_octal_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%15o";
  int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_octal_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_octal_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_octal_many_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_octal_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%o";
  ck_assert_int_eq(_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_octal_hash) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#o";
  int val = 57175;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_octal_short) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_octal_long) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_octal_many) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      _sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_octal) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_unsigned_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%u";
  ck_assert_int_eq(_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_flags) {
  char str1[256] = "";
  memset(str1, '\0', 256);
  char str2[256] = "";
  memset(str2, '\0', 256);

  const char* format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_many) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_many_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_huge) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_short) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_long) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_one_longer_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_hex_two_longer_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_one_char) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%c";
  char val = 'X';
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_one_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_one_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_one_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%15c";
  char val = 'c';
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_one_many) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_one_many_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_string) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%s";
  char* val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_string_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.15s";
  char* val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_string_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%15s";
  char* val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_string_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%-15.9s";
  char* val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_string_long) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%s";
  char* val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_string_many) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%s%s%s%s";
  char* val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char* s1 = "";
  char* s2 = "87418347813748913749871389480913";
  char* s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_ptr) {
  char str1[256] = "";
  // memset(str1, '\0', 256);
  char str2[256] = "";
  // memset(str2, '\0', 256);

  const char* format = "%p";
  _sprintf(str1, format, format);
  sprintf(str2, format, format);
  // ck_assert_int_eq(_sprintf(str1, format, format),
  //                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_ptr_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%15p";
  ck_assert_int_eq(_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_ptr_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.5p";
  ck_assert_int_eq(_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_null_ptr) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%p";
  char* ptr = NULL;
  ck_assert_int_eq(_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_string_width_huge) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char* val = "kjafdiuhfjahfjdahf";
  const char* format = "%120s";
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_n_specifier) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  int ret = 0;
  const char* format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(_sprintf(str1, format, &ret), sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_float_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_float_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_float_precision_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  const char* format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_float_precision_empty) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_float_precision_huge) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_float_precision_huge_negative) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_float_huge) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_float_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "% f";
  float val = 0;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_float_many) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_e_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_e_precision_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_e_precision_empty) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_e_precision_huge) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_e_precision_huge_negative) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_e_huge) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_E_flags) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%015E";
  float val = 0;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_e_width) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%15e";
  float val = 0;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_e_many) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(t_E_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_all_empty) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_empty_format_and_parameters) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_char) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_char) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_string) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_string) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_dec) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_dec) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_int) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_float) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%f", 0.0001), sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_float) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_unsigned_dec) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_unsigned_dec) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_char_with_alignment_left) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_char_with_alignment_right) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%-8c", '\t'), sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_char_with_alignment) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(t_test_one_hex_lower) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%x", 11), sprintf(str2, "%x", 11));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_upper) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_lower) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_upper) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(t_test_one_hex_lower_with_alignment_left) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_lower_with_alignment_right) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_upper_with_alignment_left) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_upper_with_alignment_right) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_lower_with_alignment) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_upper_with_alignment) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  ck_assert_int_eq(
      _sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(t_test_one_hex_with_hashtag) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_upper_with_hashtag) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(t_test_one_hex_lower_with_width_star) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%*x", 11, 0), sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_upper_with_width_star) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%*X", 11, 0), sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                            199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_upper_with_width_star) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                            199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(t_test_one_hex_lower_with_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  int a = _sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_upper_with_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  int a = _sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_lower_with_precision_and_other) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  int a = _sprintf(
      str1, "%#3.*x%#3x%-7.*x |%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(
      str2, "%#3.*x%#3x%-7.*x |%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_many_hex_upper_with_precision_and_other) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(
      _sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
               -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
               -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(t_test_one_hex_lower_with_length) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  long unsigned int v = 0;
  ck_assert_int_eq(_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_one_hex_upper_with_length) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);

  ck_assert_int_eq(_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  ck_assert_int_eq(_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', 256);
  memset(str2, '\0', 256);
  long unsigned int v = 0;
  ck_assert_int_eq(_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf1) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%10ld";

  ck_assert_int_eq(_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf2) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%1.1f";

  ck_assert_int_eq(_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf3) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%8.3c";

  ck_assert_int_eq(_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf4) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = _sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf6) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%7.7f";

  ck_assert_int_eq(_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf7) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%7.4s";

  ck_assert_int_eq(_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf8) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%6.6u";

  ck_assert_int_eq(_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf9) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf10) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf11) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf12) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.17Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      _sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf14) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf15) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "% 0.0hi | % 0.0hu | % 0.0hf";

  ck_assert_int_eq(_sprintf(str1, format, 1, 222, -166513.1232),
                   sprintf(str2, format, 1, 222, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf16) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "% c";

  ck_assert_int_eq(_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf17) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "% s";

  ck_assert_int_eq(_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf18) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "% s% c";

  ck_assert_int_eq(_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf19) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%210s";

  ck_assert_int_eq(_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf20) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%-115s";

  ck_assert_int_eq(_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf24) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      _sprintf(str1, format, 'f', 21, 42, 666.666,
               "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf25) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.f";

  ck_assert_int_eq(_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf26) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char format[] = "%%";

  ck_assert_int_eq(_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf27) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char format[] = "%%%%%%%%";

  ck_assert_int_eq(_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf28) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  int n1 = 0;
  int n2 = 0;
  int a = _sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf29) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%-.f";

  ck_assert_int_eq(_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf30) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%-.1d";

  ck_assert_int_eq(_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf31) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf32) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf33) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf35) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.10e";

  ck_assert_int_eq(_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf36) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf37) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%E";

  ck_assert_int_eq(_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf38) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%E%E%E";

  ck_assert_int_eq(_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf39) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf40) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf41) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf42) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_est_sprintf43) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.5o";

  ck_assert_int_eq(_sprintf(str1, format, 12345), sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_test_sprintf44) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_trailing_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  const char* format = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_large) {
  char str1[256] = "";
  memset(str1, '\0', 256);
  char str2[256] = "";
  memset(str2, '\0', 256);
  char format[] = "%g";
  double hex = 5131.43141;

  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_small) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_precision) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_precision_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_precision_missing) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_many_zeroes_in_front) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_one_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_zero) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(t_g_short_no_mantiss) {
  char str1[256] = {'\0'};
  memset(str1, '\0', 256);
  char str2[256] = {'\0'};
  memset(str2, '\0', 256);
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// Part 5. C# functions
START_TEST(t_to_upper) {
  const char str_in[] = "Hello";
  const char str_out[] = "HELLO";

  char* result = (char*)_to_upper(str_in);
  ck_assert_str_eq(str_out, result);
  free(result);

  const char str_in2[] = "";
  const char str_out2[] = "";

  char* result2 = (char*)_to_upper(str_in2);
  ck_assert_str_eq(str_out2, result2);
  free(result2);

  const char str_in3[] = "100";
  const char str_out3[] = "100";

  char* result3 = (char*)_to_upper(str_in3);
  ck_assert_str_eq(str_out3, result3);
  free(result3);
}
END_TEST

START_TEST(t_to_lower) {
  const char str_in[] = "Hello";
  const char str_out[] = "hello";

  char* result = (char*)_to_lower(str_in);
  ck_assert_str_eq(str_out, result);
  free(result);

  const char str_in2[] = "";
  const char str_out2[] = "";

  char* result2 = (char*)_to_lower(str_in2);
  ck_assert_str_eq(str_out2, result2);
  free(result2);

  const char str_in3[] = "100";
  const char str_out3[] = "100";

  char* result3 = (char*)_to_lower(str_in3);
  ck_assert_str_eq(str_out3, result3);
  free(result3);
}
END_TEST

START_TEST(t_insert) {
  const char* original = "Hello, World!";
  const char* to_insert = "Beautiful ";
  size_t index = 7;
  char* ptr = _insert(original, to_insert, index);
  ck_assert_msg(memcmp(ptr, "Hello, Beautiful World!", 24) == 0,
                "FAILURE! Test \'Hello, Beautiful World!\' failed!");
  free(ptr);
  ptr = _insert("abc", "pp", 1);
  ck_assert_msg(memcmp(ptr, "appbc", 5) == 0, "FAILURE! Test \'abc\' failed!");
  free(ptr);
  ptr = _insert("abc", "pp", 0);
  ck_assert_msg(memcmp(ptr, "ppabc", 5) == 0, "FAILURE! Test \'abc\' failed!");
  free(ptr);
  ptr = _insert("abc", "pp", 3);
  ck_assert_msg(memcmp(ptr, "abcpp", 5) == 0, "FAILURE! Test \'abc\'  failed!");
  free(ptr);
  ptr = _insert("abc", "pp", 2);
  ck_assert_msg(memcmp(ptr, "abppc", 5) == 0,
                "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
  ptr = _insert("15", "234", 1);
  ck_assert_msg(memcmp(ptr, "12345", 5) == 0, "FAILURE! Test \'15\' failed!");
  free(ptr);
  ck_assert_msg(_insert("15", "234", 3) == NULL,
                "FAILURE! Test \'15\' failed!");
}
END_TEST

START_TEST(t_trim) {
  const char str_in[] = "ohelloh";
  const char str_trim[] = "oh";
  const char str_out[] = "ell";

  char* result = (char*)_trim(str_in, str_trim);
  ck_assert_str_eq(str_out, result);
  free(result);

  const char str_in2[] = " hello      ";
  const char str_trim2[] = " ";
  const char str_out2[] = "hello";

  char* result2 = (char*)_trim(str_in2, str_trim2);
  ck_assert_str_eq(str_out2, result2);
  free(result2);

  const char str_in3[] = " this is tabs                 ";
  const char str_trim3[] = "  ";
  const char str_out3[] = "this is tabs";

  char* result3 = (char*)_trim(str_in3, str_trim3);
  ck_assert_str_eq(str_out3, result3);
  free(result3);
}
END_TEST

int main(void) {                           // int argc, char* argv[]
  Suite* suite = suite_create("_string");  // - тестовый набор
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase* tcase_memchr =
      tcase_create("_memchr");  // - группа тестов под каждую функцию
  TCase* tcase_memcmp = tcase_create("_memcmp");
  TCase* tcase_memcpy = tcase_create("_memcpy");
  TCase* tcase_memset = tcase_create("_memset");
  TCase* tcase_strncat = tcase_create("_strncat");
  TCase* tcase_strchr = tcase_create("_strchr");
  TCase* tcase_strncmp = tcase_create("_strncmp");
  TCase* tcase_strncpy = tcase_create("_strncpy");
  TCase* tcase_strcspn = tcase_create("_strcspn");
  TCase* tcase_strerror = tcase_create("_strerror");
  TCase* tcase_strlen = tcase_create("_strlen");
  TCase* tcase_strpbrk = tcase_create("_strpbrk");
  TCase* tcase_strrchr = tcase_create("_strrchr");
  TCase* tcase_strstr = tcase_create("_strstr");
  TCase* tcase_strtok = tcase_create("_strtok");
  // Part 2, 3. sprintf
  TCase* tcase_sprintf = tcase_create("_sprintf");
  // Part 5. C# functions
  TCase* tcase_toupper = tcase_create("_toupper");
  TCase* tcase_tolower = tcase_create("_tolower");
  TCase* tcase_insert = tcase_create("_insert");
  TCase* tcase_trim = tcase_create("_trim");

  // Добавление теста в группу тестов.
  // tcase_add_test(tcase_core, test_name);
  tcase_add_test(tcase_memchr, t_memchr);
  tcase_add_test(tcase_memcmp, t_memcmp);
  tcase_add_test(tcase_memcpy, t_memcpy);
  tcase_add_test(tcase_memset, t_memset);
  tcase_add_test(tcase_strncat, t_strncat);
  tcase_add_test(tcase_strchr, t_strchr);
  tcase_add_test(tcase_strncmp, t_strncmp);
  tcase_add_test(tcase_strncpy, t_strncpy);
  tcase_add_test(tcase_strcspn, t_strcspn);
  tcase_add_test(tcase_strerror, t_strerror);
  tcase_add_test(tcase_strerror, t_strerror_107);
  tcase_add_test(tcase_strlen, t_strlen);
  tcase_add_test(tcase_strpbrk, t_strpbrk);
  tcase_add_test(tcase_strrchr, t_strrchr);
  tcase_add_test(tcase_strstr, t_strstr);
  tcase_add_test(tcase_strtok, t_strtok);
  // Part 2, 3. sprintf
  tcase_add_test(tcase_sprintf, t_sprintf_c);
  tcase_add_test(tcase_sprintf, t_sprintf_n);
  // Part 5. C# functions
  tcase_add_test(tcase_toupper, t_to_upper);
  tcase_add_test(tcase_tolower, t_to_lower);
  tcase_add_test(tcase_insert, t_insert);
  tcase_add_test(tcase_trim, t_trim);

  tcase_add_test(tcase_sprintf, t_simple_int);
  tcase_add_test(tcase_sprintf, t_precise_int);
  tcase_add_test(tcase_sprintf, t_width_int);
  tcase_add_test(tcase_sprintf, t_minus_width_int);
  tcase_add_test(tcase_sprintf, t_plus_width_int);
  tcase_add_test(tcase_sprintf, t_padding_int);
  tcase_add_test(tcase_sprintf, t_star_width_int);
  tcase_add_test(tcase_sprintf, t_star_precision_int);
  tcase_add_test(tcase_sprintf, t_many_flags_many_ints);
  tcase_add_test(tcase_sprintf, t_flags_long_int);
  tcase_add_test(tcase_sprintf, t_flags_short_int);
  tcase_add_test(tcase_sprintf, t_flags_another_long_int);
  tcase_add_test(tcase_sprintf, t_zero_precision_zero_int);
  tcase_add_test(tcase_sprintf, t_space_flag_int);
  tcase_add_test(tcase_sprintf, t_unsigned_val);
  tcase_add_test(tcase_sprintf, t_unsigned_val_width);
  tcase_add_test(tcase_sprintf, t_unsigned_val_flags);
  tcase_add_test(tcase_sprintf, t_unsigned_val_precision);
  tcase_add_test(tcase_sprintf, t_unsigned_val_many_flags);
  tcase_add_test(tcase_sprintf, t_unsigned_val_short);
  tcase_add_test(tcase_sprintf, t_unsigned_val_long);
  tcase_add_test(tcase_sprintf, t_unsigned_val_many);
  tcase_add_test(tcase_sprintf, t_octal_flags);
  tcase_add_test(tcase_sprintf, t_octal_precision);
  tcase_add_test(tcase_sprintf, t_octal_many_flags);
  tcase_add_test(tcase_sprintf, t_octal_width);
  tcase_add_test(tcase_sprintf, t_octal_zero);
  tcase_add_test(tcase_sprintf, t_octal_hash);
  tcase_add_test(tcase_sprintf, t_octal_short);
  tcase_add_test(tcase_sprintf, t_octal_long);
  tcase_add_test(tcase_sprintf, t_octal_many);
  tcase_add_test(tcase_sprintf, t_octal);
  tcase_add_test(tcase_sprintf, t_unsigned_zero);
  tcase_add_test(tcase_sprintf, t_hex_width);
  tcase_add_test(tcase_sprintf, t_hex_flags);
  tcase_add_test(tcase_sprintf, t_hex_precision);
  tcase_add_test(tcase_sprintf, t_hex_many);
  tcase_add_test(tcase_sprintf, t_hex_many_flags);
  tcase_add_test(tcase_sprintf, t_hex_zero);
  tcase_add_test(tcase_sprintf, t_hex_huge);
  tcase_add_test(tcase_sprintf, t_hex_short);
  tcase_add_test(tcase_sprintf, t_hex_long);
  tcase_add_test(tcase_sprintf, t_hex_one_longer_width);
  tcase_add_test(tcase_sprintf, t_hex_two_longer_width);
  tcase_add_test(tcase_sprintf, t_one_char);
  tcase_add_test(tcase_sprintf, t_one_precision);
  tcase_add_test(tcase_sprintf, t_one_flags);
  tcase_add_test(tcase_sprintf, t_one_width);
  tcase_add_test(tcase_sprintf, t_one_many);
  tcase_add_test(tcase_sprintf, t_one_many_flags);
  tcase_add_test(tcase_sprintf, t_string);
  tcase_add_test(tcase_sprintf, t_string_precision);
  tcase_add_test(tcase_sprintf, t_string_width);
  tcase_add_test(tcase_sprintf, t_string_flags);
  tcase_add_test(tcase_sprintf, t_string_long);
  tcase_add_test(tcase_sprintf, t_string_many);
  tcase_add_test(tcase_sprintf, t_ptr);
  tcase_add_test(tcase_sprintf, t_ptr_width);
  tcase_add_test(tcase_sprintf, t_ptr_precision);
  tcase_add_test(tcase_sprintf, t_null_ptr);
  tcase_add_test(tcase_sprintf, t_string_width_huge);
  tcase_add_test(tcase_sprintf, t_n_specifier);
  tcase_add_test(tcase_sprintf, t_float_precision);
  tcase_add_test(tcase_sprintf, t_float_width);
  tcase_add_test(tcase_sprintf, t_float_precision_zero);
  tcase_add_test(tcase_sprintf, t_float_precision_empty);
  tcase_add_test(tcase_sprintf, t_float_precision_huge);
  tcase_add_test(tcase_sprintf, t_float_precision_huge_negative);
  tcase_add_test(tcase_sprintf, t_float_huge);
  tcase_add_test(tcase_sprintf, t_float_flags);
  tcase_add_test(tcase_sprintf, t_float_many);
  tcase_add_test(tcase_sprintf, t_e_precision);
  tcase_add_test(tcase_sprintf, t_e_precision_zero);
  tcase_add_test(tcase_sprintf, t_e_precision_empty);
  tcase_add_test(tcase_sprintf, t_e_precision_huge);
  tcase_add_test(tcase_sprintf, t_e_precision_huge_negative);
  tcase_add_test(tcase_sprintf, t_e_huge);
  tcase_add_test(tcase_sprintf, t_E_flags);
  tcase_add_test(tcase_sprintf, t_e_width);
  tcase_add_test(tcase_sprintf, t_e_many);
  tcase_add_test(tcase_sprintf, t_E_int);
  tcase_add_test(tcase_sprintf, t_all_empty);
  tcase_add_test(tcase_sprintf, t_empty_format_and_parameters);
  tcase_add_test(tcase_sprintf, t_test_one_char);
  tcase_add_test(tcase_sprintf, t_test_many_char);
  tcase_add_test(tcase_sprintf, t_test_one_string);
  tcase_add_test(tcase_sprintf, t_test_many_string);
  tcase_add_test(tcase_sprintf, t_test_one_dec);
  tcase_add_test(tcase_sprintf, t_test_many_dec);
  tcase_add_test(tcase_sprintf, t_test_one_int);
  tcase_add_test(tcase_sprintf, t_test_many_int);
  tcase_add_test(tcase_sprintf, t_test_one_float);
  tcase_add_test(tcase_sprintf, t_test_many_float);
  tcase_add_test(tcase_sprintf, t_test_one_unsigned_dec);
  tcase_add_test(tcase_sprintf, t_test_many_unsigned_dec);
  tcase_add_test(tcase_sprintf, t_test_one_char_with_alignment_left);
  tcase_add_test(tcase_sprintf, t_test_one_char_with_alignment_right);
  tcase_add_test(tcase_sprintf, t_test_many_char_with_alignment);
  tcase_add_test(tcase_sprintf, t_test_one_hex_lower);
  tcase_add_test(tcase_sprintf, t_test_one_hex_upper);
  tcase_add_test(tcase_sprintf, t_test_many_hex_lower);
  tcase_add_test(tcase_sprintf, t_test_many_hex_upper);
  tcase_add_test(tcase_sprintf, t_test_many_hex_lower_with_alignment);
  tcase_add_test(tcase_sprintf, t_test_one_hex_lower_with_alignment_left);
  tcase_add_test(tcase_sprintf, t_test_one_hex_lower_with_alignment_right);
  tcase_add_test(tcase_sprintf, t_test_one_hex_upper_with_alignment_left);
  tcase_add_test(tcase_sprintf, t_test_many_hex_upper_with_alignment);
  tcase_add_test(tcase_sprintf, t_test_one_hex_upper_with_alignment_right);
  tcase_add_test(tcase_sprintf, t_test_one_hex_with_hashtag);
  tcase_add_test(tcase_sprintf, t_test_one_hex_upper_with_hashtag);
  tcase_add_test(tcase_sprintf, t_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tcase_sprintf, t_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tcase_sprintf, t_test_one_hex_lower_with_width_star);
  tcase_add_test(tcase_sprintf, t_test_one_hex_upper_with_width_star);
  tcase_add_test(tcase_sprintf,
                 t_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tcase_sprintf, t_test_many_hex_upper_with_width_star);
  tcase_add_test(tcase_sprintf, t_test_one_hex_lower_with_precision);
  tcase_add_test(tcase_sprintf, t_test_one_hex_upper_with_precision);
  tcase_add_test(tcase_sprintf, t_test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tcase_sprintf, t_test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tcase_sprintf, t_test_one_hex_lower_with_length);
  tcase_add_test(tcase_sprintf, t_test_one_hex_upper_with_length);
  tcase_add_test(tcase_sprintf, t_test_sprintf1);
  tcase_add_test(tcase_sprintf, t_test_sprintf2);
  tcase_add_test(tcase_sprintf, t_test_sprintf3);
  tcase_add_test(tcase_sprintf, t_test_sprintf4);
  tcase_add_test(tcase_sprintf, t_test_sprintf6);
  tcase_add_test(tcase_sprintf, t_test_sprintf7);
  tcase_add_test(tcase_sprintf, t_test_sprintf8);
  tcase_add_test(tcase_sprintf, t_test_sprintf9);
  tcase_add_test(tcase_sprintf, t_test_sprintf10);
  tcase_add_test(tcase_sprintf, t_test_sprintf11);
  tcase_add_test(tcase_sprintf, t_test_sprintf12);
  tcase_add_test(tcase_sprintf, t_test_sprintf14);
  tcase_add_test(tcase_sprintf, t_test_sprintf15);
  tcase_add_test(tcase_sprintf, t_test_sprintf16);
  tcase_add_test(tcase_sprintf, t_test_sprintf17);
  tcase_add_test(tcase_sprintf, t_test_sprintf18);
  tcase_add_test(tcase_sprintf, t_test_sprintf19);
  tcase_add_test(tcase_sprintf, t_test_sprintf20);
  tcase_add_test(tcase_sprintf, t_test_sprintf24);
  tcase_add_test(tcase_sprintf, t_test_sprintf25);
  tcase_add_test(tcase_sprintf, t_test_sprintf26);
  tcase_add_test(tcase_sprintf, t_test_sprintf27);
  tcase_add_test(tcase_sprintf, t_test_sprintf28);
  tcase_add_test(tcase_sprintf, t_test_sprintf29);
  tcase_add_test(tcase_sprintf, t_test_sprintf30);
  tcase_add_test(tcase_sprintf, t_test_sprintf31);
  tcase_add_test(tcase_sprintf, t_test_sprintf32);
  tcase_add_test(tcase_sprintf, t_test_sprintf33);
  tcase_add_test(tcase_sprintf, t_test_sprintf35);
  tcase_add_test(tcase_sprintf, t_test_sprintf36);
  tcase_add_test(tcase_sprintf, t_test_sprintf37);
  tcase_add_test(tcase_sprintf, t_test_sprintf38);
  tcase_add_test(tcase_sprintf, t_test_sprintf39);
  tcase_add_test(tcase_sprintf, t_test_sprintf40);
  tcase_add_test(tcase_sprintf, t_test_sprintf41);
  tcase_add_test(tcase_sprintf, t_test_sprintf42);
  tcase_add_test(tcase_sprintf, t_est_sprintf43);
  tcase_add_test(tcase_sprintf, t_test_sprintf44);
  tcase_add_test(tcase_sprintf, t_g_trailing_zero);
  tcase_add_test(tcase_sprintf, t_g_large);
  tcase_add_test(tcase_sprintf, t_g_small);
  tcase_add_test(tcase_sprintf, t_g_precision);
  tcase_add_test(tcase_sprintf, t_g_precision_zero);
  tcase_add_test(tcase_sprintf, t_g_precision_missing);
  tcase_add_test(tcase_sprintf, t_g_many_zeroes_in_front);
  tcase_add_test(tcase_sprintf, t_g_one_zero);
  tcase_add_test(tcase_sprintf, t_g_zero);
  tcase_add_test(tcase_sprintf, t_g_short_no_mantiss);

  // Добавление групп тестов в тестовый набор.
  suite_add_tcase(suite, tcase_memchr);
  suite_add_tcase(suite, tcase_memcmp);
  suite_add_tcase(suite, tcase_memcpy);
  suite_add_tcase(suite, tcase_memset);
  suite_add_tcase(suite, tcase_strncat);
  suite_add_tcase(suite, tcase_strchr);
  suite_add_tcase(suite, tcase_strncmp);
  suite_add_tcase(suite, tcase_strncpy);
  suite_add_tcase(suite, tcase_strcspn);
  suite_add_tcase(suite, tcase_strerror);
  suite_add_tcase(suite, tcase_strlen);
  suite_add_tcase(suite, tcase_strpbrk);
  suite_add_tcase(suite, tcase_strrchr);
  suite_add_tcase(suite, tcase_strstr);
  suite_add_tcase(suite, tcase_strtok);
  // Part 2, 3. sprintf
  suite_add_tcase(suite, tcase_sprintf);
  // Part 5. C# functions
  suite_add_tcase(suite, tcase_toupper);
  suite_add_tcase(suite, tcase_tolower);
  suite_add_tcase(suite, tcase_insert);
  suite_add_tcase(suite, tcase_trim);

  SRunner* suite_runner = srunner_create(suite);

  // srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов.
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  // Сигнализируем о том, что тестирование прошло неудачно.
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

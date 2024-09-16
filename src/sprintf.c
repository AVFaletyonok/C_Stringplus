#include "string.h"

struct spec_flags {
  // flags:
  bool minus;
  bool plus;
  bool space;
  bool sharp;
  bool zero;
  // width:
  bool width_setted;
  int width;  // "%*.*d", width, accuracy, a
  // .accuracy:
  bool accur_setted;
  int accuracy;
  // length:
  bool h;
  bool l;
  bool big_l;
};

void reset_flags(struct spec_flags* flags);

// returns pointer to first symbol after the flags of the current specifier
const char* parse(const char** format, struct spec_flags* flags, va_list* args);
const char* parse_flags(const char* format, struct spec_flags* flags);
const char* parse_width(const char** format, struct spec_flags* flags,
                        va_list* args);
const char* parse_accuracy(const char** format, struct spec_flags* flags,
                           va_list* args);
const char* parse_length(const char* format, struct spec_flags* flags);
int parse_number(const char** format);

const char* parse_specifier(char* str, const char** format,
                            struct spec_flags* flags, va_list* args);
void handle_c(char* str, struct spec_flags* flags, va_list* args);
void handle_d(char* str, struct spec_flags* flags, va_list* args);
void handle_d_func(char* str, struct spec_flags* flags, long long int d);
void handle_e(char* str, struct spec_flags* flags, va_list* args);
void handle_e_func(char* str, struct spec_flags* flags, int precision,
                   long long int int_part, long double dec_part);
void handle_bige(char* str, struct spec_flags* flags, va_list* args);
void handle_f(char* str, struct spec_flags* flags, va_list* args);
void handle_f_func(char* str, struct spec_flags* flags, int precision,
                   long long int int_part, long double dec_part);
void handle_g(char* str, struct spec_flags* flags, va_list* args);
void handle_bigg(char* str, struct spec_flags* flags, va_list* args);
void handle_o(char* str, struct spec_flags* flags, va_list* args);
void handle_s(char* str, struct spec_flags* flags, va_list* args);
void handle_u(char* str, struct spec_flags* flags, va_list* args);
void handle_x(char* str, struct spec_flags* flags, va_list* args);
void handle_bigx(char* str, struct spec_flags* flags, va_list* args);
void handle_p(char* str, struct spec_flags* flags, va_list* args);
void handle_n(char* str, va_list* args);
void get_intdouble_arg(struct spec_flags* flags, va_list* args, int precision,
                       long long int* int_part, long double* dec_part);
int get_exp(int int_digit_count, long double dec_part);
void handle_e_zero_precision(char* str_e, long long int* int_part,
                             int* int_digit_count, long double* dec_part,
                             int* index);
void handle_e_nzero_precision(char* str_e, const char* str_ipart,
                              long long int int_part, int int_digit_count,
                              long double dec_part, int precision, int* index);

// handle flags: minus, zero and width
void handle_str(char* str, struct spec_flags* flags, const char* inp_str);
char* handle_accuracy(char* string, int accuracy, int start_pos);
long long unsigned int handle_udlength(struct spec_flags* flags, va_list* args);

char* convert_itos(char* str, int a);
char* convert_lltos(char* str, long long int a);
char* convert_llutos(char* str, long long unsigned int a);
char* convert_lluto_notation(char* str, long long unsigned int number,
                             int notation, int digit_count);
char* convert_lluto_hex(char* string, long long unsigned int number,
                        int digit_count);

long long int reverse_number(long long int a, int* digit_count);
long long unsigned int reverse_unumber(long long unsigned int a,
                                       int* digit_count);

char* clean_insert(char* src, const char* str, _size_t start_index);

// %[флаги][ширина][.точность][длина]спецификатор
int _sprintf(char* str, const char* format, ...) {
  if (str == _NULL || format == _NULL) return 0;
  str[0] = '\0';
  struct spec_flags flags = {0};
  reset_flags(&flags);
  va_list args = {0};
  va_start(args, format);

  while (*format != '\0') {
    int clean_strlen = _strcspn(format, "%");
    if (clean_strlen > 0) _strncat(str, format, clean_strlen);
    format = format + clean_strlen;
    if (*format != '\0') format++;

    // parse flags of the current specifier
    if (*format != '\0') format = parse(&format, &flags, &args);
    // parse current specifier
    if (*format != '\0') format = parse_specifier(str, &format, &flags, &args);

    reset_flags(&flags);
  }
  va_end(args);
  int str_len = _strlen(str);
  return str_len;
}

void reset_flags(struct spec_flags* flags) {
  flags->minus = flags->plus = flags->space = flags->sharp = flags->zero =
      false;
  flags->width = flags->accuracy = 0;
  flags->width_setted = flags->accur_setted = false;
  flags->h = flags->l = flags->big_l = false;
}

const char* parse_specifier(char* str, const char** format,
                            struct spec_flags* flags, va_list* args) {
  switch (**format) {
    case ('c'):
      handle_c(str, flags, args);
      break;
    case ('d'):
    case ('i'):
      handle_d(str, flags, args);
      break;
    case ('e'):
      handle_e(str, flags, args);
      break;
    case ('E'):
      handle_bige(str, flags, args);
      break;
    case ('f'):
      handle_f(str, flags, args);
      break;
    case ('g'):
      handle_g(str, flags, args);
      break;
    case ('G'):
      handle_bigg(str, flags, args);
      break;
    case ('o'):
      handle_o(str, flags, args);
      break;
    case ('s'):
      handle_s(str, flags, args);
      break;
    case ('u'):
      handle_u(str, flags, args);
      break;
    case ('x'):
      handle_x(str, flags, args);
      break;
    case ('X'):
      handle_bigx(str, flags, args);
      break;
    case ('p'):
      handle_p(str, flags, args);
      break;
    case ('n'):
      handle_n(str, args);
      break;
    case ('%'):
      _strncat(str, "%", 1);
      break;
    default:  // wrong specifier
      break;
  }

  (*format)++;
  return *format;
}

const char* parse(const char** format, struct spec_flags* flags,
                  va_list* args) {
  *format = parse_flags(*format, flags);
  if (**format != '\0') *format = parse_width(format, flags, args);
  if (**format != '\0') *format = parse_accuracy(format, flags, args);
  if (**format != '\0') *format = parse_length(*format, flags);
  return *format;
}

const char* parse_flags(const char* format, struct spec_flags* flags) {
  bool flag_exit = false;
  for (; *format != '\0' && !flag_exit; format++) {
    char c = *format;
    switch (c) {
      case '-':
        flags->minus = true;
        break;
      case '+':
        flags->plus = true;
        break;
      case ' ':
        flags->space = true;
        break;
      case '#':
        flags->sharp = true;
        break;
      case '0':
        flags->zero = true;
        break;
      default:
        flag_exit = true;
        format--;
    }
  }
  return format;
}

const char* parse_width(const char** format, struct spec_flags* flags,
                        va_list* args) {
  if (**format == '*') {
    // Ширина не в строке формата, а в кач доп арг цел-го зн-я перед аргументом
    flags->width = va_arg(*args, int);
    flags->width_setted = true;
    (*format)++;
  } else if (**format >= '0' && **format <= '9') {
    flags->width = parse_number(format);
    flags->width_setted = true;
  }
  return *format;
}

const char* parse_accuracy(const char** format, struct spec_flags* flags,
                           va_list* args) {
  if (**format == '.') {
    (*format)++;
    // flags->zero = false;
    flags->accur_setted = true;
    if (**format == '*') {
      // Точность не в строке формата, а в кач доп арг цел-го зн-я перед
      // аргументом
      flags->accuracy = va_arg(*args, int);
      (*format)++;
    } else if (**format >= '0' && **format <= '9') {
      flags->accuracy = parse_number(format);
    }
  }
  return *format;
}

// two or three flags are forbidden
const char* parse_length(const char* format, struct spec_flags* flags) {
  char c = *format;
  switch (c) {
    case 'h':
      flags->h = true;
      format++;
      break;
    case 'l':
      flags->l = true;
      format++;
      break;
    case 'L':
      flags->big_l = true;
      format++;
      break;
    default:
      break;
  }
  return format;
}

void handle_c(char* str, struct spec_flags* flags, va_list* args) {
  char c = va_arg(*args, int);
  char str_c[2] = {c, '\0'};
  handle_str(str, flags, str_c);
}

void handle_d(char* str, struct spec_flags* flags, va_list* args) {
  long long int d = 0;
  if (flags->h == true)
    d = va_arg(*args, int);
  else if (flags->l == true)
    d = va_arg(*args, long int);
  else if (flags->big_l == true)
    d = va_arg(*args, long long int);
  else
    d = va_arg(*args, int);

  handle_d_func(str, flags, d);
}

void handle_d_func(char* str, struct spec_flags* flags, long long int d) {
  char str_d[256] = {'\0'};
  _memset(str_d, '\0', 256);
  convert_lltos(str_d, d);
  int len = _strlen(str_d);
  if (len == 0 && (flags->accur_setted == false ||
                   (flags->accur_setted == true && flags->accuracy != 0)))
    str_d[len++] = '0';
  // minus was added in convert_lltos()
  if (flags->plus == true && d > 0) clean_insert(str_d, "+", 0);
  if (flags->space == true && str_d[0] != '-' && str_d[0] != '+')
    clean_insert(str_d, " ", 0);

  len = _strlen(str_d);
  int start_pos = 0;
  if (str_d[0] == '-' || str_d[0] == '+' || str_d[0] == ' ') {
    len--;
    start_pos = 1;
  }

  // add '0' on the left
  if (flags->accuracy > len) handle_accuracy(str_d, flags->accuracy, start_pos);

  // handle flags: minus, zero and width
  handle_str(str, flags, str_d);
}

int get_exp(int int_digit_count, long double dec_part) {
  int result = 0;
  if (int_digit_count > 0)
    result = int_digit_count - 1;
  else {
    if (!(dec_part < 1e-18)) {
      for (int i = 0; i < 19 && (int)dec_part == 0; i++) {
        result--;
        dec_part *= 10;
      }
    }
  }
  return result;
}

void handle_bige(char* str, struct spec_flags* flags, va_list* args) {
  char temp_str[256] = "";
  _memset(temp_str, '\0', 256);
  handle_e(temp_str, flags, args);
  int len = _strlen(temp_str);
  char* upper_str = _to_upper(temp_str);
  _strncat(str, upper_str, len);
  free(upper_str);
}

void handle_e(char* str, struct spec_flags* flags, va_list* args) {
  int precision = 6;
  if (flags->accur_setted == true) precision = flags->accuracy;

  long long int int_part = 0;
  long double dec_part = 0;
  get_intdouble_arg(flags, args, precision, &int_part, &dec_part);

  handle_e_func(str, flags, precision, int_part, dec_part);
}

void handle_e_func(char* str, struct spec_flags* flags, int precision,
                   long long int int_part, long double dec_part) {
  int exp = 0, index = 0;
  char str_e[256] = "";
  _memset(str_e, '\0', 256);
  if (int_part < 0) {
    int_part = -int_part;
    str_e[index++] = '-';
  }
  char str_ipart[256] = "";
  _memset(str_ipart, '\0', 256);

  convert_lltos(str_ipart, int_part);
  int int_digit_count = _strlen(str_ipart);
  exp = get_exp(int_digit_count, dec_part);

  if (precision == 0) {
    handle_e_zero_precision(str_e, &int_part, &int_digit_count, &dec_part,
                            &index);
  } else {
    handle_e_nzero_precision(str_e, str_ipart, int_part, int_digit_count,
                             dec_part, precision, &index);
  }

  str_e[index++] = 'e';
  str_e[index++] = exp >= 0 ? '+' : '-';
  str_e[index++] = '0' + abs(exp / 10 % 10);
  str_e[index++] = '0' + abs(exp % 10);
  str_e[index] = '\0';

  if (flags->plus == true && str_e[0] != '-') clean_insert(str_e, "+", 0);
  if (flags->space == true && str_e[0] != '-' && str_e[0] != '+')
    clean_insert(str_e, " ", 0);
  handle_str(str, flags, str_e);
}

void handle_e_zero_precision(char* str_e, long long int* int_part,
                             int* int_digit_count, long double* dec_part,
                             int* index) {
  if (*int_digit_count > 0) {
    *int_part =
        (int)round((long double)*int_part / (pow(10, *int_digit_count - 1)));
    *int_digit_count = 1;
    str_e[(*index)++] = '0' + *int_part % 10;
  } else {
    int digit = 0;
    for (int i = 0; i < 19 && digit == 0; i++) {
      *dec_part -= digit;
      *dec_part *= 10;
      digit = (int)*dec_part;
      if (digit > 9) digit = 9;
    }
    str_e[(*index)++] = '0' + (int)round(*dec_part);
  }
}

void handle_e_nzero_precision(char* str_e, const char* str_ipart,
                              long long int int_part, int int_digit_count,
                              long double dec_part, int precision, int* index) {
  int digit = 0;
  if (int_digit_count > 0) {
    int int_index = 0;
    str_e[(*index)++] = str_ipart[int_index++];
    int_digit_count--;
    str_e[(*index)++] = '.';
    for (int i = 1; int_digit_count > 0 && precision > 0; int_digit_count--) {
      if (int_digit_count > 1 && precision > 1)
        str_e[(*index)++] = str_ipart[int_index++];
      else {
        digit = ((int)round(int_part / pow(10, int_digit_count - 1))) % 10;
        if (int_digit_count == 1 && precision == 1)
          digit += (int)round(dec_part);
        str_e[(*index)++] = '0' + digit;
      }
      precision--;
      i++;
    }
  } else {
    for (int i = 0; i < 19 && digit == 0; i++) {
      dec_part *= 10;
      digit = (int)dec_part;
      dec_part -= digit;
      if (digit > 9) digit = 9;
    }
    str_e[(*index)++] = '0' + digit;
    str_e[(*index)++] = '.';
  }

  for (; precision > 0; precision--) {
    dec_part *= 10;
    digit = precision == 1 ? (int)round(dec_part) : (int)dec_part;
    if (digit > 9) digit = 9;  // Проверка на ошибки округления
    str_e[(*index)++] = '0' + digit;
    dec_part -= digit;
    // Округляем для предотвращения ошибок накопления
    dec_part = ((long double)round(dec_part * pow(10, precision - 1))) /
               pow(10, precision - 1);
  }
}

// мантиса - 7 значащих цифр, 1,175494351 E –38 ... 3,402823466 E +38
void handle_f(char* str, struct spec_flags* flags, va_list* args) {
  int precision = 6;
  if (flags->accur_setted == true) precision = flags->accuracy;

  long long int int_part = 0;
  long double dec_part = 0;
  get_intdouble_arg(flags, args, precision, &int_part, &dec_part);

  handle_f_func(str, flags, precision, int_part, dec_part);
}

void handle_f_func(char* str, struct spec_flags* flags, int precision,
                   long long int int_part, long double dec_part) {
  char str_ld[256] = "";
  _memset(str_ld, '\0', 256);

  convert_lltos(str_ld, int_part);
  int len = _strlen(str_ld);
  if (len == 0) str_ld[len++] = '0';

  int index = _strlen(str_ld);
  if (precision > 0) str_ld[index++] = '.';

  for (; precision > 0; precision--) {
    dec_part *= 10;
    int digit = (int)dec_part;
    // Проверка на ошибки округления
    if (digit > 9) digit = 9;
    str_ld[index++] = '0' + digit;
    dec_part -= digit;
    // Округляем для предотвращения ошибок накопления
    dec_part = ((long double)round(dec_part * pow(10, precision - 1))) /
               pow(10, precision - 1);
  }
  str_ld[index] = '\0';

  //  обработать флаги
  if (flags->plus == true && int_part > 0) clean_insert(str_ld, "+", 0);
  if (flags->space == true && str_ld[0] != '-' && str_ld[0] != '+')
    clean_insert(str_ld, " ", 0);

  len = _strlen(str_ld);
  int start_pos = 0;
  if (str_ld[0] == '-' || str_ld[0] == '+' || str_ld[0] == ' ') {
    len--;
    start_pos = 1;
  }
  if (flags->minus == false && flags->zero == true &&
      flags->width > len) {  // add '0' on the left
    char buf[256] = {'\0'};
    _memset(buf, '\0', 256);
    _memset(buf, '0', flags->width - len);
    clean_insert(str_ld, buf, start_pos);
  }
  flags->zero = false;
  // handle flags: minus, zero and width
  handle_str(str, flags, str_ld);
}

void get_intdouble_arg(struct spec_flags* flags, va_list* args, int precision,
                       long long int* int_part, long double* dec_part) {
  long double ld = 0;
  if (flags->l == true)
    ld = va_arg(*args, double);  // 15 digits
  else if (flags->big_l == true)
    ld = va_arg(*args, long double);  // 19 digits
  else                                // float
    ld = va_arg(*args, double);       // 7 digits
  // преобразование целой части
  *int_part = (long long int)(ld);
  // преобразование дробной части
  *dec_part = (long double)(ld - *int_part);
  if (*dec_part < 0) *dec_part = -*dec_part;
  if (precision == 0) {
    int overload_part = round(*dec_part);
    if (overload_part > 0) *int_part += overload_part;
  }
}

void handle_g(char* str, struct spec_flags* flags, va_list* args) {
  char result_str[256] = "";
  int precision = 6;
  if (flags->accur_setted == true) precision = flags->accuracy;

  long long int int_part = 0;
  long double dec_part = 0;
  get_intdouble_arg(flags, args, precision, &int_part, &dec_part);

  // change precision for g specifier
  char str_int_part[256] = "";
  _memset(str_int_part, '\0', 256);
  convert_lltos(str_int_part, int_part);
  int int_len = _strlen(str_int_part);
  if (str_int_part[0] == '-') int_len--;
  if (int_len == 0 && precision == 0) precision = -get_exp(int_len, dec_part);
  precision -= int_len;

  if (dec_part > pow(10, -precision)) {
    char str_f[256] = "";
    handle_f_func(str_f, flags, precision, int_part, dec_part);
    int len_f = _strlen(str_f);
    _strncpy(result_str, str_f, len_f);
    result_str[len_f] = '\0';
    for (; len_f > 0 && result_str[len_f - 1] == '0'; len_f--)
      result_str[len_f - 1] = '\0';
  } else {
    char str_d[256] = "";
    if (int_len < 2) flags->accuracy = 1;
    handle_d_func(str_d, flags, int_part);
    int len_d = _strlen(str_d);
    _strncpy(result_str, str_d, len_d);
    result_str[len_d] = '\0';
  }
  int result_len = _strlen(result_str);

  char str_e[256] = "";

  handle_e_func(str_e, flags, precision, int_part, dec_part);

  int len_e = _strlen(str_e);
  if (len_e < result_len) {
    _strncpy(result_str, str_e, len_e);
    result_str[len_e] = '\0';
  }

  result_len = _strlen(result_str);
  _strncat(str, result_str, result_len);
}

void handle_bigg(char* str, struct spec_flags* flags, va_list* args) {
  char temp_str[256] = "";
  _memset(temp_str, '\0', 256);
  handle_g(temp_str, flags, args);
  int len = _strlen(temp_str);
  char* upper_str = _to_upper(temp_str);
  _strncat(str, upper_str, len);
  free(upper_str);
}

// Беззнаковое восьмеричное число
// flags->plus = flags->space = false;
void handle_o(char* str, struct spec_flags* flags, va_list* args) {
  long long unsigned int o_number = 0;  // 20 digits - 8 bytes
  o_number = handle_udlength(flags, args);

  char str_o[256] = "";
  _memset(str_o, '\0', 256);
  convert_lluto_notation(str_o, o_number, 8, 19);
  int len = _strlen(str_o);
  if (len == 0 && (flags->accur_setted == false ||
                   (flags->accur_setted == true && flags->accuracy != 0)))
    str_o[len++] = '0';
  if (flags->sharp == true && !(len == 1 && str_o[0] == '0'))
    clean_insert(str_o, "0", 0);

  len = _strlen(str_o);
  // add '0' on the left
  if (flags->accuracy > len) handle_accuracy(str_o, flags->accuracy, 0);

  // handle flags: minus, zero and width
  handle_str(str, flags, str_o);
}

void handle_s(char* str, struct spec_flags* flags, va_list* args) {
  char* inp_str = va_arg(*args, char*);
  char temp_str[256] = "";
  _memset(temp_str, '\0', 256);

  int len = _strlen(inp_str);
  if (flags->accur_setted == true && flags->accuracy < len)
    len = flags->accuracy;
  _strncpy(temp_str, inp_str, len);
  temp_str[len] = '\0';
  handle_str(str, flags, temp_str);
}

// Беззнаковое десятичное целое число
// flags->plus = flags->space = false;
void handle_u(char* str, struct spec_flags* flags, va_list* args) {
  long long unsigned int u_number = 0;  // 20 digits - 8 bytes
  u_number = handle_udlength(flags, args);
  char str_u[256] = {'\0'};
  _memset(str_u, '\0', 256);
  convert_llutos(str_u, u_number);

  int len = _strlen(str_u);
  if (len == 0 && (flags->accur_setted == false ||
                   (flags->accur_setted == true && flags->accuracy != 0)))
    str_u[len++] = '0';
  // add '0' on the left
  if (flags->accuracy > len) handle_accuracy(str_u, flags->accuracy, 0);

  // handle flags: minus, zero and width
  handle_str(str, flags, str_u);
}

// Беззнаковое шестнадцатеричное целое число
// flags->plus = flags->space = false;
void handle_x(char* str, struct spec_flags* flags, va_list* args) {
  long long unsigned int x_number = 0;  // 20 digits - 8 bytes
  x_number = handle_udlength(flags, args);

  char str_hex[256] = {'\0'};
  _memset(str_hex, '\0', 256);
  convert_lluto_hex(str_hex, x_number, 20);

  int len = _strlen(str_hex);
  if (len == 0 && (flags->accur_setted == false ||
                   (flags->accur_setted == true && flags->accuracy != 0))) {
    str_hex[len++] = '0';
    str_hex[len] = '\0';
  }
  int start_pos = 0;
  len = _strlen(str_hex);
  if (flags->sharp == true && (len > 1 || x_number > 0)) {
    clean_insert(str_hex, "0x", 0);
    start_pos = 2;
  }
  // add '0' on the left
  if (flags->accuracy > len)
    handle_accuracy(str_hex, flags->accuracy, start_pos);

  // handle flags: minus, zero and width
  handle_str(str, flags, str_hex);
}

// Беззнаковое шестнадцатеричное целое число (заглавные буквы)
void handle_bigx(char* str, struct spec_flags* flags, va_list* args) {
  char temp_str[256] = "";
  _memset(temp_str, '\0', 256);
  handle_x(temp_str, flags, args);
  int len = _strlen(temp_str);
  char* upper_str = _to_upper(temp_str);
  _strncat(str, upper_str, len);
  free(upper_str);
}

void handle_p(char* str, struct spec_flags* flags, va_list* args) {
  long long unsigned int p = va_arg(*args, long long unsigned int);
  char str_p[256] = "";
  _memset(str_p, '\0', 256);
  convert_lluto_hex(str_p, p, 20);
  int len = _strlen(str_p);
  if (len == 0 && (flags->accur_setted == false ||
                   (flags->accur_setted == true && flags->accuracy != 0))) {
    str_p[len++] = '0';
    str_p[len] = '\0';
  }
  clean_insert(str_p, "0x", 0);

  char buf[256] = "";
  _memset(buf, ' ', 256);
  len = _strlen(str_p);
  if (flags->minus == true) {  // align left side
    _strncat(str, str_p, len);
    if (flags->width > len) _strncat(str, buf, flags->width - len);
  } else {  // align right side
    if (flags->width > len) _strncat(str, buf, flags->width - len);
    _strncat(str, str_p, len);
  }
}

void handle_n(char* str, va_list* args) {
  int len = _strlen(str);
  int* i_pointer = _NULL;
  i_pointer = va_arg(*args, int*);
  *i_pointer = len;
}

// handle flags: minus, zero and width
void handle_str(char* str, struct spec_flags* flags, const char* inp_str) {
  int len = _strlen(inp_str);
  char buf[256] = "";
  _memset(buf, ' ', 256);

  if (flags->minus == true) {  // align left side
    _strncat(str, inp_str, len);
    if (flags->width > len) _strncat(str, buf, flags->width - len);
  } else {                                            // align right side
    if (flags->zero == true && flags->width > len) {  // add '0' on the left
      _memset(buf, '0', flags->width - len);
      _strncat(str, buf, flags->width - len);
    } else if (flags->zero == false && flags->width > len)  //' ' on the left
      _strncat(str, buf, flags->width - len);

    _strncat(str, inp_str, len);
  }
}

char* handle_accuracy(char* string, int accuracy, int start_pos) {
  int len = _strlen(string) - start_pos;
  char buf[256] = {'\0'};
  _memset(buf, '\0', 256);
  _memset(buf, '0', accuracy - len);
  clean_insert(string, buf, start_pos);
  return string;
}

long long unsigned int handle_udlength(struct spec_flags* flags,
                                       va_list* args) {
  long long unsigned int unumber = 0;
  if (flags->h == true)
    unumber = va_arg(*args, int);
  else if (flags->l == true)
    unumber = va_arg(*args, long unsigned int);
  else if (flags->big_l == true)
    unumber = va_arg(*args, long long unsigned int);
  else
    unumber = va_arg(*args, unsigned int);
  return unumber;
}

int parse_number(const char** format) {
  int result = 0;
  for (; **format != '\0'; (*format)++) {
    char c = **format;
    if (c >= '0' && c <= '9')
      result = 10 * result + (int)(c - '0');
    else
      break;
  }
  return result;
}

char* convert_lltos(char* str, long long int a) {
  long long int rev_a = 0;
  int index = 0;
  int digit_count = 18;  // long int 8 bytes, long long int 8 bytes
  if (a < 0) {
    str[0] = '-';
    index++;
  }
  rev_a = reverse_number(a, &digit_count);
  if (rev_a < 0) rev_a = -rev_a;
  for (int i = 0; i < digit_count; i++) {
    str[index++] = '0' + rev_a % 10;
    rev_a /= 10;
  }
  int len = _strlen(str);
  for (; len < digit_count; len++) str[index++] = '0';
  str[index] = '\0';
  return str;
}

char* convert_llutos(char* str, long long unsigned int a) {
  long long unsigned int rev_a = 0;
  int digit_count = 19;

  rev_a = reverse_unumber(a, &digit_count);
  int i = 0;
  for (; i < digit_count; i++) {
    str[i] = '0' + rev_a % 10;
    rev_a /= 10;
  }
  int len = _strlen(str);
  for (; len < digit_count; len++) str[i++] = '0';
  str[i] = '\0';
  return str;
}

char* convert_lluto_notation(char* str, long long unsigned int number,
                             int notation, int digit_count) {
  long long unsigned int oct = 0;
  int cur_digit_count = 0;
  for (int i = 0; i < digit_count; i++) {
    oct = 10 * oct + number % notation;
    if (number % notation != 0) cur_digit_count = i + 1;
    number /= notation;
  }
  for (int i = 0; i < digit_count; i++) {
    if (oct % 10 == 0)
      oct /= 10;
    else
      break;
  }
  int i = 0;
  for (; i < cur_digit_count; i++) {
    str[i] = '0' + oct % 10;
    oct /= 10;
  }
  str[i] = '\0';
  return str;
}

// converts to hex notation
char* convert_lluto_hex(char* string, long long unsigned int number,
                        int digit_count) {
  int notation = 16;
  int cur_digit_count = 0;
  for (int i = 0; i < digit_count; i++) {
    char c = ' ';
    int digit = (int)(number % notation);
    if ((int)(number % notation) != 0) cur_digit_count = i + 1;
    switch (digit) {
      case 10:
        c = 'a';
        break;
      case 11:
        c = 'b';
        break;
      case 12:
        c = 'c';
        break;
      case 13:
        c = 'd';
        break;
      case 14:
        c = 'e';
        break;
      case 15:
        c = 'f';
        break;
      default:
        c = '0' + digit;
    }
    string[i] = c;
    number /= notation;
  }

  int index = 24;
  for (; index >= 0 && (string[index] == '\0' || string[index] == '0'); index--)
    ;
  string[index + 1] = '\0';
  int i = 0;
  while (i < index) {
    char temp = string[i];
    string[i] = string[index];
    string[index] = temp;
    i++;
    index--;
  }
  int len = _strlen(string);
  for (; len < cur_digit_count; len++) string[i++] = '0';
  string[cur_digit_count] = '\0';
  return string;
}

long long int reverse_number(long long int a, int* digit_count) {
  long long int rev_a = 0;
  int cur_digit_count = 0;
  for (int i = 0; i < *digit_count; i++) {
    rev_a = 10 * rev_a + a % 10;
    if (a % 10 != 0) cur_digit_count = i + 1;
    a /= 10;
  }
  for (int i = 0; i < *digit_count; i++) {
    if (rev_a % 10 == 0)
      rev_a /= 10;
    else
      break;
  }
  *digit_count = cur_digit_count;
  return rev_a;
}

long long unsigned int reverse_unumber(long long unsigned int a,
                                       int* digit_count) {
  long long unsigned int rev_a = 0;
  int cur_digit_count = 0;
  for (int i = 0; i < *digit_count; i++) {
    rev_a = 10 * rev_a + a % 10;
    if (a % 10 != 0) cur_digit_count = i + 1;
    a /= 10;
  }
  for (int i = 0; i < *digit_count; i++) {
    if (rev_a % 10 == 0)
      rev_a /= 10;
    else
      break;
  }
  *digit_count = cur_digit_count;
  return rev_a;
}

char* clean_insert(char* src, const char* str, _size_t start_index) {
  char* buf = _insert(src, str, start_index);
  int len = _strlen(buf);
  _strncpy(src, buf, len);
  src[len] = '\0';
  free(buf);
  return src;
}

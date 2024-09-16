#include "string.h"

void *_memchr(const void *str, int c, _size_t n) {
  if (str == _NULL) return _NULL;
  unsigned char *byte = (unsigned char *)str;
  unsigned char *result = _NULL;

  for (_size_t i = 0; i < n; i++) {
    if (byte[i] == (unsigned char)c) {
      result = byte + i;
      break;
    }
  }
  return result;
}

int _memcmp(const void *str1, const void *str2, _size_t n) {
  if (str1 == _NULL || str2 == _NULL) {
    perror("Erorr. str1 or str2 eq _NULL");
  }
  int res = 0;
  while (n--) {
    if (*(unsigned char *)str1 != *(unsigned char *)str2) {
      res = *(unsigned char *)str1 - *(unsigned char *)str2;
      break;
    }
    str1 = (void *)((unsigned char *)str1 + 1);
    str2 = (void *)((unsigned char *)str2 + 1);
  }

  return res;
}

void *_memcpy(void *dest, const void *src, _size_t n) {
  if (dest == _NULL || src == _NULL) return _NULL;
  char *d = (char *)dest;  // приведение типа
  const char *s = (const char *)src;

  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

void *_memset(void *str, int c, _size_t n) {
  if (str == _NULL) return _NULL;
  for (size_t i = 0; i < n; ++i) {
    ((char *)str)[i] = (char)c;  //приведение типа из блока символов в один
  }
  return str;
}

char *_strncat(char *dest, const char *src, _size_t n) {
  if (dest == _NULL || src == _NULL) return _NULL;
  _size_t dest_len = _strlen(dest);
  _size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

char *_strchr(const char *str, int c) {
  if (str == _NULL) return _NULL;
  char *result = _NULL;
  int len = _strlen(str) + 1;

  for (int i = 0; i < len; i++) {
    if (str[i] == c) {  // standart strings works on tests: str[i] == (char)c;
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

int _strncmp(const char *str1, const char *str2, _size_t n) {
  if (str1 == _NULL || str2 == _NULL) {
    perror("Erorr. str1 or str2 eq _NULL");
  }
  int res = 0;
  while (n--) {
    if (*str1 != *str2) {
      res = *(unsigned char *)str1 - *(unsigned char *)str2;
      break;
    }

    str1++;
    str2++;
  }
  return res;
}

char *_strncpy(char *dest, const char *src, _size_t n) {
  if (dest == _NULL || src == _NULL) return _NULL;

  _size_t src_len = _strlen(src);
  if (n > src_len) n = src_len + 1;

  for (_size_t i = 0; i < n; i++) dest[i] = src[i];

  return dest;
}

_size_t _strcspn(const char *str1, const char *str2) {
  if (str1 == _NULL || str2 == _NULL) return 0;
  _size_t len = 0;
  while (str1[len] != '\0' && _strchr(str2, str1[len]) == _NULL) {
    len++;
  }
  return len;
}

_size_t _strlen(const char *str) {
  if (str == _NULL) return 0;
  _size_t len = 0;
  for (; str[len] != '\0'; len++)
    ;
  return len;
}

char *_strpbrk(const char *str1, const char *str2) {
  if (str1 == _NULL || str2 == _NULL) return _NULL;

  _size_t str1_len = _strlen(str1);
  _size_t str2_len = _strlen(str2);
  if (str1_len < 1 || str2_len < 1) return _NULL;

  int flag = 0;
  _size_t i = 0;
  for (; i < str1_len && flag == 0; i++)
    for (_size_t j = 0; j < str2_len && flag == 0; j++)
      if (str1[i] == str2[j]) flag = 1;

  char *result = _NULL;
  if (flag == 1) result = (char *)(str1 + i - 1);

  return result;
}

char *_strrchr(const char *str, int c) {
  if (str == _NULL) return _NULL;
  char *result = _NULL;
  int len = _strlen(str) + 1;

  for (int i = len; i >= 0; i--) {
    if (str[i] == c) {  // standart strings works on tests: str[i] == (char)c;
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

char *_strstr(const char *haystack, const char *needle) {
  if (haystack == _NULL || needle == _NULL) return _NULL;
  char *result = _NULL;

  if (*needle == '\0') {
    result = (char *)haystack;

  } else {
    for (char *h = (char *)haystack; *h != '\0'; h++) {
      char *start_h = h;
      char *n = (char *)needle;

      while (*h == *n && *h != '\0' && *n != '\0') {
        h++;
        n++;
      }

      if (*n == '\0') {
        result = start_h;
        break;
      }
      h = start_h;
    }
  }
  return result;
}

// if delim == "", returns all the rest part of the str
char *_strtok(char *str, const char *delim) {
  static char *p_str = _NULL;
  if ((str == _NULL && p_str == _NULL) || delim == _NULL) return _NULL;

  _size_t str_len = 0;
  if (str != _NULL) p_str = str;
  str_len = _strlen(p_str);

  static char *res = _NULL;
  if (str_len > 0) {
    _size_t delim_len = _strlen(delim);
    if (delim_len < 1)
      res = p_str;
    else {
      _size_t res_len = _strcspn(p_str, delim);
      while (res_len == 0 && str_len > 0) {
        p_str++;
        str_len--;
        res_len = _strcspn(p_str, delim);
      }
      res = res_len > 0 ? p_str : _NULL;
      if (res_len < str_len - 1 && res_len != 0)
        p_str = p_str + res_len + 1;
      else
        p_str = _NULL;
      if (res != _NULL) res[res_len] = '\0';
    }
  }
  return res;
}

// Part 5. C# functions
void *_to_upper(const char *str) {
  if (str == _NULL) return _NULL;
  int len = _strlen(str);
  char *result = malloc(len + 1);
  if (result != _NULL) {
    _strncpy(result, str, len);
    result[len] = '\0';

    for (int i = 0; i < len; i++) {
      if (result[i] >= 'a' && result[i] <= 'z') {
        result[i] -= 32;
      }
    }
  }
  return result;
}

void *_to_lower(const char *str) {
  if (str == _NULL) return _NULL;
  int len = _strlen(str);
  char *result = malloc(len + 1);
  if (result != _NULL) {
    _strncpy(result, str, len);
    result[len] = '\0';
    for (int i = 0; i < len; i++) {
      if (result[i] >= 'A' && result[i] <= 'Z') {
        result[i] += 32;
      }
    }
  }
  return result;
}

void *_insert(const char *src, const char *str, _size_t start_index) {
  if (src == _NULL || str == _NULL || start_index > _strlen(src)) return _NULL;

  _size_t src_len = _strlen(src);
  _size_t str_len = _strlen(str);
  _size_t new_len = src_len + str_len;

  // Создаем новую строку, достаточную для хранения результата
  char *result = (char *)malloc(new_len + 1);  // +1 для завершающего нуля

  if (result != _NULL) {
    // Копируем часть исходной строки до позиции вставки
    _strncpy(result, src, start_index);
    result[start_index] = '\0';
    // Добавляем вставляемую строку
    _strncat(result, str, str_len);
    // Добавляем оставшуюся часть исходной строки после позиции вставки
    _strncat(result, src + start_index, src_len - start_index);
  } else
    result = _NULL;  // Не удалось выделить память

  return result;
}

void *_trim(const char *src, const char *trim_chars) {
  if (src == _NULL || trim_chars == _NULL) return _NULL;

  const char *start = src;
  const char *end = start + _strlen(start);
  while (*start != '\0' && _strchr(trim_chars, *start) != _NULL) start++;

  while (end >= start && _strchr(trim_chars, *end) != _NULL) end--;

  _size_t len = (_size_t)(end - start) + 1;
  char *result = (char *)malloc((len + 1) * sizeof(char));
  if (result != _NULL) {
    _strncpy(result, start, len);
    result[len] = '\0';
  }

  return result;
}

// %[ширина][длина]спецификатор
int _sscanf(const char *str, const char *format, ...) {
  if (str == _NULL || format == _NULL) return 0;
  va_list args = {0};
  va_start(args, format);

  while (*format != '\0') {
    int clean_strlen = _strcspn(format, "%");
    format = format + clean_strlen;

    // parse flags of the current specifier

    // parse current specifier
    if (*format != '\0') format = parse_spec(str, &format, &args);
  }
  va_end(args);
  return _strlen(str);
  ;
}

const char *parse_spec(const char *str, const char **format, va_list *args) {
  if (str == _NULL || format == _NULL) return _NULL;
  switch (**format) {
    case ('c'):
      char c = va_arg(*args, int);
      c = c;
      break;
    case ('d'):
      break;
    default:  // wrong specifier
      break;
  }
  (*format)++;
  return *format;
}

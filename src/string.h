#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define _NULL ((void*)0)

typedef long unsigned _size_t;

void* _memchr(const void* str, int c, _size_t n);
int _memcmp(const void* str1, const void* str2, _size_t n);
void* _memcpy(void* dest, const void* src, _size_t n);
void* _memset(void* str, int c, _size_t n);
char* _strncat(char* dest, const char* src, _size_t n);
char* _strchr(const char* str, int c);
int _strncmp(const char* str1, const char* str2, _size_t n);
char* _strncpy(char* dest, const char* src, _size_t n);
size_t _strcspn(const char* str1, const char* str2);
char* _strerror(int errnum);
_size_t _strlen(const char* str);
char* _strpbrk(const char* str1, const char* str2);
char* _strrchr(const char* str, int c);
char* _strstr(const char* haystack, const char* needle);
char* _strtok(char* str, const char* delim);

int _sprintf(char* str, const char* format, ...);

int _sscanf(const char* str, const char* format, ...);
const char* parse_spec(const char* str, const char** format, va_list* args);

// Part 5. Дополнительно. Реализация С# функций обработки строк
// Возвращает копию строки (str) в верхнем регистре. В случае возвращает NULL.
void* _to_upper(const char* str);
void* _to_lower(const char* str);
void* _insert(const char* src, const char* str, _size_t start_index);
void* _trim(const char* src, const char* trim_chars);

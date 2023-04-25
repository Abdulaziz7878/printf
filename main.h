#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DATA_TYPE
#define UNUSED(x) (void)(x)
#define B_SIZE 1024
/**
 * struct fmt - create struct
 * @fmt: type specifier char
 * @fn: function
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[]);
} fmt_t;

int _length_mods(const char *s, int j);

#if H_FLAG
	#define DATA_TYPE short
#elif HH_FLAG
	#define DATA_TYPE short
#elif L_FLAG
	#define DATA_TYPE long
#endif
/**
 * struct conversion - struct
 * @conv_spec: conversion specifier
 * @f: function to be executed
 */
struct conversion
{
	char conv_spec;
	int (*f)(va_list, char, int);
};
typedef struct conversion conv_list;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[]);
/****formats****/
int print_char(va_list list, char buffer[]);
int print_string(va_list list, char buffer[]);
int print_percent(va_list list, char buffer[]);
int print_int(va_list list, char buffer[]);
int print_binary(va_list list, char buffer[]);
/****formats2****/
int print_pointer(va_list list, char buffer[]);
/****custom****/
int print_reverse(va_list list, char buffer[]);
int print_rot13(va_list list, char buffer[]);
int print_unprintable(va_list list, char buffer[]);
int add_hex(char c, char buffer[], int i);
int _printf(const char *format, ...);
int call_funcs(conv_list *conversion,
		va_list conv, const char *format);
int format_checker(const char *format, int *i, int *j,
		va_list conv, conv_list *conversion);
int _field_width(const char *s, int j);

int _putchar(char c);

int _strlen(const char *s);
int _strrev(char *s, int i);

int _conv_flag(const char *s, int j);

int conv_c(va_list conv, char f, int w);
int conv_percent(va_list conv, char f, int w);
int conv_s(va_list conv, char f, int w);
int conv_i_d(va_list conv, char f, int w);
int conv_b(va_list conv, char f, int w);
int conv_u(va_list conv, char f, int w);
int conv_o(va_list conv, char f, int w);
int conv_x(va_list conv, char f, int w);
int conv_X(va_list conv, char f, int w);
int conv_S(va_list conv, char f, int w);
int conv_p(va_list conv, char f, int w);
int conv_r(va_list conv, char f, int w);
int conv_R(va_list conv, char f, int w);

#endif


#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct flags
{
	char *flags;
	int values[5];
	int values_size;
	int width;
	int prec;
	int lng;
} flags_t;

typedef struct spec
{
	char s;
	char *(*f)(va_list, flags_t);
} spec_t;

typedef struct out_f
{
	int has_ast;
	int value;
} out_f_t;

int _printf(const char *format, ...);
char *print_d(va_list, flags_t);
char *print_s(va_list, flags_t);
char *print_c(va_list, flags_t);
char *print_b(va_list, flags_t);
char *print_ud(va_list, flags_t);
char *print_o(va_list, flags_t);
char *print_h(va_list, flags_t);
char *print_uh(va_list, flags_t);
char *print_p(va_list, flags_t);
char *print_rev(va_list, flags_t);
char *print_rot13(va_list, flags_t);

#endif /* HOLBERTON_H */

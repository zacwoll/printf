#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct spec
{
	char s;
	char *(*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
char *print_d(va_list);
char *print_s(va_list);
char *print_S(va_list);
char *print_perc(va_list);
char *print_c(va_list);
char *print_b(va_list);
char *print_ud(va_list);
char *print_o(va_list);
char *print_h(va_list);
char *print_u(va_list);
char *print_p(va_list);
char *print_x(va_list);
char *print_X(va_list);
char *print_rev(va_list);
char *print_rot13(va_list);

char *convert_to_hex(int dec);

#endif /* HOLBERTON_H */

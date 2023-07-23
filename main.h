#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

struct specifier_formater
{
	char specifier;
	int (*function)(va_list);
};
int _putchar(char c);
unsigned int _strlen(const char *s);
int print_number(va_list number);
int _printf(const char *format, ...);
int _power(int base, int exponent);
int number_len(long int n);
#endif


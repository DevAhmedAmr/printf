#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

struct specifier_formater
{
	char specifier;
	int (*function)(va_list);
};
unsigned long int _power(int base, int exponent);
int number_len(long int n);
int _putchar(char c);
unsigned int _strlen(const char *s);
int print_number(va_list number);
void num_print_helper(int n, int *bytes);
int _printf(const char *format, ...);
#endif

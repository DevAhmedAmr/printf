#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct specifier_formater - struct that determine which function
 * that will handel the input to be printed
 *
 * members:
 * @specifier: the specifier that will determine which function
 * that will handel the input
 *
 * @function: the function that will handel and print the input
 */

struct specifier_formater
{
	char specifier;
	int (*function)(va_list);
};

int char_printer(va_list c);
int string_printer(va_list string);
unsigned long int _power(int base, int exponent);
int number_len(long int n);
int _putchar(char c);
unsigned int _strlen(const char *s);
int print_number(va_list number);
void num_print_helper(int n, int *bytes);
int _printf(const char *format, ...);
void formatSpecifierHandler(char specifier, int *bytes, va_list arguments);
#endif

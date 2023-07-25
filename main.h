#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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

typedef struct specifier_formater
{
	char specifier;
	int (*function)(va_list);
} specifier_formater;

/**
* struct - struct contain all numerical value 0 - 15 corresponding character in hexadecimal
* @N: int for numerical value
*@C: char for cj=harcter
*/
typedef struct {
	int N;
	char C;
} HexChar;


int char_printer(va_list c);
int string_printer(va_list string);
unsigned int _power(long int base, unsigned int exponent);
unsigned int number_len(unsigned int n);
int _putchar(char c);
unsigned int _strlen(const char *s);
int print_number(va_list number);
void num_print_helper(int n, int *bytes);
int _printf(const char *format, ...);
void formatSpecifierHandler(char specifier, int *bytes, va_list arguments);
int print_binary(va_list arg);
int unsigned_printer(va_list arg);
int Reverse(char *binBuff);
int hex_capital(va_list args);
int hex_small(va_list args);
int octal(va_list args);
int nonPrintAscii(va_list arg);

#endif

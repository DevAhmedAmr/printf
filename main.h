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
 * struct HexChar - struct contain all numerical value 0 - 15
 * corresponding character in hexadecimal
 *
 * @N: int for numerical value
 * @C: char for character
 *
 */
typedef struct HexChar
{
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
int ptr_printer(va_list args);
int hex_capitalA(unsigned int num);
void Reverse_str(char *str);
int prtRevStr(va_list arg);
int rot13(va_list args);
void convertToHexLetter_X_capital(int *bytes, unsigned int *num, char *buffer);
#endif

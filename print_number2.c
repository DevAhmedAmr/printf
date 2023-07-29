#include "main.h"

/**
 * print_number2 - print given  integer in fomat +int+int
 * @args: argument list
 * Return: (int) output length
 */
int print_number2(va_list args)
{
	int len, n;

	n = va_arg(args, int);

	len  = _printf("+%i+%i", n, n);
	return (len);
}


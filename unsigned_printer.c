#include "main.h"
/**
 * unsigned_printer_helper - a helper function for unsigned_printer_helper
 * that prints a given unsigned number and calculated the bytes that as printed
 *
 * @parameters:
 * @n: unsigned int to be printed
 * @bytes: a unsigned integer that the number of printed bytes will be added to
 */

void unsigned_printer_helper(unsigned int n, int *bytes)
{
	unsigned int numLen, divisor;

	numLen = number_len(n);

	if (n != 0)
	{
		divisor = _power(10, numLen - 1);
	}
	else
	{
		_putchar('0');
		*bytes = 1;
	}

	while (divisor)
	{
		unsigned int x = (int)(n / divisor);

		*bytes += 1;
		_putchar((x % 10) + '0');
		divisor /= 10;
	}
}
/**
 * unsigned_printer - function that print unsigned number
 * without using stdio lib
 *
 * @arg: the unsigned int that wanted to be printed but in type arg
 *
 * Return: the number of printed bytes
 */
int unsigned_printer(va_list arg)
{
	int bytes;
	unsigned int n;

	n = va_arg(arg, unsigned int);
	bytes = 0;
	unsigned_printer_helper(n, &bytes);

	return (bytes);
}


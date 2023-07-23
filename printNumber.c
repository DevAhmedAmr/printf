#include "main.h"
#include"main.h"
/**
 * num_print_helper - a helper function to help 'print_number' function
 * to prints decimals and integers
 *
 * @parameters:
 * @n: number to be printed
 * @bytes: a parameter that keeps track number of chars or bytes
 */
void num_print_helper( int n, int *bytes)
{
	int numLen, divisor;
	if (n == -2147483648L)
	{
		*bytes +=11;
		write(1, "-2147483648", 11);
		return;
	}

	if (n < 0)
	{
		*bytes +=1;
	       	_putchar('-');
		n = -n;
	}
	numLen = number_len(n);

	divisor = _power(10, numLen - 1);
	while (divisor)
	{
		int x = (int)(n / divisor);

		*bytes += 1;
		_putchar((x % 10) + '0');
		divisor /= 10;
	}
}

/**
 * print_number - function that print number
 * without using stdio lib
 *
 * @n: type int
 *
 * Return: number
 */
int print_number(va_list arg)
{
	int bytes;

	long int n;

	n = va_arg(arg, int);
	bytes = 0;
	num_print_helper(n, &bytes);

	return (bytes);
}

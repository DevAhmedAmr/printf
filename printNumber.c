#include "main.h"
/**
 * num_print_helper - a helper function for print_number
 * that prints a given number and calculated the bytes that as printed
 *
 * @parameters:
 * @n: number to be printed
 * @bytes: a integer that the number of printed bytes will be added to
 */
void num_print_helper(int n, int *bytes)
{
	int numLen, divisor;

	if (n == -2147483648)
	{
		*bytes += 11;
		write(1, "-2147483648", 11);
		return;
	}

	if (n < 0)
	{
		*bytes += 1;
		_putchar('-');
		n = -n;
	}

	numLen = number_len(n);

	if (n > 0)
	{
		divisor = _power(10, numLen - 1);
	}
	else
	{
		_putchar('0');
		*bytes = 1;
		return;
	}

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
 * @arg: the number that wanted to be printed but in type arg
 *
 * Return: the number of printed bytes
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

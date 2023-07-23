#include"main.h"
void num_print_helper(long int n, int *bytes)
{
	int numLen, divisor;
	if (n == -2147483648L)
	{
		*bytes += write(1, "-2147483648", 11);
		return;
	}

	if (n < 0)
	{
		*bytes += _putchar('-');
		n = -n;
	}
	numLen = number_len(n);

	divisor = _power(10, numLen - 1);
	while (divisor)
	{
		int x = (int)(n / divisor);

		*bytes += _putchar((x % 10) + '0');
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

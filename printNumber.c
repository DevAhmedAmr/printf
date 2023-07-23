#include "main.h"
/**
 * print_number - function that print number
 * without using stdio lib
 *
 * @n: type int
 *
 * Return: number
 */
int print_number(va_list number)
{
	int n = va_arg(number, int);
	static int bytes = 0;
	unsigned long int num = n;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
		num = n;
		bytes++;
	}

	if ((num / 10) > 0)
		print_number(number);

	_putchar((num % 10) + 48);
	bytes++;
	return bytes;
}

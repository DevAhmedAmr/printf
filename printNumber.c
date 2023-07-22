#include "main.h"
/**
 * print_number - function that print number
 * without using stdio lib
 *
 * @n: type int
 *
 * Return: number
 */

int print_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		putchar('-');
		num = -num;
	}

	if ((num / 10) > 0)
		print_number(num / 10);

	putchar((num % 10) + 48);
}

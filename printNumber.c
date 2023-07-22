#include "main.h"
int print_number(int n)
{
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
	{
		print_number(num / 10);
	}

	_putchar((num % 10) + 48);
	bytes++;
	return bytes;
}

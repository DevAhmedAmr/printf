#include"main.h"
void splitNum(long int n, int *bytes)
{
	if (n < 0)
	{
		_putchar('-');
		(*bytes)++;
		n = -n;
	}

	if (n / 10)
		splitNum(n / 10, bytes);

	_putchar(n % 10 + '0');
	(*bytes)++;
}
int print_number(va_list arg)
{
	int bytes;
	long int n;

	n = va_arg(arg, long int);
	bytes = 0;
	if (n >= 0 && n <= 9)
	{
		_putchar(n + '0');
	}

	else if (n < 0 && n > -9)
	{	
		_putchar('-');
		_putchar(n + '0');
		bytes += 2;
	}

	if (n > 9)
		splitNum(n, &bytes);

	if (n < -9)
	{

		_putchar('-');
		bytes++;

		splitNum(-(n), &bytes);
	}
	return (bytes);
}


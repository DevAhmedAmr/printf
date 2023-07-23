#include "main.h"
  int  highest_power(int num)
{
	 int power = 1;
		while (num / (power * 10) > 0)
				power *= 10;
	return (power);
}
/*
5000
num =??  * 10
5000/ ?? = 0;
*/
void splitNum(int num,int *byets)
{
		 int power = 0 , digit = 0;
		power = highest_power(num);
		while (power > 0)
		{
		digit = num / power;
		num %= power;
		power /= 10;
		_putchar(digit + 48);
		*byets += 1;

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
	int bytes, n;


	n =	va_arg(arg, int);

if (n > 0 && n <= 9)
	{
		_putchar( n + '0');
	}
else if (n < 0 && n > -9)
	{
		_putchar('*');
		_putchar(n + '0');
		bytes+=2;
	}

	if (n > 9)
		splitNum(n, &bytes);

if (n <  -9)
	{
		int nn;

		_putchar('-');
		bytes++;
		nn = n * -1;
		splitNum(nn, &bytes);
	}
	return (bytes);
}

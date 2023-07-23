#include "main.h"
 unsigned long int  highest_power(int num)
{
	unsigned long int power = 1;
		while (num / (power * 10) > 0)
				power *= 10;
	return (power);
}

void splitNum(int num,int *byets)
{
		unsigned long int power = 0 , digit = 0;
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
    int bytes = 0, n;

    n = va_arg(arg, int);

    if (n >= 0 && n <= 9)
    {
        _putchar(n + '0');
        bytes++;
    }
    else if (n < 0 && n >= -9)
    {
        _putchar('-');
        _putchar((-n) + '0');
        bytes += 2;
    }
    else if (n > 9)
    {
        splitNum(n, &bytes);
    }
    else if (n < -9)
    {
        int nn;
        _putchar('-');
        bytes++;
        nn = n * -1;
        splitNum(nn, &bytes);
    }
    return (bytes);
}

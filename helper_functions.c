#include <unistd.h>
#include "main.h"
/**
 * _strlen -  a function that returns the length of a string.
 *
 * @s: type str
 *
 * Return: length of a string
 */
unsigned int _strlen(const char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
/**
 * _putchar  - function take a chars as and input and print them
 *
 * @c: prameter char
 *
 * Description: print chars
 *
 * Return: 0 succsess , else failed
 */
int _putchar(char c)
{
	write(1, &c, sizeof(c));
	return (0);
}

/**
 * number_len - function that gets the length of a given numbers
 *
 * parameters:
 * @n: number that it's length wanted to be calculated
 *
 * Return: the given number length
 */

unsigned int number_len(unsigned int n)
{
	unsigned int len = 0;

	unsigned int divisor = 10;

	while (n)
	{
		n = n / divisor;
		len++;
	}
	return (len);
}
/**
 *  _power - function to calcualte power of base to exponent
 *
 *  @parameters:
 *  @base: number of type integer that represent the base of the power
 *  @exponent: number of type integer represnt that the exponent of the power
 *
 *  Return: the power of the given number
 */
unsigned int _power(long int base, unsigned int exponent)
{
	unsigned int result = 1;

	unsigned int i;

	for (i = 0; i < exponent; i++)
		result *= base;

	return (result);
}

/**
 * Reverse_str - function that reverse a given string
 *
 * @str: string to be reversed
 */
void Reverse_str(char *str)
{
	int midPoint = 0, ln, i;
	char tmp;

	i = _strlen(str);
	ln = i;
	midPoint = ln / 2;
	for (i = 0; i < midPoint; i++)
	{
		tmp = str[i];
		str[i] = str[(ln - 1) - i];
		str[(ln - 1) - i] = tmp;
	}
}

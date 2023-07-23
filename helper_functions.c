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

int number_len(long int n)
{
	int len = 0;
	int divisor = 10;
	while (n)
	{
		n = n / divisor;
		len++;
	}
	return len;
}

int _power(int base, int exponent)
{
	int result = 1, i;
	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}

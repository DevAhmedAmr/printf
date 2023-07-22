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

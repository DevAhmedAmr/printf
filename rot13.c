#include "main.h"
#include <stdlib.h>

char *_strcpy(char *dest, char *src);

int rot13(va_list args)
{

	char *normalLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	char *str = va_arg(args, char *), *ptr = str;

	int i, len = _strlen(str);

	char *strcpy = malloc(sizeof(char) * len);
	_strcpy(strcpy, str);
	printf("strcpy = %s\n", strcpy);

	while (*str)
	{

		for (i = 0; i < 53; i++)
		{

			if (*str == normalLetters[i])
			{
				*str = rot13[i];

				break;
			}
		}
		str++;
	}

	len = _strlen(ptr);
	printf("rot13: %s ,%i\n", len, ptr);

	return write(1, ptr, len);
}
/**
 * _strcpy - function that copies a string
 *
 * @dest: parameter of a string wanted to be copied to
 * @src: string wanted to be copy from
 *
 * Return: dest value .
 *
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int i = 0;

	for (; i <= _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
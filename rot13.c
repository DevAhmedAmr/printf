#include "main.h"
#include <stdlib.h>

char *_strcpy(char *dest, char *src);

int rot13(va_list args)
{
	char *normalLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13Letters = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *rot13Str, *ptr, *str;
	int i, len, write_status;

	str = va_arg(args, char *);

	len = _strlen(str);

	rot13Str = malloc(sizeof(char) * (len + 1));

	ptr = rot13Str;

	if (rot13Str == NULL)
		return (-1);

	_strcpy(rot13Str, str);

	while (*rot13Str)
	{
		for (i = 0; i < 53; i++)
		{
			if (*rot13Str == normalLetters[i])
			{
				*rot13Str = rot13Letters[i];
				break;
			}
		}
		rot13Str++;
	}
	len = _strlen(ptr);
	write_status = write(1, ptr, len);
	free(ptr);
	return (write_status);
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
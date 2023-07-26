#include "main.h"

/**
 * prtRevStr - print string in reversed order
 *
 * @args: sring to print
 *
 * Return: (int) number of printed charcter
 */

int prtRevStr(va_list args)
{
	int bytes = 0, i = 0, len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		return (0);

	len = _strlen(str);

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		bytes++;
	}
	return (bytes);
}

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
	int byets = 0, i = 0, len = 0;
	char *S;

S = va_arg(args, char *);
	if (S == NULL)
		return (0);
	len = _strlen(S);

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(S[i]);
		byets++;
	}
	return (byets);

}

#include "main.h"
/**
 * octal - function that convert from decimal (base 10) to
 * oct (base 8)
 *
 * parameters:
 * @args: number to be printed but in type va_list
 *
 * Return: size of the printed number
 */
int octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	int breakLoop = 0, bytes = 0;

	char buffer[1024];

	while (1)
	{
		breakLoop = (num / 8 == 0) ? 1 : 0;

		buffer[bytes] = num % 8 + '0';

		num = num / 8;

		bytes++;

		if (breakLoop == 1)
			break;
	}
	buffer[bytes] = '\0';
	Reverse(buffer);
	return (bytes);
}

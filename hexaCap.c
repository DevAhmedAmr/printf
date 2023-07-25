#include "main.h"

/**
 * hex_capital - function that convert number for base 10 to base 16
 * with a capital letters
 * arguments:
 *
 * @args: args of type va_list will be converted to unsigned int
 *
 * Return: the number of bytes of the printed number
 */
int hex_capitalA(unsigned int num)
{

	int breakLoop = 0, bytes = 0;

	char buffer[1024];

	while (1)
	{
		breakLoop = (num / 16 == 0) ? 1 : 0;
		convertToHexLetter_X_capital(&bytes, &num, buffer);

		num = num / 16;

		bytes++;

		if (breakLoop == 1)
			break;
	}
	buffer[bytes] = '\0';
	Reverse(buffer);
	return (bytes);
}

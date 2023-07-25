#include "main.h"
/**
 * convertToHexLetter_X_capital - a helper function that converts
 * the number that are bigger than 9 to hex decimal with capital
 * letters
 *
 * parameters:
 * @bytes: number of printed bytes
 * @num: number to be converted
 * @buffer: buffer to save the sub number
 */
void convertToHexLetter_X_capitall(int *bytes, unsigned int *num, char *buffer)
{
	switch (*num % 16)
	{
	case 10:
		buffer[*bytes] = 'A';
		break;
	case 11:
		buffer[*bytes] = 'B';
		break;
	case 12:
		buffer[*bytes] = 'C';
		break;
	case 13:
		buffer[*bytes] = 'D';
		break;
	case 14:
		buffer[*bytes] = 'E';
		break;
	case 15:
		buffer[*bytes] = 'F';
		break;
	default:
		buffer[*bytes] = *num % 16 + '0';
		break;
	}
}
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
		convertToHexLetter_X_capitall(&bytes, &num, buffer);

		num = num / 16;

		bytes++;

		if (breakLoop == 1)
			break;
	}
	buffer[bytes] = '\0';
	Reverse(buffer);
	return (bytes);
}

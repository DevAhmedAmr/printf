#include "main.h"
/**
 * convertToHexLetter_small_x - a helper function that converts
 * the number that are bigger than 9 to hex decimal with 'small'
 * letters
 *
 * parameters:
 * @bytes: number of printed bytes
 * @num: number to be converted
 * @buffer: buffer to save the sub number
 */
void convertToHexLetter_small_x(int *bytes, unsigned *num, char *buffer)
{
	switch (*num % 16)
	{
	case 10:
		buffer[*bytes] = 'a';
		break;
	case 11:
		buffer[*bytes] = 'b';
		break;
	case 12:
		buffer[*bytes] = 'c';
		break;
	case 13:
		buffer[*bytes] = 'd';
		break;
	case 14:
		buffer[*bytes] = 'e';
		break;
	case 15:
		buffer[*bytes] = 'f';
		break;
	default:
		buffer[*bytes] = *num % 16 + '0';
		break;
	}
}
/**
 * hex_small - function that convert number for base 10 to base 16
 * with a 'small' letters
 * arguments:
 *
 * @args: args of type va_list will be converted to unsigned int
 *
 * return the number of bytes of the printed number
 */
int hex_small(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	int breakLoop = 0, bytes = 0;

	char buffer[1024];

	while (1)
	{
		breakLoop = (num / 16 == 0) ? 1 : 0;
		convertToHexLetter_small_x(&bytes, &num, buffer);

		num = num / 16;

		bytes++;

		if (breakLoop == 1)
			break;
	}
	buffer[bytes] = '\0';
	Reverse(buffer);
	return bytes;
}
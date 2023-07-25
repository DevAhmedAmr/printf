#include "main.h"
/**
 * convertToHexLetter_ptr - a helper function to' ptr_printer' that converts
 * the number that are bigger than 9 to hex decimal with 'small'
 * letters
 *
 * parameters:
 * @bytes: number of printed bytes
 * @num: number to be converted
 * @buffer: buffer to save the sub number
 */
void convertToHexLetter_ptr(int *bytes, unsigned long int *num, char *buffer)
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
 * ptr_printer - function that convert number for base 10 to base 16
 * with a 'small' letters
 * arguments:
 *
 * @args: args of type va_list will be converted to unsigned int
 *
 * Return: the number of bytes of the printed number
 */
int ptr_printer(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);

	int bytes = 0, i;

	char buffer[8];

	for (i = 0; i < 8; i++)
		buffer[i] = '0';

	for (i = 0; i < 8; i++)
	{
		convertToHexLetter_ptr(&bytes, &num, buffer);

		num = num / 16;

		bytes++;
	}
	buffer[i] = '\0';
	Reverse(buffer);
	return (bytes);
}
#include "main.h"
#include <stdlib.h>
void Reverse_str(char *binBuff);
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

	int bytes = 0, i, len = 0;

	char *buffer = malloc(1024 * sizeof(char)), *temp, *prefix = "0x";

	if (buffer == NULL)
		return -1; /* Return error code if malloc fails */

	temp = buffer; /* Temporary pointer for manipulation */

	/* Initialize buffer to '0' */
	for (i = 0; i < buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\0')
			break;

		buffer[i] = '0';
	}
	if (num == 0)
	{
		write(1, "(nil)", 5);
		free(buffer);
		return (5); /* Include the length of "(nil)" */
	}

	for (i = 0; num != 0 && i < 1024 - 1; i++)
	{ /* Check for buffer overflow and num != 0 */
		convertToHexLetter_ptr(&bytes, &num, temp);
		num = num / 16;
		bytes++;
	}

	temp[i] = '\0'; /* Terminate the string */

	Reverse_str(temp);

	/* Skip leading zeros */
	while (*temp == '0' && *(temp + 1) != '\0')
	{ /* Check for string with all digits '0' */
		temp++;
	}

	len += _strlen(temp);
	write(1, prefix, 2);
	write(1, temp, len);
	free(buffer); /* Free the original pointer */

	return (len + 2); /* Include the length of prefix '0x' */
}
void Reverse_str(char *binBuff)
{
	int midPoint = 0, ln, i;
	char tmp;

	i = _strlen(binBuff);
	ln = i;
	midPoint = ln / 2;
	for (i = 0; i < midPoint; i++)
	{
		tmp = binBuff[i];
		binBuff[i] = binBuff[(ln - 1) - i];
		binBuff[(ln - 1) - i] = tmp;
	}
}
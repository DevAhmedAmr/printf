#include "main.h"
#include <stdlib.h>
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
 * @list: args of type va_list will be converted to unsigned int
 *
 * Return: the number of bytes of the printed number
 */
int ptr_printer(va_list list)
{
	unsigned long int num = va_arg(list, unsigned long int);

	int size = 0, len, i;
	char *p_buff = malloc(18 * sizeof(char));
	char *temp = p_buff;
	const char *prefix = "0x";

	if (num == 0)
	{
		size += write(1, "(nil)", 5);
		free(p_buff);
		return (size);
	}

	for (i = 0; i < 18; i++)
	{
		convertToHexLetter_ptr(&size, &num, temp);
		num = num / 16;
		size++;
	}

	temp[18] = '\0';
	Reverse_str(temp);

	while (*temp == '0')
		temp++;

	len = _strlen(temp);

	size = 0;

	size += write(1, prefix, 2);

	size += write(1, temp, len);

	free(p_buff);
	return (size);
}

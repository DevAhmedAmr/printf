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

	int bytes = 0, i;

	char *buffer = malloc(18 * sizeof(char));
	char *temp = buffer; /* Temporary pointer for manipulation*/
	char *prefix = "0x";

	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	for (i = 0; i < 18; i++)
		buffer[i] = '0';

	for (i = 0; i < 18; i++)
	{
		convertToHexLetter_ptr(&bytes, &num, temp);

		num = num / 16;

		bytes++;
	}

	temp[i] = '0';

	Reverse_str(temp);
	printf("\nnum = %lu\n", num);

	/* while (*temp == '0')*/
	/* {*/
	/* 	temp++;*/
	/* }*/
	/* write(1, prefix, 2);*/
	write(1, temp, _strlen(temp));
	free(buffer); /* Free the original pointer*/

	return (2 + _strlen(temp));
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
#include"main.h"
/**
 * string_printer - sub function from _printf that print a given string
 *
 * @string :string of type va_lisit
 *
 * Return: (int) number of each charcter of string printed by char_printer
 */
int string_printer(va_list string)
{
	char *str = va_arg(string, char *);

	unsigned int strLen, bytes_counted = 0, j;

	if (str == NULL)
		str = "(null)";

	strLen = _strlen(str);

	for (j = 0; j < strLen; j++)
	{
		_putchar(str[j]);
		bytes_counted++;
	}
	return (bytes_counted);
}

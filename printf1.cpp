#include "main.h"
#include <stddef.h>
int _printf(const char *format, ...);
int string_printer(char *str);
void formatSpecifierHandler(char c, int *bytes, va_list arguments);
int _printf(const char *format, ...);

int char_printer(char c)
{
	_putchar(c);
	return 1;
}
/**
 * @string_printer -  prints a string and count the printed byets
 * @str: char* the string pointer to print
 * Return: int counted byets umber
 */
int string_printer(char *str)
{
	size_t strLen = _strlen(str), bytes_counted = 0, j;

	for (j = 0; j < strLen; j++)
	{
		_putchar(str[j]);
		bytes_counted++;
	}
	return bytes_counted;
}

/**
 *  formatSpecifierHandler -lock for type specifier and call corresponding function
 * 
 * @c: char , format specifier 

 * @ bytes
 * @param arguments 
 */
void formatSpecifierHandler(char c, int *bytes, va_list arguments)
{
	switch (c)
	{
	case 'c':
		*bytes += char_printer(va_arg(arguments, int));
		break;
	case 's':
		*bytes += string_printer(va_arg(arguments, char *));
		break;
	case 'i':
		bytes += print_number(va_arg(arguments, int));
		break;
	case 'd':
		bytes += print_number(va_arg(arguments, int));
		break;

	default:
		/* Handle unexpected specifier*/
		_putchar('%');
		_putchar(c);
		*bytes += 2;
		break;
	}
}
/**
 * _printf - generic function print argumnt pass to it as a buffer
 * 
 * @format: format fore type specifiers for arguments to pe printed
 * @...: arguments to print
 * @return (int) number of printed buffer 
 */

int _printf(const char *format, ...)
{
	size_t num_args = _strlen(format), i;
	va_list args;
	int bytes = 0;

	va_start(args, format);

	for (i = 0; i < num_args; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (i < num_args) /*prevent accessing memory out of bounds*/
			{
				char c = format[i];

				formatSpecifierHandler(c, &bytes, args);
			}
			else
			{
				_putchar('%'); /*Handle case where format string ends in '%'*/
				bytes++;
			}
		}
		else
		{
			_putchar(format[i]);
			bytes += 1;
		}
	}

	va_end(args);
	return bytes;
}

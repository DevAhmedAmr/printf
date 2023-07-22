#include "main.h"
int _printf(const char *format, ...);
int string_printer(char *str);
void formatSpecifierHandler(char c, int *bytes, va_list arguments);
int _printf(const char *format, ...);

int char_printer(char c)
{
	_putchar(c);
	return 1;
}


int string_printer(char *str)
{
	unsigned int strLen = _strlen(str), bytes_counted = 0, j;

	for (j = 0; j < strLen; j++)
	{
		_putchar(str[j]);
		bytes_counted++;
	}
	return bytes_counted;
}

voint _printf(const char *format, ...)
{
	unsigned int num_args, i;
	va_list args;
	int bytes = 0;

	va_start(args, format);
	if (format == NULL)
	{
		return -1;
	}
	num_args = _strlen(format);

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

int _printf(const char *format, ...)
{
	unsigned int num_args, i;
	va_list args;
	int bytes = 0;

	va_start(args, format);
	if (format == NULL)
	{
		return -1;
	}
	num_args = _strlen(format);

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

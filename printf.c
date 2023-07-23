#include "main.h"

int char_printer(va_list c)
{
	int character = va_arg(c, int);
	_putchar(character);
	return 1;
}

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
	return bytes_counted;
}

void formatSpecifierHandler(char specifier, int *bytes, va_list arguments)
{
	int i;

	/*flag to identify if the specifier is found or not */
	int identified_specifier = 0;

	struct specifier_formater struct_specifiers[] = {
		{'c', char_printer},
		{'s', string_printer},
		{'i', print_number},
		{'d', print_number}};

	for (i = 0; i < 4; i++)
	{
		if (struct_specifiers[i].specifier == specifier)
		{
			*bytes += struct_specifiers[i].function(arguments);
			identified_specifier = 1;
		}
	}
	if (specifier == '%' && identified_specifier == 0)
	{
		*bytes += 1;
		_putchar('%');
	}
	else if (identified_specifier == 0)
	{
		_putchar('%');
		_putchar(specifier);
		*bytes += 2;
	}
}
int _printf(const char *format, ...)
{
	unsigned int num_args, i;
	va_list args;
	int bytes = 0;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return -1;

	num_args = _strlen(format);

	for (i = 0; i < num_args; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (i < num_args) /*prevent accessing memory out of bounds*/
			{
				char specifier = format[i];

				formatSpecifierHandler(specifier, &bytes, args);
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

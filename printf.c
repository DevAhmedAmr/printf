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
	case '%':
		*bytes += 1;
		_putchar('%');
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
void formatSpecifierHandler(char c, int *bytes, va_list arguments)
{
	switch (c)
	{
	case 'c':
		*bytes += char_printer(va_arg(arguments, int));
		break;
	case 's':
	{
		char *str = va_arg(arguments, char *);
		*bytes += (str == NULL) ? string_printer("(null)") : string_printer(str);
		break;
	}

	case '%':
		*bytes += 1;
		_putchar('%');
		break;
	case 'i':
		bytes += print_number(va_arg(arguments, int));
		break;
	case 'd':
		bytes += print_number(va_arg(arguments, int));
		break;

	default:
		_putchar(c);
		*bytes += 2;
		break;
	}
}

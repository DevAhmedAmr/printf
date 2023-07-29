#include "main.h"
/**
 * _printf - our super great printf
 * @format: format no need to explain  more bro
 * @...: argument to pe print
 * Return: number of bytes printed by our great function
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0;
	va_list args;
	int bytes = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		char specifier;
		
		if (format[i] == '%' && format[i + 1] == '+' && format[i + 2] == 'd')
                        {
				i += 3;	
				specifier = 'q';
				formatSpecifierHandler(specifier, &bytes, args);

                        }/*Done*/

		if (format[i] == '%')
		{
			i++;

			specifier = format[i];
			formatSpecifierHandler(specifier, &bytes, args);
		}
		else
		{
			_putchar(format[i]);
			bytes += 1;
		}
		i++;
	}
	va_end(args);
	return (bytes);
}

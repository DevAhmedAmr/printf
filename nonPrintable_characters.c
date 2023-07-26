#include "main.h"
/**
 * nonPrintAscii - print string repalceing nonprint
 * chars it with its hexadecimal value
 *
 * @arg: string to print
 *
 * Return: (int) number of charcter printed
 */
int nonPrintable_characters(va_list arg)
{
	int i, bytes = 0;
	char *upStr;

	upStr = va_arg(arg, char *);
	if (upStr == NULL)
		upStr = "(null)";

	for (i = 0; upStr[i] != '\0'; i++)
	{
		if ((upStr[i] > 0 && upStr[i] < 32) || upStr[i] >= 127)
		{
			int num = (int)upStr[i];

			if (num < 16)
			{

				_putchar('\\');
				_putchar('x');
				_putchar('0');
				_printf("%X", num);

				bytes += 4;
			}
			else
			{
				_putchar('\\');
				_putchar('x');
				bytes += _printf("%X", num) + 2;
			}
		}
		else
		{
			_putchar(upStr[i]);
			bytes++;
		}
	}
	return (bytes);
}

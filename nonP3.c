#include "main.h"
void convertToHexLetter_X_capital2(int *num, char *buffer);

/**
 * nonPrintAscii - print string repalceing nonprint
 * chars it with its hexadecimal value
 *
 * @arg: string to print
 *
 * Return: (int) number of charcter printed
 */
int nonPrintAscii(va_list arg)
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
				char buffer[10];

				_putchar('\\');
				_putchar('x');
				_putchar('0');
				_printf("%X", num);

				bytes += 4;
			}
			else
			{
				char buffer[10];
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

void convertToHexLetter_X_capital2(int *num, char *buffer)
{
	int i = 0;
	while (1)
	{

		switch (*num % 16)
		{
		case 10:
			buffer[i] = 'A';
			break;
		case 11:
			buffer[i] = 'B';
			break;
		case 12:
			buffer[i] = 'C';
			break;
		case 13:
			buffer[i] = 'D';
			break;
		case 14:
			buffer[i] = 'E';
			break;
		case 15:
			buffer[i] = 'F';
			break;
		default:
			buffer[i] = *num % 16 + '0';
			break;
		}
		*num /= 16;
		i++;
		if (*num % 16 == 0)
		{
			break;
		}
	}
	buffer[i] = '\0';
	Reverse_str(buffer);
}

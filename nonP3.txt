#include "main.h"

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
	int i, j, bytes = 0;
	char *upStr;
	HexChar hexCharA[] = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

	upStr = va_arg(arg, char *);
	if (upStr == NULL)
		upStr = "(null)";
	for (i = 0; upStr[i] != '\0'; i++)
	{
		if ((upStr[i] > 0 && upStr[i] < 32) || upStr[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar('0');
			bytes += 3;
			for (j = 0; j <= 15; j++)
			{
				if (upStr[i] == hexCharA[j].N)
				{
					_putchar(hexCharA[j].C);
					bytes++;
					break;
				}
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

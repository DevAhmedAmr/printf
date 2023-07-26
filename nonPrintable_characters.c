#include "main.h"

/**
 * hexCharf - return an Hexadecimal value for  int 0 - 15
 *
 * @ui: expected i value
 *
 * Return: (char)
 */
char hexCharf ( int ui)
{
	int i;
	char c;
		HexChar hexCharA[] = {
	{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
	{5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
	{10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};
	for (i = 0; i <= 15; i++)
	{
		if (ui == hexCharA[i].N )
		{
			c = hexCharA[i].C;
			break;
		}

	}
	return (c);
}
/**
 * nonPrintable_characters - print string repalceing nonprint
 * chars it with its hexadecimal value
 *
 * @arg: string to print
 *
 * Return: (int) number of charcter printed
 */

int nonPrintable_characters(va_list args)
{
	int i, byets = 0;
	char *upStr;

	/*	if ((upStr[i] >= 0 && upStr[i] <= 32) || upStr[i] >= 127) */
upStr = va_arg(args, char*);
	if (upStr == NULL)
		upStr = "(null)";
	for (i = 0; upStr[i] != '\0'; i++)
	{
		if (upStr[i] >=0 && upStr[i] <= 15)
		{
			putchar('\\');
			putchar('x');
			putchar('0');
			putchar(hexCharf(upStr[i]));
				byets += 4;

		}
		else if ((upStr[i] > 15 && upStr[i] < 32  ) || (upStr[i] >= 127))
		{

			putchar('\\');
			putchar('x');
			putchar(hexCharf( upStr[i] / 16));
			putchar(hexCharf( upStr[i] % 16));
			byets += 4;

		}
		else
		{
			putchar(upStr[i]);
			byets++;
		}
		/* fflush(stdout); */
	}
	return (byets);
}

#include "main.h"
int nonPrintAscii(va_list arg)
{
	int i, byets;
	char* upStr;

upStr = va_arg(arg, char*);
	for (i = 0; upStr[i] !='\0'; i++)
	{
		if((upStr[i] > 0 && upStr[i] < 32) || upStr[i] >= 127)
			{
				_putchar('\\');
				_putchar('x');
				_putchar('0');
				byets+=3;
				hex_capitalA(upStr[i]);
			}
		else
			{
			_putchar(upStr[i]);
			byets++;
			}
			fflush(stdout);
	}
	return (byets);
}

#include "main.h"
int nonPrintAscii(char *upStr)
{
	int i, j, byets;
	// char* upStr;

// upStr = va_arg(arg, char*);
	for (i = 0; upStr[i] !='\0'; i++)
	{
		if((upStr[i] > 0 && upStr[i] < 32) || upStr[i] >= 127)
			{
				_putchar('\\');
				_putchar('x');
				_putchar('0');
				byets+=3;
			_printf("%X",upStr[i]);
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

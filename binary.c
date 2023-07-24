#include "main.h"
/**
 * Reverse - Reverse and print given string
 * @binBuff: string to be reversed
 * @return (int) number of chars that printed
 */
int Reverse(char *binBuff)
{
	int midPoint = 0, ln, i;
	char tmp;

	i = _strlen(binBuff);
	ln = i;
	midPoint = ln / 2;
	for (i = 0; i < midPoint; i++)
	{
		tmp = binBuff[i];
		binBuff[i] = binBuff[(ln - 1) - i ];
		binBuff[(ln -1) -i ] = tmp;
	}
	i = 0;
	while ( binBuff[i] != '\0')
	{
		_putchar(binBuff[i]);
		i++;
	}
	return (i);
}
/**
 * * print_binary - print a binary for given number
 * @arg: argument list for number to print its binary
 * @return (int) number of chrcter of buffer of binary
 */
int print_binary(va_list arg)
{
	char *binBuff;
	unsigned int i = 0, n, buffLn;

	n = va_arg(arg, unsigned int);
	do
	{
		if (n % 2 == 0)
			binBuff[i] = '0';
		else
			binBuff[i] = '1';
		n/= 2;
		i++;
	}
	while(n != 0);
	binBuff[i] = '\0';
	buffLn = Reverse(binBuff);

	return (buffLn);
}

int main() {
	unsigned int n= 43 ;
	print_binary(n);
	// printf("\n binLen %i", print_binary(n));

	return (0);
}

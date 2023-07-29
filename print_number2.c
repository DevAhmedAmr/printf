#include "main.h"

/**
 * print_number2 - print given  integer in fomat +int+int
 * @args: argument list
 * Return: (int) output length
 */
int print_number2(va_list args)
{
	int len,  n;

	n = va_arg(args, int);
	if (n > 0)
		len  =  printf("+%i+%i", n, n);
	if (n < 0 && n != -2147482625)
		len  =  printf("-%i-%i", n, n);
	if (n == -2147482625)
		len  =  printf("%i%i", n, n);
	if (n == 0)
		len  =  printf("+%i+%i", 0, 0);


	return (len);
}

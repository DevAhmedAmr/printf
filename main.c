#include "main.h"
#include <stdio.h>
int main(void)
{
	int len;
	int len2;
	int binary = 43;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len, len2);
	len = _printf(" test :[%d, %i] %i \n", 0, -6 , 1);
	 len2 = printf(" test :[%d, %i] %i \n", 0, -6 , 1);
	         printf("Length:[%d, %i]\n", len, len2);
	printf("Length:[%d, %i]\n", len, len2);
	len = _printf(" test :[%d, %i]\n", 251511515, -52515155);
	        len2 = printf(" test :[%d, %i]\n", 251511515, -52515155);
	_printf("Length:[%d, %i]\n", len, len2);
	        printf("Length:[%d, %i]\n", len, len2);
	len =_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	_printf("_BINARY [%b]\n", binary);
	return (0);
}

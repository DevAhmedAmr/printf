#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;

	// Test cases for _printf
	_printf("Lower Bound: %u\n", 0);
	_printf("Upper Bound: %u\n", 4294967295);
	_printf("Just Above Lower Bound: %u\n", 1);
	_printf("Just Below Upper Bound: %u\n", 4294967294);
	_printf("Midpoint: %u\n", 2147483647);

	// Test cases for standard printf
	printf("Lower Bound: %u\n", 0);
	printf("Upper Bound: %u\n", 4294967295);
	printf("Just Above Lower Bound: %u\n", 1);
	printf("Just Below Upper Bound: %u\n", 4294967294);
	printf("Midpoint: %u\n", 2147483647);

	_printf("Hexadecimal representation of 0: %x\n", 24);
	printf("Hexadecimal representation of 0: %x\n", 0);
	_printf("Hexadecimal representation of 4294967295: %x\n", 4294967295);
	printf("Hexadecimal representation of 4294967295: %x\n", 4294967295);
	_printf("Hexadecimal representation of -1: %x\n", -1);
	printf("Hexadecimal representation of -1: %x\n", -1);

	/* Decimal to Octal conversion*/
	_printf("Octal representation of 0: %o\n", 0);
	printf("Octal representation of 0: %o\n", 0);
	_printf("Octal representation of 4294967295: %o\n", 4294967295);
	printf("Octal representation of 4294967295: %o\n", 4294967295);
	_printf("Octal representation of -1: %o\n", -1);
	printf("Octal representation of -1: %o\n", -1);
	_printf("%u \n", -1);
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	_printf("\n----------------------------------\n");
	printf("%s %s \n", "text1", "text2");
	_printf(" _ %s %s \n", "text1", "text2");
	printf("2mod %%\n");
	printf("1mod %\n");
	_printf("_2mod %%\n");
	_printf("_1mod %\n");

	return (0);
}

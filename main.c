#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */

int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	/* Test case 1: A non-null pointer*/
	int a = 10;
	int *ptr1 = &a;
	int *ptr2 = NULL;
	int arr[10];
	int *ptr3;
	int (*ptr4)(va_list);
	void *p = (void *)0x7fff5100b608;
	/* int x = '\x1F';*/
	len = _printf("%s%S%c", "Show me the codes: ", "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x10", '\n');
	len2 = printf("%s\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0A\\x10%c", "Show me the codes: ", '\n');
	fflush(stdout);
	printf("Len1 : %i Len2 %i.\n", len, len2);

	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");
	putchar('\n');
	len2 = printf("Could you print some non-prntable characters?\nSure:\\x1F\\x7F\\x0A\nThanks!\n");
	putchar('\n');

	fflush(stdout);

	if (len != len2)
	{
		printf("Lengths differ. len1 %i len2 %i\n", len, len2);
		fflush(stdout);
	}

	len = _printf("%S", "No special character.");
	putchar('\n');

	len2 = printf("No special character.");
	putchar('\n');

	fflush(stdout);
	if (len != len2)
	{
		printf("\nLengths differ.%i %i\n", len, len2);
		fflush(stdout);
	}

	len = _printf("%S", "\n");
	putchar('\n');

	len2 = printf("\\x0A");
	putchar('\n');
	fflush(stdout);
	if (len != len2)
	{
		printf("\nLengths differ.%i %i", len, len2);
		putchar('\n');

		fflush(stdout);
	}
	len = _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
	putchar('\n');

	len2 = printf("\\x01\\x02\\x03\\x04\\x05\\x06\\x07");
	putchar('\n');

	fflush(stdout);
	if (len != len2)
	{
		printf("\nLengths differ.%i %i\n", len, len2);
		putchar('\n');

		fflush(stdout);
	}
	printf("-----------------------------------");
	len = _printf("%p\n", p);
	len2 = printf("%p\n", p);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ. %i %i\n", len, len2);
		fflush(stdout);
	}

	len = printf("%p\n", ptr1);
	len2 = _printf("%p\n", ptr1);
	printf("len = %i len2 = %i\n", len, len2);

	/* Test case 2: The null pointer*/
	len = printf("printf:  %p\n", ptr2);
	len2 = _printf("_printf: %p\n", ptr2);
	printf("len = %i len2 = %i\n", len, len2);

	/* Test case 3: A pointer to an array*/
	ptr3 = arr;
	len = printf("printf: %p \n", ptr3);
	len2 = printf("_printf: %p\n", ptr3);
	printf("len = %i len2 = %i\n", len, len2);

	/*Test case 4: A pointer to a function*/
	ptr4 = ptr_printer;
	len = printf("%p\n", ptr4);
	len2 = _printf("%p\n", ptr4);
	printf("len = %i len2 = %i\n", len, len2);

	/* Test cases for _printf  */
	_printf("Lower Bound: %u\n", 0);
	_printf("Upper Bound: %u\n", 4294967295U);
	_printf("Just Above Lower Bound: %u\n", 1);
	_printf("Just Below Upper Bound: %u\n", 4294967294U);
	_printf("Midpoint: %u\n", 2147483647);

	/* Test cases for standard printf */
	printf("Lower Bound: %u\n", 0);
	printf("Upper Bound: %u\n", 4294967295U);
	printf("Just Above Lower Bound: %u\n", 1);
	printf("Just Below Upper Bound: %u\n", 4294967294U);
	printf("Midpoint: %u\n", 2147483647);

	_printf("Hexadecimal representation of 0: %x\n", 24);
	printf("Hexadecimal representation of 0: %x\n", 0);
	_printf("Hexadecimal representation of 4294967295: %x\n", 4294967295U);
	printf("Hexadecimal representation of 4294967295: %x\n", 4294967295U);
	_printf("Hexadecimal representation of -1: %x\n", -1);
	printf("Hexadecimal representation of -1: %x\n", -1);

	/* Decimal to Octal conversion*/
	_printf("Octal representation of 0: %o\n", 0);
	printf("Octal representation of 0: %o\n", 0);
	_printf("Octal representation of 4294967295: %o\n", 4294967295U);
	printf("Octal representation of 4294967295: %o\n", 4294967295U);
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
	_printf("Unknown:[%k]\n");
	printf("Unknown:[%k]\n");
	_printf("\n----------------------------------\n");
	printf("%s %s \n", "text1", "text2");
	_printf(" _ %s %s \n", "text1", "text2");
	printf("2mod %%\n");
	printf("1mod %\n");
	_printf("_2mod %%\n");
	_printf("_1mod %\n");
	_printf("%S\n", "Best\nSchool");

	/*Test none print */
	_printf("%S\n", "Best\nSchool");
	_printf("%S\n", "Best\tnSchool");

	/* print string in revers */
	printf("String\n");
	_printf("%r\n", "_String");
	_printf("%R we masele 3la f5adk\n", "_String");
	printf("\n 7. The big print gives  +d\n");
	_printf("cust %+d masele 3la f5adk", 1024);
	printf("\n expected +1024+1024\n");

	return (0);
}

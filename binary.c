#include "main.h"

/**
 * * print_binary - print a binary for given number
 * @arg: argument list for number to print its binary
 * @return (int) number of chrcter of buffer of binary
 */
int print_binary(va_list arg){
	int j, len, temp;
	unsigned int num;
	int binary_arr[1000];

	num = va_arg(args, unsigned int);

	len = 0;
	while (num > 0)
	{
		temp = 0;
		temp = num % 2;
		binary_arr[len] = temp + 48;
		num /= 2;
		len++;
	}

	j = len - 1;
	while (j >= 0)
	{
		*buffer.box = binary_arr[j];
		buffer.box++;
		buffer.size++;
		j--;
	}

	buffer.box--;
	return (buffer);
}


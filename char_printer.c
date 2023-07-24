#include "main.h"
/**
 * char_printer - sub function from _printf that print charcters
 * @c:argument for charcter
 * Return: (int) number of charcter printed by char_printer
 */
int char_printer(va_list c)
{
	int character = va_arg(c, int);

	_putchar(character);
	return (1);
}

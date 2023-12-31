#include "main.h"
/**
 * formatSpecifierHandler - sup function from _printf that handle spwcifier
 *lock for a type specifier charcter and call the crosponding function
 * @specifier:argument for specifier
 * @bytes:number of charcters printrd by  formatSpecifierHandler.
 * @arguments: whic is the argument passed after specifier
 */
void formatSpecifierHandler(char specifier, int *bytes, va_list arguments)
{
	int i;
	/*flag to identify if the specifier is found or not */
	int identified_specifier = 0;

	specifier_formater struct_specifiers[] = {
		{'c', char_printer},
		{'s', string_printer},
		{'i', print_number},
		{'d', print_number},
		{'b', print_binary},
		{'u', unsigned_printer},
		{'x', hex_small},
		{'X', hex_capital},
		{'S', nonPrintable_characters},
		{'o', octal},
		{'p', ptr_printer},
		{'r', prtRevStr},
		{'R', rot13},
		{'q', print_number2}};

	for (i = 0; i < 14; i++)
	{
		if (struct_specifiers[i].specifier == specifier)
		{
			*bytes += struct_specifiers[i].function(arguments);
			identified_specifier = 1;
		}
	}
	if (specifier == '%' && identified_specifier == 0)
	{
		*bytes += 1;
		_putchar('%');
	}
	else if (identified_specifier == 0)
	{
		_putchar('%');
		_putchar(specifier);
		*bytes += 2;
	}
}

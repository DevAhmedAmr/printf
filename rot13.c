#include "main.h"
int rot13(va_list args)
{
	int i, len;

	char *normalLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	char *str = va_arg(args, char *), *ptr = str;
	printf("%ss\n", str);

	while (*str)
	{
		for (i = 0; i < 53; i++)
		{
			if (*str == normalLetters[i])
			{
				*str = rot13[i];
				printf("%c\n", *str);

				break;
			}
		}
		str++;
	}
	printf("rot13: %s ,%i\n", len, ptr);

	len = _strlen(ptr);

	return write(1, ptr, len);
}

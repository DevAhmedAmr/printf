#include "main.h"
int rot13(va_list args)
{
	int i, len;

	char *normalLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	char *str = va_arg(args, char *), *ptr = str;

	while (*str)
	{
		for (i = 0; i < 53; i++)
		{
			if (*str == normalLetters[i])
			{
				*str = rot13[i];
				break;
			}
		}
		str++;
	}

	len = _strlen(str);

	return write(1, str, len);
}

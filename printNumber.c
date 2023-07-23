#include"main.h"
#include "main.h"

int highest_power(int num)
{
    int power = 1;
    while (num / (power * 10) > 0)
        power *= 10;
    return (power);
}

void num_print_helper(int n, int *bytes)
{
    int  divisor;

    if (n < 0)
    {
        *bytes += _putchar('-');
        n = -n;
    }

    divisor = highest_power(n);
    while (divisor)
    {
        int x = (int)(n / divisor);

        *bytes += _putchar((x % 10) + '0');
        divisor /= 10;
    }
}

int print_number(va_list arg)
{
    int bytes;
    int n;

    n = va_arg(arg, int);
    bytes = 0;

    if (n == 0) {
        _putchar('0');
        return 1;
    }
    else if (n == -2147483648) {
        _putchar('-');
        _putchar('2');
        _putchar('1');
        _putchar('4');
        _putchar('7');
        _putchar('4');
        _putchar('8');
        _putchar('3');
        _putchar('6');
        _putchar('4');
        _putchar('8');
        return 11;
    }
    else 
    {
        num_print_helper(n, &bytes);
    }

    return bytes;
}

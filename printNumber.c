#include"main.h"
unsigned long int highest_power(int num)
{
    unsigned long int power = 1;
    while (num / (power * 10) > 0)
        power *= 10;
    return (power);
}

void splitNum(int num, int *bytes)
{
    unsigned long int power = 0, digit = 0;
    if (num < 0) {
        _putchar('-');
        *bytes += 1;
        num = -num;
    }
    power = highest_power(num);
    while (power > 0)
    {
        digit = num / power;
        num %= power;
        power /= 10;
        _putchar(digit + '0');
        *bytes += 1;
    }
}

int print_number(va_list arg)
{
    int bytes = 0, n;

    n = va_arg(arg, int);

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
    else if (n < 0)
    {
        splitNum(n, &bytes);
    }
    else if (n > 0)
    {
        splitNum(n, &bytes);
    }
    else {
        return 0;
    }
    return bytes;
}

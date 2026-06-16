#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_digit(int *digits,int n)
{
    int i;

    i = 0;
    while (i < n)
    {
            ft_putchar(digits[i] + '0');
            i++;
    }
}
int ft_is_last(int *digits, int n)
{
    int i;
    int last;

    i = 0;
    last = 10 - n;
    while (i < n)
    {
        if  (digits[i] != last + i)
        return (0);
        i++;
    }
    return (1);
}
void    ft_recurse(int index, int start, int *digits, int n)
{
    int d;

    if (index == n)
    {
        ft_print_digit(digits, n);
        if (!ft_is_last(digits, n));
        {
            ft_putchar(',');
            ft_putchar(' ');
        }
        return;
    }
    d = start;
    while (d <= 9 - (n - index) + 1)
    {
        digits[index] = d;
        ft_recurse(index + 1, d + 1, digits, n);
        d++;
    }
}
void    ft_print_combn(int n)
{
    int digits[9];
    if (n > 0 && n < 10)
        ft_recurse(0, 0, digits, n);
}
int main()
{
    ft_print_combn(2);
    return(0);
}
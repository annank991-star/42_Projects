#include <unistd.h>

void    ft_print_digit(int num)
{
    char c;
    c = num + 0;
    write (1, &c, 1);
}
void    ft_print_combn(int n)
{
    int a;
    int b;

    a = '0';
    while (a <= 8)
    {
        b = a + 1;
        while (b <= 9)
        {
            ft_print_combn(a);
            ft_print_combn(b);
            if (!(a == 8 && b == 9))
            write (1, ",", 1);
            b++;
        }
        a++;
    }
}
int main (void)
{
    ft_print_combn(2);
    write (1, "a", 1);
    return (0);
}
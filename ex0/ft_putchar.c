#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
    write(1, "\n", 1);
}
int main (void)
{
    ft_putchar('a');
    ft_putchar('n');
    ft_putchar('n');
    ft_putchar('a');
    ft_putchar('\n');
    return (0);
}
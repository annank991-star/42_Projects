#include <unistd.h>

void    ft_putnbr(int n)
{
    if(n < 0)
    {
        write(1, "-", 1);
        n = -n;

        if(n > 0)
        {
            ft_putnbr(n/10);
            
        }

        char c = (n % 10)+'0';
        write(1, &c, 1);
        write

    }

}

int main(void)
{
    ft_putnbr(5);
    write(1, "\n", 1);
    return(0);
}
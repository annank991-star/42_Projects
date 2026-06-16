#include <unistd.h>

void    ft_print_comb2(void)
{
    char    a;
    char    b;

         a = '0';
    
    while (a <= 98)
    {
        b = a + 1;
        while(b <= 99)
        {
            char digit;
            digit = a / 10 +'0';
            write (1, &digit, 1);
            digit = a % 10 + '0';
            write (1, &digit, 1);
            if (!(a == 98 && b == 99))
            write (1, ",", 1);
            b++;
            {
            a++;
            }
        }
    }

}
int main (void)
{
    ft_print_comb2();
    write(1, "\n", 1);
    return (0);
}
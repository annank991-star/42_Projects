#include<unistd.h>

int    ft_iterative_factorial(int nb)
{   
    int result;

    if(nb < 0)
    return(0);


    result = 1;
    while (nb > 0)
    {
        result = result *nb;
        nb --;
    }
        return (result);
}

int main(void)
{
    ft_iterative_factorial(1);
    write(1, "\n", 1);
    return(0);
}
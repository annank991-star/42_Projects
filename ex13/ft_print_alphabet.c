#include <unistd.h>

int main(void)
{
    char a = '4';
    char b = '2';

    write(1, &a, 1);
    write(1, &b, 1);
    write(1, "\n", 1);
    return(0);


}
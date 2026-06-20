#include <unistd.h>
int main(void)
{
    char str['i'] = "anna\0";
    write(1, "anna", 4);
    write(1, "\n", 1);
    return(0); 
}
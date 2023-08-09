// Online C compiler to run C program online
#include <stdio.h>

int get_bit(unsigned long int n, unsigned int index)
{
    unsigned int val;
    if (index > 63)
        return (0);
    
    val = (n >> index) & 1;
    return (val);
}
int main(void)
{
    int n;

    n = get_bit(1024, 10);
    printf("%d\n", n);
    n = get_bit(98, 1);
    printf("%d\n", n);
    n = get_bit(1024, 0);
    printf("%d\n", n);
    return (0);
}



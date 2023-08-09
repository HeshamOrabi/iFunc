#include <stdio.h>

int clear_bit(unsigned long int *n, unsigned int index)
{
    unsigned int val;
    
    if (index > 63)
        return (0);
    
    *n = *n & ~(1UL << index);
    
    return (1);
}
int main(void)
{
    unsigned long int n;

    n = 1024;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 0;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    clear_bit(&n, 1);
    printf("%lu\n", n);
    return (0);
}



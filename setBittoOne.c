#include <stdio.h>

int set_bit(unsigned long int *n, unsigned int index)
{
    unsigned int val;
    
    if (index > 63)
        return (0);
    
    *n = (1UL << index) | *n;
    
    return (1);
}
int main(void)
{
    unsigned long int n;

    n = 1024;
    set_bit(&n, 5);
    printf("%lu\n", n);
    n = 0;
    set_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    set_bit(&n, 0);
    printf("%lu\n", n);
    return (0);
}



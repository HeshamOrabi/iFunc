#include <stdio.h>

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    int i, count = 0;
    unsigned long int xorval, val;
    
    xorval = n ^ m;
    
    for (i = 63; i >= 0; i--)
    {
        val = xorval >> i;
        if (val & 1)
        {
            count++;
        }
    }
    
    return (count);
}

int main(void)
{
    unsigned int n;

    n = flip_bits(1024, 1);
    printf("%u\n", n);
    n = flip_bits(402, 98);
    printf("%u\n", n);
    n = flip_bits(1024, 3);
    printf("%u\n", n);
    n = flip_bits(1024, 1025);
    printf("%u\n", n);
    return (0);
}


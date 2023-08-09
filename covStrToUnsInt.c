#include <stdio.h>

unsigned int binary_to_uint(const char *b)
{
    int i;
    unsigned int num = 0;
    
    if (!b)
    {
	    return(0);
    }
    for (i = 0; b[i] != '\0'; i++)
    {
        if (b[i] < '0' || b[i] > '1')
        {
            return (0);
        }
        
        num = 2 * num + (b[i] - '0');
    }
    return (num);
}

int main(void)
{
    unsigned int n;

    n = binary_to_uint("1");
    printf("%u\n", n);
    n = binary_to_uint("101");
    printf("%u\n", n);
    n = binary_to_uint("1e01");
    printf("%u\n", n);
    n = binary_to_uint("1100010");
    printf("%u\n", n);
    n = binary_to_uint("0000000000000000000110010010");
    printf("%u\n", n);
    return (0);
}

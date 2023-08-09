#include <stdio.h>

void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned int val;

	if (n == 0)
	{
		putchar('0');
	}

	for (i = 63; i >= 0; i--)
	{
		val = n >> i;
		if (val & 1)
		{
			putchar('1');
			count++;
		}
		else if (count)
		{
			putchar('0');
		}
	}
}
int main(void)
{
    print_binary(0);
    printf("\n");
    print_binary(1);
    printf("\n");
    print_binary(98);
    printf("\n");
    print_binary(1024);
    printf("\n");
    print_binary((1 << 10) + 1);
    printf("\n");
    return (0);
}

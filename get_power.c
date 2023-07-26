#include <stdio.h>

/**
 * power - optimized get the power func
 * @base: the num to get its power
 * @exp: the expo
 * Return: the power
 */
double power(double base, int exp)
{
	double res;

	if (base == 0)
	{
		return (0);
	}
	if (exp == 0)
	{
		return (1);
	}

	res = power(base, exp / 2);
	
	if (exp % 2 == 0)
	{
		return (res * res);
	}
	else if (exp > 0)
	{
		return (res * res * base);
	}
	else
	{
		return (res * res / base);
	}

}


int main() {
    double res;
    
    res = power(5, -2);
    printf("%lf\n", res);
    
    res = power(5, 2);
    printf("%lf\n", res);
    
    res = power(5, 3);
    printf("%lf\n", res);
    
    res = power(5, -3);
    printf("%lf\n", res);

    return 0;
}

#include <stdio.h>
#include<omp.h>
#include <stdlib.h>

int fibonnaci(int n)
{
    int val;

    if (n == 0 || n == 1)
        return n;

    else
    {
        val = fibonnaci(n-1) + fibonnaci(n-2);
        return val;
    }
}

int main()
{
    int val;
    #pragma omp parallel for private(val)
    for (int i = 0; i <= 10; i++)
    {
        val = fibonnaci(i);
        printf("Fibonacci of %d th term is:     %d\n", i, val);
    }

    return 0;
}

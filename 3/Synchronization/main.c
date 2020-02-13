// https://www.youtube.com/watch?v=WcPZLJKtywc&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG&index=8

#include <stdio.h>
#include<omp.h>
#include <stdlib.h>

int main()
{
    omp_set_num_threads(6);
    int num_nodes = 10000;
    double len_ele = 1.0/(num_nodes-1);
    double sum_copy = 0.0;

    double start_time = omp_get_wtime();

    #pragma omp parallel
    {
        // int ID = omp_get_num_threads();
        double sum = 0.0;

        for (int i = 0; i< num_nodes; i++)
        {
            double x = len_ele*i;
            sum = sum + 4.0/(1.0 + (x*x));
        }

    #pragma omp single
        sum_copy = sum_copy + sum;
    }

    double end_time = omp_get_wtime();

    printf("Pi value is: %f\n", sum_copy*len_ele);
    printf("Time taken is %f\n", end_time-start_time);
    return 0;
}

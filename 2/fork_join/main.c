// https://www.youtube.com/watch?v=OuzYICZUthM&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG&index=7

#include <stdio.h>
#include<omp.h>
#include <stdlib.h>

int main()
{
    omp_set_num_threads(4);
    int pad = 8;        // To prevent false sharing
    int num_nodes = 1000;
    double len_ele = 1.0/(num_nodes-1);
    double sum = 0.0;

    double temp[num_nodes][pad];

    double start_time = omp_get_wtime();

    #pragma omp parallel
    {
        // int ID = omp_get_num_threads();

        for (int i = 0; i< num_nodes; i++)
        {
            double x = len_ele*i;
            double val = 4.0/(1.0 + (x*x));
            temp[i][0] = val;
        }

    }

    double end_time = omp_get_wtime();

    for (int i = 0; i < num_nodes; i++)
    {
        sum = sum + temp[i][0];
    }

    printf("Pi value is: %f\n", sum*len_ele);
    printf("Time taken is %f\n", end_time-start_time);
    return 0;
}

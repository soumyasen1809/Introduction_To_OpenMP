// https://www.youtube.com/watch?v=iPb6OLhDEmM&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG&index=11

#include <stdio.h>
#include<omp.h>
#include <stdlib.h>

int main()
{
    omp_set_num_threads(4);

    int num_ele = 1000;
    double len_ele = 1.0/(num_ele-1);
    double sum = 0.0;

    double start_time = omp_get_wtick();

    #pragma omp parallel for reduction(+:sum)
        for (int i = 0; i < num_ele;  i++)
        {
            double x = i*len_ele;
            sum = sum + 4.0/(1+(x*x));
        }

    double end_time = omp_get_wtick();

    printf("Value of pi is : %f\n", sum*len_ele);
    printf("Time taken is : %f\n", start_time-end_time);

    return 0;
}

// https://www.youtube.com/watch?v=x0HkbIuJILk&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG&index=5

#include <stdio.h>
#include<omp.h>
#include <stdlib.h>

int main()
{
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("hello (%d) \n", ID);
        printf("world (%d) \n", ID);
    }

    return 0;
}

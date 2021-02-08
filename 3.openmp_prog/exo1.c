#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define CHUNKSIZE   5
#define N       30

int main (int argc, char *argv[])
{
    int tid;
   omp_set_num_threads(2);


#pragma omp parallel private(tid) num_threads(4)
    {
        tid = omp_get_thread_num();
        printf("Thread %d starting  ...\n", tid);
        if(tid==0)
        {
        printf("Salam world");
        }
    }


      /* end of parallel section */

}

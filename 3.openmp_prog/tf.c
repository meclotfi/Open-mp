#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void carree(int *tab,int n);
int main (int argc, char *argv[])
{
    int n=atoi(argv[1]);
   int tab[n];


omp_set_num_threads(4);

#pragma omp parallel for
        for (int i = 0; i < n; i++) {
            printf("thread num=%d",omp_get_thread_num());
            tab[i] = 3*i;
            printf("tab[%d]=%d \n", i, tab[i]);
        }
    double debut, fin, temps;
    debut= omp_get_wtime();
        carree(tab, n);
    fin= omp_get_wtime(); temps=fin-debut;
    printf ("Calcul parallel %f secondes\n", temps);

}

void carree(int tab[],int n)
{
    int totale=0;
    omp_set_num_threads(4);
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        printf("thread num=%d",omp_get_thread_num());
        tab[i]=tab[i]*tab[i];
        printf("tab[%d]=%d \n",i,tab[i]);
        totale = totale + tab[i];
    }
printf("totale = %d",totale);
}
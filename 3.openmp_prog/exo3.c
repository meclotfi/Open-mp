#include<stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[]){
    static long nb_pas = 100000000;
    double pas;
    double debut, fin, temps;
    int i; double x, pi, som = 0.0;
    pas = 1.0/(double) nb_pas;
    debut= omp_get_wtime();
    omp_set_num_threads(atoi(argv[1]));
#pragma omp parallel for private(i,x) reduction(+:som)
    for (i=1; i<= nb_pas; i++){
        x = (i-0.5)*pas;
        som = som + 4.0/(1.0+x*x);
    }
    pi = pas * som;
    fin= omp_get_wtime(); temps=fin-debut;
    printf ("Calcul parallel %f secondes\n", temps);

    debut= omp_get_wtime();

    for (i=1; i<= nb_pas; i++){
        x = (i-0.5)*pas;
        som = som + 4.0/(1.0+x*x);
    }
    pi = pas * som;
    fin= omp_get_wtime(); temps=fin-debut;
    printf ("Calcul seq %f secondes\n", temps);
    printf("PI=%f\n",pi);
    return 0;
}

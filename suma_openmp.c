#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000

int main() {
    int *array = (int*) malloc(SIZE * sizeof(int));
    long long suma = 0;

    for (int i = 0; i < SIZE; i++) {
        array[i] = 1;
    }

    double inicio = omp_get_wtime();

    #pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < SIZE; i++) {
        suma += array[i];
    }

    double fin = omp_get_wtime();

    printf("Suma total: %lld\n", suma);
    printf("Tiempo de ejecucion: %f segundos\n", fin - inicio);

    free(array);
    return 0;
}

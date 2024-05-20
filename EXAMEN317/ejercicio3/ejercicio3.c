#include <stdio.h>
#include <omp.h>

int main() {
    int m = 18;
    int n = 3;
    int multiplicacion = 0;
    int division = 0;

    // Multiplicacion en base a sumas
    #pragma omp parallel for reduction(+:multiplicacion)
    for (int i = 0; i < n; i++) {
        multiplicacion += m;
    }

    // Division en base a restas
    if (n != 0) {
        #pragma omp parallel for reduction(+:division)
        for (int i = 0; i < m; i += n) {
            division++;
        }
    }

    printf("Multiplicacion en base a sumas: %d\n", multiplicacion);
    printf("Division en base a restas: %d\n", division);

    return 0;
}

#include <stdio.h>
#include <omp.h>

int main() {
    int M, N;

    printf("Ingrese el numero de vectores (M): ");
    scanf("%d", &M);

    printf("Ingrese el numero de terminos (N): ");
    scanf("%d", &N);

    int series[M][N];

    #pragma omp parallel for
    for (int i = 0; i < M; i++) {
        int start_value = (i * N + 1) * 2;

        for (int j = 0; j < N; j++) {
            series[i][j] = start_value + j * 2;
        }
    }

    printf("Serie generada:\n");
    for (int i = 0; i < M; i++) {
        printf("Vector %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            printf("%d ", series[i][j]);
        }
        printf("\n");
    }

    return 0;
}
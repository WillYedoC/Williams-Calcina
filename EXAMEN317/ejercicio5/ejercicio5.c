#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4

int main(int argc, char *argv[]) {
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int matriz[N][N];
    int vector[N];
    int resultadoParcial[N] = { 0 };

    if (rank == 0) {
        printf("Matriz:\n");
        for (int i = 0; i < N; i++) {
            vector[i] = i + 1;
            for (int j = 0; j < N; j++) {
                matriz[i][j] = i * N + j + 1;
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\nVector:\n");
        for (int i = 0; i < N; i++) {
            printf("%d\n", vector[i]);
        }
        printf("\n");
    }

    MPI_Bcast(vector, N, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultadoParcial[i] += matriz[i][j] * vector[j];
        }
    }

    int resultadoFinal[N] = { 0 };
    MPI_Reduce(resultadoParcial, resultadoFinal, N, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Resultado:\n");
        for (int i = 0; i < N; i++) {
            printf("%d\n", resultadoFinal[i]);
        }
    }

    MPI_Finalize();
    return 0;
}

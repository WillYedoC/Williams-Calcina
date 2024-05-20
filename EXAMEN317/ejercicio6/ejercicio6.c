#include <stdio.h>
#include <math.h>
#include <mpi.h>

double calcular_pi(long long ini, long long fin, double h) {
    double sum = 0.0;
    double x;
    for (long long i = ini; i < fin; i++) {
        x = h * ((double)i - 0.5);
        sum += 4.0 / (1.0 + x*x);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int rank, size;
    long long N = 1000000;  
    double pi, pi_local;
    double h;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    h = 1.0 / (double)N;

    long long ini = N / size * rank;
    long long fin = N / size * (rank + 1);
    pi_local = calcular_pi_local(ini, fin, h);

    if (rank == 0) {
        pi = pi_local;
        double recv_pi;
        for (int i = 1; i < size; i++) {
            MPI_Recv(&recv_pi, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            pi += recv_pi;
        }
    } else {
        MPI_Send(&pi_local, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    if (rank == 0) {
        pi *= h;
        printf("El valor aproximado de pi es: %.16f\n", pi);
    }

    MPI_Finalize();
    return 0;
}

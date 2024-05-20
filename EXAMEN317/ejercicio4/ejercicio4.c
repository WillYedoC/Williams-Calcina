#include <stdio.h>
#include <omp.h>

#define N 4

int main() {
	int matriz[N][N];

	int vector[N]; 
	int resultado[N] = { 0 };

	for (int i = 0; i < N; i++) {
		vector[i]=i+1;
		for (int j = 0; j < N; j++) {
			matriz[i][j] = i * N + j + 1;
		}
	}
	
#pragma omp parallel for
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			resultado[i] += matriz[i][j] * vector[j];
		}
	}


	printf("Resultado:\n");
	for (int i = 0; i < N; i++) {
		printf("%d\n", resultado[i]);
	}

	return 0;
}

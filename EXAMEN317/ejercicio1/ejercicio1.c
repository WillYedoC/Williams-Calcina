#include <stdio.h>

int suma(int *a, int *b) {
    return *a + *b;
}

int resta(int *a, int *b) {
    return *a - *b;
}

int multiplicacion(int *a, int *b) {
    int resultado = 0;
    for (int i = 0; i < *b; i++) {
        resultado += *a;
    }
    return resultado;
}

int division(int *a, int *b) {
    int resultado = 0;
    while (*a >= *b) {
        *a -= *b;
        resultado++;
    }
    return resultado;
}

int main() {
    int x = 20;
    int y = 4;

    printf("Suma: %d + %d = %d\n", x, y, suma(&x, &y));
    printf("Resta: %d - %d = %d\n", x, y, resta(&x, &y));
    printf("Multiplicacion: %d * %d = %d\n", x, y, multiplicacion(&x, &y));
    printf("Division: %d / %d = %d\n", x, y, division(&x, &y));

    return 0;
}

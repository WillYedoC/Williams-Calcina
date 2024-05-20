#include <iostream>

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

    std::cout << "Suma: " << x << " + " << y << " = " << suma(&x, &y) << std::endl;
    std::cout << "Resta: " << x << " - " << y << " = " << resta(&x, &y) << std::endl;
    std::cout << "Multiplicacion: " << x << " * " << y << " = " << multiplicacion(&x, &y) << std::endl;
    std::cout << "Division: " << x << " / " << y << " = " << division(&x, &y) << std::endl;

    return 0;
}

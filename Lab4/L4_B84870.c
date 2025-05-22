#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Reserva memoria dinámica para una matriz cuadrada
void reservar_matriz(int ***matriz, int tamano) {
    *matriz = (int **)malloc(tamano * sizeof(int *));
    for (int i = 0; i < tamano; i++) {
        *(*matriz + i) = (int *)malloc(tamano * sizeof(int));
    }
}

// Llena la matriz con 0s y 1s aleatorios
void llenar_matriz(int **matriz, int tamano) {
    srand(time(NULL));
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            *(*(matriz + i) + j) = rand() % 2;
        }
    }
}

// Imprime la matriz usando aritmética de punteros
void imprimir_matriz(int **matriz, int tamano) {
    printf("Matriz (%dx%d):\n", tamano, tamano);
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

// Libera la memoria de la matriz
void liberar_matriz(int **matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        free(*(matriz + i));
    }
    free(matriz);
}

// Busca la secuencia más larga de 1s en la dirección diagonal ↓↙
void encontrar_diagonal_mas_larga(int **matriz, int tamano, int *resultado) {
    int max_longitud = 0;
    int longitud_actual = 0;

    
    for (int col = 0; col < tamano; col++) {
        int i = 0;
        int j = col;
        while (i < tamano && j >= 0) {
            if (*(*(matriz + i) + j) == 1) {
                longitud_actual++;
                if (longitud_actual > max_longitud) {
                    max_longitud = longitud_actual;
                }
            } else {
                longitud_actual = 0;
            }
            i++;
            j--;
        }
    }

    
    for (int row = 1; row < tamano; row++) {
        int i = row;
        int j = tamano - 1;
        while (i < tamano && j >= 0) {
            if (*(*(matriz + i) + j) == 1) {
                longitud_actual++;
                if (longitud_actual > max_longitud) {
                    max_longitud = longitud_actual;
                }
            } else {
                longitud_actual = 0;
            }
            i++;
            j--;
        }
    }

    *resultado = max_longitud;
}

void redimensionar_matriz(int ***matriz, int tamano_anterior, int nuevo_tamano) {
    // Crear nueva matriz
    int **nueva_matriz = (int **)malloc(nuevo_tamano * sizeof(int *));
    for (int i = 0; i < nuevo_tamano; i++) {
        nueva_matriz[i] = (int *)malloc(nuevo_tamano * sizeof(int));
    }

    // Copiar los valores anteriores
    for (int i = 0; i < tamano_anterior && i < nuevo_tamano; i++) {
        for (int j = 0; j < tamano_anterior && j < nuevo_tamano; j++) {
            *(*(nueva_matriz + i) + j) = *(*(*matriz + i) + j);
        }
    }

    // Llenar nuevas posiciones con valores aleatorios
    for (int i = 0; i < nuevo_tamano; i++) {
        for (int j = 0; j < nuevo_tamano; j++) {
            if (i >= tamano_anterior || j >= tamano_anterior) {
                *(*(nueva_matriz + i) + j) = rand() % 2;
            }
        }
    }

    // Liberar matriz anterior
    liberar_matriz(*matriz, tamano_anterior);

    // Reasignar el puntero
    *matriz = nueva_matriz;
}



int main() {
    int tamano, nuevo_tamano, diagonal_mas_larga;
    int **matriz = NULL;
    char opcion;

    srand(time(NULL));

    printf("Ingrese el tamaño inicial de la matriz cuadrada: ");
    scanf("%d", &tamano);

    reservar_matriz(&matriz, tamano);
    llenar_matriz(matriz, tamano);

    imprimir_matriz(matriz, tamano);

    encontrar_diagonal_mas_larga(matriz, tamano, &diagonal_mas_larga);
    printf("La secuencia de 1s más larga en dirección ↙ es: %d\n", diagonal_mas_larga);

    // Preguntar si se desea redimensionar la matriz
    printf("¿Desea cambiar el tamaño de la matriz? (s/n): ");
    scanf(" %c", &opcion); // espacio antes del %c para ignorar saltos de línea

    if (opcion == 's' || opcion == 'S') {
        printf("Ingrese el nuevo tamaño de la matriz: ");
        scanf("%d", &nuevo_tamano);

        redimensionar_matriz(&matriz, tamano, nuevo_tamano);
        tamano = nuevo_tamano;

        printf("\nNueva matriz generada:\n");
        imprimir_matriz(matriz, tamano);

        encontrar_diagonal_mas_larga(matriz, tamano, &diagonal_mas_larga);
        printf("La nueva secuencia más larga de 1s en dirección ↙ es: %d\n", diagonal_mas_larga);
    }

    liberar_matriz(matriz, tamano);

    return 0;
}

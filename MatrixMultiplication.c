//
// Created by josel on 11/11/2023.
//

#include "MatrixMultiplication.h"
#include <stdio.h>

int pricipal(){

    int rows1, cols1, rows2, cols2;

    printf("Ingrese el numero de filas y columnas de la primera matriz: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Ingrese el numero de filas y columnas de la segunda matriz: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("La multiplicacion de matrices no es posible. El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz.\n");
        return 0;
    }

    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];
    int resultMatrix[rows1][cols2];

    printf("Ingrese los elementos de la primera matriz:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Ingrese los elementos de la segunda matriz:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, resultMatrix);

    printf("Matriz 1:\n");
    displayMatrix(rows1, cols1, matrix1);

    printf("\nMatriz 2:\n");
    displayMatrix(rows2, cols2, matrix2);

    printf("\nMatriz Resultante:\n");
    displayMatrix(rows1, cols2, resultMatrix);

}

void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2],  int result[rows1][cols2]){
    //(rows1*cols1 ) * (rows2*cols2) = (rows1*cols2)
    int i, j, k;
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

}
void displayMatrix(int rows, int cols, int matrix[rows][cols]){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

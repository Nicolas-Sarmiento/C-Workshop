//
// Created by josel on 11/11/2023.
//

#include "MatrixMultiplication.h"
#include <stdio.h>


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

//
// Created by josel on 11/11/2023.
//

#ifndef C_WORKSHOP_MATRIXMULTIPLICATION_H
#define C_WORKSHOP_MATRIXMULTIPLICATION_H

int pricipal();
void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2],  int result[rows1][cols2]);
void displayMatrix(int rows, int cols, int matrix[rows][cols]);

#endif //C_WORKSHOP_MATRIXMULTIPLICATION_H

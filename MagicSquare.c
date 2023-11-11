//
// Created by Nicolas Sarmiento on 10/11/2023.
//

#include "MagicSquare.h"
#include <stdlib.h>
#include <stdio.h>

int **emptySquareMatrix(int order) {
    int** matrix = ( int** ) malloc( order * sizeof ( int*));
    for (int i = 0; i < order; i++) {
        matrix[i] = ( int * ) malloc( order * sizeof (int));
        for ( int j = 0; j < order; j++){
            matrix[i][j] = 0;
        }
    }
    return matrix;
}


int** obliqueMatrixElements( int order, int sizeExtended ) {
    int** extended = emptySquareMatrix( sizeExtended );

    int beginX;
    int beginY;
    int naturalNumber = 1;

    for (int i = 0; i < order; i++) {
        beginX = (sizeExtended  / 2) + i ;
        beginY = i;

        for (int j = 0; j < order; j++) {
            extended[beginY][beginX] = naturalNumber;
            naturalNumber++;
            beginX--;
            beginY++;
        }

    }

    return extended;
}

void permuteTopVerticals( int** extendedMatrix, int order ) {
    int limitTop = (order - 1) / 2;
    int rightTop = (limitTop + order) - 1;
    //Top Permutation
    for (int i = 0; i < limitTop ; i++) {
        for (int j = limitTop; j < rightTop; j++) {
            if ( extendedMatrix[i][j] == 0 ){ continue;}
            extendedMatrix[i + order][j] = extendedMatrix[i][j];
            extendedMatrix[i][j] = 0;
        }
    }
}

void permuteBottomVerticals( int** extendedMatrix, int order , int sizeExtended ){
    int left = (order - 1)/2;
    int bottom = left + order - 1;

    for (int i = sizeExtended - 1; i > bottom; i-- ){
        for (int j = left; j < ( left +order) -1 ; j++) {
            if ( extendedMatrix[i][j] == 0 ){ continue;}
            extendedMatrix[i - order][j] = extendedMatrix[i][j];
            extendedMatrix[i][j] = 0;
        }
    }
}

void permuteLeftColumns( int** extendedMatrix, int order ){
    int top = (order - 1)/2;
    int bottom = top + order;

    for (int i = top; i < bottom ; i++) {
        for (int j = 0; j < top; j++) {
            if ( extendedMatrix[i][j] == 0 ){ continue;}
            extendedMatrix[i][j + order] = extendedMatrix[i][j];
            extendedMatrix[i][j] = 0;
        }
    }
}
void permuteRightColumns( int** extendedMatrix, int order, int sizeExtended ){
    int top = (order - 1)/2;
    int bottom = top + order;

    for (int i = top; i < bottom ; i++) {
        for (int j = bottom; j < sizeExtended ; j++) {
            if ( extendedMatrix[i][j] == 0 ){ continue;}
            extendedMatrix[i][j - order] = extendedMatrix[i][j];
            extendedMatrix[i][j] = 0;
        }
    }
}

int** magicSquare( int order ){
    if ( order % 2 == 0 || order <= 2 ){ return NULL;}

    int extendedSize = (2*order) - 1;
    int leftLimit = (order - 1)/2;
    int rightLimit = leftLimit + order;
    int** magicMatrix = emptySquareMatrix( order );
    int** extended = obliqueMatrixElements( order, extendedSize);

    permuteTopVerticals(extended, order);
    permuteBottomVerticals(extended, order, extendedSize);
    permuteLeftColumns(extended, order);
    permuteRightColumns(extended, order, extendedSize);

    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            magicMatrix[i][j] = extended[leftLimit + i][ leftLimit + j];
        }
    }
    return magicMatrix;
}

void printSquareMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        printf(" ");
        for (int j = 0; j < size; j++) {
            printf(" %d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
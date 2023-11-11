//
// Created by sarmi on 10/11/2023.
//

#ifndef C_WORKSHOP_MAGICSQUARE_H
#define C_WORKSHOP_MAGICSQUARE_H

extern int** magicSquare( int order );
int** emptySquareMatrix( int order );
void printSquareMatrix( int** matrix, int size);
int** obliqueMatrixElements( int order , int sizeExtended);
void permuteTopVerticals( int** extendeMatrix, int order);
void permuteBottomVerticals( int** extendedMatrix, int order , int sizeExtended );
void permuteLeftColumns( int** extendedMatrix, int order );
void permuteRightColumns( int** extendedMatrix, int order, int sizeExtended );

#endif //C_WORKSHOP_MAGICSQUARE_H

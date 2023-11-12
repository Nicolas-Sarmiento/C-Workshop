//
// Created by sarmi on 11/11/2023.
//
#include <stdio.h>
#include <string.h>
#include "RomansNumbers.h"
#include "AmicableNumbers.h"
#include "MagicSquare.h"
#include "Menu.h"
#include "PrimeNumbers.h"
#include "EgotisticalNumber.h"
#include "InnerProduct.h"
#include "ProperNoun.h"
#include "MatrixMultiplication.h"
#include "Dates.h"



int validNaturalNumber(){
    int number = -1;
    int c;
    do {
        scanf("%d", &number);
        while ((c = getchar()) != '\n' && c != EOF); // clear scanf buffer
        if ( number < 0 ){
            printf("Input does not valid. Try again.\n");
        }
    } while ( number == -1 );
    return number;
}

void romanNumbersMenu(){
    int decimalNumber;
    printf("------- CONVERT DECIMAL NUMBERS TO ROMANS --------\n");
    printf("Input the number to convert it to a roman number \nEnter the decimal number -> ");
    decimalNumber = validNaturalNumber();
    char *romanNumberResult = romanNumber( decimalNumber );
    printf("the number %d in roman %s\n", decimalNumber, romanNumberResult);
}

void amicableNumbersMenu(){
    int numberOne;
    int numberTwo;
    printf("-------- AMICABLE NUMBERS ---------\n");
    printf("Input two numbers to verify if those are amicable numbers. \nEnter the first number -> ");
    numberOne = validNaturalNumber();
    printf("Enter the second number -> ");
    numberTwo = validNaturalNumber();

    printf("The number %d and %d are%samicable numbers.\n", numberOne, numberTwo, areAmicableNumbers(numberOne, numberTwo) ? " ": " not ");
}

void magicSquareMenu(){
    int order;
    printf("-------- MAGIC SQUARE ---------\n");
    printf("Input the order to create a magic square. The number must be a natural odd number greater than 2 (two) \nYour square order -> ");
    order = validNaturalNumber();
    int** magicSquareMatrix = magicSquare( order );
    if ( magicSquareMatrix == NULL ){
        printf("%d is an imposible order for a magic square\n", order );
        return;
    }

    printf("The magic square the order %d is:\n", order);
    printSquareMatrix( magicSquareMatrix, order );
}

void primeNumbersMenu(){
    int number = 0;
    printf("-------- PRIME NUMBER ---------\n");
    do{
        printf("Input the number you want to express in prime factors: \n");
        number = validNaturalNumber();
        if(number <=1){
            printf("Please enter a number greater than 1.\n");
        }
    } while (number <= 1);
    primeNumbers(number);
}
void egoisticalNumberMenu(){
    int number = 0;
    printf("-------- EGOISTICAL NUMBER ---------\n");
    printf("Input the number you want to check if it is egoistical: \n");
    number = validNaturalNumber();

    int result = isEgotistical(number);

    if(isEgotistical(number) == 1){
        printf( "The number %d is egoistical", number);
        return;
    }
    printf( "The number %d is not egoistical", number);
}

void innerProductMenu(){
    int size;
    int result;
    printf("-------- EGOISTICAL NUMBER ---------\n");
    printf("Input the size of the array:  \n");
    size = validNaturalNumber();
    int arrayOne[size];
    int arrayTwo[size];

    for(int i = 0; i<size; i++){
        printf("Input the %d number of the first array:  \n", i+1);
        arrayOne[i] = validNaturalNumber();
    }

    for(int i = 0; i<size; i++){
        printf("Input the %d number of the second array:  \n", i+1);
        arrayTwo[i] = validNaturalNumber();
    }
    if(sizeof(arrayOne)/ sizeof(arrayOne[0]) !=size || sizeof(arrayTwo)/ sizeof(arrayTwo[0]) !=size){
        printf("It is not possible to find the inner product of two matrices of different sizes");
        return;
    }

    result = innerProduct(arrayOne, arrayTwo, size);

    printf("The inner product is: %d", result);
}

extern void multiplyMatricesMenu(){
    int rows1, cols1, rows2, cols2;

    printf("-------- Matrix Multiplication ---------\n"
           "MATRIX NUMBER ONE\n");

    printf("Enter number of rows: ");
    rows1 = validNaturalNumber();
    printf("Enter number of columns: ");
    cols1 = validNaturalNumber();
    //scanf("%d %d", &rows1, &cols1);

    printf("MATRIX NUMBER TWO\n"
           "Enter number of rows: ");
    rows2 = validNaturalNumber();
    printf("Enter number of columns: ");
    cols2 = validNaturalNumber();
    //scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. The number of columns of the first matrix must be equal to the number of rows of the second matrix..\n");
        return;
    }

    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];
    int resultMatrix[rows1][cols2];

    printf("Enter the elements of the first matrix, do it row by row, select the number and hit enter:\n");
    for (int i = 0; i < rows1; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < cols1; j++) {
            printf("Enter element %d: ", j + 1);
            matrix1[i][j] = validNaturalNumber();
        }
    }

    printf("Enter the elements of the second matrix, do it row by row, you can enter the row divided by spaces '1 2 3 4' before hitting enter.:\n");
    for (int i = 0; i < rows2; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < cols2; j++) {
            printf("Enter element %d: ", j + 1);
            matrix2[i][j] = validNaturalNumber();
        }
    }

    multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, resultMatrix);

    printf("Matrix 1:\n");
    displayMatrix(rows1, cols1, matrix1);

    printf("\nMatrix 2:\n");
    displayMatrix(rows2, cols2, matrix2);

    printf("\nResultant matrix:\n");
    displayMatrix(rows1, cols2, resultMatrix);
}

void datesMenu(){

    printf("-------- Dates ---------\n");
    char date[30];
    int i = 0;
    while (!i){
        printf("Type the date in the format dd/mm/yyyy: ");

        fgets(date, sizeof(date), stdin);
        date[strcspn(date, "\n")] = '\0';

        char *result = verifyDate(date);
        if(result != NULL){
            i = 1;
            printf("Date: %s\n", result);
        }else{
            printf("Wrong format, the date must be consistent and remember that it must have this composition 'dd/mm/yyyy'.\n");
        }
    }
}

void properNounMenu(){
    printf("-------- Proper noun ---------\n");
    char properNoun[40];

    int aux = 0;
    while (aux == 0 ){
        printf("Enter your full name: ");

        fgets(properNoun, sizeof(properNoun), stdin);
        properNoun[strcspn(properNoun, "\n")] = '\0';

        aux = removeExtraSpaces(properNoun);
        if(aux){
            printf("New format: %s\n", properNoun);
        }else{
            printf("The name cannot contain numerical characters or special characters, try to use only letters.\n");
        }
    }


}
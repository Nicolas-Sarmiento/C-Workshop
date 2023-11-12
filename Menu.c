//
// Created by sarmi on 11/11/2023.
//
#include <stdio.h>
#include "RomansNumbers.h"
#include "AmicableNumbers.h"
#include "MagicSquare.h"
#include "Menu.h"

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
    int decimalNumber = 0;
    printf("------- CONVERT DECIMAL NUMBERS TO ROMANS --------\n");
    printf("Input the number to convert it to a roman number \nEnter the decimal number -> ");
    decimalNumber = validNaturalNumber();
    char *romanNumberResult = romanNumber( decimalNumber );
    printf("the number %d in roman %s\n", decimalNumber, romanNumberResult);
}

void amicableNumbersMenu(){
    int numberOne = 0;
    int numberTwo = 0;
    printf("-------- AMICABLE NUMBERS ---------\n");
    printf("Input two numbers to verify if those are amicable numbers. \nEnter the first number -> ");
    numberOne = validNaturalNumber();
    printf("Enter the second number -> ");
    numberTwo = validNaturalNumber();

    printf("The number %d and %d are%samicable numbers.\n", numberOne, numberTwo, areAmicableNumbers(numberOne, numberTwo) ? " ": " not ");
}

void magicSquareMenu(){
    int order = 0;
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

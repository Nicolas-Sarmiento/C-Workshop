//
// Created by sarmi on 11/11/2023.
//
#include <stdio.h>
#include "RomansNumbers.h"
#include "AmicableNumbers.h"
#include "MagicSquare.h"
#include "Menu.h"
#include "PrimeNumbers.h"
#include "EgotisticalNumber.h"
#include "InnerProduct.h"


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

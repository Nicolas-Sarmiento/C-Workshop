//
// Created by Nicolas Sarmiento on 8/11/2023.
//

#include "RomansNumbers.h"
#include <string.h>
#include <malloc.h>

const int SIZE = 4;
const  char* letterValues[] = { "I", "V", "X", "L", "C", "D", "M"};
const  int values[] = {1,5,10,50,100,500,1000 };

int* unitDecomposition( int number ) {

    if ( number > 4000 || number <= 0) { return  0; }
    int multiplies[] = {1000, 100, 10, 1};
    int* units = (int *) malloc( SIZE * sizeof(int));
    units[0] = 0;
    units[1] = 0;
    units[2] = 0;
    units[3] = 0;
    int i = 0;
    do {
        if ( number / multiplies[i] == 0 ){
            i++;
            continue;
        }
        int digitTemp = number / multiplies[i];
        number -= digitTemp * multiplies[i];
        units[i] = digitTemp * multiplies[i];
        i++;
    } while ( number );

    return units;
}

char *calcDigitsInRoman( int number, int minValue, int maxValue ){
    if (number == 0 ){ return ""; }
    char * result = (char*) malloc(10);
    result[0] = '\0';
    if ( number % 9 == 0 ){
        strcat(result, letterValues[minValue]);
        strcat(result, letterValues[maxValue + 1]);
        return result;
    }

    if ( number == ( values[maxValue] - values[minValue])){
        strcat(result, letterValues[minValue]);
        strcat(result, letterValues[maxValue]);
        return result;
    }

    do {
        if ( number >= values[maxValue] ){
            number -= values[maxValue];
            strcat(result, letterValues[maxValue]);
            continue;
        }

        number -= values[minValue];
        strcat( result, letterValues[minValue]);

    } while ( number );
    return result;
}

char *romanNumber( int number ) {
    if ( number > 4000 || number <= 0 ){
        return "does not exists";
    }

    char *result = (char *) malloc( 100);
    result[0] = '\0';
    int* units = unitDecomposition( number );
    int minKeyValue = 6;

    for (int i = 0; i < SIZE; i++) {
        if ( i == 0) {
            strcat(result, calcDigitsInRoman(units[i], minKeyValue -1, minKeyValue));
            minKeyValue -=2;
            continue;
        }

        strcat( result, calcDigitsInRoman( units[i], minKeyValue, minKeyValue +1 ));
        minKeyValue -=2;
    }
    strcat(result, "\0");
    return result;
}
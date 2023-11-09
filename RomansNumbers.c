//
// Created by sarmi on 8/11/2023.
//

#include "RomansNumbers.h"
#include <string.h>
const char letterValues[] ={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int values[] = {1,5,10,50,100,500,1000 };

int* unitDecomposition( int number ) {
    if ( number >= 10000 ) { return  0; }
    int multiplies[] = {1000, 100, 10, 1};
    static int units[] = {0,0,0,0};
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
char* calcDigitsInRoman( int number, int minValue, int maxValue ){
    if (number == 0 ){ return ""; }

    char* digits[10];
    if ( number % 9 == 0 ) {

        strcat(digits, &letterValues[minValue] );
        strcat(digits, &letterValues[maxValue+1] );
        return digits;
    }

    do {
        
    } while ( number );
}
char *romanNumber(int number) {
    char* romanNumber;

    return 0;
}







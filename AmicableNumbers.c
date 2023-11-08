//
// Created by sarmi on 8/11/2023.
//

#include "AmicableNumbers.h"

int sumDividers( int n ){
    int result = 0;
    for(int i = 1; i < n; i++){
        if( n % i == 0) { result += i; }
    }
    return result;
}
int areAmicableNumbers(int num1, int num2) {
    if ( num1 == num2 || num1 <= 0 || num2 <= 0 ) { return  0; }
    return sumDividers( num1 )  == num2  && sumDividers( num2 ) == num1;
}

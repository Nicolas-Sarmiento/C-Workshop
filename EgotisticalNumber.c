//
// Created by NickG on 10/11/2023.
//

#include "EgotisticalNumber.h"
#include <stdio.h>

#include <math.h>

int isEgotistical(int number){
    int size = floor(log10(abs(number))) + 1;
    int suma = 0;
    int temp = number;
    int digit = 0;

    while (temp > 0){
        digit = temp % 10;
        suma += pow(digit,size);
        temp /= 10;
    }
    return suma == number;
}

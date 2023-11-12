//
// Created by NickG on 11/11/2023.
//
#include <stdio.h>
#include <stdlib.h>

#include "InnerProduct.h"

int innerProduct(int arrayOne[], int arrayTwo[], int size){

    int suma = 0;

    for (int i = 0; i < size; i++) {
        suma += arrayOne[i] * arrayTwo[i];
    }
    return suma;
}

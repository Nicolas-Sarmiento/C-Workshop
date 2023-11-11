//
// Created by NickG on 11/11/2023.
//

#include "InnerProduct.h"

int innerProduct(int arrayOne[], int arrayTwo[], int size){

    printf("%d\n", sizeof(arrayOne));

    int suma = 0;

    for (int i = 0; i < size; ++i) {

        suma += arrayOne[i] * arrayTwo[i];
    }
    printf("%d", suma);

    return suma;
}

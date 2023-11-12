//
// Created by NickG on 9/11/2023.
//

#include "PrimeNumbers.h"
#include <stdio.h>

int primeNumbers(int n) {

    int count = 0;
    printf("los factores primos de %d son: ", n);
    for (int i = 2; i <= n; i++) {
        if(count > 0){
            printf(" * ");
        }
        count = 0;
        while (n % i == 0) {
            count+=1;
            n /= i;
            if(n % i != 0 && count > 1){
                printf("%d^%d", i, count);
            }
            if(n % i != 0 && count == 1){
                printf("%d", i);
            }
        }
    }
}

#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"
int main() {
    int menuOption;
    do {
        printf("------------ C UTILITIES -----------\n");
        printf("Options:\n"
               "1. Roman Number\n"
               "2. Prime Factors\n"
               "3. Proper Noun\n"
               "4. Narcissistic numbers\n"
               "5. Amicable Numbers\n"
               "6. Dates\n"
               "7. Dot Product\n"
               "8. Matrix multiply\n"
               "9. Magic Matrix\n"
               "0. Exit\n"
               "Pick your option: ");

        menuOption = validNaturalNumber();

        switch (menuOption) {
            case 1:
                romanNumbersMenu();
                break;
            case 2:
                primeNumbersMenu();
                break;
            case 3:
                break;
            case 4:
                egoisticalNumberMenu();
                break;
            case 5:
                amicableNumbersMenu();
                break;
            case 6:
                break;
            case 7:
                innerProductMenu();
                break;
            case 8:
                break;
            case 9:
                magicSquareMenu();
                break;
            case 0:
                printf("Exiting C-Utilities :) Thanks for using.\n"
                       "Authors: { \"Jose Salamanca\", \"Nicolas Sarmiento\", \"Nicolas Tinjaca\" }");
                break;
            default:
                printf("Invalid option. Try again\n");
        }
    } while ( menuOption );
    return EXIT_SUCCESS;
}

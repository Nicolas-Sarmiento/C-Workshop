//
// Created by josel on 10/11/2023.
//

#include "Dates.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char day[4], month[4], year[5];
char complete[40];

const char *months[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre"
        , "Noviembre", "Diciembre"
};

char* dates(char date[]){
    int aux = 0;

    for (int i = 0, j = 0; date[i] != '\0' ; ++i) {

        if(date[i] != '/'){

            if(aux == 0) day[j++] = date[i];
            else if (aux == 1) month[j++] = date[i];
            else if(aux == 2) year[j++] = date[i];

        }

        if(date[i] == '/'){
            aux++;j = 0;
        }

    }
    int dayInt = atoi(day);
    int mothInt = atoi(month);
    int yearInt = atoi(year);

    if(dayInt <=31 && mothInt <=12 && yearInt <= 9999){
        dateWriting(day, month, year);
        return complete;
    }else{
        return NULL;
    }

}

char *verifyDate(char date[]){

    int i, j, aux = 0;
    for (i = 0, j = 0; date[i] != '\0'; i++) {

        if(!(isdigit(date[i]) || date[i] == '/')){
            return NULL;
        }

        if(date[i] == '/'){
            aux++;
            if(aux > 2){
                return NULL;
            }
        }

        if (date[i] != ' ' ) {
            date[j++] = date[i];
        }


        if(j >= 9){
            date[j + 1] = '\0';
        }

    }

    return dates(date);
}


void dateWriting(char day[], char month[], char year[]){

    int monthInt = atoi(month);

    char aux[] = " de ";

    strcpy(complete, day);

    strcat(complete, aux);

    strcat(complete, months[monthInt - 1]);

    strcat(complete, " del ");

    strcat(complete, year);


}





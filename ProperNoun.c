//
// Created by josel on 09/11/2023.
//

#include "ProperNoun.h"

#include <ctype.h>

int removeExtraSpaces(char properNoun[]) {
    int i, j;

    for (i = 0, j = 0; properNoun[i] != '\0'; i++) {

        if (!isalpha(properNoun[i]) && properNoun[i] != ' ') {
            return 0;
        }
        if (properNoun[i] != ' ' || (i > 0 && properNoun[i - 1] != ' ')) {
            properNoun[j++] = properNoun[i];
        }

    }
    properNoun[j] = '\0';

    if (j > 0 && properNoun[j - 1] == ' ') {
        properNoun[j - 1] = '\0';
    }

    return capitalizeInitials(properNoun);
}

int convertToLowerCaseExceptInitials(char properNoun[]){

    for(int i = 1; properNoun[i] != '\0'; i++){

        properNoun[i] = tolower(properNoun[i]);

        if(properNoun[i] == ' '){

            if(properNoun[i+1] != '\0')
                i++;
        }

    }
    return 1;

}
int capitalizeInitials(char properNoun[]){

    if(properNoun[0] != '\0'){
        properNoun[0] = toupper(properNoun[0]);
    }else{
        return 0;
    }

    for(int i = 1; properNoun[i] != '\0'; i++){

        if(properNoun[i] == ' '){
            i++;
            if(properNoun[i] != '\0'){

                if(properNoun[i+1] == ' '){
                    properNoun[i] = tolower(properNoun[i]);
                }else{
                    properNoun[i] = toupper(properNoun[i]);
                }
            }
        }

    }
    return convertToLowerCaseExceptInitials(properNoun);
}

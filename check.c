//
// Created by wende on 8/4/2023.
//
#include <stdio.h>
#include "check.h"

void printFormat(Format *format){
    int lineNumber = 1;
    for(int i = 0; i < 10; i++){
        printf("%d. %c\n", lineNumber++, format->formats[i]);
    }
}

int inCorrectFormat(Format *format){
    for(int i = 1; i < 10; i++){
        if(format->formats[i] == 't' && format->formats[i-1] == 'f')
            return 0;
    }
    return 1;
}
//
// Created by wende on 8/4/2023.
//
#include <string.h>
#include "check.h"

int getCommandlineArguments(char *fileName, int args, char **argv){
    if(args > 1 && args <= 2)
        strcpy(fileName, argv[1]);
    else
        return 0;

    return 1;
}
#include <stdio.h>
#include <string.h>
#include "check.h"
#include "commonFiles/gameConfiguration.h"

int main(int args, char** argv) {
    char fileName[BUFFERSIZE];
    GameConfiguration game;
    FILE *fileptr = 0;
    int line = 1;
    //There is only one argument expected
    if(getCommandlineArguments(fileName, args, argv)){
        fileptr = fopen(fileName, "r");
    }
    else{
        fileptr = stdin;
    }

    if(fileptr == 0){
        fprintf(stderr, "%s file not found!\n", fileName);
    }

    if(!getGameConfigurationFromFile(fileptr, &line, &game)){

    }
    return 0;
}

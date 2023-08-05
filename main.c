#include <stdio.h>
#include <string.h>
#include "check.h"


int main(int args, char** argv) {
    FILE * inputFile;
    char buffer[BUFFERSIZE];
    char lineBuffer[BUFFERSIZE];
    int index = 0, linenumber = 1;
    char inputCharacter;
    Format gameFormat;
    memset(gameFormat.formats, 'f', 10);

    if(args > 1){
        inputFile = fopen(argv[1], "r");
    }
    else{
        inputFile = stdin;
    }

    while(fgets(buffer, BUFFERSIZE, inputFile) != NULL){
        for(int i = 0; i < strlen(buffer); i++){
            inputCharacter = buffer[i];
            if(inputCharacter == '#')
                break;
            else{
                lineBuffer[index++] = inputCharacter;
            }
        }
        if(strstr(lineBuffer,"RULES:") == 0){
            gameFormat.formats[rules] = 't';
        }
        else if(strstr(lineBuffer, "turn 1") == 0 || strstr(lineBuffer, "turn 3") ==0){
            gameFormat.formats[cardTurns] = 't';
        }
        memset(lineBuffer, 0, BUFFERSIZE);
        index = 0;
        linenumber++;
    }
    printFormat(&gameFormat);
    return 0;
}

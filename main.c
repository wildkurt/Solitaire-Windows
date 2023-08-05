#include <stdio.h>
#include <string.h>
#include "check.h"


int main(int args, char** argv) {
    FILE * inputFile;
    char buffer[BUFFERSIZE]={0};
    char lineBuffer[BUFFERSIZE]={0};
    int  linenumber = 1;
    char inputCharacter;
    Format gameFormat;
    memset(gameFormat.formats, 'f', 10);

    if(args > 1){
        inputFile = fopen(argv[1], "r");
        if(inputFile == NULL){
            fprintf(stderr, "File %s not found", argv[1]);
            return 1;
        }
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
                lineBuffer[i] = buffer[i];
            }
        }
        if(strstr(lineBuffer,"RULES:") != NULL){
            gameFormat.formats[rules] = 't';
        }
        else if(strstr(lineBuffer, "turn 1") != NULL || strstr(lineBuffer, "turn 3") != NULL){
            gameFormat.formats[cardTurns] = 't';
        }
        memset(lineBuffer, 0, BUFFERSIZE);
        if(inCorrectFormat(&gameFormat)){
            fprintf(stderr, "Format incorrect at line %d ", linenumber);
            return 1;
        }
        linenumber++;
    }
    printFormat(&gameFormat);
    return 0;
}

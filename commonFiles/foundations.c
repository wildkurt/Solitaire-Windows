//
// Created by wende on 5/1/2024.
//

#include <string.h>
#include "foundations.h"
int getFoundations(FILE *filename, int *line, Foundations *foundations, char *buffer, char *cleanBuffer){
    int suitsInOrder = -1;
    while(fgets(buffer, 200, filename) != NULL){
        for(int i = 0; buffer[i] != '\n'; i++){
            if(buffer[i] == '#')
                break;
            else
                cleanBuffer[i] = buffer[i];
        }
        if(strstr(cleanBuffer, "FOUNDATIONS:") != 0){
            suitsInOrder++;
            memset(buffer, 0, 200);
            memset(cleanBuffer, 0, 200);
            continue;
        }
        for(int j = 0; cleanBuffer[j] != '\0'; j++){
            if(cleanBuffer[j] == '_' || isValidRank(cleanBuffer[j])){
                if(cleanBuffer[j+1] == 'c' && suitsInOrder == 0){
                    Card temp = {cleanBuffer[j], cleanBuffer[j+1], 0};
                    foundations->fd[0] = temp;
                    suitsInOrder++;
                }
                else if(cleanBuffer[j+1] == 'd' && suitsInOrder == 1){
                    Card temp = {cleanBuffer[j], cleanBuffer[j+1], 0};
                    foundations->fd[1] = temp;
                    suitsInOrder++;
                }
                else if(cleanBuffer[j+1] == 'h' && suitsInOrder == 2){
                    Card temp = {cleanBuffer[j], cleanBuffer[j+1], 0};
                    foundations->fd[2] = temp;
                    suitsInOrder++;
                }
                else if(cleanBuffer[j+1] == 's' && suitsInOrder == 3){
                    Card temp = {cleanBuffer[j], cleanBuffer[j+1], 0};
                    foundations->fd[3] = temp;
                    suitsInOrder++;
                }

            }
        }
        memset(buffer, 0, 200);
        memset(cleanBuffer, 0, 200);
        if(suitsInOrder == 4)
            break;
        (*line)++;
    }
    return 1;
}

void printFoundationsToScreen(Foundations *foundation){
    printf("FOUNDATIONS:\n");
    for(int i = 0; i < 4; i++){
        printf("%c%c ", foundation->fd[i].rank, foundation->fd[i].suit);
    }
    printf("\n");
}
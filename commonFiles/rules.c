//
// Created by wende on 4/30/2024.
//

#include <string.h>
#include "rules.h"
int getRules(FILE *fileptr, int *line, Rules *rules){
    char buffer[200] = {0}, cleanBuffer[200] = {0};
    int foundRules = 0;
    while(fgets(buffer, 200, fileptr) != NULL){
        for(int i = 0; i < 200; i++){
            if(buffer[i] == '#'){
                if(i != 0)
                    cleanBuffer[i] = '\n';
                break;
            }
            else
                cleanBuffer[i] = buffer[i];
        }
        //printf("%s", cleanBuffer);
        if(strcmp(cleanBuffer, "RULES:") == 0){
            foundRules++;
        }
        if(strcmp(cleanBuffer, "turn 1") == 0){
            if(foundRules == 1){
                rules->cardTurnOver = 1;
                foundRules++;
            }
            else{
                fprintf(stderr,"Did not find header for rules\n");
                return 0;
            }
        }
        else if(strcmp(cleanBuffer, "turn 3") == 0){
            if(foundRules == 1){
                rules->cardTurnOver = 3;
                foundRules++;
            }
            else{
                fprintf(stderr,"Did not find header for rules\n");
                return 0;
            }
        }
        if(strcmp(cleanBuffer, "unlimited") == 0){
            if(foundRules == 2) {
                rules->wasteResetLimit = -1;
                foundRules++;
            }
            else{

            }
        }
        (*line)++;
        memset(buffer, 0, 200);
        memset(cleanBuffer, 0, 200);
    }
    return 1;
}
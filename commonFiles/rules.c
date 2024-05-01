//
// Created by wende on 4/30/2024.
//

#include <string.h>
#include <stdlib.h>
#include "rules.h"
int getRules(FILE *fileptr, int *line, Rules *rules, char *buffer, char *cleanBuffer){

    int foundRules = 0;
    while(fgets(buffer, 200, fileptr) != NULL){
        for(int i = 0; buffer[i] != '\n'; i++){
            if(buffer[i] == '#')
                break;
            else
                cleanBuffer[i] = buffer[i];
        }
        if(strstr(cleanBuffer, "FOUNDATIONS:")!=0)
            break;
        if(strstr(cleanBuffer, "RULES:") != 0){
            foundRules++;
        }
        if(strstr(cleanBuffer, "turn 1") != 0){
            if(foundRules == 1){
                rules->cardTurnOver = 1;
                foundRules++;
            }
            else{
                fprintf(stderr,"Did not find header for rules line %d\n", *line);
                return 0;
            }
        }
        else if(strstr(cleanBuffer, " turn 3") != 0){
            if(foundRules == 1){
                rules->cardTurnOver = 3;
                foundRules++;
            }
            else{
                fprintf(stderr,"Did not find header for rulesline %d\n", *line);
                return 0;
            }
        }
        if(strstr(cleanBuffer, "unlimited") != 0){
            if(foundRules == 2) {
                rules->wasteResetLimit = -1;
                foundRules++;
            }
            else{
                if(foundRules == 0)
                    fprintf(stderr,"Did not find header for rulesline %d\n", *line);

                if(foundRules == 1)
                    fprintf(stderr, "Did not find rule for card turn over line %d\n", *line);

                return 0;
            }
        }
        if(strstr(cleanBuffer, " limit ") != 0){
            foundRules++;
            char *limitptr =strstr(cleanBuffer,"limit");
            char *token = strchr(limitptr, ' ');
            token++;
            rules->wasteResetLimit = strtol(token,NULL,10);
        }

        memset(buffer, 0, 200);
        memset(cleanBuffer, 0, 200);

        if(foundRules == 3)
            break;
        (*line)++;
    }
    if(foundRules != 3){
        fprintf(stderr, "Rules not found line %dline %d\n", *line);
    }
    return 1;
}

void printRulesToScreen(Rules *rules){
    printf("RULES:\n");
    printf("    turn %d\n", rules->cardTurnOver);
    if(rules->wasteResetLimit < 0)
        printf("    unlimited\n");
    else
        printf("    limit %d\n", rules->wasteResetLimit);
}
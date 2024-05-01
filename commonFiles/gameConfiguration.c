//
// Created by wende on 4/30/2024.
//

#include "gameConfiguration.h"
#include "foundations.h"

int getGameConfigurationFromFile(FILE *filename, int *line, GameConfiguration *game){
    char buffer[200] = {0}, cleanBuffer[200] = {0};
    if(!getRules(filename, line, &game->rules, buffer, cleanBuffer)){
        return 0;
    }
    if(!getFoundations(filename, line, &game->foundations, buffer, cleanBuffer)){
        return 0;
    }

    return 1;
}

void printGameConfigurationToScreen(GameConfiguration *game){
    printRulesToScreen(&game->rules);
    printFoundationsToScreen(&game->foundations);
}
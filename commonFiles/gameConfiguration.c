//
// Created by wende on 4/30/2024.
//

#include "gameConfiguration.h"

int getGameConfigurationFromFile(FILE *filename, int *line, GameConfiguration *game){
    if(!getRules(filename, line, &game->rules)){
        return 0;
    }

    return 1;
}
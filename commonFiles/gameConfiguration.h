//
// Created by wende on 4/30/2024.
//

#ifndef SOLITAIRE_WINDOWS_GAMECONFIGURATION_H
#define SOLITAIRE_WINDOWS_GAMECONFIGURATION_H

#include "rules.h"
#include "foundations.h"

typedef struct GameConfiguration{
    Rules rules;
    Foundations foundations;
}GameConfiguration;

int getGameConfigurationFromFile(FILE *filename, int *line, GameConfiguration *game);
void printGameConfigurationToScreen(GameConfiguration *game);
#endif //SOLITAIRE_WINDOWS_GAMECONFIGURATION_H

//
// Created by wende on 4/30/2024.
//

#ifndef SOLITAIRE_WINDOWS_GAMECONFIGURATION_H
#define SOLITAIRE_WINDOWS_GAMECONFIGURATION_H

#include "rules.h"

typedef struct GameConfiguration{
    Rules rules;
}GameConfiguration;

int getGameConfigurationFromFile(FILE *filename, int *line, GameConfiguration *game);
#endif //SOLITAIRE_WINDOWS_GAMECONFIGURATION_H

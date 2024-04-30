//
// Created by wende on 4/30/2024.
//
#include <stdio.h>
#ifndef SOLITAIRE_WINDOWS_RULES_H
#define SOLITAIRE_WINDOWS_RULES_H

typedef struct Rules{
    int cardTurnOver;
    int wasteResetLimit;
}Rules;

int getRules(FILE *fileptr, int *line, Rules *rules);
#endif //SOLITAIRE_WINDOWS_RULES_H

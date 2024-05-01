//
// Created by wende on 5/1/2024.
//

#ifndef SOLITAIRE_WINDOWS_FOUNDATIONS_H
#define SOLITAIRE_WINDOWS_FOUNDATIONS_H

#include <stdio.h>
#include "card.h"

typedef struct Foundations{
    Card fd[4];
}Foundations;

int getFoundations(FILE *filename, int *line, Foundations *foundations, char *buffer, char *cleanBuffer);
void printFoundationsToScreen(Foundations *foundation);
#endif //SOLITAIRE_WINDOWS_FOUNDATIONS_H

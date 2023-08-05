//
// Created by wende on 8/3/2023.
//

#ifndef CHECK_CHECK_H
#define CHECK_CHECK_H

#define BUFFERSIZE 200
enum  formats {rules, cardTurns, wasteReset, foundation, foundationCol, tableau, tableauCol, stock, stockCol, moves};
typedef struct Format{
    char formats[10];
}Format;

void printFormat(Format *format);
int inCorrectFormat(Format *format);

#endif //CHECK_CHECK_H

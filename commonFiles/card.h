//
// Created by wende on 4/30/2024.
//

#ifndef SOLITAIRE_WINDOWS_CARD_H
#define SOLITAIRE_WINDOWS_CARD_H

typedef struct Card{
    char rank;
    char suit;
    char faceUp;
    int number;
} Card;

int isRedCard(Card temp);
int isBlackCard(Card temp);
int cardRankValue(Card temp);
#endif //SOLITAIRE_WINDOWS_CARD_H

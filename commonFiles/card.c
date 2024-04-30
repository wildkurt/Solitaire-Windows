//
// Created by wende on 4/30/2024.
//

#include "card.h"
int isRedCard(Card temp){
    if(temp.suit == 'd' || temp.suit == 'h')
        return 1;
    return 0;
}
int isBlackCard(Card temp){
    if(temp.suit == 'c' || temp.suit == 's')
        return 1;
    return 0;
}
int cardRankValue(Card temp){
    switch (temp.rank){
        case 'A' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        case 'T' : return 10;
        case 'J' : return 11;
        case 'Q' : return 12;
        case 'K' : return 13;
        default : return 0;
    }
}
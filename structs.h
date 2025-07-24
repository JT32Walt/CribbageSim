#ifndef STRUCTS_H
#define STRUCTS_H

#include <array>
#include "card.h"

typedef struct handCribStruct
{
    std::array<card, 4> keptCards;
    std::array<card, 2> cribCards;
};

typedef struct gameDataStruct
{
    int p1Wins = 0;
    int p2Wins = 0;
    int totalFirstDealWins = 0;
    int totalGames = 0;
    int totalHandPoints = 0;
    int totalHands = 0;
    int totalCribPoints = 0;
    int totalCribs = 0;
};




#endif
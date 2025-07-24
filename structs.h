#ifndef STRUCTS_H
#define STRUCTS_H

#include <array>
#include "card.h"


enum suit {
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS
};

typedef struct card {
    int suit; //uses suit enum
    int value; //card points value: 1-10
    int rank; //card rank: 1-13 (used for run detection and sorting)
};

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
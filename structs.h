#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>
#include <iostream>


enum suit {
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS
};

enum faces {
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

struct card {
    int suit; //uses suit enum
    int rank; //card rank: 1-13 (used for run detection and sorting)
    int value; //card points value: 1-10
};

struct handCribStruct
{
    std::vector<card> keptCards;
    std::vector<card> cribCards;

    void print()
    {
        std::cout << "Kept: " << keptCards[0].rank << " " << keptCards[1].rank << " " << keptCards[2].rank << " " << keptCards[3].rank << std::endl;
        std::cout << "Crib: " << cribCards[0].rank << " " << cribCards[1].rank << std::endl;
    }
};

struct gameDataStruct
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
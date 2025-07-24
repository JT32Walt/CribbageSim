#ifndef HAND_H
#define HAND_H
#include "card.h"
#include <array>
#include <iostream>

class hand
{
private:
    std::array<card, 6> dealtCards;
    std::array<card, 4> keptCards;
    std::array<card, 2> cribCards; 
    unsigned int remainingCards = 0;
public:
    hand(/* args */);
    void addCardFromDeal(card dealtCard);
    void setKept(std::array<int, 4> keepIndexes, std::array<int, 2> cribIndexes);
    void clearHand();
    void printHand();
    ~hand();
};





#endif
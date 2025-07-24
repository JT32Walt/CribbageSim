#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <array>

class deck
{
private:
    std::array<card, 52> cards;
    //TODO: change to an interator cause this is kinda dumb
    unsigned int deckTop = 0;
    /* data */
public:
    deck();
    void shuffle();
    card drawFromTop();
    card drawCardForCut();
    void printDeck();
    ~deck();
};








#endif
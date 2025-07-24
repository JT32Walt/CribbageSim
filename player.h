#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "handevaluator.h"
#include "structs.h"
#include <array>
/*
    Player class
    has the hand of cards
    keeps track of their current score
*/

//TODO: Condence the returned hand and crib into a single struct to make this less painful

class player
{
private:
    unsigned int playerScore;
    std::array<card, 6> dealtCards;
    std::array<card,6>::iterator dealtCardsIt = dealtCards.begin();
    std::array<card, 4> keptCards;
    int handScore = 0;
    //HAS A choise strategy
    handevaluator handStrategy;
    //HAS A pegging strategy
public:
    player(/* args */);
    ~player();
    void reset();
    std::array<card,4> evaluate();
    std::array<card,4> getHand();
    void dealCard(card dealtCard);
    void addscore(int score);
    bool checkIfWon();
};





#endif
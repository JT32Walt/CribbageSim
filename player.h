#ifndef PLAYER_H
#define PLAYER_H

#include "handevaluator.h"
#include "structs.h"
#include <vector>
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
    std::vector<card> dealtCards;
    std::vector<card> keptCards;
    //HAS A choise strategy
    handevaluator* handStrategy;
    //HAS A pegging strategy
public:
    player(/* args */);
    ~player();
    void reset(); //clears the hand and score
    void evaluate(); //runs the evaluator
    std::vector<card> getHand();
    void dealCard(card dealtCard);
    void addscore(int score);
    bool checkIfWon();
};





#endif
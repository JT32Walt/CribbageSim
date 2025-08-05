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
    handCribStruct postEval;
    //HAS A choise strategy
    handevaluator* handStrategy;
    //HAS A pegging strategy
public:
    player(handevaluator* handStrat); //takes in hand strat and pegging strat
    player();
    ~player();
    void reset(); //clears the hand and score
    void evaluate(); //runs the evaluator
    std::vector<card> getHand();
    std::vector<card> getCrib();
    void dealCard(card dealtCard);
    void addscore(int score);
    bool checkIfWon();
};





#endif
#ifndef PLAYER_H
#define PLAYER_H

#include "handevaluator.h"
#include "peggingevaluator.h"
#include "structs.h"
#include <vector>
/*
    Player class
    has the hand of cards
    keeps track of their current score
*/

class player
{
private:
    unsigned int playerScore;
    std::vector<card> dealtCards;
    handCribStruct postEval;
    //HAS A choise strategy
    handevaluator* handStrategy;
    //HAS A pegging strategy
    peggingevaluator* peggingStrategy;
public:
    player(handevaluator* handStrat, peggingevaluator* peggingStrat); //takes in hand strat and pegging strat
    player();
    ~player();
    void reset(); //clears the hand and score
    void evaluateHand(); //runs the evaluator
    card evalutePegging(std::vector<card> currentHand, int currentScore, std::vector<card> playedCards);
    std::vector<card> getHand();
    std::vector<card> getCrib();
    void dealCard(card dealtCard);
    void addscore(int score);
    bool checkIfWon();
};






#endif
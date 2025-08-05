#include "player.h"

player::player()
    :handStrategy(nullptr), peggingStrategy(nullptr)
{

}

player::player(handevaluator* handStrat, peggingevaluator* pegStrat)
    : handStrategy(handStrat), peggingStrategy(pegStrat)
{
    
}

player::~player()
{
    
}

void player::evaluate()
{
    postEval = handStrategy->evaluateHand(dealtCards);
}

void player::dealCard(card dealtCard)
{
    dealtCards.emplace_back(dealtCard);
}

void player::addscore(int score)
{
    playerScore += score;
}

std::vector<card> player::getHand()
{
    return postEval.keptCards;
}

std::vector<card> player::getCrib()
{
    return postEval.cribCards;
}

bool player::checkIfWon()
{
    if (playerScore >= 121)
    {
        return true;
    }
    return false;
}

void player::reset()
{
    dealtCards.clear();
    playerScore = 0;
}
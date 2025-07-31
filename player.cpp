#include "player.h"

player::player(handevaluator* handStrat)
{
    handStrategy = handStrat;
    //pegging strategy = peggingstrat
}

player::~player()
{
    delete handStrategy;
}

void player::evaluate()
{
    postEval = handStrategy->evaluateHand(dealtCards);
}

void player::dealCard(card dealtCard)
{
    dealtCards.emplace_back(dealCard);
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
#include "peggingevaluator.h"

peggingevaluator::peggingevaluator(/* args */)
{
}

peggingevaluator::~peggingevaluator()
{
}


std::vector<card> peggingevaluator::getValidCards(const std::vector<card>& cards, int roundScore)
{
    std::vector<card> valid;
    for (card c : cards)
    {
        if (c.value + roundScore <= 31)
        {
            valid.emplace_back(c);
        }
    }
    return valid;
}
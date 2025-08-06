#include "randompeggingevaluator.h"
#include <random>

randompeggingevaluator::randompeggingevaluator(/* args */)
{
}

randompeggingevaluator::~randompeggingevaluator()
{
}

card randompeggingevaluator::evaluatePegging(std::vector<card> hand, int roundScore, std::vector<card> cardsPlayed)
{
    std::vector<card> valid = getValidCards(hand, roundScore);
    if (valid.size() == 0)
    {
        return card{0,0,0};
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0,valid.size() - 1);
    return valid[distr(gen)];
}
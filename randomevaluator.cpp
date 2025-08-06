#include "randomevaluator.h"
#include <random>
randomevaluator::randomevaluator()
{

}

randomevaluator::~randomevaluator()
{

}

handCribStruct randomevaluator::evaluateHand(std::vector<card> dealtCards)
{
    std::vector<handCribStruct> allPossibilities = createAllPossiblilites(dealtCards);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0,dealtCards.size() - 1);
    return allPossibilities[distr(gen)];
}
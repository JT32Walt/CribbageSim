#include "handevaluator.h"
#include <algorithm>

handevaluator::handevaluator()
{

}

handevaluator::~handevaluator()
{
    
}

std::vector<handCribStruct> handevaluator::createAllPossiblilites(std::vector<card> dealtCards)
{
    std::vector<handCribStruct> possibilities;
    std::vector<bool> bitMask(6);
    std::fill(bitMask.begin(), bitMask.begin() + 4, true);

    do
    {
        std::vector<card> handCards;
        std::vector<card> cribCards;
        handCribStruct possibility;

        for (int i = 0; i < 6; i++)
        {
            if (bitMask[i])
            {
                handCards.emplace_back(dealtCards[i]);
            }
            else
            {
                cribCards.emplace_back(dealtCards[i]);
            }
        }
        possibility.keptCards = handCards;
        possibility.cribCards = cribCards;
        possibilities.emplace_back(possibility);

    } while (std::prev_permutation(bitMask.begin(), bitMask.end()));

    return possibilities;
}
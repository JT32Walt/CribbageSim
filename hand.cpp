#include "hand.h"

hand::hand(/* args */)
{
}

hand::~hand()
{
}

void hand::addCardFromDeal(card dealtCard)
{
    dealtCards[remainingCards] = dealtCard;
    remainingCards++;
}

void hand::setKept(std::array<int, 4> keepIndexes, std::array<int, 2> cribIndexes)
{
    for (int i = 0; i < 4; i++)
    {
        keptCards[i] = dealtCards[keepIndexes[i]];
    }
    cribCards[0] = dealtCards[cribIndexes[0]];
    cribCards[1] = dealtCards[cribIndexes[1]];
}

void hand::clearHand()
{
    dealtCards.fill(card{});
    keptCards.fill(card{});
    cribCards.fill(card{});
}

void hand::printHand()
{
    for (auto i : dealtCards) {
        std::cout << i.getValue() << " " << i.getSuit() << std::endl;
    }
}
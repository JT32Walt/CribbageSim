#include "deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <random>

deck::deck()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            int roundedValue = j > 10 ? 10 : j;
            cards[i * 13 + (j - 1)] = card({i, j, roundedValue});
        }
    }

}

void deck::shuffle()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    deckTop = 0;
    for (unsigned int i = 51; i > 1; i--)
    {
        unsigned int roll = std::rand() % (i + 1);
        std::swap(cards[i], cards[roll]);
    }
}

card deck::drawFromTop()
{
    deckTop++; //set the next card to the "top"
    return cards[deckTop - 1];    
}

//current cut is a uniform distribution maybe move to normal distribution later
card deck::drawCardForCut()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(deckTop, 51);
    return cards[dist(gen)];
}

void deck::printDeck()
{
    for (auto i : cards) {
        std::cout << i.rank << " " << i.suit << " " << i.value << "\n";
    }
}

deck::~deck()
{
}
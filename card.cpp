#include "card.h"

card::card()
{
    value = 0;
    suit = 0;
}

card::card(int i_value, int i_suit)
{
    value = i_value;
    suit = i_suit;
}

int card::getValue()
{
    return value;
}

int card::getSuit()
{
    return suit;
}

card::~card()
{
}

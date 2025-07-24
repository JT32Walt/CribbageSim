#ifndef CARD_H
#define CARD_H

enum suit {
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS
};

class card
{
private:
    int value;
    int suit;
public:
    card();
    card(int value, int suit);
    int getValue();
    int getSuit();
    ~card();
};



#endif
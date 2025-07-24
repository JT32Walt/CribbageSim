#ifndef HANDEVALUATOR_H
#define HANDEVALUATOR_H
#include <array>

class handevaluator
{

public:
    virtual std::array<card, 4> evaluateHand(std::array<card, 6> dealtCards);
    virtual ~handevaluator();
};
#endif
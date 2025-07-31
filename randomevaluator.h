#ifndef RANDOMEVALUATOR_H
#define RANDOMEVALUATOR_H

#include "handevaluator.h"


class randomevaluator : public handevaluator
{
private:
    /* data */
public:
    randomevaluator(/* args */);
    handCribStruct evaluateHand(std::vector<card> dealtCards) override;
    ~randomevaluator() override;
};

#endif
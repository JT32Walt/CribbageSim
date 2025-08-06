#ifndef RANDOMPEGGINGEVALUATOR_H
#define RANDOMPEGGINGEVALUATOR_H

#include "peggingevaluator.h"

class randompeggingevaluator : public peggingevaluator
{
public:
    randompeggingevaluator(/* args */);
    card evaluatePegging(std::vector<card> hand, int currentRoundScore, std::vector<card> cards) override;
    ~randompeggingevaluator() override;
};





#endif
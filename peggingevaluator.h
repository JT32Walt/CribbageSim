#ifndef PEGGINGEVALUATOR_H
#define PEGGINGEVALUATOR_H
#include <vector>
#include "structs.h"

class peggingevaluator
{
    public:
    peggingevaluator(/* args */);
    virtual int evaluatePegging(std::vector<card> hand, int currentRoundScore, std::vector<card> cards);
    virtual ~peggingevaluator();
};




#endif
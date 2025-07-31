#ifndef HANDEVALUATOR_H
#define HANDEVALUATOR_H
#include <vector>
#include "structs.h"

class handevaluator
{

public:
    handevaluator();
    virtual handCribStruct evaluateHand(std::vector<card> dealtCards) = 0;
    std::vector<handCribStruct> createAllPossiblilites(std::vector<card> dealtCards);
    virtual ~handevaluator();
};
#endif
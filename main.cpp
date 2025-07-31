#include "deck.h"
#include <vector>
#include <iostream>
#include "scorer.h"
#include "structs.h"
#include "randomevaluator.h"
#include "handevaluator.h"

int main() {
    
    std::vector<card> testhand;
    card c1{SPADES, 1, 1};
    card c2{SPADES, 2, 2};
    card c3{SPADES, 3, 3};
    card c4{SPADES, 4, 4};
    card c5{SPADES, 5, 5};
    card c6{SPADES, 6, 6};
    testhand.emplace_back(c1);
    testhand.emplace_back(c2);
    testhand.emplace_back(c3);
    testhand.emplace_back(c4);
    testhand.emplace_back(c5);
    testhand.emplace_back(c6);
    
    handevaluator *testEval = new randomevaluator();
    handCribStruct testReturn = testEval->evaluateHand(testhand);
    testReturn.print();
    return 0;
}
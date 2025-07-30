#include "deck.h"
#include <vector>
#include <iostream>
#include "scorer.h"
#include "structs.h"

int main() {
    
    std::vector<card> testhand;
    card c1{HEARTS, 1, 1};
    card c2{DIAMONDS, 1, 1};
    card c3{DIAMONDS, 2, 2};
    card c4{DIAMONDS, 3, 3};
    card cut{HEARTS, 3, 3};
    testhand.emplace_back(c1);
    testhand.emplace_back(c2);
    testhand.emplace_back(c3);
    testhand.emplace_back(c4);
    int score = scoreHand(testhand, cut);
    std::cout << score << std::endl;

    return 0;
}
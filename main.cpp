#include "deck.h"
#include <vector>
#include <iostream>
#include "scorer.h"
#include "structs.h"

int main() {
    
    std::vector<card> testhand;
    card c1{HEARTS, 5, 5};
    card c2{DIAMONDS, 5, 5};
    card c3{CLUBS, 5, 5};
    card c4{SPADES, 11, 10};
    card cut{SPADES, 5, 5};
    testhand.emplace_back(c1);
    testhand.emplace_back(c2);
    testhand.emplace_back(c3);
    testhand.emplace_back(c4);
    int score = scoreHand(testhand, cut);
    std::cout << score << std::endl;

    return 0;
}
#include "deck.h"
#include <vector>
#include <iostream>
#include "scorer.h"
#include "structs.h"
#include "player.h"
#include "randomevaluator.h"
#include "handevaluator.h"

int main() {
    deck testDeck;
    randomevaluator* testEval = new(randomevaluator);
    player testPlayer(testEval);
    testDeck.shuffle();

    for (int i = 0; i < 6; i++)
    {
        testPlayer.dealCard(testDeck.drawFromTop());
    }

    testPlayer.evaluate();
    
    std::vector<card> testPlayerHand = testPlayer.getHand();
    std::vector<card> testPlayerCrib = testPlayer.getCrib();

    for (card c : testPlayerHand)
    {
        c.print();
    }
    std::cout << std::endl;

    for (card c : testPlayerCrib)
    {
        c.print();
    }
    std::cout << std::endl;


    

    return 0;
}
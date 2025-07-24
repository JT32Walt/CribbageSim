#include "deck.h"
#include "hand.h"

int main() {
    
    deck testDeck;
    hand testHand;
    card testCard;
    //testDeck.printDeck();
    testDeck.shuffle();
    //testDeck.printDeck();
    testCard = testDeck.drawCardForCut();
    testHand.addCardFromDeal(testCard);
    testHand.printHand();
    testHand.clearHand();
    testHand.printHand();
    return 0;
}
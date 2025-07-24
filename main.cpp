#include "deck.h"
#include "structs.h"

int main() {
    
    deck testDeck;
    card testCard;
    testDeck.printDeck();
    testDeck.shuffle();
    //testDeck.printDeck();
    //testCard = testDeck.drawCardForCut();
    return 0;
}
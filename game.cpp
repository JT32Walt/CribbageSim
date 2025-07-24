#include "game.h"

game::game() {

}

game::~game() {

}

void game::resetGame()
{
    winner = 0;
    p1.reset();
    p2.reset();

    mainDeck.shuffle();
    while (true)
    {
        //draws the card for cut. loops until the cards are not the same card
        //should shuffle the deck enough in the whole function that it makes it okay for the start of the game
        card p1Card = mainDeck.drawCardForCut();
        card p2Card = mainDeck.drawCardForCut();

        if (p1Card.value < p2Card.value)
        {
            curretCrib = PLAYER1;
            break;
        }
        else if (p1Card.value > p2Card.value)
        {
            curretCrib = PLAYER2;
            break;
        }
        mainDeck.shuffle();
    }
    
}

void game::initializeRound()
{
    mainDeck.shuffle();
    //deal 6 cards to each player
    for (int i = 0; i < 6; i++)
    {
        p1.dealCard(mainDeck.drawFromTop());
        p2.dealCard(mainDeck.drawFromTop());
    }    
    //run the evaluators
    handCribStruct p1Hand = p1.evaluate();//call to eval here
    handCribStruct p2Hand = p2.evaluate();//call to eval here
    //put cards into crib
    //fuck it its 4 so just do it 4 times and not deal with the copy bullshit. You are going to see this later and hate it
    crib[0] = p1Hand.cribCards[0];
    crib[1] = p1Hand.cribCards[1];
    crib[2] = p2Hand.cribCards[0];
    crib[3] = p2Hand.cribCards[1];

    //sort the crib and their hands so we do not have to later, note for later, just use built in sort dumbass


    //do the cut
    cutCard = mainDeck.drawCardForCut();
    //jack check
    if (cutCard.value == 11) 
    {
        //give score to whoevers crib it is
        //and i guess you have to check if anyone has won. actually everythime sobody scores you do. Method? Method
    }
}


void game::runPegging()
{
    /*
        Ideas for implamentation.
        Use a vector, append cards to vector, clear vector when the peging round is over
        this should make checking for runs easier, however i have no idea how OOO runs will be
        might be a really fucking dumb implamentation, but every time take the last 3 cards, sort them, then check if they are in order, 
        then i guess keep doing that and increase until we get to the start of the vector or its no longer in order
        have put this all in another function
        should also check for pairs, triples, quads, 15s, 31s, and maybe GOs.
        for go determination we will check their hands for valid cards that they can play and give it to them. MAKE SURE THEY CAN ONLY GIVE ONE GO. check that resets at 31?
        pegging evaluator will get passed: the current played cards vector, valid cards, and the current score/count
        keep running until nobody has cards left


        subfunctions: getValidCards(), checkForPoints(), 
    */
}

/*
Likely implamentation of runGame()
    resetGame()
    while(!winner)
    {
        initialzeRound()
        runPegging()
        scoreHands()
        checkWin()
        //all these funtions should be updating the data structure as it goes along
    }
    return gameDataStruct
*/
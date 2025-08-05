#include "game.h"
#include "scorer.h"

game::game() {

}

game::game(handevaluator* p1Hand, handevaluator* p2Hand)
{
    player p1(p1Hand);
    player p2(p2Hand);   
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
            currentCrib = PLAYER1;
            break;
        }
        else if (p1Card.value > p2Card.value)
        {
            currentCrib = PLAYER2;
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
    p1.evaluate();//call to eval here
    p2.evaluate();//call to eval here
    //put cards into crib
    //fuck it its 4 so just do it 4 times and not deal with the copy bullshit. You are going to see this later and hate it
    std::vector<card> p1Crib = p1.getCrib();
    std::vector<card> p2Crib = p2.getCrib();
    crib.emplace_back(p1Crib[0]);
    crib.emplace_back(p1Crib[1]);
    crib.emplace_back(p2Crib[0]);
    crib.emplace_back(p2Crib[1]);
    //sort the crib and their hands so we do not have to later, note for later, just use built in sort dumbass
    sortByRank(crib);


    //do the cut
    cutCard = mainDeck.drawCardForCut();
    //jack check
    if (cutCard.value == 11) 
    {
        //give score to whoevers crib it is
        if (currentCrib == PLAYER1)
        {
            //this check needs to become a method
            p1.addscore(2);
            if (p1.checkIfWon())
            {
                //set a flag here i guess
            }
        }
        else if (currentCrib == PLAYER2)
        {
            p2.addscore(2);
            if (p2.checkIfWon())
            {
                //i guess set a flag here
            }
        }
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
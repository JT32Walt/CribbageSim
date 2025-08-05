#include "game.h"
#include "scorer.h"


game::game() 
    :p1(nullptr, nullptr), p2(nullptr, nullptr)
{

}

game::game(handevaluator* p1Hand, handevaluator* p2Hand, peggingevaluator* p1Peg, peggingevaluator* p2Peg)
{
    player p1(p1Hand, p1Peg);
    player p2(p2Hand, p2Peg);   
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
    p1.evaluateHand();//call to eval here
    p2.evaluateHand();//call to eval here
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
            winCheck();
        }
        else if (currentCrib == PLAYER2)
        {
            p2.addscore(2);
            winCheck();
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

    std::vector<card> playedCards;
    int currentScore = 0;
    std::vector<card> p1Hand = p1.getHand();
    std::vector<card> p2Hand = p2.getHand();
    playerPeggingStruct p1Struct {p1, p1Hand, false};
    playerPeggingStruct p2Struct {p2, p2Hand, false};
    playerPeggingStruct currentPlayer = currentCrib == PLAYER1 ? p2Struct : p1Struct;
    playerPeggingStruct otherPlayer = currentCrib == PLAYER2 ? p1Struct : p2Struct;
    
    

    while(!(p1Struct.hand.size()|p2Struct.hand.size())) //while someone has cards
    {
        //run the pegging evaluator
        card chosenCard = currentPlayer.p.evalutePegging(p1Hand, currentScore, playedCards); //evaluate pegging will return a "null" card with value 0 if it has no valid moves
        if (chosenCard.rank = 0) //cannot play so we give the other person a go
        {
            //give other player a point and foce a flag so that its there turn.
            if (!otherPlayer.done)
            {
                otherPlayer.p.addscore(1);
                winCheck();
                if (!winner)
                {
                    break;
                }
            }
            currentPlayer.done = true;
            
        }
        else
        {
            playedCards.emplace_back(chosenCard);
            currentScore += chosenCard.value;
            removeCardFromHand(currentPlayer.hand, chosenCard);

            //do card scoring here probably write a method for it
        }

        //current player switching logic
        if (!otherPlayer.done)
        {
            playerPeggingStruct temp = currentPlayer;
            currentPlayer = otherPlayer;
            otherPlayer = temp;
        }
        //stuff to reset, still need to swap though
        if (currentPlayer.done && otherPlayer.done)
        {
            currentScore = 0;
            playerPeggingStruct temp = currentPlayer;
            currentPlayer = otherPlayer;
            otherPlayer = temp;
        }
    }
}

void game::removeCardFromHand(std::vector<card> hand, card selectedCard)
{
    hand.erase(std::remove_if(hand.begin(), hand.end(),
        [&selectedCard](const card& c){ return c.suit == selectedCard.suit && c.rank == selectedCard.rank;}),
        hand.end());
}

void game::winCheck()
{
    if (p1.checkIfWon())
    {
        winner = PLAYER1;
    }
    else if (p2.checkIfWon())
    {
        winner = PLAYER2;
    }
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
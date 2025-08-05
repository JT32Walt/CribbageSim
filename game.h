#ifndef GAME_H
#define GAME_H
#include <vector>
#include "deck.h"
#include "player.h"



/*
    GAME CLASS

    Setus up each round
    contains the players and the decks of cards
    responsible for putting the cards into hands
    responsible for keeping track of who's crib it is
    generates the cut card

    actually runs the simulation

    checks if somebody has won and says who


*/
enum players {
    PLAYER1 = 1,
    PLAYER2 = 2
};




class game
{
private:
    deck mainDeck;
    card cutCard;
    player p1;
    player p2;
    int winner = 0;
    int currentCrib = 0;
    std::vector<card> crib;


public:
    game() = default;
    game(handevaluator* p1Hand, handevaluator* p2Hand, peggingevaluator* p1Peg, peggingevaluator* p2Peg);
    void resetGame(); //game initalization
    void initializeRound(); //deals cards, generates cut, runs hand evaluation and sets the crib up
    void runPegging(); //runs the pegging phase
    void game::removeCardFromHand(std::vector<card> hand, card selectedCard);
    void scoreHands(); //scores the hands in the proper orders and also checks for win
    bool addScoreToPlayer(int player, int score); //adds the score to the given player, and checks if they have won, this should be called anytime score is added
    void winCheck();
    ~game();
};

struct playerPeggingStruct
{
    player p;
    std::vector<card> hand;
    bool done;
};

#endif
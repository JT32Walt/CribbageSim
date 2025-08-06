#include "deck.h"
#include <vector>
#include <iostream>
#include "scorer.h"
#include "structs.h"
#include "player.h"
#include "randomevaluator.h"
#include "handevaluator.h"
#include "peggingevaluator.h"
#include "randompeggingevaluator.h"
#include "game.h"

int main() {
    randomevaluator* p1Eval = new randomevaluator();
    randomevaluator* p2Eval = new randomevaluator();
    randompeggingevaluator* p1PegEval = new randompeggingevaluator();
    randompeggingevaluator* p2PegEval = new randompeggingevaluator();

    game testGame(p1Eval, p2Eval, p1PegEval, p2PegEval);
    testGame.resetGame();
    testGame.initializeRound();
    testGame.runPegging();


    

    return 0;
}
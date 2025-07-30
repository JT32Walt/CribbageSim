#ifndef SCORER_H
#define SCORER_H

#include "structs.h"
#include <vector>
#include <array>
#include <algorithm>

int scoreHand(std::vector<card> hand, card cutCard, bool fullScore = true, bool isCrib = false);
bool allSameSuit(std::vector<card> hand);
int scoreSetsOfTwo(std::vector<card> hand);
int scoreSetsOfThree(std::vector<card> hand);
int scoreSetsOfFour(std::vector<card> hand);
int scoreSetsOfFive(std::vector<card> hand);
void sortByRank(std::vector<card>& hand);

#endif
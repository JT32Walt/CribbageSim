#include "scorer.h"

int scoreHand(std::vector<card> hand, card cutCard, bool fullScore, bool isCrib) //used to score the hand, used by evaluators
{
    int score = 0;
    std::vector<card> combined;
    if (fullScore) 
    {
        for (const card& c : hand)
        {
            if (c.rank == JACK && c.suit == cutCard.suit)
            {
                score += 1;
            }
        }
        combined = hand;
        combined.emplace_back(cutCard);
        if (allSameSuit(combined))
        {
            score += 5;
        }
        else if (allSameSuit(hand) && !isCrib)
        {
            score += 4;
        }
    }
    else
    {
       if (allSameSuit(hand))
       {
        score += 4;
       }
       combined = hand;
    }
    sortByRank(combined);

    score += scoreSetsOfTwo(combined);
    score += scoreSetsOfThree(combined);
    score += scoreSetsOfFour(combined);
    if (fullScore)
    {
        score += scoreSetsOfFive(combined);
    }
    return score;
}

bool allSameSuit(std::vector<card> hand)
{
    int firstSuit = hand[0].suit;
    for (const card& c : hand)
    {
        if (c.suit != firstSuit)
        {
            return false;
        }
    }
    return true;

}

int scoreSetsOfTwo(std::vector<card> hand)
{
    int score = 0;
    for (int i = 0; i < hand.size() - 1; i++)
    {
        for (int j = i + 1; j < hand.size(); j++)
        {
            if ((hand[i].rank == hand[j].rank) || (hand[i].value + hand[j].value == 15))
            {
                score = score + 2;
            }
        }
    }
    return score;
}

int scoreSetsOfThree(std::vector<card> hand)
{
    int score = 0;
    int size = hand.size();
    // there is not really not away to avoid the nesting
    //i take that back its O(N^3) and really fucking slow
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (hand[i].value + hand[j].value + hand[k].value == 15)
                {
                    score += 2;
                }

                std::vector<int> ranks = {hand[i].rank, hand[j].rank, hand[k].rank};

                if (ranks[1] == ranks[0] + 1 && ranks[2] == ranks[1] + 1)
                {
                    score += 3;
                }
            }
        }
    }
    return score;
}

int scoreSetsOfFour(std::vector<card> hand)
{
    int score = 0;
    int size = hand.size();
    for (int i = 0; i < size - 3; i++)
    {
        for (int j = i + 1; j < size - 2; j++)
        {
            for (int k = j + 1; k < size - 1; k++)
            {
                for (int l = k + 1;  l < size; l++)
                {
                    if (hand[i].value + hand[j].value + hand[k].value + hand[l].value == 15)
                    {
                        score = score + 2;
                    }

                    std::vector<int> ranks = {hand[i].rank, hand[j].rank, hand[k].rank, hand[l].rank};

                    if (ranks[1] == ranks[0] + 1 && ranks[2] == ranks[1] + 1 && ranks[3] == ranks[2] + 1)
                    {
                        score = score + 4;
                    }
                }
            }
        }
    }
    return score;
}

int scoreSetsOfFive(std::vector<card> hand)
{
    int score = 0;
    if (hand[0].value + hand[1].value + hand[2].value + hand[3].value + hand[4].value == 15)
    {
        score += 2;
    }
    if (hand[1].rank == hand[0].rank + 1 && hand[2].rank == hand[1].rank + 1 && hand[3].rank == hand[2].rank + 1 && hand[4].rank == hand[3].rank + 1)
    {
        score += 5;
    }
    return score;
}

void sortByRank(std::vector<card>& hand)
{
    std::sort(hand.begin(), hand.end(), [](const card& a, const card& b){
        return a.rank < b.rank;
    });
}
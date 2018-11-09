//
// Created by Andrew Call on 3/2/2017.
//

#include "Card.h"
#include <random>
#include <algorithm>
#include <cstdlib>

Card::Card(int cardSize, int numberMax, int cardNumber) : m_cardNumber(cardNumber)
{
  createNumberSet(cardSize, numberMax);
}


void Card::createNumberSet(int cardSize, int numberMax)
{
    int amountOfNumbers = cardSize*cardSize;
    m_numberSet.push_back(rand() % numberMax + 1);
    int count = 0;
    while(count < amountOfNumbers)
    {
        int n = rand() % numberMax + 1;
        if (std::find(m_numberSet.begin(), m_numberSet.end(), n) == m_numberSet.end())
        {
            m_numberSet.push_back(n);
            count++;
        }
    }
}


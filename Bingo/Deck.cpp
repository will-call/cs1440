//
// Created by Stephen Clyde on 2/16/17.
//

#include <iostream>
#include "Deck.h"
#include "iomanip"

Deck::Deck(int cardSize, int cardCount, int numberMax) : m_cardSize(cardSize), m_cardCount(cardCount), m_numberMax(numberMax)
{
    // TODO: Implement
    int numberRangeMin = 2*cardSize*cardSize;
    int numberRangeMax = 2*numberRangeMin;
    if(cardSize >= 3 && cardSize <= 15 && cardCount >= 3 && cardCount <= 10000 && numberMax <= numberRangeMax && numberMax >= numberRangeMin)
    {
        for(int i = 1; i < cardCount + 1; i++){
            m_cards.push_back(new Card(cardSize, numberMax, i));
        }
    }
}

Deck::~Deck()
{
    // TODO: Implement
    if(m_cards.size() != 0)
    {
        for(int i = 0; i < getCardCount(); i++)
        {
            delete m_cards[i];
        }
    }

}

void Deck::print(std::ostream& out) const
{
    // TODO: Implement
    for(int i = 1; i < getCardCount() + 1; i++)
    {
        print(out, i);
    }
}

void Deck::print(std::ostream& out, int cardIndex) const
{
    // TODO: Implement
    out << "Card #" << m_cards[cardIndex-1]->getCardNumber() << std::endl;
    int count = 0;
    for(int i = 0; i < getCardSize(); i++)
    {
        dividingLine(out);
        for(int j = 0; j < getCardSize(); j++)
        {
            out << "| " << std::setw(3) << std::left << m_cards[cardIndex-1]->getNumberSet()[count];
            count++;
        }
        out << "|\n";
    }
    dividingLine(out);
    out << std::endl;
}

void Deck::dividingLine(std::ostream& out) const
{
    for(int i = 0; i < getCardSize(); i++)
        out << "+----";
    out << "+\n";
}




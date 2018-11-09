//
// Created by Andrew Call on 3/2/2017.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H

#include <vector>

class Card {
private:
    std::vector<int> m_numberSet;
    int m_cardNumber;
public:
    Card(int cardSize, int numberMax, int cardNumber);
    void createNumberSet(int cardSize, int numberMax);
    int getCardNumber() const {return m_cardNumber;}
    std::vector<int> getNumberSet() const {return m_numberSet;}
};


#endif //BINGO_CARD_H

//
// Created by Andrew Call on 3/3/2017.
//

#include "DeckTester.h"
#include <iostream>
#include "../Deck.h"

void DeckTester::testConstructorAndGetter()
{
    std::cout << std::endl  << "Test Suite: DeckTester::testConstructorAndGetter" << std::endl;

    {
        std::cout << "Test Case 1: Constructor that should work\n";
        Deck deck1(3,3,18);
        if(deck1.getCardSize() != 3)
        {
            std::cout << "Failure in constructor: unexpected value for getCardSize: " << deck1.getCardSize();
            return;
        }
        if(deck1.getCardCount() != 3)
        {
            std::cout << "Failure in constructor: unexpected value for getCardCount: " << deck1.getCardCount();
            return;
        }

        if(deck1.getNumberMax() != 18)
        {
            std::cout << "Failure in constructor: unexpected value for getNumberMax: " << deck1.getNumberMax();
            return;
        }
    }

    {
        std::cout << "Test Case 2: Constructor that shouldn't work\n";
        Deck deck1(1,1,9);
        if(deck1.getCards().size() != 0)
        {
            std::cout << "Failure in constructor: no cards should be generated";
        }
    }


}

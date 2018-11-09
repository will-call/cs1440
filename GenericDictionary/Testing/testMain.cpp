//
// Created by Andrew Call on 4/5/2017.
//

#include "DictionaryTester.h"
#include "KeyValueTester.h"

int main()
{
    KeyValueTester keyValueTester;
    keyValueTester.testKeyValues();

    DictionaryTester dictionaryTester;
    dictionaryTester.testDictionary();

    return 0;
}

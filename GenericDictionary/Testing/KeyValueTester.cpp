//
// Created by Andrew Call on 4/5/2017.
//

#include <iostream>
#include "../KeyValue.h"
#include "KeyValueTester.h"

void KeyValueTester::testKeyValues()
{
    std::cout << "Testing KeyValue...\n";
    KeyValue<int,int> kv(-1, -1);
    KeyValue<int,int> kv1 = kv;

    if(kv1.getKey() != kv.getKey() || kv1.getValue() != kv.getValue())
    {
        std::cout << "Error, copy constructor failed!\n";
    }


}
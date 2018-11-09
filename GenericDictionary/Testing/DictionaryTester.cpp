//
// Created by Andrew Call on 4/5/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "../Dictionary.h"

void DictionaryTester::testDictionary()
{
    std::cout << "Testing Dictionary...\n";
    Dictionary<int, std::string> dictionary;
    dictionary.add(1,"one");
    dictionary.add(2,"two");
    dictionary.add(3,"three");
    //try for duplicate key
    try
    {
        dictionary.add(1, "ONE");
    }
    catch (...) {}

    //try to get out of bounds
    try
    {
        dictionary.getByIndex(5);
    }
    catch (...){}

    //try to get by bad key
    try
    {
        dictionary.getByKey(7);
    }
    catch (...){}

    //try to remove by bad key
    try
    {
        dictionary.removeByKey(7);
    }
    catch (...){}

    //try to remove out of bounds
    try
    {
        dictionary.removeByIndex(5);
    }
    catch (...){}

    Dictionary<int,std::string> dictionary1 = dictionary;

    //try copy constructor
    if(dictionary1.getByKey(1).getKey() != dictionary.getByKey(1).getKey())
    {
        std::cout << "Error, copy constructor failed\n";
    }

    KeyValue<int, std::string> kv = dictionary.getByKey(1);
    kv = KeyValue<int,std::string>(10, "ten");
    KeyValue<int, std::string> kv1 = dictionary.getByKey(1);

    if(kv1.getKey() == 10)
    {
        std::cout << "Error, key/value pair shouldn't have been changed!\n";
    }





}

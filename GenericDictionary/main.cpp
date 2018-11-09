#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary<int, std::string> dictionary;
    dictionary.add(1,"one");
    dictionary.add(2,"two");
    dictionary.add(3,"three");

    const KeyValue<int,std::string>& key1 = dictionary.getByIndex(0);
    std::cout << "Key 1: " << key1.getKey() << std::endl;

    const KeyValue<int,std::string>& key2 = dictionary.getByKey(2);
    std::cout << "Key 2: " << key2.getKey() << std::endl;

    int count = dictionary.getCount();
    std::cout << "Number of entries: " << count << std::endl;

    dictionary.removeByIndex(2);

    count = dictionary.getCount();
    std::cout << "Number of entries: " << count << std::endl;

    dictionary.add(4,"four");
    dictionary.removeByKey(2);
    count = dictionary.getCount();
    std::cout << "Number of entries: " << count << std::endl;




    return 0;
}
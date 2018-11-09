//
// Created by Andrew Call on 4/5/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <vector>
#include <stdexcept>
#include "KeyValue.h"

template <typename K, typename V>
class Dictionary : public KeyValue<K,V>
{
private:
    std::vector<KeyValue<K,V>*> m_dictionary;

public:
    Dictionary()
    {
        m_dictionary.reserve(10);
    }

    Dictionary(unsigned int i)
    {
        m_dictionary.reserve(i);
    }

    Dictionary(const Dictionary &obj)
    {
        m_dictionary = obj.m_dictionary;
    }

    bool contains(K key)
    {
        for(int i = 0; i < m_dictionary.size(); i++)
        {
            if(m_dictionary[i]->getKey() == key)
            {
                return true;
            }
        }
        return false;
    }


    void add(K key, V value)
    {
        if(this->contains(key))
        {
            throw std::domain_error("Bad key");
        }

        m_dictionary.push_back(new KeyValue<K,V>(key, value));
    }

    unsigned int getCount(){ return m_dictionary.size(); }

    const KeyValue<K,V> & getByKey(K key)
    {
        for(int i = 0; i < m_dictionary.size(); i++)
        {
            if (m_dictionary[i]->getKey() == key)
            {
                return *m_dictionary[i];
            }
        }

        throw std::domain_error("Bad key");

    }

    const KeyValue<K,V> & getByIndex(unsigned int index)
    {
        if(index > m_dictionary.size())
        {
            throw std::domain_error("Index specified is out of expected range");
        }
        else
        {
            return *m_dictionary[index];
        }
    }

    void removeByKey(K key)
    {
        for(int i = 0; i < m_dictionary.size(); i++)
        {
            if (m_dictionary[i]->getKey() == key)
            {
                m_dictionary.erase(m_dictionary.begin() + i);
                return;
            }
        }
                throw std::domain_error("Bad key");
    }

    void removeByIndex(unsigned int index)
    {
        if(index > m_dictionary.size())
        {
            throw std::domain_error("Index specified is out of expected range");
        }
        else
        {
            m_dictionary.erase(m_dictionary.begin() + index);
        }
    }




};
#endif //GENERICDICTIONARY_DICTIONARY_H

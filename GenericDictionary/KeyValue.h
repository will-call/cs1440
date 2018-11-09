//
// Created by Andrew Call on 4/5/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H

template <typename K, typename V>
class KeyValue
{
private:
    K m_key;
    V m_value;

public:
    KeyValue(){}
    KeyValue(K key, V value)
    {
        m_key = key;
        m_value = value;
    }
    KeyValue(const KeyValue &obj)
    {
        m_key = obj.m_key;
        m_value = obj.m_value;
    }

    const K& getKey() const { return m_key; }
    const V& getValue() const { return m_value; }
};

#endif //GENERICDICTIONARY_KEYVALUE_H

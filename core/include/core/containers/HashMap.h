#pragma once

#include <cstddef>
#include <cassert>

namespace cpptests::core::containers {

static const unsigned int HASH_TABLE_SIZE = 128;

template <typename K>
struct HashFunc
{
    unsigned int operator()(const K& key)
    {
        return reinterpret_cast<unsigned int>(key) % HASH_TABLE_SIZE;
    }
};

template <typename K, typename V>
class HashNode
{
private:
    K m_key;
    V m_value;
    HashNode<K, V>* m_next;

public:
    HashNode(const K& key, const V& value)
    : m_key(key)
    , m_value(value)
    , m_next(nullptr)
    {}

    const K& getKey() const
    {
        return m_key;
    }

    void setKey(const K& key)
    {
        m_key = key;
    }

    const V& getValue() const
    {
        return m_value;
    }

    void setValue(const V& value)
    {
        m_value = value;
    }

    const HashNode<K, V>* getNext() const
    {
        return m_next;
    }

    void setNext(const HashNode<K, V>* const next)
    {
        assert(m_next == nullptr && "next should be null");
        m_next = next;
    }
};

template <typename K, typename V>
class HashMap
{
private:
    HashNode<K, V>** m_hashTable;

public:
    HashMap()
    {
        m_hashTable = new HashNode<K, V>* [HASH_TABLE_SIZE] {nullptr};
    }

    void put(const K& key, const V& value)
    {
    }
};
}
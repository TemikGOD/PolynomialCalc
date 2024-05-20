#pragma once
#include "../Polynomial/polynomial.h"

template <typename Key, typename Value>
class TableInterface
{
public:
    virtual void add(const Key& _key, Value* const _polynomial) = 0;
    virtual void erase(const Key& _key) = 0;
    virtual Value search(const Key& _key) = 0;
    virtual ~TableInterface() { };
    virtual Value getValue(int index) = 0;
    virtual Key getKey(int index) = 0;
    virtual size_t size() = 0;
};


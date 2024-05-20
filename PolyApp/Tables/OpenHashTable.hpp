#pragma once
#include "../Containers/Vector.h"
#include "MyExcepions.hpp"
#include "TableInterface.hpp"
#include <string>
#include <utility>

template<typename Key, typename Value>
class OpenHashTable : public TableInterface<Key, Value>
{
private:
  size_t sizeT;
  struct tableRow
  {
    Key key_;
    Value* value_;
    char flag;
    tableRow() : value_(nullptr), flag(0) { };
    tableRow(Key _key, Value* _value, unsigned _flag) : key_(_key), value_(_value), flag(_flag) { };
  };
  ad::Vector<tableRow> table;
  const double loadFactor = 0.75;
  int count = 0;

  size_t hashFunction(const Key& _key, uint32_t seed = 2166136261u);
  void resize();
public:
  OpenHashTable() : sizeT(100), table(sizeT) {}
  OpenHashTable(const size_t _size) : sizeT(_size), table(_size) {}
  ~OpenHashTable();

  Value getValue(int index) override { return *table[index].value_; };
  Key getKey(int index) override { return table[index].key_; }


  size_t size() override;
  void add(const Key& key, Value* const value) override;
  void erase(const Key& key) override;
  Value search(const Key& key) override;
};

template<typename Key, typename Value>
size_t OpenHashTable<Key, Value>::hashFunction(const Key& _key, uint32_t seed)
{
  string strKey;
  if constexpr (std::is_same<Key, std::string>::value) {
    strKey = _key;
  }
  else {
    std::stringstream address;
    address << std::hex << &_key;
    strKey = address.str();
  }
  uint32_t prime = 16777619u;
  size_t hash = seed;
  for (char c : strKey) {
    hash ^= c;
    hash *= prime;
  }
  return hash % sizeT;
}

template<typename Key, typename Value>
void OpenHashTable<Key, Value>::resize()
{
  sizeT *= 2;
  ad::Vector<tableRow> newTable(sizeT);
  for (auto& item : table) {
    if (item.flag == 1)
    {
      int index = hashFunction(item.key_);
      newTable[index] = item;
    }
  }
  table = newTable;
}

template<typename Key, typename Value>
OpenHashTable<Key, Value>::~OpenHashTable()
{
  for (auto& item : table)
    if (item.flag == 1)
      delete item.value_;
}

template<typename Key, typename Value>
size_t OpenHashTable<Key, Value>::size() {
  size_t count = 0;
  for (auto& o : table)
    if (o.flag == 1)
      count++;
  return count;
}

template <typename Key, typename Value>
void OpenHashTable<Key, Value>::add(const Key& key, Value* const value)
{
  size_t index = hashFunction(key);
  if (table[index].flag != 1)
    table[index] = tableRow(key, value, 1);
  else
  {
    while (table[index].flag == 1)
    {
      if (table[index].key_ == key)
        throw AddException("A value with this key is already in the table");
      else
        if (index != sizeT - 1)
          index++;
        else
          index = 0;
    }
    table[index] = tableRow(key, value, 1);
  }
  count++;
  if (count > sizeT * loadFactor)
    resize();
}

template <typename Key, typename Value>
void OpenHashTable<Key, Value>::erase(const Key& key)
{
  if (count == 0) {
    throw EmptyTableException("Cannot delete value from an empty table.");
  }
  size_t index = hashFunction(key);
  size_t firstIndex = index;
  while (table[index].flag == 1)
  {
    if (table[index].key_ == key)
    {
      delete table[index].value_;
      table[index].flag = 2;
      break;
    }
    else
      if (index != sizeT - 1)
        index++;
      else
        index = 0;
    if (index == firstIndex)
      throw NothingFoundException("There is no such key in the table");
  }
  if (table[index].flag != 2)
    throw NothingFoundException("There is no such key in the table");
}

template <typename Key, typename Value>
Value OpenHashTable<Key, Value>::search(const Key& key)
{
  if (count == 0) {
    throw EmptyTableException("Table is empty");
  }
  size_t index = hashFunction(key);
  if (table[index].flag == 0)
    throw NothingFoundException("There is no such key in the table");
  else
  {
    size_t firstIndex = index;
    while (table[index].flag != 0)
    {
      if (table[index].key_ == key)
        return *table[index].value_;
      else
        if (table[index].flag == 2)
        {
          index++;
          continue;
        }
        else
          if (index != sizeT - 1)
            index++;
          else
            index = 0;
      if (index == firstIndex)
        throw NothingFoundException("There is no such key in the table");
    }
  }
}


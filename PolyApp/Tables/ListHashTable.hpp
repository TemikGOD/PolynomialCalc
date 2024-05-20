#pragma once
#include "../Containers/List.h"
#include "../Containers/Vector.h"
#include "MyExcepions.hpp"
#include "TableInterface.hpp"
#include <utility>
#include <sstream>

template<typename Key, typename Value>
class ListHashTable : public TableInterface<Key, Value>
{
public:
  ListHashTable() : sizeT(100), table(sizeT), count(0) {}
  ListHashTable(int _size) : sizeT(_size), table(sizeT), count(0) {}
  ~ListHashTable();

  Value getValue(int index) override { return *table[index].front().second; };
  Key getKey(int index) override { return table[index].front().first; };
  size_t size() override;
  void add(const Key& _key, Value* const _value) override;
  void erase(const Key& _key) override;
  Polynomial search(const Key& _key) override;

private:
  const double loadFactor = 0.75;
  int sizeT;
  int count;
  ad::Vector<ad::List<pair<Key, Value*>>> table;
  size_t hashFunction(const Key& _key, uint32_t seed = 2166136261u);
  void resize();
};

template<typename Key, typename Value>
ListHashTable<Key, Value>::~ListHashTable()
{
  for (auto& del : table)
    for (auto& item : del)
      delete item.second;
}

template<typename Key, typename Value>
size_t ListHashTable<Key, Value>::size() {
  size_t count = 0;
  for (auto o : table)
    if (o.front().first != "")
      count++;
  return count;
}

template<typename Key, typename Value>
void ListHashTable<Key, Value>::add(const Key& _key, Value* const _value) {
  int index = hashFunction(_key);
  for (auto it = table[index].begin(); it != table[index].end(); ++it) 
    if ((*it).first == _key) 
      throw AddException("This key is already in table");
  table[index].push_back(std::make_pair(_key, _value));
  count++;
  if (count > sizeT * loadFactor) {
    resize();
  }
}

template<typename Key, typename Value>
void ListHashTable<Key, Value>::erase(const Key& _key) {
  if (count == 0) {
    throw EmptyTableException("Cannot delete value from an empty table.");
  }
  int index = hashFunction(_key);
  for (auto it = table[index].begin(); it != table[index].end(); ++it) {
    if ((*it).first == _key) {
      table[index].erase(it);
      count--;
      return;
    }
  }
  throw NothingFoundException("There is no such key in the table");
}

template<typename Key, typename Value>
Polynomial ListHashTable<Key, Value>::search(const Key& _key) {
  if (count == 0) {
    throw EmptyTableException("Table is empty");
  }
  int index = hashFunction(_key);
  for (auto it = table[index].begin(); it != table[index].end(); ++it) {
    if ((*it).first == _key) {
      if ((*it).second == nullptr) {
        throw NothingFoundException("There is no such key in the table");
      }
      return *(*it).second;
    }
  }
  throw NothingFoundException("Cannot return polynomial with Key not found.");
}

template<typename Key, typename Value>
size_t ListHashTable<Key, Value>::hashFunction(const Key& _key, uint32_t seed) {
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
void ListHashTable<Key, Value>::resize() {
  sizeT *= 2;
  ad::Vector<ad::List<pair<Key, Value*>>> newTable(sizeT);
  for (auto& bucket : table) {
    for (auto& item : bucket) {
      int index = hashFunction(item.first);
      newTable[index].push_back(item);
    }
  }
  table = newTable;
}

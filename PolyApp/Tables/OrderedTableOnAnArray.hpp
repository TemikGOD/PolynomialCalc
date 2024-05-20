#pragma once
#include "../Containers/Vector.h"
#include "../Polynomial/Polynomial.h"
#include "MyExcepions.hpp"
#include "TableInterface.hpp"
#include <utility>

template <typename Key, typename Value>
class OrderedTable : public TableInterface<Key, Value> {
private:
  ad::Vector<pair<Key, Value*>> table;

public:
  OrderedTable() {}

  ~OrderedTable()
  {
    for (const auto& del : table)
      delete del.second;
  }

  Value getValue(int index) override { return *table[index].second; }
  Key getKey(int index) override { return table[index].first; }

  size_t size() override { return table.size(); }

  void add(const Key& _key, Value* const _value) override;

  void erase(const Key& _key) override;

  Value search(const Key& _key) override;
};

template<typename Key, typename Value>
void OrderedTable<Key, Value>::add(const Key& _key, Value* const _value) {
  if (table.size() == 0)
  {
    table.push_back(std::make_pair(_key, _value));
    return;
  }
  int left = 0, right = table.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (table[mid].first == _key) {
      throw AddException("A polynomial with this name is already in the table");
    }
    else if (table[mid].first < _key) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  table.insert(table.begin() + left, std::make_pair(_key, _value));
}

template<typename Key, typename Value>
void OrderedTable<Key, Value>::erase(const Key& _key) {
  int temp = -1;
  ad::Vector<pair<Key, Value*>> tempArray;
  if (table.size() == 0)
    throw EmptyTableException("Empty table");

  int left = 0, right = table.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (table[mid].first == _key) {
      temp = mid;
      break;
    }
    else if (table[mid].first < _key) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  if (temp == -1)
    throw NothingFoundException("No polynomial found with this key");
  for (int i = 0; i < temp; i++) {
    tempArray.push_back(table[i]);
  }
  for (int i = temp + 1; i < table.size(); i++) {
    tempArray.push_back(table[i]);
  }
  table = tempArray;
}

template<typename Key, typename Value>
Value OrderedTable<Key, Value>::search(const Key& _key) {
  int temp = -1;
  int left = 0, right = table.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (table[mid].first == _key) {
      return *table[mid].second;
    }
    else if (table[mid].first < _key) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  if (temp == -1)
    throw NothingFoundException("There is no such key in the table");
}

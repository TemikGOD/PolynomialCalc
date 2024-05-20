#pragma once

#include "../Containers/List.h"
#include "../Polynomial/Polynomial.h"
#include "MyExcepions.hpp"
#include "TableInterface.hpp"
#include <utility>

template<typename Key, typename Value>
class LinearListTable : public TableInterface<Key, Value>
{
private:
  ad::List<pair<Key, Value*>> table;
  bool isInTable(const Key& key);
public:
  LinearListTable() {}
  ~LinearListTable();

  size_t size() override { return table.getSize(); }
  Value getValue(int index) override;
  Key getKey(int index) override;
  void add(const Key& key, Value* _value) override;
  void erase(const Key& key) override;
  Value search(const Key& key) override;
};

template<typename Key, typename Value>
inline bool LinearListTable<Key, Value>::isInTable(const Key& key)
{
if (table.empty())
  return false;
for (const auto& item : table)
  if (item.first == key)
    return true;
return false;
}

template<typename Key, typename Value>
inline LinearListTable<Key, Value>::~LinearListTable()
{
  for (const auto& del : table)
    delete del.second;
}

template<typename Key, typename Value>
inline Value LinearListTable<Key, Value>::getValue(int index)
{
  auto iter = table.begin();
  size_t count = 0;
  while (count != index)
  {
    ++iter;
    ++count;
  }
  return *(*iter).second;
}

template<typename Key, typename Value>
inline Key LinearListTable<Key, Value>::getKey(int index)
{
  auto iter = table.begin();
  size_t count = 0;
  while (count != index)
  {
    ++iter;
    ++count;
  }
  return (*iter).first;
}

template<typename Key, typename Value>
inline void LinearListTable<Key, Value>::add(const Key& key, Value* _value)
{
  if (isInTable(key))
    throw AddException("Polynomial already exists in table");
  table.push_back(std::make_pair(key, _value));
}

template<typename Key, typename Value>
inline void LinearListTable<Key, Value>::erase(const Key& key)
{
  if (table.empty())
    throw EmptyTableException("Table is Empty");

  for (auto it = table.begin(); it != table.end(); ++it)
    if ((*it).first == key)
    {
      table.pop_front();
      return;
    }
  throw NothingFoundException("Polynomial not found in table");
}

template<typename Key, typename Value>
inline Value LinearListTable<Key, Value>::search(const Key& key)
{
  for (const auto& item : table)
    if (item.first == key)
      return *(item.second);
  throw NothingFoundException("Polynomial not found in table");
}

#pragma once
#include "../Containers/Vector.h"
#include "MyExcepions.hpp"
#include "TableInterface.hpp"
#include <utility>

template <typename Key, typename Value>
class LinearTableOnAnArray :public TableInterface<Key, Value>
{
private:
	ad::Vector<std::pair<Key, Value*>> table;

public:
	size_t size() override { return table.size(); }
	Value operator[](size_t poz) { return *table[poz].second; }

	~LinearTableOnAnArray();

	Value getValue(int index) override { return *table[index].second; }
	Key getKey(int index) override { return table[index].first; }

	Value search(const Key& _key) override;

	void add(const Key& _key, Value* const _pol) override;

	void erase(const Key& _key) override;

};

template<typename Key, typename Value>
LinearTableOnAnArray<Key, Value>::~LinearTableOnAnArray()
{
	for (auto& item : table)
		delete item.second;
}

template<typename Key, typename Value>
Value LinearTableOnAnArray<Key, Value>::search(const Key& _key)
{
	for (auto i = 0; i < table.size(); i++)
		if (table[i].first == _key)
			return *table[i].second;
	throw NothingFoundException("Nothing found");
}

template<typename Key, typename Value>
void LinearTableOnAnArray<Key, Value>::add(const Key& _key, Value* const _pol)
{
	bool addedCheck = false;
	try
	{
		search(_key);
	}
	catch (NothingFoundException& exp)
	{
		table.push_back(std::make_pair(_key, _pol));
		addedCheck = true;
	}
	if (!addedCheck)
	{
		throw AddException("A polynomial with this name is already in the table");
	}
}

template<typename Key, typename Value>
void LinearTableOnAnArray<Key, Value>::erase(const Key& _key)
{
	if (this->size() == 0)
		throw EmptyTableException("There is nothing in the table");
	int poz = -1;
	try
	{
		for (int i = 0; i < table.size(); i++)
			if (table[i].first == _key)
			{
				poz = i;
				break;
			}
		if (poz == -1)
			throw NothingFoundException("Nothing found");
	}
	catch (const NothingFoundException&)
	{
		throw NothingFoundException("There is no polynomial with this name in the table");
	}
	table[poz] = table[size() - 1];
	table.pop_back();
}

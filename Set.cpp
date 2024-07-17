#include "Set.h"

namespace mySet
{
	template<class T>
	Set<T>::Set() : items(nullptr), numItems(0)
	{
	}

	template<class T>
	Set<T>::~Set()
	{
		if (items != nullptr)
		{
			delete[] items;
		}
	}

	template<class T>
	Set<T>::Set(const Set<T>& other)
	{
		numItems = other.numItems;
		items = other.toArray();
	}

	template<class T>
	void Set<T>::operator=(const Set<T>& rightSide)
	{
		if (items != nullptr)
		{
			delete[] items;
		}
		numItems = rightSide.numItems;
		items = rightSide.toArray;
	}

	template<class T>
	void Set<T>::add(T item)
	{
		if (!contains(item))
		{
			T* newItems = new T[numItems + 1];
			for (int x = 0; x < numItems; x++)
			{
				newItems[x] = items[x];
			}
			newItems[numItems] = item;
			if (numItems > 0)
			{
				delete[] items;
			}
			numItems++;
			items = newItems;
		}
	}

	template<class T>
	void Set<T>::remove(T item)
	{
		if (contains(item))
		{
			T* copy = nullptr;
			if (numItems > 1)
			{
				copy = new T[numItems - 1];
				for (int y = 0, j=0; y < numItems; y++)
				{
					if (items[y] != item)
					{
						copy[j] = items[y];
						j++;
					}
				}
			}
			delete[] items;
			items = copy;
			numItems--;
		}
	}
	template<class T>
	int Set<T>::size() const
	{
		return numItems;
	}

	template<class T>
	bool Set<T>::contains(T item) const
	{
		for (int x = 0; x < numItems; x++)
		{
			if (items[x] == item)
			{
				return true;
			}
		}
		return false;
	}

	template<class T>
	T* Set<T>::toArray() const
	{
		T* copy = nullptr;
		if (numItems > 0)
		{
			copy = new T[numItems];
			for (int x = 0; x < numItems; x++)
			{
				copy[x] = items[x];
			}
		}
		return copy;
	}
}
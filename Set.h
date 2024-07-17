#ifndef SET_H
#define SET_H

namespace mySet
{
	template<class T>
	class Set
	{
	public:
		Set();
		~Set();
		Set(const Set<T>& other);
		void operator=(const Set<T>& rightSide);
		void add(T item);
		void remove(T item);
		int size() const;
		bool contains(T item) const;
		T* toArray() const;

	private:
		T* items;
		int numItems;
	};

}



#endif 
#include <iostream>
#include <string>
#include <cstdlib>
#include "Set.cpp"
using namespace std;
using namespace mySet;


template<class T>
void outputSet(Set<T> mySet)
{
	T* ptr = mySet.toArray();
	if (ptr != nullptr)
	{
		for (int x = 0; x < mySet.size(); x++)
		{
			cout << ptr[x] << endl;
		}
		delete[] ptr;
	}
	else
	{
		cout << "The set is empty." << endl;
	}

}

int main()
{
	Set<int> intSet;
	intSet.add(3);
	intSet.add(4);
	intSet.add(5);
	intSet.add(10);
	intSet.add(3);
	cout << "Contents of intSet: " << endl;
	outputSet(intSet);

	cout << "Contains 3: " << intSet.contains(3) << endl;
	cout << "Contains 550: " << intSet.contains(550) << endl;

	cout << "Removing 3, 4, and 400" << endl;
	intSet.remove(3);
	intSet.remove(4);
	intSet.remove(400);
	outputSet(intSet);

	Set<int> newIntSet = intSet;
	newIntSet.add(200);
	cout << "New int set with 200 added" << endl;
	outputSet(newIntSet);
	cout << "Orignial set: " << endl;
	outputSet(intSet);

	Set<string> stringSet;
	stringSet.add("bill");
	stringSet.add("Steve");
	stringSet.add("dog");
	stringSet.add("Nancy");
	cout << "String set: " << endl;
	outputSet(stringSet);

	stringSet.remove("bill");
	stringSet.remove("Steve");
	stringSet.remove("dog");
	stringSet.remove("Nancy");
	cout << "String set after removal:" << endl;
	outputSet(stringSet);

	return 0;
}
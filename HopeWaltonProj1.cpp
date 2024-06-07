//Author: Hope Walton
//Version: 06/07/2024
 


#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main()
{
    //Code to test reverse function
    char message[] = "Hello";
    char* front = message; // pointer to the first character
    char* rear = message + strlen(message) - 1; // pointer to the last character

    reverse(front, rear); // call the reverse function
    cout << message << endl; // output the reversed string
    cout << endl;
 

    // Code to test add entry and delete entry function
    int size = 5;
    string* names = new string[size];
    names[0] = "Hope";
    names[1] = "Luke";
    names[2] = "Caitlin";
    names[3] = "Arthur";
    names[4] = "Betty";

    cout << "The initial list is:" << endl;
    print(names, size);

    //Testing the addition of names to the array
    names = addEntry(names, size, "Leroy");
    names = addEntry(names, size, "Snips");
    cout << "After adding names:" << endl;
    print(names, size);

    //Testing the deletion of names from the array
    names = deleteEntry(names, size, "Leroy");
    names = deleteEntry(names, size, "Bob"); //Non-existent name
    print(names, size);

    delete[] names;
    return 0;
    
}

void reverse(char* front, char* rear) 
{
   while (front < rear) {
     // Swap the characters
     char temp = *front;
     *front = *rear;
     *rear = temp;

     // Move the pointers
     front++;
     rear--;
    }
}

string* addEntry(string* dynamicArray, int& size, string newEntry)
{
    string* newArray = new string[size + 1];
    for (int x = 0; x < size; x++) {
        newArray[x] = dynamicArray[x];
    }
    newArray[size] = newEntry;
    size++;
    delete[] dynamicArray;
    return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    string* result = dynamicArray;
    int toDelete = -1;
    for (int x = 0; x < size; x++) {
        if (dynamicArray[x] == entryToDelete) {
            toDelete = x;
            break;
        }
    }
    if (toDelete == -1) {
        return result;
    }
    else {
        result = new string[size - 1];
        int indexNewArray = 0;
        for (int y = 0; y < size; y++) {
            if (y != toDelete) {
                result[indexNewArray] = dynamicArray[y];
                indexNewArray++;
            }
            else {
                //Do nothing
            }
        }
        size--;
        delete[] dynamicArray;
    }
    return result;
}

void print(const string* dynamicArray, int size)
{
    for (int x = 0; x < size; x++) {
        cout << x << ": " << dynamicArray[x] << endl;
    }
    cout << endl;
}
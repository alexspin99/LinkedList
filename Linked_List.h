#include <iostream>
using namespace std;

// Define a structure to use as the list item
struct ListItem
{
     int      key;          
     float    theData;
      ListItem *next;
};

class Linked_List
{
     private:
          ListItem *head;               // Pointer to head of the list

     public:
          Linked_List();               // Class constructor
          ~Linked_List();              // Class destructor
          void ClearList();             // Remove all items from the list
          bool Insert(int key, float f);// Add an item to the end of the list
          bool Delete(int key);         // Delete an item from the list
          bool Search(int key, float *retVal); // Search for an item in the list
          int ListLength();             // Return number of items in list
          bool isEmpty();               // Return true if list is empty
          bool isFull();                // Return true if list is full
          void PrintList();             // Print all items in the list
};


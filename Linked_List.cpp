#include<iostream>
#include<string>
#include "Linked_List.h"

using namespace std;

//Constructor
Linked_List::Linked_List()
{
	//Set head of list as null since list is empty
	head = NULL;
}

//Destructor
Linked_List::~Linked_List()
{
	ClearList();
}


void Linked_List::ClearList()
{
	//create temp pointer to iteratively delete items in list
	ListItem* tempPtr = head;
	
	while(head != NULL)
	{
		head = head->next;
		delete tempPtr;
	}
}

bool Linked_List::Insert(int key, float f)
{
	//only adds if there is memory left 
	if (!isFull())
	{
		//allocate space and store ListItem 
		ListItem* location;
		location = new ListItem;
		location->key = key;
		location->theData = f;
		//Point to previous item
		location->next = head;
		
		//store new address for head of list
		head = location;
	}
	else
		cout << "No memory left to allocate new item.";
	
	
	
}

bool Linked_List::Delete(int key)
{
	//location points to item to be deleted, ontopLocation points one on top
	ListItem* deleteLocation = head;
	ListItem* onTopLocation = head;
	
	//If top item is deleted 
	if(deleteLocation->key == key)
	{
		head = head->next;
		delete deleteLocation;
		return true;
	}
	else
	{
		
		int iter = 0;
		
		//find correct location to delete, have templocation point one before it
		while(deleteLocation->key != key)
		{
			deleteLocation = deleteLocation->next;
			//moves onTopLocation to next, delayed 1 on top of deleteLocation
			if (iter > 0)
				onTopLocation = onTopLocation->next;
			iter++;
			//returns false if it can't find item
			if (deleteLocation == NULL)
				return false;
		}
			
	
		//If middle item is deleted
		if (deleteLocation->next != NULL)
		{				
			//makes location on top point to location after delete location
			onTopLocation->next = (onTopLocation->next)->next;
			//deletes location
			delete deleteLocation;
			return true;
		}
		//If bottom item is deleted
		else
		{
			//delete bottom item
			delete deleteLocation;
			//make new bottom item point to NULL
			onTopLocation->next = NULL;
			return true;
		}
	}
}

bool Linked_List::Search(int key, float *retVal)
{
	ListItem* tempPtr = head;
	if(!isEmpty())
	{
		while(tempPtr != NULL)
		{
			//returns true if key matches the current item
			if (tempPtr->key == key)
			{
				*retVal = tempPtr->theData;
				return true;
			}
			//go to next item in list
			tempPtr = tempPtr->next;
		}
		//returns false if no items match
		return false;
	}
}

int Linked_List::ListLength()
{
	int length = 0;
	ListItem* tempPtr = head;
	while(tempPtr != NULL)
	{
		//iterate length
		length++;
			
		//go to next item in list
		tempPtr = tempPtr->next;
	}
	
	return length;
}

bool Linked_List::isEmpty()
{
	//List is empty only if head pointer is NULL
	if (head == NULL)
		return true;
	else
		return false;
}

bool Linked_List::isFull()
{
	ListItem* location;
	try 
	{
		//Allocates space for new location
		location = new ListItem;
		//deletes location if no exception is thrown and returns false
		delete location;
		return false;
	}
	catch(bad_alloc exception)
	{
		//list is full if no room is left in memory
		return true;
	}
}

void Linked_List::PrintList()
{
	ListItem *temp;

     cout << "\n\nItems in the List\n";
     cout << "-----------------------------------------------------------\n";
     cout << "Key\t\tData\n";
     cout << "-----------------------------------------------------------\n";

     if(head == NULL)     // Report no items in the list
     {
          cout << "\t List is currently empty.\n";
     }
     else
     {
          temp = head;
          while(temp != NULL)
          {
               cout << temp->key << "\t\t" << temp->theData << "\n";
               temp=temp->next;
          }
     }
     cout << "-----------------------------------------------------------\n\n";
	
}


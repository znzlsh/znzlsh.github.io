//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------


#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

: maxSize(maxNumber),
size(0),
cursor(-1)
{
	dataItems = new DataType[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		dataItems[i] = NULL;
	}
}

//--------------------------------------------------------------------

List:: ~List()

// Frees the memory used by a list.

{
	delete [] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType &newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	if (isFull()) {
		cout << "List is Full!!" << endl;
	}
	else if (cursor == size-1)
	{
		dataItems[++cursor] = newDataItem;
		size++;
	}
	else
	{
		for (int i = size; cursor < i; i--) {
			dataItems[i] = dataItems[i - 1];
		}
		dataItems[++cursor] = newDataItem;
		size++;
	}


}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.

{
	if (isEmpty())
	{
		cout << "list is Empty!!" << endl;
	}
	else if (size == 1) {
		dataItems[cursor--] = NULL;
		size--;
	}
	else if (cursor == size - 1) {
		dataItems[cursor] = NULL;
		cursor = 0;
		size--;
	}
	else
	{
		for (int i = cursor; i < size-1; i++) {
			dataItems[i] = dataItems[i + 1];
		}
		dataItems[size-1] = NULL;
		size--;
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType &newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
	if (isEmpty()) {
		cout << "List is Empty!!";
	}
	else
	{
		dataItems[cursor] = newDataItem;
	}


}

//--------------------------------------------------------------------

void List::clear()

// Removes all the data items from a list.

{
	for (int i = 0; i < maxSize; i++)
	{
		dataItems[i] = NULL;
	}
	cursor = -1;
	size = 0;

}

//--------------------------------------------------------------------

bool List::isEmpty() const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
	if (size==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------

bool List::isFull() const

// Returns 1 if a list is full. Otherwise, returns 0.

{
	if (size == maxSize) {
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------
 
int List::gotoBeginning() throw (logic_error)

// Moves the cursor to the beginning of the list.

{
	cursor = 0;
	return 0;

}



//--------------------------------------------------------------------

int List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	cursor = size - 1;
	return 0;
}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.

{
	if (cursor==size-1)
	{
		return false;
	}
	else {
		cursor++;
		return true;
	}
	

}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	if (cursor == 0) {
		return false;
	}
	else
	{
		cursor--;
		return true;
	}


}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)

// Returns the item marked by the cursor.

{
	return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << "| " << dataItems[i] << " |";
		}
		cout << endl;
		for (int i = 0; i < cursor; i++) cout << "     ";
		cout << "  ^";
	}
	
}
 
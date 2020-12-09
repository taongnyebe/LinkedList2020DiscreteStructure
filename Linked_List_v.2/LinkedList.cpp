#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

#define cout std::cout << "\n\t"

// this will be used to constantly check the numbers provided in each
// NOT YET DONE!
void LinkedList::MoveNumber(int state)
{
	switch (state)
	{
	case 0: // this is incrementing the following numbers
		curr = head;

		for (int i = 0; ; i++)
		{
			// this will stop when it finds the null
			if (curr == NULL) break;

			curr->indexNumber++;
			curr = curr->next;
		}
		break;

	case 1: // this is rearanging numbers
		curr = head;

		for (int a = 1; a <= nodeCounter; a++)
		{
			if (curr == NULL)
				break;
			curr->indexNumber = a;
			curr = curr->next;
		}
		break;
	}
}

void LinkedList::Add(nodePtr n, nodePtr next, int data, int index)
{
	n->next = next;
	n->idNumber = data;
	n->indexNumber = index;
}

void LinkedList::RevTraverse(nodePtr node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		LinkedList::RevTraverse(node->next);
		cout << node->indexNumber << ": " << node->idNumber << '\n';
	}
}

LinkedList::LinkedList()
{
	// this will empty the nodes
	head = NULL;
	tail = NULL;
	curr = NULL;
	temp = NULL;

	nodeCounter = 0;
}

// this is called only when it requires to display the total number of nodes in the list
int LinkedList::NodeCount()
{
	return nodeCounter;
}

// You can use search data in state 2 in search function
void LinkedList::AddNode(char state, int dataIDN, int index)
{
	nodePtr n = new node;

	switch (state)
	{ 
	case '1': // this state will add at the start of the list
		nodeCounter++;

		Add(n, head, dataIDN, 1);

		if (n->next != NULL)
		{
			MoveNumber(0);
		}

		head = n;
		
		if (tail == NULL)
			tail = n;

		cout << "ID: " << n->idNumber << " is Added to the head of the List.\n\n";
		break;
	case '2': // this state will add at the defined index user prefered
		temp = head;
		curr = head;

		// this will check if the index is available or not
		while (curr != NULL && curr->indexNumber != index)
		{
			temp = curr;
			curr = curr->next;
		}

		if (curr == NULL)
		{
			// this action will be implemented if there is no index available

			if (head == NULL)
			{
				cout << "List is currently empty.";
				cout << "The ID Number will be added at the start.\n";

				LinkedList::AddNode('1', dataIDN, 0);
			}
			else
			{
				cout << "Index: " << index << " is currently not available.";
				cout << "The ID Number will be added at the end.\n";

				LinkedList::AddNode('3', dataIDN, 0);
			}
		}
		else
		{
			cout << "The Index " << curr->indexNumber << " of the List Contain ID: " << curr->idNumber << "." << "\n\n";

			nodeCounter++;

			Add(n, curr, dataIDN, index);
		}
		break;
	case '3': // this state will add at the end of the list
		nodeCounter++;

		Add(n, NULL, dataIDN, nodeCounter); // Null declares it will be the end of the list

		if (head != NULL)
		{
			// this will connect the new node to the end and replace the tail into the new tail
			tail->next = n;
			tail = n;
		}
		else
		{
			// this declare that it is the first node and last
			head = n;
			tail = n;

			cout << "ID: " << n->idNumber << " is Added to the head of the List.\n\n";
		}
		break;
	}
}

// You can use search data to find the data to be deleted
void LinkedList::DeleteNode(int index)
{
	nodePtr delPtr = NULL;

	temp = head;
	curr = head;

	while (curr != NULL && curr->indexNumber != index)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL) 
	{
		cout << index << " was not in the list" << '\n';
		delete delPtr; 
	}
	else
	{
		delPtr = curr;
		curr = curr->next; 
		temp->next = curr; 

		if (delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
		if (delPtr == tail)
		{
			tail = temp;
		}

		delete delPtr; 
		cout << "The Data's in " << index << " was deleted successfully\n\n";
	}

	nodeCounter--;

	MoveNumber(1);
}

void LinkedList::PrintList(char state)
{
	switch (state)
	{
	case '1': // ascending display
		curr = head;

		while (curr != NULL)
		{
			cout << curr->indexNumber << ": " << curr->idNumber << '\n';
			curr = curr->next;
		}

		cout;
		break;
	case '2': // decending display
		curr = head;

		RevTraverse(head);

		cout;
		break;
	}
}

void LinkedList::Search(int lookingFor)
{
	temp = head;
	curr = head;

	while (curr != NULL && curr->idNumber != lookingFor && curr->indexNumber != lookingFor)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		cout << lookingFor << " was not found in the list" << '\n';
	}
	else
	{
		cout << "The value " << lookingFor << " was in the number " << curr->indexNumber << " of the list.\n";
	}

	cout;
}
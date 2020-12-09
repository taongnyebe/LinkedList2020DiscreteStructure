#pragma once

#ifndef UI_H
#define UI_H

class LinkedList
{
private:
	// blue print of the node
	typedef struct node
	{
		int idNumber,
			indexNumber;
		node* next;
	}* nodePtr;

	// node cunter
	int nodeCounter;

	// node temporary storage of valuable information
	nodePtr head,
		tail,
		curr,
		temp;

	// maybe features
	void MoveNumber(int state);
	void Add(nodePtr, nodePtr, int, int);
	void RevTraverse(nodePtr);
public:
	// constructor
	LinkedList();

	// Getter
	int NodeCount();

	// functions
	void AddNode(char state, int dataIDN, int index);
	void DeleteNode(int index);
	void PrintList(char state);
	void Search(int lookingFor);

};
#endif // ! UI_H
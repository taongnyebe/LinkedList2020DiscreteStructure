#include <iostream>
#include <Windows.h>
#include <conio.h>

// this is custom mini functions by the user
#define cout std::cout << "\n\t"
#define cin std::cin 
#define border cout << "\b" << "*--------------------------------------*"

// this is the blueprint of nodes, blueprint pattern of how to create something
struct slinklist
{
	int data;
	struct slinklist* next;
};

typedef struct slinklist node;
node* start = NULL; int

// use for UI = User Interface
menu()
{
	int ch;

	system("color A1"); // use for aesthetics
	border;
	cout << "-------------   Create   ------------- ";
	cout << "1. Create a list ";
	cout << "------------   Insert   ------------- "; 
	cout << "2. Insert a node at beginning ";
	cout << "3. Insert a node at end";
	cout << "4. Insert a node at middle";
	cout << "------------   Delete   ------------- ";
	cout << "5. Delete a node from beginning";
	cout << "6. Delete a node from Last";
	cout << "7. Delete a node from Middle";
	cout << "------------  Traverse  ------------- ";
	cout << "8. Traverse the list (Left to Right)";
	cout << "9. Traverse the list (Right to Left)";
	cout << "------------   Count    ------------- ";
	cout << "10. Count nodes "; 
	cout << "11. Exit ";
	border;
	cout << "\n ";
	cout << "\t" << "Enter your choice: ";
	cout << "\t" << "    >>   <<" << "\b\b\b\b";
	cin >> ch;

	return ch;
}

// this is responsible for creating new nodes
node* getnode()
{
	node* newnode; // create a new node 

	newnode = (node*)malloc(sizeof(node)); // create space for the specified number of nodes

	cout << "\n Enter data: ";
	cin >> newnode -> data; // connecting the nodes
		newnode->next = NULL;

	return newnode;
}

// this is responsible for counting nodes and creating the right amount of space defined by the user
int countnode(node* ptr)
{
	int count = 0;

	// this will count until it finds the null value
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return (count);
}


void createlist(int n)
{
	int i;
	
	// this two below will create two new pointer nodes to be used
	node* newnode;
	node* temp;

	// this will repeteadly do the code until it meets user defined output
	for (i = 0; i < n; i++)
	{
		newnode = getnode();
		if (start == NULL) // this will be done if there no nodes on the current list
		{
			start = newnode;
		}
		else // is there is one or more nodes in the list this will be done
		{
			temp = start;

			// this will try to find the end and ad nodes to the end
			while (temp->next != NULL)
				temp = temp->next;

			temp->next = newnode;
		}
	}
}

// this is reponsible for displaying in proper order/ ascending 
void traverse()
{
	// this node created to temporarily store the addresses of the nodes
	node* temp;

	// this is declared to start reading it from head to the tail, which null lies
	temp = start;

	cout << "\n The contents of List (Left to Right): \n";

	if (start == NULL) // if there is nothing in the list this will be displayed
	{
		cout << "\n Empty List";

		return;
	}
	else
	{
		// this will be continuesly done until it finds the tail
		while (temp != NULL)
		{
			cout << temp->data << "-->"; // display what inside
			temp = temp->next; // this will overwrite, papalitan yung dati ng nakalagay
		}
	}

	cout << " X ";
}

// this will display in descending order 
// this function also uses recursion process
void rev_traverse(node * start)
{
	if (start == NULL) // this will turn back o where it stopped and continuesly go back
	{
		return; // parang yung feeling na nasa lugar ka kung saan kayo nagdadate dati 
	}// tapos maalala mo lahat ganun
	else
	{
		rev_traverse(start->next); // this will call itself But using different parameter/next parameter
		cout << start->data; // kung babalik na sya sa alalaala nya ito yung magpapakita nakaraan
	}
}

// this will add to the start and push the other nodes
void insert_at_beg()
{
	node* newnode;
	newnode = getnode();

	if (start == NULL)
	{
		start = newnode;
	}
	else
	{
		newnode->next = start; // will push the start
		start = newnode; // will be set as the start
	}
}

// this will add to the last of the list
void insert_at_end()
{
	node* newnode, * temp;
	newnode = getnode();

	if (start == NULL)
	{
		start = newnode;
	}
	else
	{
		temp = start;
		while (temp->next != NULL) // wil find the end of the list
			temp = temp->next; 
		temp->next = newnode; // will connect the new to the tail
	}
}

// will add somewhere between
void insert_at_mid()
{
	node* newnode, * temp, * prev;
	int pos, nodectr, ctr = 1;

	newnode = getnode();

	cout << "\n Enter the position: ";
	cin >> pos;

	nodectr = countnode(start);

	if (pos > 1 && pos < nodectr) // will check if it is possible to be placed
	{
		temp = prev = start;

		while (ctr < pos) // this will find the position
		{
			prev = temp;
			temp = temp->next;
			ctr++;
		}

		// this will add it and push the other one back
		prev->next = newnode;
		newnode->next = temp;
	}
	else
		cout << "position " << pos << " is not a middle position";
}

// this will delete what is in the start of the list
void delete_at_beg()
{
	node* temp;

	if (start == NULL) // will check if there is something in list
	{
		cout << "\n No nodes are exist..";
		return;
	}
	else 
	{
		// this will delete when found
		temp = start;
		start = temp->next; // and set the next to be the first
		free(temp);

		// to inform the user
		cout << "\n Node deleted ";
	}
}

// this will delete what is in the last of the list
void delete_at_last()
{
	node* temp, * prev;
	if (start == NULL)
	{
		cout << "\n Empty List..";
		return;
	}
	else
	{
		temp = start;
		prev = start;
		while (temp->next != NULL) // will find the end
		{
			prev = temp;
			temp = temp->next;
		}

		// this will delete it
		prev->next = NULL;
		free(temp);
		cout << "\n Node deleted ";
	}
}

// this will delete what is declared
void delete_at_mid()
{
	int ctr = 1, pos, nodectr;
	node* temp, * prev;

	if (start == NULL)
	{
		cout << "\n Empty List..";
		return;
	}
	else
	{
		cout << "\n Enter position of node to delete: ";
		cin >> pos;

		nodectr = countnode(start);

		if (pos > nodectr) // will check if node is present
		{
			cout << "\nThis node doesnot exist";
		}
		if (pos > 1 && pos < nodectr)
		{
			temp = prev = start;

			while (ctr < pos) // will find the node
			{
				prev = temp;
				temp = temp->next;
				ctr++;
			}

			prev->next = temp->next;
			free(temp);

			cout << "\n Node deleted..";
		}
		else
		{
			cout << "\n Invalid position..";
			return;
		}
	}
}

void main(void)
{
	int ch, n;

	while (true)
	{
		ch = menu(); // this will call the menu

		switch (ch) // option to go to
		{
		case 1:
			if (start == NULL)
			{
				cout << "\n Number of nodes you want to create: ";
				cin >> n;

				createlist(n);

				cout << "\n List created..";
			}
			else
				cout << "\n List is already created..";
			break;
		case 2:
			insert_at_beg();
			break;
		case 3:
			insert_at_end();
			break;
		case 4:
			insert_at_mid();
			break;
		case 5:
			delete_at_beg();
			break;
		case 6:
			delete_at_last();
			break;
		case 7:
			delete_at_mid();
			break;
		case 8:
			traverse();
			break;
		case 9:
			cout << "\n The contents of List (Right to Left): \n";
			rev_traverse(start);
			cout << " X ";
			break;
		case 10:
			cout << "\n No of nodes : " << countnode(start);
			break;
		case 11:
			exit(0);
			return;
		default: // error trapping: out scope value input
			border;
			cout << "Error!";
			border;
			cout << "User use out-of-scope value.";
			border;
			cout << '\n';

			system("pause");
			exit(0);
			break;
		}

		system("pause");
		system("cls");
	}
}
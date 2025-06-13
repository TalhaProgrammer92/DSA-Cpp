#include <iostream>

using namespace std;

// ? Node that stores a integer value and address of another node
class Node
{
public:
	// * Data of the node
	int value;
	Node *next;

	// * Constructor
	Node(int value) : value(value), next(NULL) {}
};

// ? Linked list to create a list of connected nodes
class DoublyList
{
private:
	// * Main pointers
	Node *head, *tail;

public:
	// * Constructor
	DoublyList() : head(NULL), tail(NULL) {}

	// * Method - Push a node at front
	void push_front(int value)
	{
		// ? Create a new node
		Node *node = new Node(value);

		// ? If the list is empty
		if (head == NULL)
			tail = node;

		// ? If the list is not empty
		else
			node->next = head;

		// ? Finalize
		head = node;
	}

	// * Method - Detect cycle
	bool has_cycle()
	{
		if (head != NULL)
		{
			Node *slow = head, *fast = head;

			while (fast != NULL && fast->next != NULL)
			{
				slow = slow->next;
				fast = fast->next->next;

				if (slow == fast)
					return true;
			}
		}

		return false;
	}

	// * Method - Get a node at particular index
	Node *at(int index)
	{
		if (head != NULL)
		{
			Node *start = head;

			for (int i = 0; i < index; i++)
				start = start->next;

			return start;
		}
		throw out_of_range("The given index is out of range!");
	}

	// * Method - Link two nodes
	void link(int index1, int index2)
	{
		Node *first = at(index1), *second = at(index2);

		first->next = second;
	}

	// * Method - Print the list
	void print()
	{
		if (head != NULL)
		{
			if (has_cycle())
			{
				cout << "It contains a cycle!" << endl;
				return;
			}

			// ? Get the starting node
			Node *start = head;

			// ? Iterate through the list
			while (start != NULL)
			{
				cout << start->value << "->";
				start = start->next;
			}
			cout << "NULL" << endl;
		}
	}
};

int main()
{
	// * Linked list object
	DoublyList list;

	// * Pushing values at front
	list.push_front(5);
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);

	cout << "Before Cycle: "; list.print();
	
	// * Create a cycle
	list.link(4, 2);
	list.print();

	return 0;
}

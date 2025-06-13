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

	// * Method - Reverse the list
	void reverse()
	{
		Node *prev = NULL, *current = head, *next = NULL;

		while (current != NULL)
		{
			next = current->next;

			current->next = prev;

			prev = current;
			current = next;
		}

		tail = head;
		head = prev;
	}

    // * Method - Print the list
    void print()
    {
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

	// * Reverse
	cout << "Before:\t"; list.print();
    list.reverse();
	cout << "After:\t"; list.print();
}

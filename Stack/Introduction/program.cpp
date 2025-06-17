#include <iostream>
#include <vector>

using namespace std;

// ? Stack - Vector Based
template <class Type>
class StackVector
{
	vector<Type> data;

public:
	// * Method - Push a value
	void push(Type value)
	{
		data.push_back(value);
	}

	// * Method - Pop a value
	void pop()
	{
		data.pop_back();
	}

	// * Method - Top value
	Type top()
	{
		return data[data.size() - 1];
	}
};

// ? Node class for stack based linked list
template <class Type>
class Node
{
public:
	// * Attributes
	Type data;
	Node<Type> *next;

	// * Constructor
	Node(Type data) : data(data), next(NULL) {}
};

template <class Type>
class StackLinkedList
{
	// * Attributes
	Node<Type> *head, *tail;

public:
	// * Constructor
	StackLinkedList() : head(NULL), tail(NULL) {}

	// * Method - Push data into the stack
	void push(Type data)
	{
		Node<Type> *node = new Node(data);

		if (head == NULL)
			head = tail = node;
		else
		{
			node->next = head;

			head = node;
		}
	}

	// * Method - Pop data from the stack
	void pop()
	{
		Node<Type> *temp = head;

		head = head->next;

		temp->next = NULL;

		delete temp;
	}

	// * Method - Get data of top
	Type top()
	{
		return head->data;
	}
};

int main()
{
	// ? Stack - Vector Based
	StackVector<int> stack_vector;

	// * Pushing data
	stack_vector.push(1);
	stack_vector.push(2);
	stack_vector.push(3);

	// * Popping data
	stack_vector.pop();		// ! 3 Removed
	stack_vector.pop();		// ! 2 Removed

	// * Print top value
	cout << stack_vector.top() << endl;

	// ? Stack - Linked List Based
	StackLinkedList<int> stack_list;

	// * Pushing data
	stack_list.push(1);
	stack_list.push(2);
	stack_list.push(3);

	// * Popping data
	stack_list.pop();		// ! 3 Removed

	// * Print the data
	cout << stack_list.top() << endl;
}
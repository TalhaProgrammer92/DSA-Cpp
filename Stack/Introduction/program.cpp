#include <iostream>
#include <vector>

using namespace std;

// ? Stack - Vector Based
class StackVector
{
	vector<int> data;

public:
	// * Method - Push a value
	void push(int value)
	{
		data.push_back(value);
	}

	// * Method - Pop a value
	void pop()
	{
		data.pop_back();
	}

	// * Method - Top value
	int top()
	{
		return data[data.size() - 1];
	}

	// * Method - Check if stack is empty
	bool empty()
	{
		return data.size() == 0;
	}
};

// ? Node class for stack based linked list
class Node
{
public:
	// * Attributes
	int data;
	Node *next;

	// * Constructor
	Node(int data) : data(data), next(NULL) {}
};

class StackLinkedList
{
	// * Attributes
	Node *head;

public:
	// * Constructor
	StackLinkedList() : head(NULL) {}

	// * Method - Push data into the stack
	void push(int data)
	{
		Node *node = new Node(data);

		if (head != NULL)
			node->next = head;

		head = node;
	}

	// * Method - Pop data from the stack
	void pop()
	{
		Node *temp = head;

		head = head->next;

		temp->next = NULL;

		delete temp;
	}

	// * Method - Get data of top
	int top()
	{
		return head->data;
	}

	// * Method - Check if stack is empty
	bool empty()
	{
		return head == NULL;
	}
};

int main()
{
	// ? Stack - Vector Based
	StackVector stack_vector;

	// * Pushing data
	stack_vector.push(1);
	stack_vector.push(2);
	stack_vector.push(3);

	// * Print top value
	cout << "Stack (Vector): ";
	while (!stack_vector.empty())
	{
		cout << stack_vector.top() << ' ';
		stack_vector.pop();
	}
	cout << endl;

	// ? Stack - Linked List Based
	StackLinkedList stack_list;

	// * Pushing data
	stack_list.push(1);
	stack_list.push(2);
	stack_list.push(3);

	// * Print the data
	cout << "Stack (Linked List): ";
	while (!stack_list.empty())
	{
		cout << stack_list.top() << ' ';
		stack_list.pop();
	}
	cout << endl;
}

#include <iostream>
#include <vector>

using namespace std;

// ? Block
class Block
{
public:
	// * Attributes
	int data;
	Block *next;

	// * Constructors
	Block();
	Block(int data);
};

// ? Queue
class Queue
{
	// * Attributes
	Block *top;

public:
	// * Constructor
	Queue();

	// * Push data
	void push(int data);

	// * Pop data
	int pop();

	// * Top data
	int top_data();

	// * Getter - Size
	int size();
};

// ? Entry Point
int main()
{
	// * Data & Objects
	vector<int> data = {1, 2, 3, 4, 5};
	Queue queue;

	// * Push data
	for (int element : data)
		queue.push(element);

	// * Pop & Display
	while (queue.size() > 0)
		cout << queue.pop() << endl;
}

// ? Block - Methods

// * Constructors
Block::Block() : next(NULL) {}
Block::Block(int data) : data(data), next(NULL) {}

// ? Queue - Methods

// * Constructors
Queue::Queue() : top(NULL) {}

// * Push data
void Queue::push(int data)
{
	Block *block = new Block(data);

	if (top == NULL)
		top = block;
	else
	{
		// ! Find last block and push that new block to next to the last block
		Block *temp = top;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = block;
	}
}

// * Pop data
int Queue::pop()
{
	if (top != NULL)
	{
		int data = top->data;

		Block *block = top;

		top = top->next;

		delete block;

		return data;
	}
	return INT_MIN;
}

// * Top data
int Queue::top_data()
{
	if (top != NULL)
		return top->data;
	return INT_MIN;
}

// * Size
int Queue::size()
{
	int blocks = 0;
	Block *block = top;

	while (block != NULL)
	{
		blocks++;
		block = block->next;
	}

	return blocks;
}

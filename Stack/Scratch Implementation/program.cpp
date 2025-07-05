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
	Block() : next(NULL) {}
	Block(int data) : data(data), next(NULL) {}
};

// ? Stack
class Stack
{
	// * Atributes
	Block *top;

public:
	// * Constructor
	Stack() : top(NULL) {}

	// * Push data
	void push(int data)
	{
		Block *block = new Block(data);

		if (top != NULL)
			block->next = top;

		top = block;
	}

	// * Pop data
	int pop()
	{
		int data = top->data;
		
		Block *temp = top;

		top = top->next;

		delete temp;

		return data;
	}

	// * Getter - Size
	int size()
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
};

int main()
{
	// * Objects
	vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Stack stack;

	// * Push data
	for (int element : data)
		stack.push(element);
	
	// * Pop & Display
	while (stack.size() > 0)
	{
		cout << stack.pop() << endl;
	}
}

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

int main()
{
	// ? Stack - Vector Based
	StackVector<int> stack_vector;
	
	// * Pushing data
	stack_vector.push(1);
	stack_vector.push(2);
	stack_vector.push(3);

	// * Popping data
	stack_vector.pop();
	stack_vector.pop();

	// * Print top value
	cout << stack_vector.top() << endl;
}
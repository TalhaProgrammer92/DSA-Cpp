#include <iostream>
#include <list>

using namespace std;

void print(list<int> &_list)
{
	for (int element : _list)
		cout << element << ' ';
	cout << endl;
}

int main() {
	cout << "\n** Initialization **" << endl;

	list<int> l = {1, 2, 3};	// * Initialize a list

	l.push_back(4);		// * Add a number at end
	l.push_front(0);	// * Add a number at front

	print(l);	// * Print the list

	cout << "\n** Pop **" << endl;

	l.pop_back();	// * Pop last element
	l.pop_front();	// * Pop first element

	print(l);

	return 0;
}
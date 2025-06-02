#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> d = {1, 2, 3};

	d.push_back(4);
	d.push_front(0);

	for (int i : d)
		cout << i << ' ';
	cout << endl;

	return 0;
}
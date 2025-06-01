#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = {4, 6, 7};

	vec.push_back(9);

	cout << "Size: " << vec.size() << "\nCapacity: " << vec.capacity() << endl;

	cout << vec[2] << endl;
	cout << vec.at(1) << endl;

	cout << "First: " << vec.front() << "\nLast: " << vec.back() << endl;

	vector<int> same(3, 2);		// * All (3) elments will be 2

	for (int element : same)
		cout << element << ' ';
	cout << endl;

	vector<int> vec_copy(vec);	// * Copy all elmeents of vec to vec1 | Another Method: vector<int> vec_copy = vec1;

	for (int element : vec_copy)
		cout << element << ' ';
	cout << endl;

	return 0;
}
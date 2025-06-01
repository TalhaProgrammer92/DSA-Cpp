#include <iostream>
#include <vector>

using namespace std;

// * Print elements of a vector
void print(vector<int> &_vector)
{
	for (int element : _vector)
		cout << element << ' ';
	cout << endl;
}

int main()
{
	cout << "\n** Normal **" << endl;

	vector<int> vec = {4, 6, 7};

	vec.push_back(9);

	cout << "Size: " << vec.size() << "\nCapacity: " << vec.capacity() << endl;

	cout << vec[2] << endl;
	cout << vec.at(1) << endl;

	cout << "First: " << vec.front() << "\nLast: " << vec.back() << endl;

	cout << "\n** Same Elments **" << endl;

	vector<int> same(3, 2);		// * All (3) elments will be 2

	print(same);

	cout << "\n** Copy Elements **" << endl;

	vector<int> vec_copy(vec);	// * Copy all elmeents of vec to vec1 | Another Method: vector<int> vec_copy = vec1;

	print(vec_copy);
	
	cout << "\n** Erase **" << endl;

	const int index = 2;
	vec_copy.erase(vec_copy.begin() + index);	// * Erases element at particular index of the vector (vec_copy)
	
	print(vec_copy);

	const int start = 1, end = 2;
	vec_copy.erase(vec_copy.begin() + start, vec_copy.begin() + end);	// * Erases elements in a range from start to end - 1
	
	print(vec_copy);

	cout << "\n** Insert **" << endl;

	const int idx = 1;
	vec_copy.insert(vec_copy.begin() + idx, 5);

	print(vec_copy);

	cout << "\n** Clear **" << endl;

	vec_copy.clear();
	print(vec_copy);

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// ? Array
	vector<int> array = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

	//? Sort [Bubble Sort - O(n2)]
	for (int i = 0; i < array.size() - 1; i++)
		for (int j = 0; j < array.size() - i - 1; j++)
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);

	//? Display
	for (auto &&element : array)
		cout << element << ' ';
	cout << endl;

	return 0;
}
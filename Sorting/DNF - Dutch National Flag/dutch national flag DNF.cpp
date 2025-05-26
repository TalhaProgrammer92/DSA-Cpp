#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// ? Array
	vector<int> array = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

	//? Sort [Dutch National Flag - O(n)]
	/*
	! Rules:
		0s -> 0 to low - 1
		1s -> low to mid - 1
		2s -> high + 1 to n - 1
		Unsorted -> mid to high
	*/

	int mid = 0, high = array.size() - 1, low = 0;

	while (mid <= high)
	{
		switch (array[mid])
		{
		case 0:
			swap(array[low++], array[mid++]);
			break;

		case 1:
			mid++;
			break;

		case 2:
			swap(array[high--], array[mid]);
			break;
		}
	}

	//? Display
	for (auto &&element : array)
		cout << element << ' ';
	cout << endl;

	return 0;
}
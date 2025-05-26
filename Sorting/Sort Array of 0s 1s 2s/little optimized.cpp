#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// ? Array
	vector<int> array = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

	//? Sort - O(n)

	//* Count the number of elements - O(n)
	int count[] = {0, 0, 0};

	for (int i = 0; i < array.size(); i++)
	{
		switch (array[i])
		{
		case 0:
			count[0]++;
			break;

		case 1:
			count[1]++;
			break;

		case 2:
			count[2]++;
			break;
		}
	}

	//* Overrite - O(n)
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			array[index++] = i;
		}
	}

	//? Display
	for (auto &&element : array)
		cout << element << ' ';
	cout << endl;

	return 0;
}
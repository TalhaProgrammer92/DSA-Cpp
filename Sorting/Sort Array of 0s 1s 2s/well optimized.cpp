#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// ? Array
	vector<int> array = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

	//? Sort - O()

	//? Display
	for (auto &&element : array)
		cout << element << ' ';
	cout << endl;

	return 0;
}
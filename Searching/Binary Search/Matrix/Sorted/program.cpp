#include <iostream>
#include <vector>

using namespace std;

bool exists(vector<vector<int>> &matrix, int &target)
{
	// ? If the matrix is empty
	if (matrix.size() == 0)
		return false;

	// ? Search for the given target

	return false;
}

int main() {
	// ! Array
	/*
		? Find given target from the given array
		* Each row is sorted in ascending order
	*/
	vector<vector<int>> matrix = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	int target = 5;

	cout << "Status: " << exists(matrix, target) << endl;

	return 0;
}
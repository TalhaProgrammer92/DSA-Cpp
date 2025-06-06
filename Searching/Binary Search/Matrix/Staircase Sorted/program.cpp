#include <iostream>
#include <vector>

using namespace std;

struct Position
{
	int row = 0, column = 0;
};

int get_value(Position &pos, vector<vector<int>> &matrix)
{
	return matrix[pos.row][pos.column];
}

bool exists(vector<vector<int>> &matrix, int &target)
{
	// ? If the matrix is empty
	if (matrix.size() == 0)
		return false;

	// ? Positions for start, end, and mid cells of the matrix
	Position start, end, mid;

	// ! Extreme last value
	end.row = matrix.size() - 1;
	end.column = matrix[0].size() - 1;

	// ! Extreme corner value w.r.t start and end
	mid.row = 0;
	mid.column = end.column;

	// ? Searching for target
	while (mid.row <= end.row && mid.column >= 0)
	{
		// ! Get valid at mid position
		int value = get_value(mid, matrix);

		// ! If target found -> true
		if (value == target)
			return true;

		// ! If target < value -> Decrease column (Left)
		else if (value > target)
			mid.column--;

		// ! If target > value -> Increase row (Bottom)
		else if (value < target)
			mid.row++;
	}

	return false;
}

int main()
{
	// ! Array
	/*
		? Find given target from the given array
		* Each row and column are sorted in ascending order
	*/
	vector<vector<int>> matrix = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}};
	int target = 8;

	cout << "Status: " << exists(matrix, target) << endl;

	return 0;
}

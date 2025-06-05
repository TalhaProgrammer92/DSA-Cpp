#include <iostream>
#include <vector>

using namespace std;

struct Position
{
	int row = 0, column = 0;
};

const int get_value(Position &pos, vector<vector<int>> &matrix)
{
	return matrix[pos.row][pos.column];
}

bool exists(vector<vector<int>> &matrix, int &target)
{
	// ? If the matrix is empty
	if (matrix.size() == 0)
		return false;

	// ! Positions for start and end cell of the matrix
	Position start, end;
	end.row = matrix.size() - 1;
	end.column = matrix[0].size() - 1;

	return false;
}

int main() {
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
		{18, 21, 23, 26, 30}
	};
	int target = 5;

	cout << "Status: " << exists(matrix, target) << endl;

	return 0;
}
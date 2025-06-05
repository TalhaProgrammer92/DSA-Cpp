#include <iostream>
#include <vector>

using namespace std;

// * Check if the given number exists in a matrix or not using brute-force approach
bool exists_brute_froce(vector<vector<int>> &matrix, int &target)
{
	// ? Take each row
	for (auto row : matrix)
		// ? Take each number on each row
		for (int number : row)
			// ? If found the target -> True
			if (number == target)
				return true;

	// ? If no target was found
	return false;
}

// * Check if the given number exists in a matrix or not using binary-search approach
bool exists_binary_search(vector<vector<int>> &matrix, int &target)
{
	// ? The the given matrix is empty
	if (matrix.size() == 0)
		return false;

	// ? Tri-indices for matrix
	int start = 0, end = matrix.size() - 1, mid, r_end = matrix[0].size() - 1;

	while (start <= end)
	{
		// ? Center index of matrix
		mid = start + (end - start) / 2;

		// ? If target exists in current (center) row -> Search in this row
		if (matrix[mid][0] <= target && matrix[mid][r_end] >= target)
		{
			// ? Tri-indices for current (center) row
			int left = 0, right = r_end, center, number;

			// ? Search for the target
			while (left <= end)
			{
				// ? Center index of row
				center = left + (right - left) / 2;

				// ? Number at center index
				number = matrix[mid][center];

				// ? If the target on right side
				if (number > target)
					right = center - 1;

				// ? If the target on left side
				else if (number < target)
					left = center + 1;

				// ? If target found
				else if (number == target)
					return true;
			}
		}

		// ? If last number of current (center) row is less than target -> Move to next row
		else if (matrix[mid][r_end] < target)
			start = mid + 1;

		// ? If first number of current (center) row is greater than target -> Move to previous row
		else if (matrix[mid][0] > target)
			end = mid - 1;
	}

	// ? If no target was found
	return false;
}

int main()
{
	// ! Array
	/*
		? Find given target from the given array
		* Each row is sorted in ascending order
		* The first integer of each row is greater than the last integer of previous row
	*/
	vector<vector<int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60},
	};
	int target = 34;

	cout << "Status: " << exists_brute_froce(matrix, target) << endl;
	cout << "Status: " << exists_binary_search(matrix, target) << endl;

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &array, int start, int end)
{
	// ? Pivot number
	int pivot = array[end], index = start - 1;

	// ? Iterate from start to end - 1
	for (int i = start; i < end; i++)
		// ? If the current number is less/equal to the pivot number
		if (array[i] <= pivot)
			// ? Swap the current number and the number at next index
			swap(array[i], array[++index]);

	// ? Swap the number at end and the number at next index
	swap(array[end], array[++index]);

	return index;
}

void sort(vector<int> &array, int start, int end)
{
	if (start < end)
	{
		// ? Pivot index
		int pivot_index = partition(array, start, end);

		// ? Left half
		sort(array, start, pivot_index - 1);

		// ? Right half
		sort(array, pivot_index + 1, end);
	}
}

void display(vector<int> &array, const string &message)
{
	cout << message;

	for (int num : array)
		cout << num << ' ';

	cout << endl;
}

int main()
{
	vector<int> array = {1, 4, 2, 3, 9, 5, 7, 6, 8, 0};

	display(array, "Unsorted: ");

	sort(array, 0, array.size() - 1);

	display(array, "Sorted: ");

	return 0;
}

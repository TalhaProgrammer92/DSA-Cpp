#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];        // * Current element to be inserted
        int j = i - 1;

        // ! Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void display(vector<int> &array)
{
	for (auto &&i : array)
		cout << i << ' ';
	cout << endl;
}

int main()
{
	vector<int> array = {4, 1, 5, 2, 3};

	display(array);

	sort(array);

	display(array);

	return 0;
}

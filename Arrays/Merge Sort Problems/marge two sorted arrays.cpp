#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// * Variables
	vector<int> a = {1, 2, 3, 0, 0, 0}, b = {2, 5, 6};
	int m = 3, n = 3;

	// * Algorithm
	int index = m + n - 1, i = 2, j = 2;
	while (j >= 0)
		a[index--] = (b[i] > a[i]) ? b[j--] : a[i--];

	// * Print the array
	for (int i = 0; i < m + n; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}
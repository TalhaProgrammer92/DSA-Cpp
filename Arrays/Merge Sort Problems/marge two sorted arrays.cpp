#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// * Variables
	// vector<int> a = {1, 2, 3, 0, 0, 0}, b = {2, 5, 6};
	vector<int> a = {4, 5, 6, 0, 0, 0}, b = {1, 2, 3};
	int m = 3, n = 3;

	// * Algorithm
	int index = m + n - 1, i = m - 1, j = n - 1;
	while (j >= 0)
		if ( i >= 0)
			a[index--] = (b[i] > a[i]) ? b[j--] : a[i--];
		else
			a[index--] = b[j--];

	// * Print the array
	for (int i = 0; i < m + n; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	static void sort(vector<int> &array)
	{
		for (int i = i; i < array.size(); i++)
		{
			int prev = i - 1;
			int curr = array[i];

			while (array[prev] > curr && prev >= 0)
			{
				array[prev + 1] = array[prev];
				prev--;
			}
			array[prev + 1] = curr;
		}
	}

	static void display(vector<int> &array)
	{
		for (auto &&i : array)
			cout << i << ' ';
		cout << endl;
	}
};

int main()
{
	vector<int> array = {4, 1, 5, 2, 3};

	Solution::display(array);

	Solution::sort(array);

	Solution::display(array);

	return 0;
}
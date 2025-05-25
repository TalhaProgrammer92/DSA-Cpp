#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	static void sort(vector<int> &array)
	{
		for (int i = 0; i < array.size() - 1; i++)
		{
			int small = i;

			for (int j = i + 1; j < array.size(); j++)
			{
				if (array.at(j) < array.at(small))
					small = j;
			}

			swap(array.at(i), array.at(small));
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
#include <iostream>
#include <vector>

using namespace std;

// ? Find out the pair of given array that's pair sum is equal to the given targer by using brute force approach.
// TODO: Array: {2, 7, 11, 15}, Target: 9

class Solution
{
public:
    void printPairs(vector<int> &array, int target)
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = i + 1; j < array.size(); j++)
            {
                if (array[i] + array[j] == target)
                {
                    cout << "Sum of the pair (" << array[i] << ", " << array[j] << ") is " << target << endl;
                    return;
                }
            }
        }
        cout << "No pairs found with the given target." << endl;
    }
};

int main()
{
    vector<int> array = {2, 7, 11, 15};
    Solution().printPairs(array, 9);
}

/*
    Output:

    Sum of the pair (2, 7) is 9

    Time Complexity: O(n^2)
*/
#include <iostream>
#include <vector>

using namespace std;

// ? Find out the pair of given array that's pair sum is equal to the given targer by using two pointer approach.
// TODO: Array: {2, 7, 11, 15}, Target: 9

class Solution
{
public:
    void printPairs(vector<int> &array, int target)
    {
        //* i is left pinter while j is right pointer of the given vector array
        int i = 0, j = array.size() - 1;

        while (i < j)
        {
            //* If the sum is less than the target, increment the left pointer
            if (array[i] + array[j] < target)
            {
                j--;
            }
            //* If the sum is greater than the target, decrement the right pointer
            else if (array[i] + array[j] > target)
            {
                i++;
            }
            //* If the sum is equal to the target, print the pair
            else
            {
                cout << "Sum of the pair (" << array[i] << ", " << array[j] << ") is " << target << endl;
                return;
            }
        }
        //* If no pair is found, print a message indicating the same
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

    Time Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ? Find out majority element (appears more than n/2 times) in an array by sorting the array.
// TODO: Array = {1, 2, 2, 1, 1}, Majority Element = 1

class Solution
{
public:
    int findMajorityElement(vector<int> &nums)
    {
        int count = 1, limit = nums.size() / 2;
        sort(nums.begin(), nums.end()); //* Sort the array.

        //* Count the number of times the current element appears in the array.
        for (int i = 0; i < nums.size() - 1; i++)
        {
            //* If current element is same as the next element, increment the count.
            if (nums[i] == nums[i + 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }

            //* If count reaches the limit (n/2), return the current element as majority element.
            if (count > limit)
            {
                return nums[i];
            }
        }
    }
};

int main()
{
    vector<int> numbers = {1, 2, 2, 1, 1};
    cout << Solution().findMajorityElement(numbers) << endl;
}

/*
    Output:

    1

    Time Complexity:
     O(n.log(n)) - Sorting the array.
     O(n) - Iterating through the array to find the majority element.
    => O(n.log(n)) + O(n) = O(n.log(n))
*/

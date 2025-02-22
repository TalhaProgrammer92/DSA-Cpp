#include <iostream>
#include <vector>

using namespace std;

// ? Find out majority element (appears more than n/2 times) in an array by using Brute Force Approach.
// TODO: Array = {1, 2, 2, 1, 1}, Majority Element = 1

class Solution
{
public:
    int findMajorityElement(vector<int> &nums)
    {
        int count, limit = nums.size() / 2;

        //* Iterate through each element in the array.
        for (int i = 0; i < nums.size(); i++)
        {
            count = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                //* If current element is same as the next element, increment the count.
                if (nums[i] == nums[j])
                    count++;
                //* If count reaches the limit (n/2), return the current element as majority element.
                if (count > limit)
                    return nums[i];
            }
            count = 0;
        }
        return -1; //* Majority element not found in the array.
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

    Time Complexity: O(n^2)
*/
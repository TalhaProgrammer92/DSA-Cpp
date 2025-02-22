#include <iostream>
#include <vector>

using namespace std;

// ? Find out majority element (appears more than n/2 times) in an array by using Moore's Voting Algorithm.
// TODO: Array = {1, 2, 2, 1, 1}, Majority Element = 1

class Solution
{
public:
    int findMajorityElement(vector<int> &nums)
    {
        int majorityElement = nums[0], count = 1;

        //* Iterate through each element in the array.
        for (int i = 1; i < nums.size(); i++)
        {
            //* If count is 0, assign current element as majority element.
            if (count == 0)
            {
                majorityElement = nums[i];
                count = 1;
            }
            //* If current element is same as majority element, increment the count.
            else if (nums[i] == majorityElement)
                count++;
            //* If current element is different from majority element, decrement the count.
            else
                count--;
        }

        count = 0;
        //* Iterate through each element in the array.
        for (int i = 0; i < nums.size(); i++)
        {
            //* If current element is same as majority element, increment the count.
            if (nums[i] == majorityElement)
                count++;
        }

        //* If count is greater than n/2, return the majority element.
        if (count > nums.size() / 2)
            return majorityElement;
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

    Time Complexity: O(n)
*/
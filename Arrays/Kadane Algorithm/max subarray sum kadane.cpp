#include <iostream>

using namespace std;

// ? Find out the maximum subarray sum of {3, -4, 5, 4, -1, 7, -8} by using Kadane's Algorithm

class Solution
{
public:
    int maxSubArraysum(int array[], int size)
    {
        int currentSum = 0, maxSum = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            currentSum = max(array[i], currentSum + array[i]);
            maxSum = max(maxSum, currentSum);
            // Reset currentSum if it becomes negative
            if (currentSum < 0)
                currentSum = 0;
        }

        return maxSum;
    }
};

int main()
{
    int array[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(array) / sizeof(array[0]);

    cout << Solution().maxSubArraysum(array, size);
}

/*
    Output:

    15  (The maximum subarray sum is 15)

    Time Complexity: O(n)
*/
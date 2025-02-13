#include <iostream>
#include <climits> // For INT_MIN

using namespace std;

// ? Find out the maximum subarray sum of {3, -4, 5, 4, -1, 7, -8} by using Brute Force Approach

class Solution
{
public:
    int maxSubArraysum(int array[], int size)
    {
        int maxSum = INT_MIN;

        // Consider all subarrays
        for (int i = 0; i < size; i++)
        {
            int currentSum = 0;
            for (int j = i; j < size; j++)
            {
                currentSum += array[j]; // Compute sum of subarray from i to j
                maxSum = max(maxSum, currentSum);
            }
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

    Time Complexity: O(n^2)
*/
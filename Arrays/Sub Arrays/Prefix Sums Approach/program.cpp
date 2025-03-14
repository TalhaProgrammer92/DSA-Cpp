#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void computePrefixSum(vector<int>& arr, vector<int>& prefixSum)
    {
        prefixSum[0] = arr[0];  // First element remains the same
        for (int i = 1; i < arr.size(); i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
    }

    void printAllSubArraySums(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> prefixSum(n);
        computePrefixSum(arr, prefixSum);

        // Iterate over all possible subarrays
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int subarraySum = (i == 0) ? prefixSum[j] : prefixSum[j] - prefixSum[i - 1];
                cout << "Sum of subarray [" << i << " to " << j << "] = " << subarraySum << endl;
            }
        }
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution().printAllSubArraySums(arr);
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)

/*
Output:

Sum of subarray [0 to 0] = 1
Sum of subarray [0 to 1] = 3
Sum of subarray [0 to 2] = 6
Sum of subarray [0 to 3] = 10
Sum of subarray [0 to 4] = 15
Sum of subarray [1 to 1] = 2
Sum of subarray [1 to 2] = 5
Sum of subarray [1 to 3] = 9
Sum of subarray [1 to 4] = 14
Sum of subarray [2 to 2] = 3
Sum of subarray [2 to 3] = 7
Sum of subarray [2 to 4] = 12
Sum of subarray [3 to 3] = 4
Sum of subarray [3 to 4] = 9
Sum of subarray [4 to 4] = 5
*/
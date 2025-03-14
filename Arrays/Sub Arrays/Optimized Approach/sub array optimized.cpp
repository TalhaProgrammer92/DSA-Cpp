#include <iostream>

using namespace std;

class Solution
{
public:
    void printAllSubArrays(int array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            string subarray = "";
            for (int j = i; j < size; j++)
            {
                subarray += to_string(array[j]); // Append element to the subarray string
                cout << subarray << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Solution().printAllSubArrays(arr, size);
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
Output:

1 12 123 1234 12345 
2 23 234 2345 
3 34 345 
4 45 
5 
*/
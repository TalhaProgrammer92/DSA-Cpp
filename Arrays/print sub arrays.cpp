#include <iostream>

using namespace std;

class Solution
{
public:
    void printAllSubArrays(int array[], int size)
    {
        // Loop through all subarrays
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                // Print the subarray
                for (int k = i; k <= j; k++)
                    cout << array[k];
                cout << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    // Test the algorithm
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Solution().printAllSubArrays(arr, size);
}

/*
    Output:

    1 12 123 1234 12345 
    2 23 234 2345       
    3 34 345
    4 45
    5
*/
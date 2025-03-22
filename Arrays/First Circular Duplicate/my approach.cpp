#include <iostream>
#include <vector>

using namespace std;

/*
Given an array of integers, find the first element that appears more than once when traversing circularly (i.e., looping back to the start when reaching the end). If no duplicate is found, return -1.

Example:
Input: arr = {4, 2, 5, 3, 2, 6}  
Output: 2
*/

class Solution
{
    public:
    static int firstDuplicate(vector<int> arr)
    {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int num = arr[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (num == arr[j])
                {
                    return num;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {4, 2, 5, 3, 2, 6};
    cout << Solution::firstDuplicate(arr) << endl;
    return 0;
}

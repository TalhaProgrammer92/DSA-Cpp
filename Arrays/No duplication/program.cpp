#include <iostream>
#include <vector>

using namespace std;

/*
You are given a sorted array of integers where every number duplicates except one number.
Write a function that returns the number that does not duplicate.
Example:
Input: vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
Output: 4

Use O(log n) instead of O(n) solution.
*/

class Solution{
    public:
        static int findUnique(vector<int>& nums){
            for (int i = 0; i < nums.size(); i += 2){
                if (nums[i] != nums[i + 1]){
                    return nums[i];
                }
            }
            return -1;
        }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    cout << Solution::findUnique(nums) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

/*
ou are given an array of N distinct integers in the range [1, N+1].
However, one number is missing.
Example:
int findMissingNumber(vector<int>& nums);
findMissingNumber({1, 2, 3, 4, 6, 7, 8}) => 5
*/

class Solution {
    public:
        static int findMissingNumber(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;

            for (int i = 0; i < n; i++) {
                sum += nums[i];
            }

            return (n + 1) * (n + 2) / 2 - sum;     //* This is the formula to find the missing number, as we know the range of the numbers
        }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8};
    cout << Solution::findMissingNumber(nums) << endl;
    return 0;
}
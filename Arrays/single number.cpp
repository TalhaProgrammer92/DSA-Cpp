#include <iostream>
#include <vector>

using namespace std;

// ? Given a non-empty array of integers 'nums', every element eppears twice except for one. Find the single one.
// TODO: You must implement a solution with a linear runtime complexity and use only constant extra space.

/* 
==================================
Example:
==================================
Input: nums = [4, 1, 2, 1, 2]
Output: 4

==================================
Constraints:
==================================
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
*/

class Solution{
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for (int num : nums) {
            answer ^= num;  // XOR Operator: m XOR 0 = m, m XOR m = 0
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    
    // Output would be 4
    cout << Solution().singleNumber(nums) << endl;
}

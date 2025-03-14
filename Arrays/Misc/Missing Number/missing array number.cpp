#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];
        }
        return sum;
    }
};

int main()
{
    vector<int> nums = {3, 0, 1, 4};
    cout << "Missing number is " << Solution::missingNumber(nums) << endl;
}

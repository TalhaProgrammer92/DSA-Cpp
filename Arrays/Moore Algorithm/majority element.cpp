#include <iostream>
#include <vector>

using namespace std;

// ? Find out majority element (appears more than n/2 times) in an array by using Moore's Algorithm.
// TODO: Array = {1, 2, 2, 1, 1}, Majority Element = 1

class Solution{
public:
    int findMajorityElement(vector<int>& nums){
        int majorityElement = nums[0];
        int count = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == majorityElement){
                count++;
            }
            else{
                count--;
                if(count == 0){
                    majorityElement = nums[i];
                    count = 1;
                }
            }
    
        }
        
        return majorityElement;
    }
};

int main()
{
    vector<int> numbers = {1, 2, 2, 1, 1};
    cout << Solution().findMajorityElement(numbers) << endl;
}

/*
    Output:

    1
 
    Note: The time complexity of this solution is O(n), where n is the size of the input array.
    The space complexity is O(1), as we are not using any additional data structures.
*/
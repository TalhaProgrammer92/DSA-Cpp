#include <iostream>
#include <vector>

using namespace std;

/*
Find the first missing positive integer in an unsorted array (without sorting).

Example:

vector<int> arr = {3, 4, -1, 1};  
Output: 2 (since 2 is the first missing positive number)
*/

class Solution
{
    public:
        static int missingNumber(vector<int>& arr) {
            int n = arr.size();
            int number = 1;

            for (int i = 0 ; i < n; i++){
                int current = arr[i];
                
                for (int j = 0; j < n; j++)
                {
                    if (arr[j] == number){
                        number++;
                        break;
                    }
                }
            }

            return number;
        }
};

int main() {
    vector<int> arr = {3, 4, -1, 1};
    // vector<int> arr = {7, 8, 9, 11, 12};
    cout << Solution::missingNumber(arr) << endl;
}
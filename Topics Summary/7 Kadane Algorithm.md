# **Kadane’s Algorithm (Maximum Subarray Sum) in C++**  

**Kadane’s Algorithm** finds the **maximum sum subarray** in an array of integers in **O(n) time**.  

## **Algorithm Steps:**  
1. Maintain two variables:  
   - `max_sum` → Stores the maximum sum found so far.  
   - `current_sum` → Tracks the sum of the current subarray.  
2. Iterate through the array:  
   - Add the current element to `current_sum`.  
   - If `current_sum` is negative, reset it to `0`.  
   - Update `max_sum` if `current_sum` is greater.  

## **C++ Implementation:**
```cpp
#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n) {
    int max_sum = INT_MIN, current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        if (current_sum > max_sum) 
            max_sum = current_sum;
        if (current_sum < 0) 
            current_sum = 0;
    }

    return max_sum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Subarray Sum: " << kadane(arr, n) << endl;
    return 0;
}
```
**Output:**  
```
Maximum Subarray Sum: 6
```
(*Subarray: [4, -1, 2, 1]*)

---

### **Real-Life Example: Stock Market Profit**  
Imagine tracking **daily profit/loss** in the stock market.  
- **Positive values** → Gains  
- **Negative values** → Losses  
Kadane’s Algorithm helps find the period with the **maximum cumulative profit**.

#### **Example:**
```cpp
int stockChanges[] = {-3, 5, -2, 9, -8, 4, 6, -1};
```
Kadane’s Algorithm will find the most **profitable streak**, helping investors **decide the best buying/selling period**.
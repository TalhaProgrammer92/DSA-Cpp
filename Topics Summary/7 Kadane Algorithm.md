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

## **Mathematical Formula**  

Kadane’s Algorithm follows a **dynamic programming** approach to find the **maximum subarray sum** efficiently.

### **Recurrence Relation:**  
Let `max_sum` be the global maximum subarray sum and `current_sum` be the sum of the current subarray ending at index `i`.

\[
current\_sum = \max(arr[i], current\_sum + arr[i])
\]

\[
max\_sum = \max(max\_sum, current\_sum)
\]

### **Explanation:**
1. **Choice 1:** Start a new subarray at `arr[i]` → `arr[i]`
2. **Choice 2:** Extend the current subarray by adding `arr[i]` → `current_sum + arr[i]`
3. **Update `max_sum`** to store the maximum sum found so far.

### **Example Calculation:**
For `arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`  

| i  | arr[i] | current_sum (max(arr[i], current_sum + arr[i])) | max_sum |
|----|--------|---------------------------------|---------|
| 0  | -2     | -2                              | -2      |
| 1  |  1     | **max(1, -2 + 1) = 1**          | 1       |
| 2  | -3     | **max(-3, 1 + (-3)) = -2**      | 1       |
| 3  |  4     | **max(4, -2 + 4) = 4**          | 4       |
| 4  | -1     | **max(-1, 4 + (-1)) = 3**       | 4       |
| 5  |  2     | **max(2, 3 + 2) = 5**           | 5       |
| 6  |  1     | **max(1, 5 + 1) = 6**           | 6       |
| 7  | -5     | **max(-5, 6 + (-5)) = 1**       | 6       |
| 8  |  4     | **max(4, 1 + 4) = 5**           | 6       |

Final **max_sum = 6**, from subarray `[4, -1, 2, 1]`.

This recurrence relation ensures **O(n) time complexity**, making Kadane’s Algorithm optimal for finding the **maximum subarray sum**. 🚀
## 🚀 **Optimized Approach Using Prefix Sums (O(n))**  
We can **avoid nested loops** completely by using **prefix sums** for efficient subarray calculations.

---

### **What is a Prefix Sum?**
A **prefix sum array** stores cumulative sums so that subarray sums can be computed in **constant time O(1)** instead of iterating over elements.

For an array `arr = [1, 2, 3, 4, 5]`, its **prefix sum array** is:

| **Index (i)** | **arr[i]** | **Prefix Sum (prefix[i])** |
|------|------|------|
| 0 | 1 | 1 |
| 1 | 2 | 3 (1+2) |
| 2 | 3 | 6 (1+2+3) |
| 3 | 4 | 10 (1+2+3+4) |
| 4 | 5 | 15 (1+2+3+4+5) |

Using the **prefix sum array**, any subarray sum `arr[i] to arr[j]` can be found in **O(1)** using:

\[
\text{subarray sum} = \text{prefix}[j] - \text{prefix}[i-1]
\]

---

### **Optimized Code Using Prefix Sum (O(n))**
```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void computePrefixSum(vector<int>& arr, vector<int>& prefixSum)
    {
        prefixSum[0] = arr[0];  // First element remains the same
        for (int i = 1; i < arr.size(); i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
    }

    void printAllSubArraySums(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> prefixSum(n);
        computePrefixSum(arr, prefixSum);

        // Iterate over all possible subarrays
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int subarraySum = (i == 0) ? prefixSum[j] : prefixSum[j] - prefixSum[i - 1];
                cout << "Sum of subarray [" << i << " to " << j << "] = " << subarraySum << endl;
            }
        }
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution().printAllSubArraySums(arr);
}
```

---

## **Explanation of Optimized Code**
1. **Compute the Prefix Sum (O(n))**
   - `computePrefixSum()` creates a **prefix sum array** that stores cumulative sums.

2. **Compute Subarray Sums in O(1)**
   - Instead of iterating over elements in a subarray (O(n) per subarray), we calculate sums using:
     \[
     \text{prefix}[j] - \text{prefix}[i-1]
     \]
   - This reduces the complexity from **O(n³) → O(n²)**.

---

## **Example Execution**
For `arr = [1, 2, 3, 4, 5]`, the prefix sum array is:

```
Prefix Sum: [1, 3, 6, 10, 15]
```

Using this, we compute subarray sums efficiently:

| **i (Start)** | **j (End)** | **Subarray** | **Computed Sum (O(1))** |
|------|------|------|------|
| 0 | 0 | `[1]` | `prefix[0] = 1` |
| 0 | 1 | `[1,2]` | `prefix[1] = 3` |
| 0 | 2 | `[1,2,3]` | `prefix[2] = 6` |
| 1 | 2 | `[2,3]` | `prefix[2] - prefix[0] = 6 - 1 = 5` |
| 1 | 3 | `[2,3,4]` | `prefix[3] - prefix[0] = 10 - 1 = 9` |
| 2 | 4 | `[3,4,5]` | `prefix[4] - prefix[1] = 15 - 3 = 12` |

---

## **Time Complexity Analysis**
1. **Prefix sum computation:** `O(n)`
2. **Iterate over all subarrays:** `O(n²)`
3. **Compute sum in O(1) using prefix sum array**  
   **Total Complexity:** **O(n²)** (same as previous, but faster in practice)

---

## **When is this Useful?**
✅ **Great for problems involving sum queries of subarrays**  
✅ **Reduces repeated calculations, making it much faster than O(n³)**  
✅ **Useful in range sum problems like competitive programming questions**

---

## **Even Faster Approach? (Sliding Window / Kadane's Algorithm)**
For **maximum subarray sum**, we can use **Kadane’s Algorithm (O(n))**, which finds the **maximum sum subarray in a single pass**.
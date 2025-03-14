Here’s an **optimized version** of the program that reduces the time complexity from **O(n³) to O(n²)** by removing the innermost loop.

---

### **Optimized Code (O(n²))**
```cpp
#include <iostream>

using namespace std;

class Solution
{
public:
    void printAllSubArrays(int array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            string subarray = "";
            for (int j = i; j < size; j++)
            {
                subarray += to_string(array[j]); // Append element to the subarray string
                cout << subarray << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Solution().printAllSubArrays(arr, size);
}
```

---

## **Explanation of Optimized Code**
The key difference in this version is that it **eliminates the innermost loop** (`for (int k = i; k <= j; k++)`), which was previously responsible for printing subarrays.

### **Breakdown of Optimized Code**
1. **Outer Loop (Start Index - `i`)**  
   - Runs from `0` to `size - 1`.
   - Represents the **starting point** of the subarrays.

2. **Inner Loop (End Index - `j`)**  
   - Runs from `i` to `size - 1`.
   - Instead of using an additional loop for printing, it **builds the subarray incrementally** using a string.

3. **Subarray Storage (`subarray += to_string(array[j])`)**  
   - At each step, `array[j]` is **appended to a string**.
   - Printing happens **immediately**, eliminating an extra loop.

---

## **Example Execution**
For `arr = {1, 2, 3, 4, 5}`:

| **i (Start Index)** | **j (End Index)** | **Subarray Stored & Printed** |
|------|------|-------------------|
| 0 | 0 | `1` |
| 0 | 1 | `12` |
| 0 | 2 | `123` |
| 0 | 3 | `1234` |
| 0 | 4 | `12345` |
| 1 | 1 | `2` |
| 1 | 2 | `23` |
| 1 | 3 | `234` |
| 1 | 4 | `2345` |
| 2 | 2 | `3` |
| 2 | 3 | `34` |
| 2 | 4 | `345` |
| 3 | 3 | `4` |
| 3 | 4 | `45` |
| 4 | 4 | `5` |

### **Output**
```
1 12 123 1234 12345
2 23 234 2345
3 34 345
4 45
5
```

---

## **Time Complexity Analysis**
1. **Outer loop runs `O(n)` times**.
2. **Inner loop runs up to `O(n)` times for each `i`**.
3. **String concatenation is O(1) on average (amortized)**.

### **Final Complexity:**
- **O(n²) instead of O(n³)** 🚀

### **Space Complexity:**
- **O(1)** (no extra memory used apart from loop variables).

---

## **Final Thoughts**
✅ **Why is this better?**
- Eliminates **extra loop**.
- Reduces **time complexity** from O(n³) to **O(n²)**.
- Uses **incremental string building** instead of iterating over elements repeatedly.

❌ **When is it still inefficient?**
- If `n` is **very large**, an **O(n²)** approach is still slow.
- For **special cases like finding max subarrays**, algorithms like **Kadane’s Algorithm (O(n))** are preferable.
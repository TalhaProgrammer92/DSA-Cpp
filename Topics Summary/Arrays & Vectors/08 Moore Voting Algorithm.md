# Moore's Voting Algorithm
Moore's Voting Algorithm is an efficient algorithm used to find the **majority element** in an array. A majority element is an element that appears **more than ⌊n/2⌋ times** in an array of size `n`. This algorithm works in **O(n) time complexity** and **O(1) space complexity**, making it very efficient compared to other methods like sorting or using hash maps.

### **Algorithm Steps**
1. **Find a Candidate for Majority Element**  
   - Maintain a `candidate` variable to store a potential majority element.
   - Use a `count` variable to track its frequency.
   - Iterate through the array:
     - If `count` is 0, set `candidate` to the current element.
     - If the current element equals `candidate`, increment `count`.
     - Otherwise, decrement `count`.

2. **Verify the Candidate**  
   - Since the first step only finds a potential majority element, iterate again to confirm if it actually appears more than `⌊n/2⌋` times.

---

### **C++ Implementation**
```cpp
#include <iostream>
using namespace std;

// Function to find the majority element using Moore's Voting Algorithm
int findMajorityElement(int arr[], int n) {
    int candidate = -1, count = 0;

    // Step 1: Find potential majority element
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify if the candidate is actually a majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    return (count > n / 2) ? candidate : -1;  // Return -1 if no majority element exists
}

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int majorityElement = findMajorityElement(arr, n);
    if (majorityElement != -1)
        cout << "Majority Element: " << majorityElement << endl;
    else
        cout << "No Majority Element" << endl;

    return 0;
}
```

---

### **Time & Space Complexity**
- **Time Complexity:** `O(n)`, as we traverse the array twice.
- **Space Complexity:** `O(1)`, since we use only a few extra variables.

---

### **Key Points**
- Works only if a **majority element exists**.
- If no element appears more than `⌊n/2⌋` times, the algorithm will return `-1` (or an indication of no majority).
- Efficient compared to other methods like sorting (`O(n log n)`) or hash maps (`O(n)` space).
## 🔍 **What is Binary Search?**

**Binary Search** is a fast and efficient algorithm used to find an element in a **sorted array** or **list**. It follows a **divide-and-conquer** approach by repeatedly dividing the search interval in half.

Instead of checking every element (like linear search), binary search checks the **middle element** and then discards half of the search space depending on the comparison result.

---

## 📘 **How Binary Search Works (Theory)**

Given a **sorted array**, the algorithm:

1. Calculates the middle index:
   `mid = low + (high - low) / 2`
2. Compares the **target element** with `arr[mid]`:

   * If equal → element is found.
   * If target < `arr[mid]` → search in the **left half**.
   * If target > `arr[mid]` → search in the **right half**.
3. Repeat steps until:

   * The element is found.
   * Or the range becomes invalid (`low > high`) → element not found.

---

## ✅ **Practical Use Cases of Binary Search**

1. **Searching in a sorted database**:

   * E.g., Searching student records sorted by roll number.

2. **Finding square root / kth root** (within precision using binary search).

3. **Finding the first/last occurrence of an element** in a sorted array (modified binary search).

4. **Search in games**:

   * E.g., Guessing a number in a fixed range.

5. **Optimizing problems**:

   * Minimum/maximum values satisfying a condition.
   * E.g., Allocating minimum number of pages in books (binary search on answers).

---

## 🧠 **Binary Search Approaches in C++**

### 1. **Iterative Binary Search**

```cpp
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Element not found
}
```

🔹 **Pros**: Efficient and avoids stack overflow.
🔹 **Cons**: Slightly longer code due to loop control.

---

### 2. **Recursive Binary Search**

```cpp
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}
```

🔹 **Pros**: Cleaner and easier to write.
🔹 **Cons**: Uses extra stack space due to recursion.

---

### 3. **Optimized Variants**

Depending on the problem, binary search can be optimized:

* **Lower Bound** (first occurrence of a number):

```cpp
int lowerBound(int arr[], int n, int target) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low; // Or check if arr[low] == target
}
```

* **Binary Search on Answer**: Used for optimization problems like:

  * Allocate minimum pages, minimum capacity to ship packages, etc.

---

## 📊 **Time Complexity Analysis**

| Case         | Time Complexity | Explanation                            |
| ------------ | --------------- | -------------------------------------- |
| Best Case    | **O(1)**        | Element found at mid on first attempt. |
| Average Case | **O(log n)**    | Each step halves the search space.     |
| Worst Case   | **O(log n)**    | Search goes until 1 element is left.   |

🔹 **Space Complexity**:

* Iterative → **O(1)** (no extra space)
* Recursive → **O(log n)** due to call stack

---

## 🧪 **Example Usage:**

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 23;

    int index = binarySearch(arr, size, key);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
```

---

## 🧾 Summary

| Topic            | Details                                                   |
| ---------------- | --------------------------------------------------------- |
| Purpose          | Fast search in a sorted array                             |
| Approach         | Divide-and-conquer                                        |
| Input Condition  | Array must be **sorted**                                  |
| Time Complexity  | O(log n)                                                  |
| Space Complexity | O(1) or O(log n)                                          |
| Variants         | Iterative, Recursive, Lower/Upper Bound, Search on answer |

---

## 🧮 **Bubble Sort Algorithm in C++**

### 👉 **Idea:**

Bubble Sort works by **repeatedly swapping adjacent elements** if they are in the wrong order. It "bubbles" the largest (or smallest) element to the end of the array in each iteration.

---

## 📍 **C++ Code for Bubble Sort**

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	// Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
		// Inner loop for comparisons
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if elements are in wrong order
			if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```

---

## 🔍 **Working on Each Iteration**

Let’s trace this array:

```cpp
arr = {5, 2, 9, 1, 5, 6}
```

### Pass 1 (i = 0):

| Comparison | Swap? | Array after step |
| ---------- | ----- | ---------------- |
| 5 vs 2     | Yes   | 2 5 9 1 5 6      |
| 5 vs 9     | No    | 2 5 9 1 5 6      |
| 9 vs 1     | Yes   | 2 5 1 9 5 6      |
| 9 vs 5     | Yes   | 2 5 1 5 9 6      |
| 9 vs 6     | Yes   | 2 5 1 5 6 9      |

**9 has bubbled to the end.**

---

### Pass 2 (i = 1):

| Comparison | Swap? | Array after step |
| ---------- | ----- | ---------------- |
| 2 vs 5     | No    | 2 5 1 5 6 9      |
| 5 vs 1     | Yes   | 2 1 5 5 6 9      |
| 5 vs 5     | No    | 2 1 5 5 6 9      |
| 5 vs 6     | No    | 2 1 5 5 6 9      |

---

### Pass 3 (i = 2):

| Comparison | Swap? | Array after step |
| ---------- | ----- | ---------------- |
| 2 vs 1     | Yes   | 1 2 5 5 6 9      |
| 2 vs 5     | No    | 1 2 5 5 6 9      |
| 5 vs 5     | No    | 1 2 5 5 6 9      |

---

### Pass 4 (i = 3):

| Comparison | Swap? | Array after step |
| ---------- | ----- | ---------------- |
| 1 vs 2     | No    | 1 2 5 5 6 9      |
| 2 vs 5     | No    | 1 2 5 5 6 9      |

---

### Pass 5 (i = 4):

| Comparison | Swap? | Array after step |
| ---------- | ----- | ---------------- |
| 1 vs 2     | No    | 1 2 5 5 6 9      |

---

✅ Array is sorted!

---

## ⏳ **Time Complexity Analysis**

| Case        | Comparisons     | Swaps      | Complexity       |
| ----------- | --------------- | ---------- | ---------------- |
| **Best**    | No swaps needed | 0          | O(n) (Optimized) |
| **Average** | n(n-1)/2        | Some swaps | O(n²)            |
| **Worst**   | n(n-1)/2        | Many swaps | O(n²)            |

* Outer loop runs **(n-1)** times.
* Inner loop runs **(n-1)**, **(n-2)**, ..., 1 times → Sum = (n-1) + (n-2) + ... + 1 = **n(n-1)/2** comparisons.

### ❗ **If we add a flag to detect no swaps in a pass (optimized Bubble Sort)**:

* Best case (already sorted array) time = **O(n)**.

---

## 🧮 **Space Complexity**

* Bubble Sort is **in-place** (no extra arrays).
* Uses **O(1)** auxiliary space (for temp variable in swap).

---

## 📌 **Final Summary**

| Metric           | Bubble Sort (Standard) |
| ---------------- | ---------------------- |
| Best Time        | O(n) (optimized)       |
| Average Time     | O(n²)                  |
| Worst Time       | O(n²)                  |
| Space Complexity | O(1)                   |
| Stable?          | Yes                    |
| In-place?        | Yes                    |

---

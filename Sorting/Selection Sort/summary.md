## 🔷 **Selection Sort Algorithm**

### 📍 **Idea:**

* Selection Sort divides the array into two parts:

  * **Sorted** part (initially empty)
  * **Unsorted** part (initially the entire array)
* In each iteration:

  * Find the **smallest element** in the **unsorted** part.
  * Swap it with the **first element of the unsorted** part.
* Repeat until the array is sorted.

---

## 🧮 **Selection Sort Code in C++**

Here’s the **basic code** (similar to what you had):

```cpp
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}
```

---

## 📊 **Example Walkthrough**

Let’s sort this array:

```
arr = {4, 1, 5, 2, 3}
```

---

### **Pass 1 (i = 0)**

* Find the smallest from **\[4, 1, 5, 2, 3]**
* Smallest is **1** at index 1
* Swap **4** and **1**

Array:

```
1 4 5 2 3
```

---

### **Pass 2 (i = 1)**

* Find the smallest from **\[4, 5, 2, 3]**
* Smallest is **2** at index 3
* Swap **4** and **2**

Array:

```
1 2 5 4 3
```

---

### **Pass 3 (i = 2)**

* Find the smallest from **\[5, 4, 3]**
* Smallest is **3** at index 4
* Swap **5** and **3**

Array:

```
1 2 3 4 5
```

---

### **Pass 4 (i = 3)**

* Find the smallest from **\[4, 5]**
* Smallest is **4** at index 3
* Swap **4** and **4** (no change)

Array:

```
1 2 3 4 5
```

---

### **Pass 5 (i = 4)**

* Only one element left, no swaps needed.

✅ Final sorted array:

```
1 2 3 4 5
```

---

## 🏎️ **Time Complexity**

| Case         | Comparisons | Time Complexity |
| ------------ | ----------- | --------------- |
| Best Case    | n(n-1)/2    | **O(n²)**       |
| Average Case | n(n-1)/2    | **O(n²)**       |
| Worst Case   | n(n-1)/2    | **O(n²)**       |

* **Always** performs n(n-1)/2 comparisons (no early exit like Bubble Sort).

---

## 💾 **Space Complexity**

| Factor          | Space Used                                           |
| --------------- | ---------------------------------------------------- |
| Auxiliary Space | **O(1)** (in-place, only temp variable for swapping) |
| Total Space     | **O(1)**                                             |

---

## ✅ **Selection Sort Summary**

| Feature          | Selection Sort                                                        |
| ---------------- | --------------------------------------------------------------------- |
| Time Complexity  | O(n²)                                                                 |
| Space Complexity | O(1)                                                                  |
| Stable?          | ❌ (not stable unless modified)                                        |
| In-place?        | ✅ Yes                                                                 |
| Best Use Case    | Small datasets, or when swaps are expensive but comparisons are cheap |

---
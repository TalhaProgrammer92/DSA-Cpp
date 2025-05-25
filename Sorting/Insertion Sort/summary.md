## 🔷 **Insertion Sort Algorithm**

### 📍 **Idea:**

* Imagine sorting a **deck of cards in your hand**:

  * Pick one card (starting from the second), compare it to the ones before it, and **insert it at the correct position**.
* In Insertion Sort:

  * Start from index `1`.
  * For each element, **shift larger elements** to the right and insert the current element into the correct spot.
* Repeat for all elements.

---

## 🧮 **Insertion Sort Code in C++**

Here’s the basic code:

```cpp
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Element to insert
        int j = i - 1;

        // Shift elements to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

		// Insert key at correct position
        arr[j + 1] = key;
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

### 🔹 **Pass 1 (i = 1, key = 1)**

* Compare 1 with 4 (arr\[0])
* 4 > 1, so shift 4 to the right
* Insert 1 at position 0

Array:

```
1 4 5 2 3
```

---

### 🔹 **Pass 2 (i = 2, key = 5)**

* Compare 5 with 4 (arr\[1])
* 5 > 4, no shift
* Insert 5 at position 2 (already there)

Array:

```
1 4 5 2 3
```

---

### 🔹 **Pass 3 (i = 3, key = 2)**

* Compare 2 with 5 (arr\[2]) → shift 5
* Compare 2 with 4 (arr\[1]) → shift 4
* Compare 2 with 1 (arr\[0]) → 2 > 1 → stop

Insert 2 at position 1

Array:

```
1 2 4 5 3
```

---

### 🔹 **Pass 4 (i = 4, key = 3)**

* Compare 3 with 5 (arr\[3]) → shift 5
* Compare 3 with 4 (arr\[2]) → shift 4
* Compare 3 with 2 (arr\[1]) → 3 > 2 → stop

Insert 3 at position 2

Final Sorted Array:

```
1 2 3 4 5
```

---

## 🏎️ **Time Complexity**

| Case                        | Comparisons & Shifts          | Time Complexity      |
| --------------------------- | ----------------------------- | -------------------- |
| Best Case (sorted array)    | n-1 comparisons, 0 shifts     | **O(n)** (efficient) |
| Average Case                | \~ n²/4 comparisons & shifts  | **O(n²)**            |
| Worst Case (reverse sorted) | n(n-1)/2 comparisons & shifts | **O(n²)**            |

---

## 💾 **Space Complexity**

| Factor          | Space Used                                         |
| --------------- | -------------------------------------------------- |
| Auxiliary Space | **O(1)** (in-place, only one extra variable `key`) |
| Total Space     | **O(1)**                                           |

---

## 📝 **Insertion Sort Summary**

| Feature          | Insertion Sort                         |
| ---------------- | -------------------------------------- |
| Time Complexity  | O(n²) (worst), O(n) (best)             |
| Space Complexity | O(1)                                   |
| Stable?          | ✅ Yes                                  |
| In-place?        | ✅ Yes                                  |
| Best Use Case    | Nearly sorted arrays or small datasets |

---

### ✅ **Key Points:**

* Insertion Sort is **efficient for small or nearly sorted data**.
* It’s **stable** (preserves order of equal elements).
* **Best case is linear (O(n))**, unlike Selection Sort or Bubble Sort.

---
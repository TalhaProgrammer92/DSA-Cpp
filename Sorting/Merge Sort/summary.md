## 🔍 **Theoretical Overview**

### 🧠 **Concept**

* **Merge Sort** works by **dividing** the array into smaller sub-arrays, sorting those sub-arrays, and then **merging** them back together in a sorted manner.
* It recursively **splits** the array until each sub-array has only one element (base case).
* Then it **merges** these sorted sub-arrays step by step to form the final sorted array.

---

## 🧱 **Algorithm Structure**

### 1. `sort()` Function

* Responsible for the **divide** part.
* It recursively splits the array into two halves:

  ```cpp
  int mid = start + (end - start) / 2;
  sort(array, start, mid);     // Left half
  sort(array, mid + 1, end);   // Right half
  ```

### 2. `merge()` Function

* Responsible for the **conquer + combine** part.
* It takes two sorted sub-arrays (from `start` to `mid`, and from `mid+1` to `end`) and merges them into a single sorted array.

---

## 🧮 **Step-by-Step Working with Example**

Initial array:

```
[12, 31, 35, 8, 32, 17]
```

### ➤ Step 1: Recursive Splitting

``` pgsql
sort(array, 0, 5)
  → sort(array, 0, 2)
    → sort(array, 0, 1)
      → sort(array, 0, 0) → return
      → sort(array, 1, 1) → return
      → merge(0, 0, 1) → [12, 31]
    → sort(array, 2, 2) → return
    → merge(0, 1, 2) → [12, 31, 35]

  → sort(array, 3, 5)
    → sort(array, 3, 4)
      → sort(array, 3, 3) → return
      → sort(array, 4, 4) → return
      → merge(3, 3, 4) → [8, 32]
    → sort(array, 5, 5) → return
    → merge(3, 4, 5) → [8, 32, 17] → [8, 17, 32] after merging

→ Final merge(0, 2, 5)
  Merge [12, 31, 35] and [8, 17, 32]
  → [8, 12, 17, 31, 32, 35]
```

---

## 🔧 **merge() – Detailed Explanation**

Given two sorted ranges:

* `array[start..mid]` (left)
* `array[mid+1..end]` (right)

### Process:

1. Compare the first elements of each side.
2. Insert the smaller one into a temporary array.
3. Continue until one side is exhausted.
4. Append remaining elements from the non-exhausted side.
5. Copy `temp` back into original array from index `start`.

---

## ✅ Final Output

```
8 12 17 31 32 35
```

---

## Dry Run

### 🌀 **Splitting Phase**

| Call Level | Function Call  | Subarray                 | Action                        |
| ---------- | -------------- | ------------------------ | ----------------------------- |
| 1          | sort(0, 5)     | \[12, 31, 35, 8, 32, 17] | Divide into \[0–2] and \[3–5] |
| 2          | sort(0, 2)     | \[12, 31, 35]            | Divide into \[0–1] and \[2]   |
| 3          | sort(0, 1)     | \[12, 31]                | Divide into \[0] and \[1]     |
| 4          | sort(0, 0)     | \[12]                    | Return (base case)            |
| 4          | sort(1, 1)     | \[31]                    | Return (base case)            |
| 3          | merge(0, 0, 1) | \[12, 31]                | Merged → \[12, 31]            |
| 2          | sort(2, 2)     | \[35]                    | Return (base case)            |
| 2          | merge(0, 1, 2) | \[12, 31], \[35]         | Merged → \[12, 31, 35]        |

| Call Level | Function Call  | Subarray        | Action                      |
| ---------- | -------------- | --------------- | --------------------------- |
| 2          | sort(3, 5)     | \[8, 32, 17]    | Divide into \[3–4] and \[5] |
| 3          | sort(3, 4)     | \[8, 32]        | Divide into \[3] and \[4]   |
| 4          | sort(3, 3)     | \[8]            | Return (base case)          |
| 4          | sort(4, 4)     | \[32]           | Return (base case)          |
| 3          | merge(3, 3, 4) | \[8, 32]        | Merged → \[8, 32]           |
| 2          | sort(5, 5)     | \[17]           | Return (base case)          |
| 2          | merge(3, 4, 5) | \[8, 32], \[17] | Merged → \[8, 17, 32]       |

---

### 🔗 **Final Merge**

| Call Level | Function Call  | Subarray                    | Action                                |
| ---------- | -------------- | --------------------------- | ------------------------------------- |
| 1          | merge(0, 2, 5) | \[12, 31, 35], \[8, 17, 32] | Merged → **\[8, 12, 17, 31, 32, 35]** |

---

## 📌 Summary

| Property         | Value            |
| ---------------- | ---------------- |
| Time Complexity  | O(n log n)       |
| Space Complexity | O(n)             |
| Stable Sort?     | ✅ Yes            |
| Sorting Type     | Comparison-based |
| Technique        | Divide & Conquer |

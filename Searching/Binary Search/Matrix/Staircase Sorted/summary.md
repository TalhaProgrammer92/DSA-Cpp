## ✅ **Matrix Rules**

The matrix has:

* Rows sorted in **ascending order** (left to right).
* Columns sorted in **ascending order** (top to bottom).

Example matrix used:

```
[
  { 1,  4,  7, 11, 15},
  { 2,  5,  8, 12, 19},
  { 3,  6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
]
```

Target: `8`

---

## 🧠 **Key Idea**

Start searching from the **top-right corner** of the matrix. From there:

* If the value is **equal to the target**, return `true`.
* If the value is **greater than the target**, move **left** (decrease column).
* If the value is **less than the target**, move **down** (increase row).

This works because of the sorted nature of the matrix.

---

## 🔍 **Step-by-Step Flow**

### 1. **Initialization**

```cpp
Position start, end, mid;

// At bottom-right
end.row = matrix.size() - 1;
end.column = matrix[0].size() - 1;

// Start from top-right
mid.row = 0;
mid.column = end.column;
```

We define 3 positions:

* `start` (not used explicitly here)
* `end` = bottom-right corner
* `mid` = our **moving pointer**, initially at **top-right** (0, last column)

---

### 2. **Main Loop**

```cpp
while (mid.row <= end.row && mid.column >= 0)
```

This keeps `mid` inside matrix bounds.

Inside the loop:

```cpp
int value = matrix[mid.row][mid.column];
```

Then compare:

* If `value == target`: found! return `true`
* If `value > target`: move **left** → `mid.column--`
* If `value < target`: move **down** → `mid.row++`

This eliminates a **row or column on each step**, giving us **O(m + n)** time complexity.

---

## 🧪 **Example: Target = 8**

| Step | Position (row, col) | Value | Action   |
| ---- | ------------------- | ----- | -------- |
| 1    | (0, 4)              | 15    | Go left  |
| 2    | (0, 3)              | 11    | Go left  |
| 3    | (0, 2)              | 7     | Go down  |
| 4    | (1, 2)              | 8     | ✅ Found! |

---

## 🔧 **Helper Function**

```cpp
int get_value(Position &pos, vector<vector<int>> &matrix)
```

Returns the matrix value at a given position for cleaner code.

---

## 🧾 **Output**

```
Status: 1
```

Which means **true** (target exists in matrix).

---

## ✅ Summary

* The algorithm performs a **search from top-right**, moving **left or down** based on comparison.
* It avoids checking every element (unlike brute-force).
* **Time Complexity**: `O(m + n)` where `m` = rows, `n` = columns.
* Efficient for sorted matrices in both directions.
## 🔢 Example Matrix

We'll use the same rules:

* Rows sorted in ascending order.
* First number of each row > last number of previous row.

```cpp
vector<vector<int>> matrix = {
	{2, 4, 6, 8},
	{11, 13, 17, 19},
	{21, 24, 27, 30}
};
int target = 17;
```

---

## 🚀 Step-by-Step: Binary Search

### 🔹 Step 1: Matrix Overview

```
Row 0: [ 2,  4,  6,  8 ]
Row 1: [11, 13, 17, 19] ← target is here
Row 2: [21, 24, 27, 30]
```

---

### 🔹 Step 2: Binary Search to Find the Correct Row

* Initial:

  ```
  start = 0, end = 2 (total 3 rows)
  r_end = 3 (last column index)
  ```

* Compute:

  ```
  mid = (0 + 2) / 2 = 1
  ```

* Check if target fits in Row 1:

  ```
  matrix[1][0] = 11
  matrix[1][3] = 19

  11 ≤ 17 ≤ 19 → YES!
  ```

✅ So, search inside **Row 1**.

---

### 🔹 Step 3: Binary Search Inside Row 1: `[11, 13, 17, 19]`

* Initial:

  ```
  left = 0, right = 3
  ```

* First iteration:

  ```
  center = (0 + 3) / 2 = 1
  matrix[1][1] = 13

  13 < 17 → move right → left = 2
  ```

* Second iteration:

  ```
  center = (2 + 3) / 2 = 2
  matrix[1][2] = 17

  17 == 17 → ✅ Target found!
  ```

---

## 🧾 Final Output

```cpp
cout << exists_binary_search(matrix, 17); // prints 1 (true)
```

---

## 🔁 Recap of Binary Search Flow

| Step          | Variables                         | Action                            |
| ------------- | --------------------------------- | --------------------------------- |
| Find Row      | `start = 0`, `end = 2`, `mid = 1` | Target fits in row → search there |
| Search in Row | `left = 0`, `right = 3`           | Binary search in row\[1]          |
| Narrow Down   | `center = 1`, value = 13          | 13 < 17 → go right                |
| Found Target  | `center = 2`, value = 17          | ✅ Match                           |
---
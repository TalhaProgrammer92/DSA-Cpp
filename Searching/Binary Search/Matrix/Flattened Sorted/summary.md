### 🔢 **Matrix Structure Rule**

The matrix follows **special rules**:

* Each row is sorted in ascending order.
* The first integer of each row is **greater than the last integer of the previous row**.

So, visually, it looks like this:

```cpp
vector<vector<int>> matrix = {
	{1, 3, 5, 7},
	{10, 11, 16, 20},
	{23, 30, 34, 60}
};
```

This kind of matrix behaves like a **flattened sorted array** when viewed linearly.

---

## 🧪 Method 1: Brute-Force Search

### 🔍 Function: `exists_brute_froce`

**Goal:** Loop through every element in the matrix and check if it matches the target.

### 📋 Steps:

1. Loop through each **row** of the matrix.
2. For each **row**, loop through each **element**.
3. Compare each element with the `target`.
4. If found, return `true`; if loop completes with no match, return `false`.

### ✅ Pros:

* Very simple and easy to understand.

### ❌ Cons:

* **Time Complexity:** O(m × n), where `m` is number of rows and `n` is number of columns.
* Inefficient for large matrices.

### 🔧 Example:

```cpp
exists_brute_froce(matrix, 34); // returns true
```

---

## 🚀 Method 2: Binary Search

### 🔍 Function: `exists_binary_search`

**Goal:** Use binary search to locate the target efficiently using matrix properties.

---

### 🔧 Key Matrix Properties Used:

* Entire matrix can be imagined as a **sorted 1D array**.
* Instead of flattening it, we use **two binary searches**:

  1. First binary search to **find the correct row**.
  2. Second binary search to **search within that row**.

---

### 📋 Steps:

#### 🔹 Step 1: Find the Correct Row

* Set `start = 0`, `end = total_rows - 1`.
* Use binary search on **rows**:

  * For middle row `mid`, check if `target` is in the range:

    ```
    matrix[mid][0] <= target <= matrix[mid][last_column]
    ```
  * If true, we search inside this row.
  * If `target` is smaller, move `end = mid - 1`.
  * If `target` is larger, move `start = mid + 1`.

#### 🔹 Step 2: Search Inside the Row

* Perform regular binary search on `matrix[mid]`:

  * Set `left = 0`, `right = last_column`.
  * If `matrix[mid][center] == target`, return `true`.
  * If target is smaller, move `right = center - 1`.
  * If larger, move `left = center + 1`.

#### 📉 Time Complexity:

* **O(log m + log n)** = **O(log (m × n))**, much faster.

### 🔧 Example:

```cpp
exists_binary_search(matrix, 34); // returns true
```

---

## 🧪 Output

### 👇 Main Function:

```cpp
int main() {
	vector<vector<int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};
	int target = 34;

	cout << "Status: " << exists_brute_froce(matrix, target) << endl;
	cout << "Status: " << exists_binary_search(matrix, target) << endl;
}
```

### 🖨️ Output:

```
Status: 1
Status: 1
```

(`1` means `true`, the target was found.)

---

## ✅ Summary Table

| Method        | Steps                                 | Time Complexity  | Space Complexity | Efficient? |
| ------------- | ------------------------------------- | ---------------- | ---------------- | ---------- |
| Brute-Force   | Linear scan each row and element      | O(m × n)         | O(1)             | ❌ No       |
| Binary Search | Binary search row, then search in row | O(log m + log n) | O(1)             | ✅ Yes      |
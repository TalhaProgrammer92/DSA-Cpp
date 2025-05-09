## ✅ **Algorithm (C++-style pseudocode)**

```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
```

---

## ⏱️ **Time Complexity Analysis**

### 1. **Outer loop:**

Runs from `i = 0` to `n - 2` → **(n - 1) iterations**

### 2. **Inner loop:**

For each `i`, inner loop runs from `j = i + 1` to `n - 1`.
Total comparisons:

* For i = 0 → n - 1 comparisons
* For i = 1 → n - 2 comparisons
* ...
* For i = n-2 → 1 comparison

🔢 **Total comparisons:**

$$
(n - 1) + (n - 2) + \dots + 1 = \frac{n(n - 1)}{2}
$$

So,
✅ **Worst-case time complexity:**

$$
O(n^2)
$$

✅ **Best-case time complexity:**
Still **O(n²)** (no early exit or optimization even if array is sorted)

✅ **Average-case time complexity:**

$$
O(n^2)
$$

---

## 🧠 **Space Complexity Analysis**

* Uses only a few extra variables (`minIndex`, `i`, `j`, temporary variable for `swap`)
* No recursion or extra arrays used

✅ **Space Complexity:**

$$
O(1) \quad \text{(in-place sorting)}
$$

---

### ✅ Final Answer:

| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Best Case    | O(n²)           | O(1)             |
| Average Case | O(n²)           | O(1)             |
| Worst Case   | O(n²)           | O(1)             |

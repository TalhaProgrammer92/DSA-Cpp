## 🔥 QUICK SORT THEORY

### 📌 1. **What is Quick Sort?**

Quick Sort is a **Divide and Conquer** algorithm:

* It picks a **pivot** element.
* **Partitions** the array so elements **≤ pivot go left**, elements **> pivot go right**.
* Then it **recursively** sorts the left and right parts.

It doesn’t use extra arrays — it sorts **in-place** (no memory wastage).

---

### 📌 2. **Partition Logic**

```cpp
int pivot = array[end];
```

* Pick the **last element** as pivot.
* Compare every element from `start` to `end - 1` with this pivot.
* If it's ≤ pivot → move it to the left side using a swap.

📌 **Partition function:**

```cpp
int partition(vector<int> &array, int start, int end)
{
	int pivot = array[end], index = start - 1;

	for (int i = start; i < end; i++)
		if (array[i] <= pivot)
			swap(array[i], array[++index]);

	swap(array[end], array[++index]); // place pivot in correct position

	return index;
}
```

📌 **Example:**

```cpp
vector<int> array = {1, 4, 2, 3, 9, 5, 7, 6, 8, 0};
```

* First call: `start = 0`, `end = 9`
* Pivot = `array[9] = 0`

Loop runs from i = 0 to 8, and all values are > 0, so no swaps happen.
At the end, pivot `0` is placed at index `0`. Partition returns `0`.

New recursive calls:

* `sort(array, 0, -1)` → base case.
* `sort(array, 1, 9)` → repeat again.

---

### 📌 3. **Recursive Sort Logic**

```cpp
void sort(vector<int> &array, int start, int end)
{
	if (start < end)
	{
		int pivot_index = partition(array, start, end);
		sort(array, start, pivot_index - 1);   // Left part
		sort(array, pivot_index + 1, end);     // Right part
	}
}
```

It continues until each part of the array is sorted.

---

### ✅ Example Flow (Partial)

Let's trace the first few steps:

```
Unsorted: [1, 4, 2, 3, 9, 5, 7, 6, 8, 0]

→ pivot = 0
→ partitioned: [0, 4, 2, 3, 9, 5, 7, 6, 8, 1]
→ pivot index = 0

Now recursive calls:
- sort(0, -1) → base case
- sort(1, 9)
```

Next pivot = 1, it continues sorting the right side.

Eventually, you get:

```
Sorted: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

---

## ⏱ TIME COMPLEXITY

Let `n` = number of elements

| Case        | Time Complexity | Explanation                                                           |
| ----------- | --------------- | --------------------------------------------------------------------- |
| **Best**    | O(n log n)      | Pivot divides array into equal halves each time.                      |
| **Average** | O(n log n)      | On average, random partitions are balanced.                           |
| **Worst**   | O(n²)           | Bad pivots (e.g., already sorted array), all elements go to one side. |

### ⚠️ Pivot choice: `array[end]` (last element)

* This works great on **random arrays**.
* But gives **worst case** on sorted arrays (`{1, 2, 3, 4}`).

---

## 💾 SPACE COMPLEXITY

| Resource            | Complexity                   | Why?                |
| ------------------- | ---------------------------- | ------------------- |
| **Auxiliary stack** | O(log n) average, O(n) worst | Recursive calls     |
| **In-place array**  | O(1)                         | No extra array used |

So overall:

```
Time:    O(n log n) avg, O(n²) worst
Space:   O(log n) avg, O(n) worst (stack)
```

---

## ✅ Summary

| Feature               | Details                     |
| --------------------- | --------------------------- |
| **Algorithm**         | Quick Sort (by reference)   |
| **Pivot**             | Last element (`array[end]`) |
| **Sorting**           | In-place using recursion    |
| **Best/Average Time** | `O(n log n)`                |
| **Worst Time**        | `O(n²)`                     |
| **Space (extra)**     | `O(1)`                      |
| **Space (stack)**     | `O(log n)` avg              |

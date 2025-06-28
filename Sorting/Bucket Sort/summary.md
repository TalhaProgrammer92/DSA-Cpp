## 🔁 **Dry Run**

Input:

```cpp
float arr[] = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
int n = 6;
```

### Step 1: Create `n` empty buckets

```cpp
vector<float> buckets[6]; // An array of 6 vectors
```

### Step 2: Distribute elements into buckets using `int(n * arr[i])`

| i | arr\[i] | index = int(6 \* arr\[i]) | Bucket\[index] After Insertion      |
| - | ------- | ------------------------- | ----------------------------------- |
| 0 | 0.897   | int(5.382) → 5            | buckets\[5] = {0.897}               |
| 1 | 0.565   | int(3.39) → 3             | buckets\[3] = {0.565}               |
| 2 | 0.656   | int(3.936) → 3            | buckets\[3] = {0.565, 0.656}        |
| 3 | 0.123   | int(0.738) → 0            | buckets\[0] = {0.123}               |
| 4 | 0.665   | int(3.99) → 3             | buckets\[3] = {0.565, 0.656, 0.665} |
| 5 | 0.343   | int(2.058) → 2            | buckets\[2] = {0.343}               |

Now, the buckets look like:

```
buckets[0]: 0.123
buckets[1]: empty
buckets[2]: 0.343
buckets[3]: 0.565, 0.656, 0.665
buckets[4]: empty
buckets[5]: 0.897
```

### Step 3: Sort Each Bucket

Using `std::sort()`:

* bucket\[0]: already sorted
* bucket\[2]: already sorted
* bucket\[3]: becomes \[0.565, 0.656, 0.665]
* Others: empty or single element

### Step 4: Concatenate all buckets

Final array after copying elements:

```
arr = [0.123, 0.343, 0.565, 0.656, 0.665, 0.897]
```

✅ Sorted successfully!

---

## ⏱️ Time Complexity

Let:

* `n` = number of elements
* `k` = number of buckets (here, `k = n`)

### Best Case (Uniformly distributed input):

* Distributing elements: O(n)
* Sorting individual buckets: If each bucket has ≈1 element → O(1) per bucket
* Total sorting: O(k × 1 log 1) = O(n × 0) = O(n)
* Concatenating: O(n)

**✅ Best Time: O(n)**

### Average Case:

* Elements are evenly distributed across buckets
* Sorting m elements per bucket (m ≈ constant)
* `O(n + n × log(n/k)) = O(n + n × log(n))` (if k is a constant fraction of n)

**✅ Average Time: O(n + n log n) → O(n log n)**

### Worst Case (All elements go into one bucket):

* Sorting one bucket with `n` elements: O(n log n)
* Distributing + concatenating: O(n)

**❌ Worst Time: O(n log n)**

---

## 🧠 Space Complexity

We use:

* `n` buckets (vectors) → Each element is copied once
* Total space = input array + buckets

**✅ Space Complexity: O(n)** (extra space for buckets)

---

## 🔚 Summary

| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Best Case    | O(n)            | O(n)             |
| Average Case | O(n log n)      | O(n)             |
| Worst Case   | O(n log n)      | O(n)             |
### 🟥 **O(1) – Constant Time**

🔹 **Definition:** Time doesn’t increase with input size.
🔹 **Example:**

```cpp
int getFirst(int arr[]) {
    return arr[0];
}
```

➡️ Always takes the same time, no matter how big the array is.

🔹 **Another example:**
**Find sum of first `n` natural numbers using formula:**

```cpp
int sum = n * (n + 1) / 2;
```

➡️ Just one formula – runs in **constant time**.

---

### 🟩 **O(log n) – Logarithmic Time**

🔹 **Definition:** Time grows slowly even as input grows.
🔹 **Example:**
**Binary Search:**

```cpp
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

➡️ Cuts the search space in half every step.

---

### 🟦 **O(n) – Linear Time**

🔹 **Definition:** Time grows directly with input size.
🔹 **Example:**
**Find sum of elements in array:**

```cpp
int sum = 0;
for(int i = 0; i < n; i++) {
    sum += arr[i];
}
```

➡️ One step per element.

---

### 🟧 **O(n log n) – Linearithmic Time**

🔹 **Definition:** A mix of linear and logarithmic time.
🔹 **Example:**
**Merge Sort or Quick Sort average case:**

```cpp
void mergeSort(...) { ... }
```

➡️ Divides array (log n) and merges (n).

---

### 🟨 **O(n²) – Quadratic Time**

🔹 **Definition:** Time grows with square of input size.
🔹 **Example:**
**Print all pairs of array elements:**

```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        cout << arr[i] << ", " << arr[j] << endl;
    }
}
```

➡️ Nested loop for each element pair.

---

### 🟪 **O(2ⁿ) – Exponential Time**

🔹 **Definition:** Time doubles with each increase in input.
🔹 **Example:**
**Fibonacci using naive recursion:**

```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

➡️ Horribly slow for large `n`.

---

### 🟥 **O(n!) – Factorial Time**

🔹 **Definition:** Time grows factorially (brutal).
🔹 **Example:**
**Generate all permutations of a string:**

```cpp
void permute(string s, int l, int r) {
    if(l == r) cout << s << endl;
    else {
        for(int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l+1, r);
            swap(s[l], s[i]); // backtrack
        }
    }
}
```

➡️ Grows insanely fast, only used for small inputs.

---

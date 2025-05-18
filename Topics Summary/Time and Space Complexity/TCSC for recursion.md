Calculating **time** and **space complexity** for **recursive algorithms** requires a solid understanding of how recursion works, including the **number of recursive calls** and **memory usage per call**. Here's a step-by-step explanation with **examples** to make things crystal clear.

---

## 🔁 GENERAL STRATEGY

### 🔸 Time Complexity (T(n))

1. **Count the number of recursive calls**.
2. **Set up a recurrence relation**, based on how the function reduces the problem.
3. **Solve the recurrence relation** using:

   * Substitution
   * Recursion Tree
   * Master Theorem (for divide-and-conquer)

### 🔸 Space Complexity

1. Count **maximum depth of recursion stack**.
2. Consider **extra memory** used at each level (arrays, variables, etc.).

---

## ✅ EXAMPLE 1: Factorial

```cpp
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

### 🔹 Time Complexity

* One recursive call per `n` until 0.
* **T(n) = T(n - 1) + O(1)**
* Solving: T(n) = O(n)

### 🔹 Space Complexity

* Max depth = `n` calls on call stack.
* Space = O(n)

---

## ✅ EXAMPLE 2: Fibonacci (Naive Recursive)

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

### 🔹 Time Complexity

* Each call spawns 2 new calls:

  * T(n) = T(n-1) + T(n-2) + O(1)
* This gives **exponential growth**:

  * **T(n) = O(2ⁿ)** (approximately)

### 🔹 Space Complexity

* Max depth = `n` (due to one branch reaching down to `fib(0)` or `fib(1)`)
* So, **Space = O(n)**

---

## ✅ EXAMPLE 3: Binary Search (Recursive)

```cpp
int binarySearch(int arr[], int l, int r, int x) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (x < arr[mid]) return binarySearch(arr, l, mid - 1, x);
    else return binarySearch(arr, mid + 1, r, x);
}
```

### 🔹 Time Complexity

* Problem size reduces by half every time:

  * **T(n) = T(n/2) + O(1)**
* Use Master Theorem:

  * a = 1, b = 2, d = 0 ⇒ **O(log n)**

### 🔹 Space Complexity

* Max depth = log(n) recursive calls
* So, **Space = O(log n)**

---

## ✅ EXAMPLE 4: Merge Sort

```cpp
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
```

### 🔹 Time Complexity

* Divide into 2 parts, merge takes linear time
* Recurrence: **T(n) = 2T(n/2) + O(n)**
* Master Theorem: a = 2, b = 2, d = 1 → **O(n log n)**

### 🔹 Space Complexity

* Recursion depth = log n
* If `merge` uses a temp array: O(n)
* So, **Space = O(n)** (auxiliary array) or **O(log n)** (if in-place merge)

---

## 🧠 TIPS TO REMEMBER

| Pattern                                 | Time Complexity | Space Complexity              |
| --------------------------------------- | --------------- | ----------------------------- |
| Tail recursion                          | Often O(n)      | O(n) stack (unless optimized) |
| Divide & Conquer                        | O(n log n)      | O(log n)                      |
| Exponential recursion (e.g., Fibonacci) | O(2ⁿ)           | O(n)                          |
| Memoized recursion                      | O(n)            | O(n)                          |

---

## ✅ **What is Recursion?**

A function that **calls itself** until a **base condition** is met.

---

## 🔍 **General Approach to Analyzing Recursion**

1. **Write the recurrence relation.**
2. **Solve the recurrence** using substitution or recursion tree.
3. **Count auxiliary space** (e.g., call stack memory).

---

## 📘 **Example 1: Factorial Function**

```cpp
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

### 🔹 Step-by-Step Time Analysis:

* For `n`, it makes **1 call to `n - 1`**, which makes another, until it reaches 0.
* Total recursive calls = `n + 1` (including base case)

🔁 **Recurrence Relation:**

$$
T(n) = T(n - 1) + O(1)
$$

🔧 **Solution:**

$$
T(n) = O(n)
$$

### 🔹 Space Complexity:

Each recursive call waits on the stack →
So, **stack depth** = `n`

✅ **Time: O(n)**
✅ **Space: O(n)** (due to call stack)

---

## 📘 **Example 2: Fibonacci (Naive)**

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

### 🔹 Step-by-Step Time Analysis:

* Tree-like structure.
* Each call spawns **two new calls** until base case.

🔁 **Recurrence Relation:**

$$
T(n) = T(n - 1) + T(n - 2) + O(1)
$$

🔧 **Solution:**

$$
T(n) = O(2^n)
$$

### 🔹 Space Complexity:

* Max call depth is `n`

✅ **Time: O(2ⁿ)**
✅ **Space: O(n)**

---

## 📘 **Example 3: Tail Recursion (Optimizable)**

```cpp
int sumTail(int n, int acc = 0) {
    if (n == 0) return acc;
    return sumTail(n - 1, acc + n);
}
```

* This is **tail recursive**, and compilers can **optimize** it to **O(1) space**.
* Same number of calls as normal recursion.

✅ **Time: O(n)**
✅ **Space: O(1)** (if optimized)

---

## 🧠 **Summary Table**

| Function Type        | Time Complexity | Space Complexity     |
| -------------------- | --------------- | -------------------- |
| Factorial (basic)    | O(n)            | O(n)                 |
| Fibonacci (naive)    | O(2ⁿ)           | O(n)                 |
| Tail Recursion (sum) | O(n)            | O(1) \[if optimized] |

---

## 📘 Fibonacci Recursive Function

```cpp
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

---

## 🧠 Step-by-Step Time Complexity

Each call makes **two more calls**, so the structure is a **binary tree**.

### 🔁 Recurrence Relation:

$$
T(n) = T(n - 1) + T(n - 2) + O(1)
$$

This grows **exponentially**, and the number of calls doubles roughly every level.

### 🔧 Solving the Recurrence:

The height of the recursion tree is `n`, and at each level, the number of calls doubles ⇒

$$
T(n) = O(2^n)
$$

---

## 🧮 Space Complexity

Space comes from the **maximum call stack depth** (which is **`n`** in worst case).

✅ **Time Complexity: O(2ⁿ)**
✅ **Space Complexity: O(n)**

---

## 🌲 Recursion Tree for `fib(5)` (simplified)

```
             fib(5)
           /        \
       fib(4)       fib(3)
      /     \       /     \
   fib(3)  fib(2) fib(2)  fib(1)
   /   \    / \    / \
fib(2) fib(1) fib(1) fib(0) ...
 /  \
fib(1) fib(0)
```

* Many **duplicate subproblems** (like `fib(3)`, `fib(2)`).
* Can be optimized with **memoization** or **dynamic programming**.

---

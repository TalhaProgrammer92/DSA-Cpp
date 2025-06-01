## 🌟 What is STL in C++?

**STL** stands for **Standard Template Library**.
It is a **collection of classes and functions** that help you manage **data structures** and **algorithms** easily.

It saves you from writing code from scratch for common tasks like:

* Sorting
* Searching
* Working with lists, maps, stacks, etc.

In short:
➡ **STL = Pre-written, reusable code for data structures + algorithms.**

---

## 🌲 Main Components of STL

There are **three main parts** of STL:

| **Component**  | **What it is**                                  | **Examples**                               |
| -------------- | ----------------------------------------------- | ------------------------------------------ |
| **Containers** | Data structures that store data                 | `vector`, `list`, `deque`, `map`, `set`    |
| **Algorithms** | Functions that perform operations on containers | `sort()`, `find()`, `reverse()`, `count()` |
| **Iterators**  | Pointers that allow traversal of containers     | `begin()`, `end()`, `++`, `--`             |

---

## 🔍 Let's Understand Each Component Briefly

### 1️⃣ **Containers** – *Data structures for storing data.*

* **Sequence Containers** – Linear data

  * `vector`, `list`, `deque`
* **Associative Containers** – Key-value pairs (like maps in Python)

  * `map`, `set`, `multimap`, `multiset`
* **Container Adaptors** – Special containers

  * `stack`, `queue`, `priority_queue`

### 2️⃣ **Algorithms** – *Ready-made functions to process data.*

* Sorting: `sort()`
* Searching: `find()`
* Counting: `count()`
* Reversing: `reverse()`
* Many more!

### 3️⃣ **Iterators** – *Used to move through the elements.*

* Think of iterators as **pointers** that can traverse containers.
* Example:

  ```cpp
  vector<int> v = {1, 2, 3};
  for (auto it = v.begin(); it != v.end(); ++it) {
      cout << *it << " ";
  }
  ```

---

## 🚀 Why Use STL?

✅ Saves time (no need to write common code from scratch)
✅ Reduces bugs (well-tested library)
✅ Faster development (focus on logic, not implementation)
✅ Efficient algorithms

---

## 📝 Example: Using a Vector with STL

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 3, 8, 1};

    sort(v.begin(), v.end());  // Using STL algorithm

    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
```

**Output:**

```
1 3 5 8
```
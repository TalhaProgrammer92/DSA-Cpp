### 🌟 What is a `vector` in C++?

A **vector** is a **dynamic array** from the Standard Template Library (STL). It automatically **resizes** itself when you add or remove elements, unlike arrays where the size is fixed.

Think of it as an **array with superpowers**:

* You can add, remove, access, or modify elements easily.
* It manages memory and resizing behind the scenes.

Let’s break it down with **fresh examples**!

---

## 📦 1️⃣ **Declaring a vector**

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create an empty vector of integers
    vector<int> numbers;

    // Create a vector with initial values
    vector<string> fruits = {"apple", "banana", "cherry"};

    // Create a vector with same value repeated
    vector<double> prices(5, 9.99);  // 5 elements, each 9.99

    return 0;
}
```

---

## ➕ 2️⃣ **Adding Elements (`push_back`)**

```cpp
vector<int> numbers;

numbers.push_back(10);  // Add 10
numbers.push_back(20);  // Add 20
numbers.push_back(30);  // Add 30
```

This resizes the vector **automatically**.

---

## 📐 3️⃣ **Size vs Capacity**

```cpp
cout << "Size: " << numbers.size() << endl;
cout << "Capacity: " << numbers.capacity() << endl;
```

* **Size** = Number of elements you added.
* **Capacity** = How much memory is reserved (internal optimization).
  Capacity may be larger than size because vectors grow in chunks.

---

## 🔑 4️⃣ **Accessing Elements**

```cpp
cout << numbers[1] << endl;       // Access like array (No bounds checking)
cout << numbers.at(1) << endl;    // Safer, throws exception if out of range
cout << numbers.front() << endl;  // First element
cout << numbers.back() << endl;   // Last element
```

---

## ✂️ 5️⃣ **Removing Elements**

```cpp
// Remove element at position 1
numbers.erase(numbers.begin() + 1);  

// Remove a range of elements
numbers.erase(numbers.begin() + 0, numbers.begin() + 2);  
```

---

## ➕ 6️⃣ **Inserting Elements**

```cpp
numbers.insert(numbers.begin() + 1, 50);  // Insert 50 at index 1
```

---

## 🔄 7️⃣ **Copying Vectors**

```cpp
vector<int> copy_numbers(numbers);  // Copy constructor

// Or
vector<int> another_copy = numbers; // Copy assignment
```

---

## 🧹 8️⃣ **Clearing All Elements**

```cpp
numbers.clear();
```

---

## 📌 Example Code: My Own Style

Here’s a small, clear example combining these:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> data = {1, 2, 3};  // Initialize

    data.push_back(4);             // Add element

    cout << "Size: " << data.size() << endl;
    cout << "Capacity: " << data.capacity() << endl;

    cout << "First: " << data.front() << ", Last: " << data.back() << endl;

    data.insert(data.begin() + 2, 99); // Insert 99 at index 2

    data.erase(data.begin() + 1); // Remove element at index 1

    data.clear(); // Remove all elements

    cout << "After clear, size: " << data.size() << endl;

    return 0;
}
```

---

✅ **In a nutshell**:

* Vectors grow/shrink automatically.
* Use `push_back`, `insert`, `erase`, `clear` for dynamic manipulation.
* Safer access with `.at()`, `.front()`, `.back()`.
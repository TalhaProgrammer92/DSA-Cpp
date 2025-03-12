# Arrays in C++
### **Arrays in C++ as a Data Structure**  

#### **What is an Array?**  
An **array** in C++ is a **fixed-size, contiguous** collection of elements of the **same data type** stored in sequential memory locations. It allows efficient access using an **index**.  

---

### **Characteristics of Arrays**  
✔ **Fixed Size** – Once declared, the size cannot change.  
✔ **Contiguous Memory** – Elements are stored in adjacent memory locations.  
✔ **Efficient Access** – Elements can be accessed in **O(1) time** using an index.  
✔ **Same Data Type** – All elements must be of the same type (int, float, char, etc.).  

---

### **Declaration and Initialization in C++**  
#### **1. Declaration**
```cpp
int arr[5]; // Declares an array of size 5
```

#### **2. Initialization**  
```cpp
int arr[5] = {10, 20, 30, 40, 50}; // Initializes with values
```
or  
```cpp
int arr[] = {10, 20, 30, 40, 50}; // Compiler automatically sets size
```

---

### **Accessing Elements**  
Elements are accessed using an **index (0-based indexing in C++)**.  
```cpp
cout << arr[0];  // Outputs: 10
```

---

### **Types of Arrays**  
1. **One-Dimensional Array**  
   ```cpp
   int arr[3] = {1, 2, 3};
   ```
2. **Multi-Dimensional Array (2D Array Example)**  
   ```cpp
   int matrix[2][2] = {{1, 2}, {3, 4}};
   cout << matrix[1][0]; // Outputs: 3
   ```
3. **Dynamic Arrays (Using `new`)**  
   ```cpp
   int* dynArr = new int[5]; // Dynamically allocated array
   ```

---

### **Advantages of Arrays in C++**  
✔ **Fast Access** – Direct access using an index (**O(1)**).  
✔ **Cache Friendly** – Stored in contiguous memory, improving performance.  
✔ **Easy Traversal** – Can use loops to iterate over elements.  

---

### **Disadvantages of Arrays in C++**  
❌ **Fixed Size** – Cannot resize after declaration.  
❌ **Insertion/Deletion is Costly** – Shifting elements takes **O(n)** time.  
❌ **Wastage of Memory** – Unused spaces still occupy memory.  

---

### **Common Operations on Arrays (Time Complexity)**  
| Operation       | Time Complexity |
|----------------|---------------|
| Access (index) | **O(1)** |
| Traversal      | **O(n)** |
| Insertion at end | **O(1)** (if space available) |
| Insertion at beginning/middle | **O(n)** |
| Deletion from end | **O(1)** |
| Deletion from middle | **O(n)** |

---

### **Example: Traversing an Array in C++**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```
**Output:**  
```
Array elements: 10 20 30 40 50
```

---

### **Conclusion**  
Arrays in C++ are a fundamental data structure that allows **efficient storage and retrieval** of elements. However, their **fixed size and costly insertion/deletion** make **dynamic data structures** (like vectors and linked lists) more flexible alternatives in many cases.
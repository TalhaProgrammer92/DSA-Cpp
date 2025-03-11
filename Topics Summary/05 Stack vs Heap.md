# **Stack vs. Heap in C++ (DSA Context)**

## 1. **Stack Memory**  
   - Stores **local variables** and function call data.  
   - **Faster** allocation/deallocation (LIFO structure).  
   - **Limited** size; can cause **stack overflow** if overused.  

   **Example:**  
   ```cpp
   void func() {
       int x = 10; // Stored in stack
   }
   ```

## 2. **Heap Memory**  
   - Used for **dynamic memory allocation** (`new`, `malloc()`).  
   - **Slower**, but more **flexible** (size not fixed).  
   - Must be **manually deallocated** to prevent memory leaks.  

   **Example:**  
   ```cpp
   int* ptr = new int(10); // Allocated in heap
   delete ptr; // Freeing heap memory
   ```

## **Relation to DSA:**  
- **Stack** is used for function recursion, **DFS (Depth First Search)**, and maintaining function call stacks.  
- **Heap** is used for **linked lists, trees, graphs**, and data structures requiring dynamic sizing.
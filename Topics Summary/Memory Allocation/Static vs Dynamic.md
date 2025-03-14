# Static vs. Dynamic Memory Allocation in C++

## 1. **Static Memory Allocation**  
   - Memory is allocated at **compile-time**.  
   - Fixed size; cannot be resized during execution.  
   - Faster but less flexible.  

   **Example:**  
   ```cpp
   int arr[10]; // Allocates memory for 10 integers at compile-time
   ```

## 2. **Dynamic Memory Allocation**  
   - Memory is allocated at **runtime** using `new` or `malloc()`.  
   - Can be resized and freed when no longer needed.  
   - Slower but more flexible.  

   **Example:**  
   ```cpp
   int* arr = new int[10]; // Allocates memory for 10 integers at runtime
   delete[] arr; // Frees allocated memory
   ```

## Usage
In **DSA**, dynamic allocation is crucial for **linked lists, trees, graphs**, etc., as the size of data structures is not known beforehand.
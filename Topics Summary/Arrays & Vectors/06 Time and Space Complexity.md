# **Time and Space Complexity in DSA (C++)**  

## 1. **Time Complexity**  
   - Measures **execution time** of an algorithm based on input size (**n**).  
   - Expressed using **Big-O notation** (e.g., O(1), O(n), O(log n), O(n²)).  

   **Example:**  
   ```cpp
   // O(n) complexity
   for(int i = 0; i < n; i++) {
       cout << i << " ";
   }
   ```
   - If `n = 10⁶`, an **O(n²) algorithm** may be too slow, whereas **O(n log n)** is more efficient.

## 2. **Space Complexity**  
   - Measures **memory usage** of an algorithm.  
   - Includes **input storage, auxiliary space, and recursion stack size**.  

   **Example:**  
   ```cpp
   int arr[n]; // O(n) space
   ```
   - Recursion increases space complexity due to **stack frames**.  

## **Constraints in Competitive Programming**  
- **n ≤ 10⁶ → O(n log n) or O(n) is feasible.**  
- **n ≤ 10⁸ → O(n) or O(1) is preferred (1s time limit).**  
- **Recursion depth ~ 10⁴ may cause stack overflow.**
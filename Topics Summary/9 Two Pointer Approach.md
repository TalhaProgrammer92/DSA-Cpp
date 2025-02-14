# Two Pointer Approach
## **Two Pointer Approach**  
The **Two Pointer Approach** is an optimization technique used in problems involving searching, sorting, and linked lists. It involves using two pointers to traverse an array or list efficiently, reducing the time complexity compared to brute force methods.  

## **Real-Life Example**  
Imagine two people walking toward each other from opposite ends of a straight road. They will meet at some point in the middle. Similarly, in programming, we use two pointers—one starting from the beginning and the other from the end—to process data more efficiently.  

## **Why is it Better than Brute Force?**  
1. **Improved Efficiency** – Often reduces **O(n²)** time complexity to **O(n)** in problems like pair sum or palindrome checking.  
2. **Less Redundant Work** – Instead of checking all pairs (like in brute force), it smartly eliminates unnecessary comparisons.  
3. **Memory Efficient** – Works in-place without requiring extra space in most cases.  

## **Example Problem: Finding Two Sum in a Sorted Array**  
Given a sorted array and a target sum, we need to find two numbers that add up to the target.  
- **Brute Force:** Check all pairs (**O(n²)**).  
- **Two Pointer Approach:**  
  - Start one pointer at the beginning (`i = 0`) and another at the end (`j = n-1`).  
  - If `arr[i] + arr[j] > target`, move `j` left.  
  - If `arr[i] + arr[j] < target`, move `i` right.  
  - Stop when a match is found (**O(n)** time complexity).  

This approach is commonly used in **binary search problems, sorting, and linked list operations** for optimized performance.
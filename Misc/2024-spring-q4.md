# Creating a Balanced BST from an Unsorted Array

Based on the screenshot, I'll provide a solution to create a balanced binary search tree (BST) from an unsorted array, where the tree is stored in an array representation with children at positions `2*k` and `2*k+1` for node at position `k`.

## Solution Code

```cpp
#include <algorithm>
#include <vector>
#include <functional> // Add this for std::function

void makeBalancedBST(unsigned *begin, unsigned numElem) {
    if (numElem == 0) return;
    
    std::vector<unsigned> arr(begin, begin + numElem);
    std::sort(arr.begin(), arr.end());
    std::vector<unsigned> bst(numElem + 1, 0); // 1-based indexing

    // Define the lambda first (before using it)
    auto buildBST = [&](int start, int end, int index, auto&& buildBST) -> void {
        if (start > end) return;
        
        int mid = start + (end - start) / 2;
        bst[index] = arr[mid];
        
        buildBST(start, mid - 1, 2 * index, buildBST);     // Left subtree
        buildBST(mid + 1, end, 2 * index + 1, buildBST);   // Right subtree
    };

    // Call the lambda with itself as parameter (for recursion)
    buildBST(0, numElem - 1, 1, buildBST);
    
    // Copy back to original array
    for (int i = 1, j = 0; i <= numElem; ++i, ++j) {
        begin[j] = bst[i];
    }
}
```

*OR (Lambda Function)*

```cpp
void buildBST(const std::vector<unsigned>& arr, std::vector<unsigned>& bst, 
              int start, int end, int index) {
    if (start > end) return;
    int mid = start + (end - start) / 2;
    bst[index] = arr[mid];
    buildBST(arr, bst, start, mid - 1, 2 * index);
    buildBST(arr, bst, mid + 1, end, 2 * index + 1);
}
```

## Explanation of the Function

1. **Input Parameters**: The function takes an unsorted array (`begin`) and its size (`numElem`).

2. **Sorting**: First, we sort the input array because a BST requires elements to be ordered (left < parent < right).

3. **BST Construction**:
   - We use a divide-and-conquer approach to build a balanced BST.
   - The middle element of the current subarray becomes the root of the current subtree.
   - Elements before the middle go to the left subtree, elements after go to the right subtree.
   - This ensures the tree is height-balanced.

4. **Array Representation**:
   - The BST is stored in an array where for any node at index `k`:
     - Left child is at `2*k`
     - Right child is at `2*k+1`
   - This is a common array representation of a complete binary tree.

5. **Recursive Building**:
   - The `buildBST` function recursively constructs the tree by:
     - Finding the middle element of the current range
     - Placing it at the current index
     - Then processing the left and right halves similarly

6. **Copying Back**:
   - Finally, we copy the BST from our temporary vector back to the original array in level-order (left to right).

This approach ensures we get a balanced BST because we always select the middle element as the root at each step, which minimizes the height of the resulting tree. The time complexity is O(n log n) due to the sorting step, and the space complexity is O(n) for the temporary storage.

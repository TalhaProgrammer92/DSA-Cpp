# Finding Majority Element in an array by sorting it

## **How the Code Works**

```cpp
class Solution
{
public:
    int findMajorityElement(vector<int> &nums)
    {
        int count = 1, limit = nums.size() / 2;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > limit)
            {
                return nums[i];
            }
        }
    }
};
```

The provided C++ code finds the **majority element** in an array, which is an element that appears **more than** ⌊n/2⌋ times. Here's a step-by-step explanation:

1. **Sorting the Array**  
   - The code first sorts the input array `nums` using `sort(nums.begin(), nums.end())`.  
   - After sorting, the same elements are grouped together.

2. **Finding the Majority Element**  
   - A variable `count` is initialized to 1, and `limit` is set to `n/2`, where `n` is the size of the array.
   - The code then iterates through the sorted array.
   - If the current element is the same as the next element, `count` is incremented.
   - Otherwise, `count` is reset to 1.
   - If `count` exceeds `limit`, the current element is returned as the majority element.

3. **Returning the Majority Element**  
   - Since the majority element appears more than `n/2` times, it will always be found within a single contiguous block after sorting.

---

## **Why is This Approach Better than Brute Force?**
A brute force approach would check every element's frequency, which takes **O(n²) time complexity** in the worst case. This approach is more efficient because:

1. **Sorting is O(n log n)**  
   - The array is sorted in **O(n log n)** time, which is better than the O(n²) brute force approach.
   
2. **Single Pass (O(n)) to Find Majority Element**  
   - Instead of counting occurrences for every element (O(n²)), this approach uses a **single pass** (O(n)) through the sorted array to check counts.

3. **Overall Time Complexity: O(n log n)**
   - The sorting step dominates the runtime, making the total complexity **O(n log n)**.
   - This is significantly better than **O(n²)** in brute force.

---
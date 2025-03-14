## **Code Explanation**
The C++ program finds the missing number in a sequence of numbers from `0` to `n`. The given array contains `n` distinct numbers from `0` to `n` but is missing one number. The goal is to determine which number is missing.

---

### **Breakdown of Each Line**
```cpp
#include <iostream>
#include <vector>
```
- `#include <iostream>`: This is the standard input-output library that allows using `cout` for printing output.
- `#include <vector>`: This includes the vector library, which provides the `vector` container used in the program.

```cpp
using namespace std;
```
- This statement allows using standard C++ functions and classes (like `cout`, `vector`, etc.) without explicitly prefixing them with `std::`.

---

### **Class Definition**
```cpp
class Solution
{
public:
    static int missingNumber(vector<int> &nums)
```
- `class Solution`: Defines a class named `Solution` to contain the function for finding the missing number.
- `public:`: Specifies that the function inside the class is accessible from outside the class.
- `static int missingNumber(vector<int> &nums)`: Declares a static function that takes a reference to a vector of integers and returns an integer (the missing number).

---

### **Algorithm Used: Sum Formula Approach**
```cpp
int n = nums.size();
```
- Retrieves the size `n` of the vector `nums`. The vector has `n` elements, meaning it contains numbers from `0` to `n`, missing one.

```cpp
int sum = n * (n + 1) / 2;
```
- Uses the **sum formula for the first `n` natural numbers**:  
  \[
  S = \frac{n(n+1)}{2}
  \]
  - This formula gives the sum of numbers from `0` to `n` if none were missing.

```cpp
for (int i = 0; i < n; i++)
{
    sum -= nums[i];
}
```
- Iterates through each element in the vector `nums` and **subtracts** its value from `sum`.
- This effectively removes all existing numbers, leaving only the missing number.

```cpp
return sum;
```
- Returns the remaining value in `sum`, which is the missing number.

---

### **Main Function**
```cpp
int main()
{
    vector<int> nums = {3, 0, 1, 4};
```
- Defines a vector `nums` with elements `{3, 0, 1, 4}`. The missing number should be `2` since the range is `0` to `4`.

```cpp
cout << "Missing number is " << Solution::missingNumber(nums) << endl;
```
- Calls the `missingNumber` function using `Solution::missingNumber(nums)`, prints the result.

---

### **Algorithm Analysis**
- **Time Complexity**: \(O(n)\)  
  - The formula calculation is \(O(1)\), and the loop runs \(O(n)\) times.
- **Space Complexity**: \(O(1)\)  
  - Only a few integer variables are used; no extra memory is needed.

---

### **Example Execution**
#### Given Input:
```cpp
vector<int> nums = {3, 0, 1, 4};
```
#### Step-by-Step Execution:
1. **Compute Expected Sum**:  
   \[
   \text{sum} = \frac{4(4+1)}{2} = \frac{20}{2} = 10
   \]
2. **Subtract Each Element**:
   ```
   sum = 10 - 3 = 7
   sum = 7 - 0 = 7
   sum = 7 - 1 = 6
   sum = 6 - 4 = 2
   ```
3. **Final Value of sum**: `2` (missing number)

#### Output:
```
Missing number is 2
```

---

## **Conclusion**
- This program efficiently finds the missing number using the sum formula approach.
- The method works well when a single number is missing in the sequence from `0` to `n`.
- It avoids extra memory usage, making it an optimal solution.
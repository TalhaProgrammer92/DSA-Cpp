### 🔍 **What is a Span in Stock Prices?**

The **span** of a stock's price on a given day is defined as the **number of consecutive days (including the current day)** the stock price has been **less than or equal to the current day's price**.

In simple terms, it's **"how many days in a row, up to today, has the price been lower than or equal to today's price?"**

#### 📊 Example:

For this price list:
`prices = {100, 80, 60, 70, 60, 75, 85}`

The spans are:
`span   = {1,   1,  1,  2,  1,  4,  6}`

Let’s now go over both methods **separately**.

---

## ✅ `span_brute_force` – Brute Force Method

### 🔧 **Logic:**

* For each day's price, go back and **count how many previous consecutive days (including today)** had prices **less than or equal** to the current price.
* Stop when a **greater price** is found.

### 🔁 **Dry Run with `prices = {100, 80, 60, 70, 60, 75, 85}`**

| i | price | compared with                                        | days (span) |
| - | ----- | ---------------------------------------------------- | ----------- |
| 0 | 100   | –                                                    | 1           |
| 1 | 80    | 100 (>)                                              | 1           |
| 2 | 60    | 80 (>)                                               | 1           |
| 3 | 70    | 60 (<=) → 80 (>)                                     | 2           |
| 4 | 60    | 70 (>)                                               | 1           |
| 5 | 75    | 60 (<=), 70 (<=) → 80 (>)                            | 4           |
| 6 | 85    | 75 (<=), 60 (<=), 70 (<=), 60 (<=), 80 (<=), 100 (>) | 6           |

✅ Final output: `span = {1, 1, 1, 2, 1, 4, 6}`

---

## ✅ `span_optimal` – Stack-Based Optimal Method

### 🔧 **Logic:**

* Use a **stack** to store indices of prices.
* For each price:

  * **Pop indices** from the stack while the top index points to a price **less than or equal to** current price.
  * If the stack is empty → no greater price to the left → span = i + 1.
  * If not empty → span = i - top index (last greater price).
* Push current index onto the stack.

### 🔁 **Dry Run**

Let’s go step by step:

#### Initial:

`stack = []`
`span = []`

---

### i = 0 → price = 100

* Stack empty → span = 1
* Push 0 → `stack = [0]`

### i = 1 → price = 80

* 80 < 100 → no pop → span = 1
* Push 1 → `stack = [0,1]`

### i = 2 → price = 60

* 60 < 80 → no pop → span = 1
* Push 2 → `stack = [0,1,2]`

### i = 3 → price = 70

* 70 > 60 → pop 2
* 70 < 80 → stop popping → span = 3 - 1 = 2
* Push 3 → `stack = [0,1,3]`

### i = 4 → price = 60

* 60 < 70 → no pop → span = 1
* Push 4 → `stack = [0,1,3,4]`

### i = 5 → price = 75

* 75 > 60 → pop 4
* 75 > 70 → pop 3
* 75 < 80 → stop → span = 5 - 1 = 4
* Push 5 → `stack = [0,1,5]`

### i = 6 → price = 85

* 85 > 75 → pop 5
* 85 > 80 → pop 1
* 85 < 100 → stop → span = 6 - 0 = 6
* Push 6 → `stack = [0,6]`

✅ Final output: `span = {1, 1, 1, 2, 1, 4, 6}`

---

### ⚖️ Time Complexity Comparison

| Method          | Time Complexity |
| --------------- | --------------- |
| Brute Force     | O(n²)           |
| Optimal (Stack) | O(n)            |

Because in the optimal version, **each element is pushed and popped at most once**, the overall time is linear.
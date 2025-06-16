## 🔍 Theory (What the function does)

This function **swaps every two adjacent nodes in a linked list**, **iteratively**.

### ✅ Key Concepts:

* It performs **pairwise swapping** of nodes (`1 <-> 2`, `3 <-> 4`, etc.).
* The function **does not change the values**, only the **pointers** (node links).
* It uses a **loop with pointers** to walk through the list and swap nodes in-place.

---

## 📌 Pointers Used

* `first` → points to the first node of a pair
* `second` → points to the second node of a pair
* `next` → points to the node after the second (start of next pair)
* `previous` → tracks the node before the current pair, to link it after swap
* `head` → updated when the first swap is done (head changes after the first pair)

---

## 🔄 Dry Run: `1 -> 2 -> 3 -> 4 -> 5 -> NULL`

### 🔧 Initial State:

```
head = 1
first = 1
second = 2
previous = NULL
```

### ✅ First Iteration:

#### Swap 1 and 2

* `next = second->next = 3`
* `second->next = first` → 2 → 1
* `first->next = next` → 1 → 3
* Since `previous == NULL`, update `head = second = 2`

Now:

```
2 -> 1 -> 3 -> 4 -> 5 -> NULL
```

Update:

```
previous = first = 1
first = next = 3
second = next->next = 4
```

---

### ✅ Second Iteration:

#### Swap 3 and 4

* `next = second->next = 5`
* `second->next = first` → 4 → 3
* `first->next = next` → 3 → 5
* `previous->next = second` → 1 → 4

Now:

```
2 -> 1 -> 4 -> 3 -> 5 -> NULL
```

Update:

```
previous = first = 3
first = next = 5
second = next->next = NULL
```

---

### ✅ Third Iteration:

Loop ends since `second == NULL`. No more pairs.

---

## ✅ Final Result:

```
2 -> 1 -> 4 -> 3 -> 5 -> NULL
```

---

## 🧠 Summary

### ✔ What it does:

Swaps nodes **pairwise** without recursion.

### ✔ Time Complexity:

* `O(n)`, where `n` is number of nodes.

### ✔ Space Complexity:

* `O(1)` — constant space; done iteratively with pointer manipulation.

---

## 👀 Visual for first pair:

Before:

```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

After:

```
2 -> 1 -> 4 -> 3 -> 5 -> NULL
```

Each pair is reversed **by changing next pointers only**, not data.
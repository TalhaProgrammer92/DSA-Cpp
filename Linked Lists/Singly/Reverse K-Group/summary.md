# K-group Reversal

## 🔍 Theory (How it works)

### ✅ Step-by-step explanation:

1. **Check if `k` nodes are available**
   Before performing reversal, it checks if there are at least `k` nodes to reverse. If not, it returns the head as-is.

2. **Recursive call for the rest**
   If `k` nodes are available, it calls itself recursively for the remaining list after the current `k` nodes. This ensures the tail of the reversed group points to the head of the next reversed segment.

3. **Reverse current `k` nodes**
   It reverses the current group of `k` nodes by linking each node's `next` to the `previous` pointer (which was returned from the recursive call).

4. **Return new head**
   After reversing the current `k` group, it returns the new head (which is the last node of the original group).

---

## 🔁 Dry Run for list `1 -> 2 -> 3 -> 4 -> 5 -> NULL` and `k = 2`

### 📌 Initial list:

```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

---

### 🔄 First Call: `reverse(1, 2)`

* `k=2`, check nodes: ✅ (1, 2)
* Recursive call: `reverse(3, 2)`

---

### 🔄 Second Call: `reverse(3, 2)`

* `k=2`, check nodes: ✅ (3, 4)
* Recursive call: `reverse(5, 2)`

---

### 🔄 Third Call: `reverse(5, 2)`

* `k=2`, check nodes: ❌ (only 1 node: 5)
* Return head = 5 (no reversal)

---

### 🔁 Back to Second Call:

Reverse current group: 3 → 4

* `previous = 5`
* Reverse 3, 4:

```
4 -> 3 -> 5
```

Return: new head = 4

---

### 🔁 Back to First Call:

Reverse current group: 1 → 2

* `previous = 4`
* Reverse 1, 2:

```
2 -> 1 -> 4 -> 3 -> 5
```

Return: new head = 2

---

## ✅ Final Result:

```
2 -> 1 -> 4 -> 3 -> 5 -> NULL
```

Each group of `2` nodes has been reversed.

---

## 🧠 Summary

* Works recursively in chunks of size `k`.
* First confirms enough nodes exist to reverse.
* Reverses current `k` nodes and connects to recursively reversed rest.
* **Time complexity**: `O(n)`, each node is visited once.
* **Space complexity**: `O(n/k)` recursion stack frames.
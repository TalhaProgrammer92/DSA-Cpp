---

## 🧠 Priority Queue Using Min-Heap

### Concept Recap:

* A **Min-Heap** is a binary tree where:

  * The **smallest element is always at the root**.
  * Each parent is smaller than its children.

We use a **dynamic array (`vector`)** to implement it.

---

## 📦 Sample Code:

Let’s assume this code runs:

```cpp
PriorityQueue pq;
pq.insert(50);
pq.insert(30);
pq.insert(20);
pq.insert(10);
pq.insert(40);
```

---

## Step-by-Step Dry Run:

### Initial: `heap = []`

---

### 1️⃣ `insert(50)`

* Heap becomes: `[50]`
  (No parent to compare, no heapify needed.)

---

### 2️⃣ `insert(30)`

* Heap before heapify: `[50, 30]`
* Parent of index `1` is at `0` → compare 30 < 50
  ✅ Swap!

```
Before: [50, 30]
Swap:   [30, 50]
```

---

### 3️⃣ `insert(20)`

* Heap before heapify: `[30, 50, 20]`
* Parent of index `2` is `0`: 20 < 30
  ✅ Swap!

```
Before: [30, 50, 20]
Swap:   [20, 50, 30]
```

---

### 4️⃣ `insert(10)`

* Heap before heapify: `[20, 50, 30, 10]`
* Index = 3, Parent = (3-1)/2 = 1 → 10 < 50 → ✅ Swap
* New index = 1, Parent = 0 → 10 < 20 → ✅ Swap again

```
Before: [20, 50, 30, 10]
After 1: [20, 10, 30, 50]
After 2: [10, 20, 30, 50]
```

---

### 5️⃣ `insert(40)`

* Heap before heapify: `[10, 20, 30, 50, 40]`
* Index = 4, Parent = 1 → 40 > 20 → ❌ No swap needed.

Final heap:

```
[10, 20, 30, 50, 40]
```

---

## 🌟 Display:

```cpp
pq.display();
```

```
10 20 30 50 40
```

---

## 🔍 `getMin()`

```cpp
pq.getMin();  // returns 10
```

* Top/root of the heap → index 0 = 10

---

## 🔄 `deleteMin()`

1. Replace root (10) with last element (40)
2. Heap becomes: `[40, 20, 30, 50]`
3. Heapify down:

   * Index 0: Compare with children 20 and 30
   * 20 is smallest → ✅ Swap with 20
   * Index 1: Children = 50 → 40 < 50 → ❌ No swap

Result:

```
Before: [10, 20, 30, 50, 40]
Swap:   [40, 20, 30, 50]
After:  [20, 40, 30, 50]
```

---

## 📦 Final Heap:

```cpp
pq.display();
```

```
20 40 30 50
```

---

## Summary Table:

| Operation   | Heap                  |
| ----------- | --------------------- |
| insert(50)  | \[50]                 |
| insert(30)  | \[30, 50]             |
| insert(20)  | \[20, 50, 30]         |
| insert(10)  | \[10, 20, 30, 50]     |
| insert(40)  | \[10, 20, 30, 50, 40] |
| getMin()    | → 10                  |
| deleteMin() | \[20, 40, 30, 50]     |

---

## 🔁 In Short:

| Method        | What it does                      | Time Complexity |
| ------------- | --------------------------------- | --------------- |
| `insert(x)`   | Adds element & maintains heap     | O(log n)        |
| `getMin()`    | Gets the smallest element         | O(1)            |
| `deleteMin()` | Removes smallest and re-heapifies | O(log n)        |

---
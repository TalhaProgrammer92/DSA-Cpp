## 🟩 What is a Queue?

A **Queue** is a **linear data structure** that follows the **FIFO** (First-In, First-Out) principle.

### ✅ Key Properties:

| Operation | Description                                |
| --------- | ------------------------------------------ |
| `push()`  | Adds an element to the **rear**            |
| `pop()`   | Removes an element from the **front**      |
| `top()`   | Returns the front element without removing |
| `size()`  | Returns the number of elements             |

In a Queue:

* **The first element added** is the **first to be removed**
* Works like a real-life line: first person in line is served first

---

## 🧠 Dry Run of Your Code

We’ll dry run **this snippet**:

```cpp
vector<int> data = {1, 2, 3, 4, 5};
Queue queue;

for (int element : data)
	queue.push(element);

while (queue.size() > 0)
	cout << queue.pop() << endl;
```

---

### 🛠 Internal Pointers

* `top`: points to **front** of the queue
* `bottom`: points to **rear** of the queue

---

### 📦 Step-by-Step Execution:

### Initial state:

* `top = NULL`, `bottom = NULL`

---

### 🟢 `push(1)`

* `top == NULL`, so:

  * `top = new Block(1)`
  * `bottom = top`
* Queue now: **\[1]**

---

### 🟢 `push(2)`

* Create new `Block(2)`
* `bottom->next = Block(2)`
* `bottom = Block(2)`
* Queue: **\[1 → 2]**

---

### 🟢 `push(3)`

* Create new `Block(3)`
* `bottom->next = Block(3)`
* `bottom = Block(3)`
* Queue: **\[1 → 2 → 3]**

---

### 🟢 `push(4)`

* Queue: **\[1 → 2 → 3 → 4]**

### 🟢 `push(5)`

* Queue: **\[1 → 2 → 3 → 4 → 5]**

---

Now the queue is filled.
Let’s move to popping:

---

### 🔴 `pop()`

1. `top = Block(1)`
2. Save `data = 1`
3. Move `top = top->next → Block(2)`
4. Delete old `Block(1)`
5. Output: `1`

---

### 🔴 `pop()`

* `top = Block(2)`
* Save `data = 2`
* Move `top = Block(3)`
* Delete `Block(2)`
* Output: `2`

---

### 🔴 `pop() → 3`

### 🔴 `pop() → 4`

### 🔴 `pop() → 5`

After 5th pop:

* `top = NULL`
* `bottom = Block(5)` (technically needs nulling too if we wanted)

---

### 🔚 Final Output:

```
1
2
3
4
5
```

---

## ✅ Summary of Queue's Behavior in Your Code:

* It **correctly enqueues** by adding to the `bottom`
* It **correctly dequeues** from the `top`
* You’re maintaining `top` and `bottom` pointers correctly
* `size()` function is used perfectly to control the loop

---
---

## 🔁 Recap: What is Deque?

A **Deque (Double-Ended Queue)** is a linear data structure where:

* You can **insert** and **delete** from **both ends** — `front` and `rear`.

There are 4 main actions:

* `insertFront()`
* `insertRear()`
* `deleteFront()`
* `deleteRear()`

This implementation is **circular**, meaning when the end is reached, we **wrap around**.

---

## 🧠 Internal State

```cpp
int* arr;     // array to store elements
int size;     // maximum size
int front;    // index of front element
int rear;     // index of rear element
```

---

# 🧪 Dry Run Step by Step

### Let’s assume:

```cpp
Deque dq(5);
```

Initially:

```cpp
arr = [_, _, _, _, _]
front = -1
rear  = -1
```

---

## 1️⃣ `dq.insertRear(10);`

* `isEmpty()` → true
* So: `front = rear = 0`
* `arr[rear] = 10`

```
arr   = [10, _, _, _, _]
front = 0
rear  = 0
```

---

## 2️⃣ `dq.insertRear(20);`

* `rear = (0 + 1) % 5 = 1`
* `arr[1] = 20`

```
arr   = [10, 20, _, _, _]
front = 0
rear  = 1
```

---

## 3️⃣ `dq.insertFront(5);`

* `front = (0 - 1 + 5) % 5 = 4`
* `arr[4] = 5`

```
arr   = [10, 20, _, _, 5]
front = 4
rear  = 1
```

🧠 Note: Circular behavior — `front` wrapped to the **last index**.

---

## 4️⃣ `dq.insertFront(2);`

* `front = (4 - 1 + 5) % 5 = 3`
* `arr[3] = 2`

```
arr   = [10, 20, _, 2, 5]
front = 3
rear  = 1
```

---

## 5️⃣ `dq.insertRear(30);`

* `rear = (1 + 1) % 5 = 2`
* `arr[2] = 30`

```
arr   = [10, 20, 30, 2, 5]
front = 3
rear  = 2
```

🧠 Queue is now **full**:
`(rear + 1) % size == front ⇒ (2 + 1) % 5 == 3`

---

## 🧾 Display:

Traverse from `front = 3` to `rear = 2`:

Indexes visited: `3 → 4 → 0 → 1 → 2`

```
Deque: 2 5 10 20 30
```

---

## 🔙 `dq.deleteFront();`

* `Deleted: arr[3] = 2`
* `front = (3 + 1) % 5 = 4`

```
arr   = [10, 20, 30, 2, 5]
front = 4
rear  = 2
```

---

## 🔚 `dq.deleteRear();`

* `Deleted: arr[2] = 30`
* `rear = (2 - 1 + 5) % 5 = 1`

```
arr   = [10, 20, 30, 2, 5]
front = 4
rear  = 1
```

---

## 🧾 Display Again:

Indexes from `front = 4` to `rear = 1`:
`4 → 0 → 1`

```
Deque: 5 10 20
```

---

## 🔍 `getFront()` & `getRear()`

* `arr[front] = arr[4] = 5`
* `arr[rear]  = arr[1] = 20`

✅ Outputs:

```
Front element: 5
Rear element: 20
```

---

## Summary Table of States:

| Operation        | `front` | `rear` | Queue Content         |
| ---------------- | ------- | ------ | --------------------- |
| `insertRear(10)` | 0       | 0      | \[10, \_, \_, \_, \_] |
| `insertRear(20)` | 0       | 1      | \[10, 20, \_, \_, \_] |
| `insertFront(5)` | 4       | 1      | \[10, 20, \_, \_, 5]  |
| `insertFront(2)` | 3       | 1      | \[10, 20, \_, 2, 5]   |
| `insertRear(30)` | 3       | 2      | \[10, 20, 30, 2, 5]   |
| `deleteFront()`  | 4       | 2      | \[10, 20, 30, 2, 5]   |
| `deleteRear()`   | 4       | 1      | \[10, 20, 30, 2, 5]   |

---

## ✅ Final Deque

```cpp
Deque: 5 10 20
Front element: 5
Rear element: 20
```

---
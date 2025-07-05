---

## 🔁 Circular Queue vs Linear Queue (Array-Based)

| Feature                   | **Linear Queue**              | **Circular Queue**                |
| ------------------------- | ----------------------------- | --------------------------------- |
| **Front & Rear Movement** | Only moves forward            | Wraps around using modulo `%`     |
| **Space Usage**           | Wastes space after dequeues   | Reuses space after dequeues       |
| **When Full?**            | When `rear == size - 1`       | When `(rear + 1) % size == front` |
| **Needs Shifting?**       | May require shifting          | ❌ No shifting ever needed         |
| **Performance**           | Can degrade (due to shifting) | Always O(1) enqueue/dequeue       |

---

### 🧠 Why Use Circular Queue?

> In a **linear queue**, once the `rear` hits the end, you **can’t insert** anymore even if there’s empty space in the front.
> In a **circular queue**, you **wrap around** and use that space efficiently.

---

## 🔁 Circular Queue Structure

Let’s say the queue size = 5.

Initial state:

```
[ _  _  _  _  _ ]
  ↑
front = rear = -1  (queue is empty)
```

Now let’s dry run every method step-by-step.

---

## 🔸 `enqueue(int val)` Dry Run

### Step 1: First insert (val = 10)

```cpp
if (isEmpty()) => true
front = rear = 0
queue[rear] = 10
```

```
[10 _ _ _ _]
 ↑
 F,R = 0
```

### Step 2: Next insert (val = 20)

```cpp
rear = (rear + 1) % size = (0 + 1) % 5 = 1
queue[rear] = 20
```

```
[10 20 _ _ _]
 ↑  ↑
 F   R
```

---

## 🔸 `dequeue()` Dry Run

### Step 1: Dequeue 10

```cpp
val = queue[front] = 10
front = (front + 1) % size = (0 + 1) % 5 = 1
```

```
[10 20 _ _ _]
    ↑  ↑
    F  R
```

**10 returned, but not removed physically** — it’ll be overwritten later.

### Step 2: Dequeue 20

```cpp
val = queue[1] = 20
Since front == rear ⇒ set both to -1 (queue now empty)
```

```
[10 20 _ _ _]
    ↑
F,R = -1
```

---

## 🔸 `isEmpty()` Logic

```cpp
return front == -1;
```

Simple and accurate. Queue is empty if no element has been added or all have been removed.

---

## 🔸 `isFull()` Logic

```cpp
return (rear + 1) % size == front;
```

Let’s simulate:

### State:

```
[30 40 50 60 70]
  ↑           ↑
  F           R
front = 0, rear = 4, size = 5
```

Now:

```cpp
(rear + 1) % size = (4 + 1) % 5 = 0
front = 0 ⇒ isFull = true
```

So queue is full even though rear is "before" front — **wrap-around happened**.

---

## 🔸 `peek()`

```cpp
if (isEmpty()) return -1;
return queue[front];
```

Simply shows the front value without removing it.

---

## 🔸 `display()`

```cpp
int i = front;
while (true) {
    print(queue[i]);
    if (i == rear) break;
    i = (i + 1) % size;
}
```

This loop correctly handles both:

* Normal order (front < rear)
* Wrapped around (rear < front)

---

## 🔁 Quick Full Dry Run Example:

### Size = 5

```cpp
enqueue(10);
enqueue(20);
enqueue(30);
dequeue();       // removes 10
dequeue();       // removes 20
enqueue(40);
enqueue(50);
enqueue(60);     // Wraps to start of array
```

Result:

```
[60 _ _ 30 40 50]
 ↑        ↑
 R        F
```

Now the queue contains: `30, 40, 50, 60`

* front = 2
* rear = 0

---

## ✅ Summary of Each Method:

| Method    | Purpose                          | Core Logic                          |
| --------- | -------------------------------- | ----------------------------------- |
| `enqueue` | Add element, wrap rear if needed | `rear = (rear + 1) % size`          |
| `dequeue` | Remove element, wrap front       | `front = (front + 1) % size`        |
| `isFull`  | Check if rear caught front       | `(rear + 1) % size == front`        |
| `isEmpty` | Check if front is reset          | `front == -1`                       |
| `peek`    | Show front element               | `return queue[front]`               |
| `display` | Traverse circularly              | `i = (i + 1) % size` loop till rear |

---
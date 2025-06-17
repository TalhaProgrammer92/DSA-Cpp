This program demonstrates the **stack data structure** using two implementations:

1. **Stack using `vector`** (dynamic array-based)
2. **Stack using linked list** (pointer-based)

---

## 🔍 THEORY EXPLANATION

### ✅ `StackVector` Class (Vector-based Stack)

Uses C++ STL `vector<int>` internally to mimic LIFO (Last In First Out) behavior.

#### Key Methods:

* `push(int value)`: Adds `value` to the end of the vector.
* `pop()`: Removes the last element.
* `top()`: Returns the last element.
* `empty()`: Returns `true` if vector is empty.

> Internally, `vector` manages memory and resizes automatically.

---

### ✅ `StackLinkedList` Class (Linked List-based Stack)

Implements stack using **singly linked list**. Each node contains:

* `data` (int)
* `next` (pointer to next node)

#### Key Methods:

* `push(int data)`: Creates a new node and places it at the front.
* `pop()`: Deletes the front node (top of stack).
* `top()`: Returns data of the front node.
* `empty()`: Checks if `head` is `NULL`.

> Manual memory management is used here (`new`, `delete`).

---

## 🔁 DRY RUN / WORKING (Step-by-Step Execution)

### **Main Function**

#### Part 1: Vector-Based Stack

```cpp
StackVector stack_vector;

stack_vector.push(1);  // [1]
stack_vector.push(2);  // [1, 2]
stack_vector.push(3);  // [1, 2, 3]
```

Now start the loop:

```cpp
while (!stack_vector.empty())
{
	cout << stack_vector.top() << ' ';
	stack_vector.pop();
}
```

* Loop 1: `top()` = 3 → print `3`, then pop → \[1, 2]
* Loop 2: `top()` = 2 → print `2`, then pop → \[1]
* Loop 3: `top()` = 1 → print `1`, then pop → \[]

Print:

```
Stack (Vector): 3 2 1
```

---

#### Part 2: Linked List-Based Stack

```cpp
StackLinkedList stack_list;

stack_list.push(1);  // head -> 1
stack_list.push(2);  // head -> 2 -> 1
stack_list.push(3);  // head -> 3 -> 2 -> 1
```

Now start the loop:

```cpp
while (!stack_list.empty())
{
	cout << stack_list.top() << ' ';
	stack_list.pop();
}
```

* Loop 1: `top()` = 3 → print `3`, then pop → head -> 2
* Loop 2: `top()` = 2 → print `2`, then pop → head -> 1
* Loop 3: `top()` = 1 → print `1`, then pop → head = NULL

Print:

```
Stack (Linked List): 3 2 1
```

---

## ✅ Final Output:

```
Stack (Vector): 3 2 1
Stack (Linked List): 3 2 1
```

---

## 🔚 Summary:

* Both implementations follow LIFO order.
* Vector version is simpler due to STL handling memory.
* Linked list version gives deeper control and teaches manual memory management.
* The dry run proves both stacks behave identically from the user perspective.
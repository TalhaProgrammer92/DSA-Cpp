## 🔹 Introduction to Linked Lists

A **linked list** is a **linear data structure** where each element (called a **node**) contains two parts:

1. **Data** – the value it stores (like an integer, string, etc.)
2. **Pointer/Reference** – the address of the **next node** in the sequence

Unlike arrays:

* Linked lists do **not** store elements in contiguous memory locations.
* Insertion and deletion are **efficient (O(1))** at the beginning (front), unlike arrays that require shifting elements.

Types of linked lists:

* **Singly Linked List** – Each node points to the next node.
* **Doubly Linked List** – Each node points to both the next and previous node.
* **Circular Linked List** – Last node points to the head instead of `NULL`.

Your code implements a **Singly Linked List**.

---

## 🔹 `Node` Class

```cpp
class Node
{
public:
    int value;       // The data the node holds
    Node *next;      // Pointer to the next node in the list

    Node(int value) : value(value), next(NULL) {}
};
```

### ✅ Working:

* This class defines the **structure of a node**.
* It stores:

  * `value`: integer data
  * `next`: pointer to the next node in the list
* The constructor initializes:

  * `value` with the passed argument
  * `next` with `NULL` (since it doesn't point to any node yet)

> ⚠️ Note: `Node* next` enables dynamic linking of nodes in the list.

---

## 🔹 `LinkedList` Class

```cpp
class LinkedList
{
private:
    Node *head, *tail; // Pointers to the first and last node

public:
    LinkedList() : head(NULL), tail(NULL) {}
```

### ✅ Working:

* `head`: Points to the **first node**.
* `tail`: Points to the **last node**.
* The constructor initializes both to `NULL`, meaning the list starts empty.

---

### 🔸 `void push_front(int value)`

Inserts a new node **at the beginning** of the list.

```cpp
Node *node = new Node(value);
```

* Allocates memory for a new node dynamically with the given value.

```cpp
if (head == NULL)
    tail = node;
else
    node->next = head;
head = node;
```

* If the list is **empty**, `tail` is also set to this node.
* If not, the new node’s `next` points to the current head.
* `head` is then updated to point to this new node.

---

### 🔸 `void push_back(int value)`

Inserts a new node **at the end** of the list.

```cpp
Node *node = new Node(value);
```

* Creates a new node with the given value.

```cpp
if (head == NULL)
    head = node;
else
    tail->next = node;
tail = node;
```

* If the list is empty, both `head` and `tail` point to the new node.
* Otherwise, the current tail's `next` points to the new node.
* `tail` is then updated to the new node.

---

### 🔸 `void pop_front()`

Removes the node **from the front** of the list.

```cpp
Node *start = head;
head = head->next;
start->next = NULL;
delete start;
```

* Stores the current head.
* Moves head to the next node.
* Disconnects and deletes the old head node to free memory.

---

### 🔸 `void pop_back()`

Removes the node **from the end** of the list.

```cpp
Node *node = head;
while (node->next != tail)
    node = node->next;
```

* Traverses to the second-last node.

```cpp
Node *temp = tail;
tail = node;
node->next = NULL;
delete temp;
```

* Deletes the last node.
* Updates `tail` and disconnects the node.

---

### 🔸 `void insert(int value, int index)`

Inserts a new node **at a given index**.

```cpp
if (index == 0)
    push_front(value);
else if (index == size - 1)
    push_back(value);
```

* For index `0`, insert at front.
* For `last index`, insert at end.

```cpp
else if (index > 0 && index < size)
{
    Node *node = new Node(value);
    Node *prev = at(index - 1), *next = prev->next;
    node->next = next;
    prev->next = node;
}
```

* For middle positions:

  * Create new node.
  * Find previous node using `at(index - 1)`
  * Adjust `next` pointers to insert in between.

> ⚠️ If the index is invalid, it throws `out_of_range`.

---

### 🔸 `int size()`

Returns the number of nodes in the list.

```cpp
int count = 0;
Node *start = head;
while (start != NULL)
{
    start = start->next;
    count++;
}
return count;
```

* Traverses the list and increments a counter.

---

### 🔸 `Node* at(int index)`

Returns the node pointer at the specified index.

```cpp
Node *start = head;
for (int i = 0; i < index; i++)
    start = start->next;
return start;
```

* Traverses node-by-node until the given index.
* If list is empty, throws `out_of_range`.

---

### 🔸 `int index(int value)`

Searches for a value and returns its index.

```cpp
Node *start = head;
int index = 0;
while (start != NULL)
{
    if (start->value == value)
        return index;
    start = start->next;
    index++;
}
return -1;
```

* Linear search for the value.
* Returns index if found, else `-1`.

---

### 🔸 `void print()`

Prints all node values in the list.

```cpp
Node *start = head;
while (start != NULL)
{
    cout << start->value << "->";
    start = start->next;
}
cout << "NULL" << endl;
```

* Iterates through each node and prints its value followed by `"->"`.

---

## 🔹 `main()` Function Explained

```cpp
LinkedList list;
```

* Creates an instance of the `LinkedList` class.

```cpp
list.push_front(1);
list.push_front(2);
```

* Inserts 2 at front → becomes head.
* Inserts 1 at front → becomes new head.

**List now**: `1->2` → But `push_front` reverses it → **Final: 2->1**

```cpp
list.push_back(3);
list.push_back(4);
list.push_back(5);
```

* Appends 3, 4, and 5 at the end.

**List becomes**: `2->1->3->4->5`

```cpp
list.pop_front(); // Removes 2
list.pop_back();  // Removes 5
```

**List becomes**: `1->3->4`

```cpp
list.insert(2, 1); // Insert 2 at index 1
```

**List becomes**: `1->2->3->4`

```cpp
list.print();
```

> Output: `1->2->3->4->NULL`

```cpp
cout << "Value at Node#" + to_string(index + 1) << ": " << list.at(index)->value << endl;
```

* Shows value at `index 2` (3rd node): Output → `Value at Node#3: 3`

```cpp
cout << "Value " + to_string(value) + " is located at index: " << list.index(value) << endl;
```

* Searches for value `2`: Output → `Value 2 is located at index: 1`

```cpp
cout << "Size: " << list.size() << endl;
```

* Output: `Size: 4`

---

## ✅ Summary

It demonstrates a **custom singly linked list** with full CRUD operations:

* **Create** (`push_front`, `push_back`, `insert`)
* **Read** (`print`, `size`, `at`, `index`)
* **Update** — Not included here, could be added with an `update(index, value)` method
* **Delete** (`pop_front`, `pop_back`)
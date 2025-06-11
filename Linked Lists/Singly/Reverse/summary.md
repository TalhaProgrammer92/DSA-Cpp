## 🧱 **Class: `Node`**

```cpp
class Node {
public:
    int value;
    Node *next;

    Node(int value) : value(value), next(NULL) {}
};
```

### 🔍 Purpose:

This class represents a **node** in the linked list.

### 🧠 Concept:

* `int value`: stores the actual data.
* `Node* next`: pointer to the next node in the list.
* Constructor initializes:

  * `value` with the given value.
  * `next` to `NULL` (as it's not linked yet).

---

## 🧱 **Class: `LinkedList`**

```cpp
class LinkedList {
private:
    Node *head, *tail;
```

### 🔍 Purpose:

This class manages the entire list: nodes, insertion, printing, and reversal.

* `head`: pointer to the first node of the list.
* `tail`: pointer to the last node of the list.

---

### 🔧 **Constructor**

```cpp
LinkedList() : head(NULL), tail(NULL) {}
```

* Initializes an **empty list** by setting both `head` and `tail` to `NULL`.

---

### ➕ **Method: `push_front(int value)`**

```cpp
void push_front(int value)
{
    Node *node = new Node(value);

    if (head == NULL)
        tail = node;
    else
        node->next = head;

    head = node;
}
```

### 🔍 Purpose:

Inserts a new node **at the beginning** of the list.

### 📘 Working:

1. A new node is dynamically created.
2. If the list is empty:

   * Make both `head` and `tail` point to this node.
3. If not empty:

   * Link the new node’s `next` to the current head.
4. Update `head` to the new node.

---

### 🔁 **Method: `reverse()`**

```cpp
void reverse()
{
    Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;    // Save next node
        current->next = prev;    // Reverse current node's pointer
        prev = current;          // Move prev one step forward
        current = next;          // Move current one step forward
    }

    tail = head;     // Update tail
    head = prev;     // Update head to last processed node
}
```

### 🔍 Purpose:

**Reverses the entire linked list** in-place.

### 📘 Working:

* It uses three pointers:

  * `prev`: stores the previous node (starts as `NULL`).
  * `current`: the node being processed.
  * `next`: saves the next node before breaking the original link.

* The loop:

  1. Stores the next node.
  2. Reverses the `next` pointer of the current node to point to `prev`.
  3. Shifts `prev` and `current` one node forward.

* After the loop:

  * `prev` becomes the new head.
  * Old head becomes the new tail.

---

### 📤 **Method: `print()`**

```cpp
void print()
{
    Node *start = head;

    while (start != NULL)
    {
        cout << start->value << "->";
        start = start->next;
    }
    cout << "NULL" << endl;
}
```

### 🔍 Purpose:

Prints all elements of the list from `head` to `tail`.

### 📘 Output Format:

* Example: `1->2->3->NULL`

---

## 🧪 **Function: `main()`**

```cpp
int main()
{
    LinkedList list;

    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    cout << "Before:\t"; list.print();
    list.reverse();
    cout << "After:\t"; list.print();
}
```

### 🔍 Purpose:

This is the **driver function** that tests the functionality of the linked list.

### 📘 Execution Flow:

1. A new `LinkedList` object is created.
2. Values `5` to `1` are inserted at the front.

   * Final list: `1->2->3->4->5->NULL`
3. The list is printed **before reversal**.
4. The list is **reversed** in-place.

   * Now becomes: `5->4->3->2->1->NULL`
5. The list is printed **after reversal**.

---

## ✅ **Output**

```
Before:	1->2->3->4->5->NULL
After:	5->4->3->2->1->NULL
```
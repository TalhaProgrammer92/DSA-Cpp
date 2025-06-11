## ✅ **Main Purpose of the Code**

This program builds a **singly linked list**, prints it, and **finds the middle node** of the list using its `middle()` method.

---

## 🔍 Breakdown of Important Parts

### 🧱 `class Node`

```cpp
class Node {
public:
    int value;
    Node *next;

    Node(int value) : value(value), next(NULL) {}
};
```

* Represents each individual node.
* Holds an integer `value` and a pointer `next` to the next node.

---

### 🧱 `class LinkedList`

Manages all linked list operations.

#### 🔹 Constructor

```cpp
LinkedList() : head(NULL), tail(NULL) {}
```

* Initializes an empty list.

---

### 🔹 `push_front(int value)`

Adds a new node **at the beginning** of the list.

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

* If list is empty, both `head` and `tail` point to the new node.
* Otherwise, links new node to current head and updates `head`.

---

### 🔹 `int size()`

Calculates and returns the **number of nodes** in the list.

```cpp
int size()
{
    int count = 0;
    Node *start = head;

    while (start != NULL)
    {
        start = start->next;
        count++;
    }

    return count;
}
```

* Traverses the list and counts the nodes.

---

### 🔹 `Node* at(int index)`

Returns the **node at a specific index** (0-based).

```cpp
Node* at(int index)
{
    if (head != NULL)
    {
        Node *start = head;
        for (int i = 0; i < index; i++)
            start = start->next;

        return start;
    }

    throw out_of_range("The given index is out of range!");
}
```

* Loops through the list until the desired index is reached.
* Throws an error if list is empty.

---

### 🔹 `Node* middle()`

Returns the **middle node** of the list.

```cpp
Node* middle()
{
    if (head != NULL)
    {
        Node *start = head;
        int mid = size() / 2;

        return at(mid);
    }
}
```

* Calls `size()` to get the total number of nodes.
* Finds middle index using `size() / 2`.
* Uses `at()` to get the node at that index.

> If size is even, it returns the **second middle** node (e.g., for 6 nodes, it returns node at index 3).

---

### 🔹 `print()`

Displays all the values in the list.

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

---

## 🧪 `main()` Execution

```cpp
int main()
{
    LinkedList list;

    list.push_front(6);
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    list.print();

    cout << "Middle Node value: " << list.middle()->value << endl;
}
```

### 🧠 Step-by-step:

1. Values inserted: `1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL`
2. The middle index: `size() / 2 = 6 / 2 = 3`
3. The node at index 3 is **4**, so output is:

---

## ✅ **Final Output**

```
1->2->3->4->5->6->NULL
Middle Node value: 4
```
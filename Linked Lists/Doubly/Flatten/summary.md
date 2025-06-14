### 🔹 `Node` class – `child` pointer

Each node has:

* `value` – the data.
* `next` – points to the next node in the current level.
* `previous` – points to the previous node in the current level.
* **`child`** – *a pointer to another doubly linked list*, creating a multilevel structure.

---

### 🔹 `DoublyList::create_child(int index, Node* head)`

Purpose:
To connect a node at a certain `index` in the current list to a **child list**, whose head is passed.

How it works:

1. Traverse the current list to reach the node at `index`.
2. Set that node's `child` pointer to the head of another list.

Used in:

```cpp
list2.creat_child(1, list3.head);  // Node with value 7 gets child pointing to 9
list1.creat_child(2, list2.head);  // Node with value 3 gets child pointing to 6
```

---

### 🔹 Dry Run of `flatten_list()`

Initial structure:

```
List1: 1 <-> 2 <-> 3 (child 6) <-> 4 <-> 5
List2: 6 <-> 7 (child 9) <-> 8
List3: 9 <-> 10
```

Call: `flatten.head = flatten_list(list1.head);`

---

#### Step-by-step Execution:

* **Node 1** → No child → move to 2
* **Node 2** → No child → move to 3
* **Node 3** → Has `child = 6`

##### 1st recursive flatten on 6:

* **Node 6** → No child → move to 7
* **Node 7** → Has `child = 9`

###### 2nd recursive flatten on 9:

* **Node 9** → No child → move to 10
* **Node 10** → No child → end
  Return head = 9

> Flattened sublist returned: `9 <-> 10`
> Now attach it to node 7 → `7 -> 9 -> 10`
> Update links: `7.next = 9`, `9.prev = 7`, and so on.

> Final so far in list2: `6 <-> 7 <-> 9 <-> 10 <-> 8`

Return head = 6

> Back to node 3
> Attach the result (6...) to node 3:

* `3.next = 6`, `6.prev = 3`

Then connect flattened tail (`8`) to preserved `4`:

* Traverse till tail: 6 → 7 → 9 → 10 → 8
* `8.next = 4`, `4.prev = 8`

---

### 🔚 Final flattened structure:

```
1 <-> 2 <-> 3
            ↓
            6 <-> 7 <-> 9 <-> 10 <-> 8
                                     ↓
                                     4 <-> 5
```

Sequentially becomes:

```
1 <-> 2 <-> 3 <-> 6 <-> 7 <-> 9 <-> 10 <-> 8 <-> 4 <-> 5 <-> NULL
```

---

### ✅ Final Output Matches the Image:

```
Flatten: 1 <-> 2 <-> 3 <-> 6 <-> 7 <-> 9 <-> 10 <-> 8 <-> 4 <-> 5 <-> NULL
```
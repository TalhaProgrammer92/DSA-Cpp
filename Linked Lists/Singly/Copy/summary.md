### 🧠 Problem Overview: Copy List with Random Pointers

Here's given a linked list where each node contains:

* `next` pointer (standard)
* `random` pointer (can point to any node or `null`)

The **goal** is to return a deep copy of the list — i.e., a new list where each node has the same `value`, `next`, and `random` structure as the original, but is **completely independent**.

---

### 🧪 Dry Run on Example in Image

The list is:

```
7 → 13 → 11 → 10 → 1 → NULL
```

With random pointers:

* 7.random → NULL
* 13.random → 7
* 11.random → 1
* 10.random → 11
* 1.random → 7

---

### 🔎 Code Analysis

```cpp
Node *deep_copy(Node *head)
{
    Node *old_node = head->next, *new_head, *new_node, *new_temp;
    unordered_map<Node*, Node*> map;

    // Step 1: Copy head node
    new_head = new Node(head->value);
    new_temp = new_head;
    map[head] = new_temp;

    // Step 2: Copy rest of the nodes and build `next` links
    while (old_node != NULL)
    {
        Node *new_node = new Node(old_node->value);
        new_temp->next = new_node;

        new_temp = new_temp->next;
        map[old_node] = new_temp;
        old_node = old_node->next;
    }

    // Step 3: Copy the random pointers
    old_node = head;
    new_temp = new_head;
    while (old_node != NULL)
    {
        new_temp->random = map[old_node->random];

        old_node = old_node->next;
        new_temp = new_temp->next;
    }

    return new_head;
}
```

---

### ✅ DRY RUN (Step-by-Step)

#### Initialization:

* `map = {}`
* `new_head = new Node(7)`
* `map[7] = new_head`
* `new_temp = new_head`
* `old_node = head->next = 13`

#### 1️⃣ Copy `next` Pointers

* Create `Node(13)` → `new_temp->next = 13`
  `map[13] = new Node(13)`

* Create `Node(11)` → `map[11] = new Node(11)`

* Create `Node(10)` → `map[10] = new Node(10)`

* Create `Node(1)` → `map[1] = new Node(1)`

At this point, the new list (without randoms) looks like:

```
7' → 13' → 11' → 10' → 1' → NULL
```

#### 2️⃣ Copy `random` Pointers

Original `random` connections:

* 7.random → NULL → `7'.random = NULL`
* 13.random → 7 → `13'.random = map[7] = 7'`
* 11.random → 1 → `11'.random = map[1] = 1'`
* 10.random → 11 → `10'.random = map[11] = 11'`
* 1.random → 7 → `1'.random = map[7] = 7'`

---

### 🧾 Final New List

```
7' → 13' → 11' → 10' → 1' → NULL
 |      |       |      |
 v      v       v      v
NULL   7'      1'     11' 
                \
                 → 7'
```

---

### ⚡ Time & Space Complexity

* **Time:** `O(n)` (2 passes: one for `next`, one for `random`)
* **Space:** `O(n)` for the hash map

---

### 🛠️ Summary

The algorithm:

1. Clones the list while storing mappings from old to new nodes.
2. Uses the map to correctly assign random pointers in a second pass.

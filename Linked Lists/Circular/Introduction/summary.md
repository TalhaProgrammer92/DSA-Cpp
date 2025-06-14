## 🧠 **Theory: Circular Linked List**

A **Circular Linked List (CLL)** is a linear data structure where the last node **points back to the first**, creating a loop. It has no `NULL` at the end, unlike a singly linked list.

* **Head**: Points to the first node.
* **Tail**: Points to the last node.
* **tail->next = head** always.

### Common Operations:

1. Insert at head
2. Insert at tail
3. Delete from head
4. Delete from tail
5. Print the list

---

## 🧱 **Concept Overview (Class Design)**

### ✅ `Node` class:

* `int value`: stores the data.
* `Node* next`: pointer to the next node.

### ✅ `CircularLinkedList` class:

* **Private members**: `head`, `tail`
* **Public methods**:

  * `insert_at_head(int)`
  * `insert_at_tail(int)`
  * `delete_at_head()`
  * `delete_at_tail()`
  * `print()`
  * Destructor to deallocate memory.

---

## 🔄 **Method-by-Method DRY Run**

### 1. `insert_at_head(int value)`

#### Logic:

* Creates a new node.
* If list is empty, `head = tail = node`
* Else, points `node->next` to `head`, updates `head`
* Ensures circularity by `tail->next = head`

#### DRY Run:

Let list be empty.

```cpp
insert_at_head(1);
```

* new node created: `node(1)`
* `head = tail = node`
* `tail->next = head` → `1 -> 1`

Next:

```cpp
insert_at_head(0);
```

* new node: `node(0)`
* `node->next = head` → `0 -> 1`
* `head = node`, `tail->next = head`
* List: `0 -> 1 -> (loops back to 0)`

---

### 2. `insert_at_tail(int value)`

#### Logic:

* Creates a new node.
* If list is empty, `head = tail = node`
* Else, link current tail to new node, update tail
* Maintain circular link `tail->next = head`

#### DRY Run (continue previous state: `0 -> 1`):

```cpp
insert_at_tail(2);
```

* new node: `node(2)`
* `tail->next = node` → `1 -> 2`
* `tail = node`
* `tail->next = head` → `2 -> 0`
* List: `0 -> 1 -> 2 -> (loops to 0)`

---

### 3. `delete_at_head()`

#### Logic:

* If list is empty: do nothing.
* If list has 1 node: set `head = tail = NULL`
* Else:

  * Save current head in `temp`
  * `head = head->next`
  * `tail->next = head`
  * Delete `temp`

#### DRY Run (state: `0 -> 1 -> 2 -> 0`):

```cpp
delete_at_head();
```

* `temp = 0`
* `head = 1`
* `tail->next = 1`
* delete 0
* List: `1 -> 2 -> (loops to 1)`

---

### 4. `delete_at_tail()`

#### Logic:

* If list is empty: do nothing.
* If list has 1 node: `head = tail = NULL`
* Else:

  * Traverse to 2nd last node
  * Update `tail` to that node
  * `tail->next = head`
  * Delete old tail

#### DRY Run (state: `1 -> 2 -> 3 -> (loop to 1)`):

```cpp
delete_at_tail();
```

* `temp = 3`
* traverse to 2nd last → `node = 2`
* `tail = 2`, `tail->next = 1`
* delete 3
* List: `1 -> 2 -> (loop to 1)`

---

### 5. `print()`

#### Logic:

* If list is empty: print "List is empty!"
* Else:

  * Start from `head`
  * Loop until reaching `tail`, printing `value`
  * After loop, print `tail->value`

#### DRY Run:

List: `1 -> 2 -> 3 -> 4 -> 5 -> (loop to 1)`

```cpp
print();
```

Output:

```
1->2->3->4->5
```

---

### 6. `Destructor ~CircularLinkedList()`

#### Logic:

* While `head != NULL`, call `delete_at_head()`
* Frees memory for each node in circular list

---

## 🧪 **Main Function Flow**

### Insert Head:

```cpp
list.insert_at_head(5); // List: 5  
list.insert_at_head(4); // List: 4->5  
list.insert_at_head(3); // List: 3->4->5  
list.insert_at_head(2); // List: 2->3->4->5  
list.insert_at_head(1); // List: 1->2->3->4->5  
list.insert_at_head(0); // List: 0->1->2->3->4->5  
```

### Insert Tail:

```cpp
list.insert_at_tail(6); // 0->1->...->5->6  
list.insert_at_tail(7); // ...->6->7  
list.insert_at_tail(8); // ...->7->8  
list.insert_at_tail(9); // ...->8->9  
list.insert_at_tail(10); // ...->9->10  
```

### Delete Head:

```cpp
list.delete_at_head(); // Removes 0
```

### Delete Tail:

```cpp
list.delete_at_tail(); // Removes 10
```

### Final List:

```
1->2->3->4->5->6->7->8->9
```

---

## ✅ **Summary**

| Method             | Purpose                      | Maintains Circularity | Deallocates Memory           |
| ------------------ | ---------------------------- | --------------------- | ---------------------------- |
| insert\_at\_head() | Adds node at beginning       | ✅                     | ❌ (manual deletion required) |
| insert\_at\_tail() | Adds node at end             | ✅                     | ❌                            |
| delete\_at\_head() | Removes node from beginning  | ✅                     | ✅                            |
| delete\_at\_tail() | Removes node from end        | ✅                     | ✅                            |
| print()            | Displays all node values     | ✅                     | N/A                          |
| destructor         | Clears all memory at the end | ✅                     | ✅                            |
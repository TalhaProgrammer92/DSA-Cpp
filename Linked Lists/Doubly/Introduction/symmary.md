### ✅ **Definition: Doubly Linked List**

A **doubly linked list** is a dynamic data structure made of nodes where each node contains:

* **Data (value)**
* A pointer to the **next** node
* A pointer to the **previous** node

This allows **bidirectional traversal**, i.e., nodes can be traversed **forward** and **backward**.
It supports efficient **insertion** and **deletion** from both **front** and **back** ends.

---

### 🔍 **Dry Run of the Code**

Assume the following operations are performed:

```cpp
DoublyList list;
list.push_back(10);
list.push_front(20);
list.push_back(30);
list.print();       // Expected Output: 20<->10<->30<->NULL

list.pop_front();   
list.print();       // Expected Output: 10<->30<->NULL

list.pop_back();    
list.print();       // Expected Output: 10<->NULL
```

---

### Step-by-Step Execution:

#### 1️⃣ `list.push_back(10);`

* New node created with value `10`, next = NULL, previous = NULL.
* Since list is empty:

  * `head = node`
  * `tail = node`
* List now: `10<->NULL`

#### 2️⃣ `list.push_front(20);`

* New node created with value `20`, next = NULL, previous = NULL.
* Since list is not empty:

  * `node->next = head` → 20 → 10
  * `head->previous = node`
  * `head = node`
* List now: `20<->10<->NULL`

#### 3️⃣ `list.push_back(30);`

* New node created with value `30`, next = NULL, previous = NULL.
* Since list is not empty:

  * `node->previous = tail` → 10
  * `tail->next = node` → 10 → 30
  * `tail = node`
* List now: `20<->10<->30<->NULL`

#### 4️⃣ `list.print();`

* Traverses: 20 → 10 → 30
* Output:

  ```
  20<->10<->30<->NULL
  ```

---

#### 5️⃣ `list.pop_front();`

* `start = head` (node with value `20`)
* Since head ≠ tail:

  * `head = head->next` → new head is `10`
  * `start->next = NULL`
  * `head->previous = NULL`
* `delete start` (deletes 20)
* List now: `10<->30<->NULL`

#### 6️⃣ `list.print();`

* Traverses: 10 → 30
* Output:

  ```
  10<->30<->NULL
  ```

---

#### 7️⃣ `list.pop_back();`

* `node = tail->previous` → 10
* `temp = tail` → 30
* `tail = node` → tail = 10
* `node->next = NULL`
* `temp->previous = NULL`
* `delete temp` (deletes 30)
* List now: `10<->NULL`

#### 8️⃣ `list.print();`

* Traverses: 10
* Output:

  ```
  10<->NULL
  ```

---

### ✅ Summary After Operations

Final list:

```
10<->NULL
```
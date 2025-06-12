### 🔧 **Technique Used:**

The technique is **recursive merging** of two sorted linked lists.
At every recursive step:

* Compare the values at `head1` and `head2`.
* The smaller node becomes part of the merged list.
* Recurse with the remaining elements of the chosen list and the full other list.

---

### 🧠 **Step-by-Step Working (Dry Run):**

Input Lists:

```
List1: 1 -> 3 -> 5 -> NULL  
List2: 2 -> 3 -> 6 -> NULL
```

Let's trace the calls of:

```cpp
merge(1->3->5, 2->3->6)
```

---

#### 📍 Step 1:

```
head1 = 1, head2 = 2  
1 <= 2 → head1 is smaller
head1->next = merge(3->5, 2->3->6)
```

---

#### 📍 Step 2:

```
head1 = 3, head2 = 2  
2 < 3 → head2 is smaller
head2->next = merge(3->5, 3->6)
```

---

#### 📍 Step 3:

```
head1 = 3, head2 = 3  
3 <= 3 → head1 is smaller
head1->next = merge(5, 3->6)
```

---

#### 📍 Step 4:

```
head1 = 5, head2 = 3  
3 < 5 → head2 is smaller
head2->next = merge(5, 6)
```

---

#### 📍 Step 5:

```
head1 = 5, head2 = 6  
5 <= 6 → head1 is smaller
head1->next = merge(NULL, 6)
```

---

#### 📍 Step 6 (Base Case):

```
head1 = NULL → return head2 (6)
```

Now recursion starts **unwinding**, and pointers are connected back:

---

### 🪢 **Backtracking and Linking**

* `merge(NULL, 6)` returns `6`

  * So, `5->next = 6`
* `merge(5, 6)` returns `5`

  * So, `3->next = 5`
* `merge(3, 6)` returns `3`

  * So, `3->next = 3`
* `merge(3, 3->6)` returns `3`

  * So, `2->next = 3`
* `merge(3->5, 2->3->6)` returns `2`

  * So, `1->next = 2`

---

### ✅ **Final Merged List:**

```
1 -> 2 -> 3 -> 3 -> 5 -> 6 -> NULL
```

---

### 🔁 **Summary of Steps:**

1. Recursively compare heads of both lists.
2. Choose the smaller node to continue.
3. Recurse with the rest of the list.
4. When one list is empty, return the other.
5. Backtrack and link the nodes.

This approach uses **recursion** to naturally build and return the merged list without extra data structures.

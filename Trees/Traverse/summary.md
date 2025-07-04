## 🌳 Constructed Tree:

```
         1
       /   \
      2     3
     / \   /
    4   5 6
```

Each node:

* `1` is root
* `2` and `3` are children of `1`
* `4`, `5` are children of `2`
* `6` is left child of `3`

---

### 🟩 `preorder(root)`: Root → Left → Right

**Dry Run Trace** (what gets printed):

```shell
preorder(1)
→ print 1
→ preorder(2)
   → print 2
   → preorder(4)
      → print 4
      → preorder(NULL) // returns
      → preorder(NULL) // returns
   → preorder(5)
      → print 5
      → preorder(NULL) // returns
      → preorder(NULL) // returns
→ preorder(3)
   → print 3
   → preorder(6)
      → print 6
      → preorder(NULL)
      → preorder(NULL)
   → preorder(NULL)
```

**Output:**

```c
Preorder: 1 2 4 5 3 6
```

---

### 🟨 `inorder(root)`: Left → Root → Right

**Dry Run Trace**:

```shell
inorder(1)
→ inorder(2)
   → inorder(4)
      → inorder(NULL)
      → print 4
      → inorder(NULL)
   → print 2
   → inorder(5)
      → inorder(NULL)
      → print 5
      → inorder(NULL)
→ print 1
→ inorder(3)
   → inorder(6)
      → inorder(NULL)
      → print 6
      → inorder(NULL)
   → print 3
   → inorder(NULL)
```

**Output:**

```c
Inorder: 4 2 5 1 6 3
```

---

### 🟦 `postorder(root)`: Left → Right → Root

**Dry Run Trace**:

```shell
postorder(1)
→ postorder(2)
   → postorder(4)
      → postorder(NULL)
      → postorder(NULL)
      → print 4
   → postorder(5)
      → postorder(NULL)
      → postorder(NULL)
      → print 5
   → print 2
→ postorder(3)
   → postorder(6)
      → postorder(NULL)
      → postorder(NULL)
      → print 6
   → postorder(NULL)
   → print 3
→ print 1
```

**Output:**

```c
Postorder: 4 5 2 6 3 1
```

---

### 🔄 Summary Table

| Traversal | Order             | Output        |
| --------- | ----------------- | ------------- |
| Preorder  | Root, Left, Right | `1 2 4 5 3 6` |
| Inorder   | Left, Root, Right | `4 2 5 1 6 3` |
| Postorder | Left, Right, Root | `4 5 2 6 3 1` |

---

### 📌 Tip to Remember

* **Preorder** → Think of a pre-visit. Root comes first.
* **Inorder** → Classic LNR (Left-Node-Right), used in BSTs to get sorted output.
* **Postorder** → Post = Root is printed *after* left and right, useful in deletion.

---
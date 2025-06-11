A classic algorithm used to detect a **cycle in a linked list**, commonly known as **Floyd’s Cycle Detection Algorithm** or the **Tortoise and Hare algorithm**.

---

### ✅ **Explanation of the Approach**

* It uses two pointers:

  * `slow`: moves **one step at a time**
  * `fast`: moves **two steps at a time**
* Both pointers start at the `head` of the linked list.
* In each iteration:

  * `slow` moves to `slow->next`
  * `fast` moves to `fast->next->next`
* If there is **no cycle**, the `fast` pointer will eventually reach the end (`NULL`), and the loop will terminate.
* If there **is a cycle**, eventually `slow` and `fast` will **meet at the same node** inside the cycle. At that point, the function returns `true`.
* If the loop exits without the pointers meeting, it returns `false`.

```cpp
bool has_cycle(Node *head)
{
  if (head != NULL)
  {
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        return true;
    }
  }

  return false;
}
```

---

### 🕒 **Time Complexity**

* **O(n)**, where `n` is the number of nodes in the linked list.

  * In the worst case, `fast` and `slow` meet after traversing part of the list, and it will take linear time.
  * Even if a cycle exists, the number of steps before they meet is proportional to the number of nodes.

---

### 💾 **Space Complexity**

* **O(1)** (constant space)

  * Only two pointers (`slow`, `fast`) are used regardless of the size of the list.

---

### 🔁 Summary

| Aspect           | Value                                       |
| ---------------- | ------------------------------------------- |
| Time Complexity  | `O(n)`                                      |
| Space Complexity | `O(1)`                                      |
| Method Used      | Floyd's Cycle Detection (Tortoise and Hare) |
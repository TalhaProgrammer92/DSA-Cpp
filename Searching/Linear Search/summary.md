### **Initial Setup (main function)**

```cpp
int target = 6;
int array[] = {0, 4, 3, 7, 5, 6, 11};
```

* `target` is assigned the value `6`.
* `array` is initialized with 7 elements: `{0, 4, 3, 7, 5, 6, 11}`.

---

### **Size Calculation**

```cpp
sizeof(array) / sizeof(array[0])
```

* `sizeof(array)` gives total size in bytes of the array (7 integers).
* `sizeof(array[0])` gives size of one integer.
* Assuming `int` is 4 bytes:

  * `sizeof(array)` = `4 * 7` = `28`
  * `sizeof(array[0])` = `4`
* Result: `28 / 4 = 7`
* So, `size = 7`

---

### **Function Call**

```cpp
index = linear_search(array, 7, 6);
```

This calls the `linear_search` function with:

* `array[] = {0, 4, 3, 7, 5, 6, 11}`
* `size = 7`
* `target = 6`

---

### **Inside linear\_search**

```cpp
if (array != NULL)
```

* `array` is not `NULL`, so the condition passes.

```cpp
for (int i = 0; i < size; i++)
```

Loop begins to search for `target` (`6`):

* `i = 0`: array\[0] = 0 → not equal
* `i = 1`: array\[1] = 4 → not equal
* `i = 2`: array\[2] = 3 → not equal
* `i = 3`: array\[3] = 7 → not equal
* `i = 4`: array\[4] = 5 → not equal
* `i = 5`: array\[5] = 6 → match found

```cpp
return i; // returns 5
```

---

### **Back to main**

```cpp
int index = 5;
```

The function returns `5`, so `index` gets the value `5`.

---

### **Final Output**

```cpp
cout << "The target " << target << " is located at index " << index << endl;
```

Prints:

```
The target 6 is located at index 5
```

---

### **Conclusion**

* The program performs a **linear search**.
* It finds the `target` (6) at index `5` in the array.
* The result is correctly printed to the console.

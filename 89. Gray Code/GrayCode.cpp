/*# Intuition

Gray code is a sequence where every two consecutive numbers differ by exactly **one bit**.

To generate the Gray code for `n` bits:

* Assume we already know the Gray code sequence for `n-1` bits.
* Copy that sequence as the first half.
* Traverse the previous sequence **in reverse order**, and set the newly added highest bit (`n-1`th bit) to `1`.
* Appending these numbers ensures that:

  * Adjacent numbers inside each half differ by one bit.
  * The last number of the first half and the first number of the second half also differ by only one bit.

This is known as the **Reflection Method** for generating Gray codes.

---

# Approach

1. **Base Case**

   * For `n = 1`, the Gray code sequence is:

     ```
     [0, 1]
     ```

2. **Recursive Step**

   * Recursively generate the Gray code for `n-1` bits.
   * Copy this sequence into the answer.
   * Compute the new highest bit:

     ```cpp
     int bit = 1 << (n-1);
     ```
   * Traverse the previous sequence in reverse order.
   * Set the highest bit using bitwise OR (`bit | temp[i]`) and append it.

3. Return the constructed sequence.

---

# Time Complexity

* At each level, all previously generated values are copied once.
* Total numbers generated = (2^n).

**Time Complexity:** `O(2^n)`

---

# Space Complexity

* The output itself contains `2^n` integers.
* Recursive depth is `O(n)`.

**Space Complexity:** `O(2^n)` (output) + `O(n)` (recursion stack)

---

# Code

```cpp*/
class Solution {
public:

    vector<int> solve(int n){
        if(n==1){
            return {0, 1};
        }

        vector<int> temp = solve(n-1);
        vector<int> ans = temp;

        int bit = 1 << (n-1);

        for(int i = temp.size()-1; i >= 0; i--){
            ans.push_back(bit | temp[i]);
        }

        return ans;
    }

    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        return solve(n);
    }
};/*
```

---

# Dry Run (Example: `n = 3`)

### Step 1: `solve(1)`

```
[0, 1]
```

---

### Step 2: `solve(2)`

Previous:

```
[0, 1]
```

Highest bit:

```
1 << 1 = 2 (10₂)
```

Reverse previous:

```
1, 0
```

Add highest bit:

```
2 | 1 = 3
2 | 0 = 2
```

Result:

```
[0, 1, 3, 2]
```

---

### Step 3: `solve(3)`

Previous:

```
[0, 1, 3, 2]
```

Highest bit:

```
1 << 2 = 4 (100₂)
```

Reverse previous:

```
2, 3, 1, 0
```

Add highest bit:

```
4 | 2 = 6
4 | 3 = 7
4 | 1 = 5
4 | 0 = 4
```

Final Gray code:

```
[0, 1, 3, 2, 6, 7, 5, 4]
```

### Binary Representation

| Decimal | Binary |
| ------: | :----: |
|       0 |   000  |
|       1 |   001  |
|       3 |   011  |
|       2 |   010  |
|       6 |   110  |
|       7 |   111  |
|       5 |   101  |
|       4 |   100  |

Notice that every consecutive pair differs by exactly **one bit**, satisfying the Gray code property.
*/

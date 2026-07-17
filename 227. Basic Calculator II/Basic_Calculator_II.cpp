# Intuition

The expression contains only `+`, `-`, `*`, and `/` operators with no parentheses.

Instead of evaluating everything immediately, we use a stack to respect operator precedence:

* For `+`, push the current number.
* For `-`, push the negative of the current number.
* For `*` and `/`, immediately compute the result with the top of the stack and push it back.

At the end, all multiplication and division have already been evaluated, so simply summing the stack gives the final answer.

---

# Approach

1. Initialize:

   * A stack to store numbers.
   * `curr_num` to build multi-digit numbers.
   * `last_sign` as `'+'` (assume the first number is positive).
2. Traverse the string character by character.
3. If the current character is a digit:

   * Build the current number.
4. If the current character is an operator (or we've reached the end of the string):

   * Perform the operation indicated by `last_sign`:

     * `'+'` → Push `curr_num`.
     * `'-'` → Push `-curr_num`.
     * `'*'` → Pop the top, multiply by `curr_num`, push the result.
     * `'/'` → Pop the top, divide by `curr_num`, push the result.
   * Update `last_sign`.
   * Reset `curr_num` to `0`.
5. Finally, pop all elements from the stack and add them to obtain the answer.

---

# Time Complexity

* Each character is processed exactly once.

**Time Complexity:** **O(n)**

where `n` is the length of the string.

---

# Space Complexity

* In the worst case (only `+` and `-` operations), every number is pushed onto the stack.

**Space Complexity:** **O(n)**

---

# Code

```cpp
class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) {
            return 0;
        }

        stack<int> st;
        int curr_num = 0;
        char last_sign = '+';

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                curr_num = curr_num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || (i == s.length() - 1)) {

                if (last_sign == '+') {
                    st.push(curr_num);
                }
                else if (last_sign == '-') {
                    st.push(-curr_num);
                }
                else if (last_sign == '*') {
                    int num = st.top();
                    st.pop();
                    st.push(num * curr_num);
                }
                else if (last_sign == '/') {
                    int num = st.top();
                    st.pop();
                    st.push(num / curr_num);
                }

                curr_num = 0;
                last_sign = c;
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
```

---

# Dry Run

### Example

```
s = "3+2*2"
```

| Character | curr_num | last_sign | Stack | Action            |
| --------- | -------: | :-------: | :---: | ----------------- |
| '3'       |        3 |    '+'    |   []  | Build number      |
| '+'       |        0 |    '+'    |  [3]  | Push 3            |
| '2'       |        2 |    '+'    |  [3]  | Build number      |
| '*'       |        0 |    '*'    | [3,2] | Push 2            |
| '2'       |        2 |    '*'    | [3,2] | Build number      |
| End       |        0 |    '2'    | [3,4] | Compute 2 × 2 = 4 |

Now sum the stack:

```
3 + 4 = 7
```

**Answer = 7**

---

### Example 2

```
s = "14-3/2"
```

| Character | curr_num | last_sign |  Stack  | Action              |
| --------- | -------: | :-------: | :-----: | ------------------- |
| '1','4'   |       14 |    '+'    |    []   | Build 14            |
| '-'       |        0 |    '-'    |   [14]  | Push 14             |
| '3'       |        3 |    '-'    |   [14]  | Build number        |
| '/'       |        0 |    '/'    | [14,-3] | Push -3             |
| '2'       |        2 |    '/'    | [14,-3] | Build number        |
| End       |        0 |    '2'    | [14,-1] | Compute -3 / 2 = -1 |

Sum the stack:

```
14 + (-1) = 13
```

**Answer = 13**

---

### Why does this work?

* `+` and `-` simply store values (positive or negative).
* `*` and `/` are evaluated immediately with the most recent number, ensuring the correct operator precedence.
* After processing the entire string, only addition remains, so summing the stack produces the correct result.

✅ **Time Complexity:** `O(n)`
✅ **Space Complexity:** `O(n)` (optimal for the stack-based approach)

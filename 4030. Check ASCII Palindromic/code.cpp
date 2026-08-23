## Intuition

For each character:

1. Convert it to its ASCII value.
2. Extract its 8 bits from left to right.
3. Append those bits to `str`.
4. Check whether the resulting binary string is a palindrome.

### Example

For:

```cpp
s = "A"
```

ASCII of `'A'` = `65`

Binary representation:

```text
01000001
```

Reverse:

```text
10000010
```

They are different, so:

```cpp
false
```

---

## Approach

```cpp
class Solution {
public:
    bool isPalindromic(string s) {
        string str = "";

        // Convert every character into 8-bit binary
        for (auto it : s) {
            int ascii = it;

            for (int i = 7; i >= 0; i--) {
                str += ((ascii >> i) & 1) + '0';
            }
        }

        // Check if the complete binary string is palindrome
        int start = 0;
        int end = str.length() - 1;

        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};
```

## Time Complexity

Let `n` be the length of `s`.

* Converting each character takes `8` operations.
* Palindrome checking takes `8n` operations.

So:

**Time Complexity: `O(n)`**

## Space Complexity

You create a binary string of length `8n`.

**Space Complexity: `O(n)`**

---

## Dry Run

```text
s = "A"
```

### Step 1: Convert `'A'`

```text
ASCII('A') = 65
```

8-bit binary:

```text
01000001
```

So:

```text
str = "01000001"
```

### Step 2: Palindrome Check

```text
start = 0 → '0'
end = 7   → '1'
```

Since:

```text
'0' != '1'
```

Return:

```text
false
```

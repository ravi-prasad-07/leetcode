# 214. Shortest Palindrome

## Problem Description

Given a string `s`, you can convert it to a palindrome by adding characters in front of it.

Return the **shortest palindrome** you can find by performing this transformation.

### Example 1

**Input:**
```text
s = "aacecaaa"
```

**Output:**
```text
"aaacecaaa"
```

### Example 2

**Input:**
```text
s = "abcd"
```

**Output:**
```text
"dcbabcd"
```

---

## Approach: KMP Algorithm (LPS Array)

### Intuition

The goal is to make the given string a palindrome by adding the minimum number of characters at the beginning.

A string is a palindrome if it reads the same forward and backward.

Instead of checking every possible prefix, we can use the **KMP (Knuth-Morris-Pratt) algorithm** to find the longest palindromic prefix efficiently.

The main idea is:

1. Find the reverse of the original string.
2. Construct a combined string using the original string, a separator, and its reverse.
3. Build the LPS (Longest Prefix Suffix) array for the combined string.
4. The last value of the LPS array gives the length of the longest palindromic prefix.
5. Reverse the remaining suffix and add it to the beginning of the original string.

### Why Does This Work?

Let the original string be `s` and its reverse be `rev`.

Construct the string:

```text
s + "#" + rev
```

The `#` character acts as a separator between the two strings.

The final LPS value represents the longest prefix of `s` that matches a suffix of `rev`. This matching portion is the longest palindromic prefix of the original string.

Once we know its length, we only need to reverse the characters that come after this prefix and prepend them to the original string.

---

## C++ Solution

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();

        if (n == 1) {
            return s;
        }

        string ans = s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        s = s + '#' + rev;

        int m = s.length();
        vector<int> lps(m, 0);

        int length = 0;
        int i = 1;

        while (i < m) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            }
            else {
                if (length != 0) {
                    length = lps[length - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int idx = lps[m - 1];

        string sub = ans.substr(idx);

        reverse(sub.begin(), sub.end());

        sub += ans;

        return sub;
    }
};
```

---

## Dry Run

Consider the input:

```text
s = "aacecaaa"
```

### Step 1: Reverse the String

```text
Original: aacecaaa
Reverse:  aaacecaa
```

### Step 2: Construct the Combined String

```text
s + "#" + rev

aacecaaa#aaacecaa
```

### Step 3: Build the LPS Array

Using the KMP algorithm, calculate the LPS array for the combined string.

The last value is:

```text
lps[m - 1] = 7
```

Therefore, the longest palindromic prefix has a length of `7`.

### Step 4: Extract the Remaining Suffix

The original string is:

```text
a a c e c a a a
0 1 2 3 4 5 6 7
```

The first seven characters form the palindrome:

```text
aacecaa
```

The remaining suffix is:

```text
a
```

### Step 5: Reverse the Suffix

```text
Suffix:          a
Reversed suffix: a
```

### Step 6: Add the Reversed Suffix to the Beginning

```text
Reversed suffix + Original string

a + aacecaaa
```

**Final Output:**

```text
aaacecaaa
```

The resulting string is a palindrome, and only one character was added to the beginning.

---

## Complexity Analysis

Let `n` be the length of the input string.

### Time Complexity: O(n)

- Reversing the string takes `O(n)` time.
- Constructing the combined string takes `O(n)` time.
- Building the LPS array takes `O(n)` time.
- Extracting and reversing the suffix takes at most `O(n)` time.

Therefore, the overall time complexity is **O(n)**.

### Space Complexity: O(n)

- The reversed string requires `O(n)` space.
- The combined string requires `O(n)` space.
- The LPS array requires `O(n)` space.
- The resulting substring requires at most `O(n)` space.

Therefore, the overall auxiliary space complexity is **O(n)**.

---

## Key Takeaways

- The problem can be solved efficiently using the KMP algorithm.
- The LPS array helps identify the longest palindromic prefix.
- Only the suffix after the longest palindromic prefix needs to be reversed and added to the beginning.
- This approach avoids checking every prefix individually.
- The solution runs in linear time, `O(n)`.

## LeetCode

**Problem:** [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)

**Topic Tags:** String, KMP Algorithm, LPS Array, String Matching

**Language:** C++

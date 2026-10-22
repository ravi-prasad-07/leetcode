````

# 583. Delete Operation for Two Strings

**Difficulty:** Medium
**Topics:** String, Dynamic Programming, Recursion, Memoization
**Language:** C++

---

## Problem Statement

Given two strings `word1` and `word2`, return the minimum number of steps required to make the two strings equal.

In one step, you can delete exactly one character from either string.

### Example 1

**Input**
```text
word1 = "sea"
word2 = "eat"
```

**Output**
```text
2
```

**Explanation:** Delete `'s'` from `"sea"` and `'t'` from `"eat"`. Both strings become `"ea"`.

---

## Intuition

To make two strings equal, we need to delete characters that do not belong to their common subsequence.

We compare characters from the end of both strings:

- If the characters match, keep them and move both pointers backward.
- If the characters differ, try deleting a character from either string and choose the option with fewer deletions.
- If one string becomes empty, delete all remaining characters from the other string.

Since the same subproblems can occur multiple times, we use **memoization (top-down dynamic programming)** to store previously computed results.

## Approach

Define `solve(str, st, i, j)` as the minimum number of deletions required to make the prefixes `str[0...i]` and `st[0...j]` equal.

1. **Base cases**
   - If `i < 0`, return `j + 1`.
   - If `j < 0`, return `i + 1`.

2. **Memoization**

   If `dp[i][j] != -1`, return the previously computed result.

3. **Matching characters**

   If `str[i] == st[j]`, no deletion is needed for these characters. Move both pointers backward.

4. **Different characters**

   Delete one character from either string and choose the minimum:

   ```cpp
   1 + min(
       solve(str, st, i, j - 1, dp),
       solve(str, st, i - 1, j, dp)
   )
   ```

5. Store the computed result in `dp[i][j]` and return it.

---

## C++ Solution

```cpp
class Solution {
private:
    int solve(const string& str, const string& st,
              int i, int j, vector<vector<int>>& dp) {
        if (i < 0) {
            return j + 1;
        }

        if (j < 0) {
            return i + 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (str[i] == st[j]) {
            return dp[i][j] =
                solve(str, st, i - 1, j - 1, dp);
        }

        return dp[i][j] = 1 + min(
            solve(str, st, i, j - 1, dp),
            solve(str, st, i - 1, j, dp)
        );
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(word1, word2, n - 1, m - 1, dp);
    }
};
```

---

## Dry Run

**Input**

```text
word1 = "sea"
word2 = "eat"
```

Initially, `i = 2` and `j = 2`.

| `word1[i]` | `word2[j]` | Decision |
|:---:|:---:|---|
| `a` | `t` | Characters differ. Try deleting either character. |
| `a` | `a` | Characters match. Move both pointers backward. |
| `e` | `e` | Characters match. Move both pointers backward. |
| `s` | Empty | Delete the remaining character `s`. |

### Result

1. Delete `'s'` from `"sea"` to obtain `"ea"`.
2. Delete `'t'` from `"eat"` to obtain `"ea"`.

**Output:** `2`

### DP Table

Each cell represents the minimum deletions needed to make the corresponding prefixes equal. The empty prefix is included for clarity.

| `word1 \ word2` | `""` | `"e"` | `"ea"` | `"eat"` |
|:---:|---:|---:|---:|---:|
| `""` | 0 | 1 | 2 | 3 |
| `"s"` | 1 | 2 | 3 | 4 |
| `"se"` | 2 | 1 | 2 | 3 |
| `"sea"` | 3 | 2 | 1 | **2** |

The bottom-right cell gives the final answer: **2 deletions**.

---

## Complexity Analysis

Let `n` and `m` be the lengths of `word1` and `word2`, respectively.

- **Time Complexity:** `O(n * m)` — Each DP state is computed at most once.
- **Space Complexity:** `O(n * m)` — The memoization table uses `O(n * m)` space, and the recursion stack requires up to `O(n + m)` additional space.

---

## Key Takeaway

This problem is closely related to the **Longest Common Subsequence (LCS)** problem.

If `LCS` is the length of the longest common subsequence of the two strings, then:

$$
\text{Minimum Deletions} = n + m - 2 \times LCS
$$

We retain the common subsequence and delete all characters outside it.

---

## Related Problems

- [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
- [712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)
- [1092. Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/)

---

**LeetCode Problem:** [583. Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/)
````

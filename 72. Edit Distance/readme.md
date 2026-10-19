# 72. Edit Distance

**Difficulty:** Medium  
**Topic:** Dynamic Programming, Recursion, Memoization  
**LeetCode:** [Edit Distance](https://leetcode.com/problems/edit-distance/)

## Problem Statement

Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` into `word2`.

You can perform the following three operations:

1. **Insert** a character.
2. **Delete** a character.
3. **Replace** a character.

## Intuition

The goal is to convert `word1` into `word2` using the minimum number of operations.

We compare the characters of both strings from right to left.

- If the current characters are equal, no operation is needed. We move to the previous characters in both strings.
- If the characters are different, we have three choices: insert, delete, or replace a character.

We calculate the cost of all three operations and choose the minimum.

To avoid recalculating the same subproblems, we use **recursion with memoization**.

## Approach

### 1. Define the DP State

Let:

`solve(str, st, n, m)`

represent the minimum operations required to convert the prefix `str[0...n]` into `st[0...m]`.

We store computed answers in a 2D DP array:

`dp[n][m]`

### 2. Handle Base Cases

- If `n < 0`, the first string has no characters left. We must insert all remaining characters of the second string, requiring `m + 1` operations.
- If `m < 0`, the second string has no characters left. We must delete all remaining characters of the first string, requiring `n + 1` operations.

### 3. If Characters Are Equal

If `str[n] == st[m]`, no operation is required.

Move to the previous characters in both strings:

```cpp
solve(str, st, n - 1, m - 1, dp);
```

### 4. If Characters Are Different

Consider the following three operations:

- **Insert:** `solve(str, st, n, m - 1, dp)`
- **Delete:** `solve(str, st, n - 1, m, dp)`
- **Replace:** `solve(str, st, n - 1, m - 1, dp)`

Take the minimum cost and add `1` for the current operation:

```cpp
1 + min({insert, del, replace});
```

### 5. Memoization

Before calculating a state, check whether its answer is already stored in `dp`.

If it is, return the stored result. Otherwise, calculate the answer and save it.

## C++ Solution

```cpp
class Solution {
private:
    int solve(const string& str, const string& st,
              int n, int m, vector<vector<int>>& dp) {

        if (n < 0) {
            return m + 1;
        }

        if (m < 0) {
            return n + 1;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (str[n] == st[m]) {
            return dp[n][m] =
                solve(str, st, n - 1, m - 1, dp);
        }

        int insert = solve(str, st, n, m - 1, dp);
        int del = solve(str, st, n - 1, m, dp);
        int replace = solve(str, st, n - 1, m - 1, dp);

        return dp[n][m] =
            1 + min({insert, del, replace});
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(
            word1.length(),
            vector<int>(word2.length(), -1)
        );

        return solve(
            word1,
            word2,
            word1.length() - 1,
            word2.length() - 1,
            dp
        );
    }
};
```

## Example

**Input:**

```text
word1 = "horse"
word2 = "ros"
```

**Output:**

```text
3
```

**Explanation:**

Convert `"horse"` into `"ros"` using three operations:

```text
horse
  ↓ Replace 'h' with 'r'
rorse
  ↓ Delete 'r'
rose
  ↓ Delete 'e'
ros
```

Therefore, the minimum number of operations is `3`.

## Dry Run

For `word1 = "horse"` and `word2 = "ros"`:

| Step | Operation | Result | Cost |
|---|---|---|---:|
| 1 | Replace `h` with `r` | `rorse` | 1 |
| 2 | Delete `r` | `rose` | 2 |
| 3 | Delete `e` | `ros` | 3 |

The recursive solution explores the possible operations and returns the minimum cost. Memoization ensures that each DP state is calculated at most once.

**Final Answer:** `3`

## Complexity Analysis

Let:

- `N` = length of `word1`
- `M` = length of `word2`

### Time Complexity

**`O(N × M)`**

There are at most `N × M` unique DP states, and each state performs constant additional work.

### Space Complexity

**`O(N × M)`** for the DP table, plus **`O(N + M)`** for the recursion stack in the worst case.

Overall space complexity is **`O(N × M)`**.

## Key Takeaways

- Edit Distance is a classic Dynamic Programming problem.
- Use recursion with memoization to avoid repeated calculations.
- Equal characters require no operation.
- Different characters lead to three choices: insert, delete, or replace.
- The minimum of these choices gives the optimal answer.

---

**Pattern:** Recursion + Memoization (Top-Down Dynamic Programming)

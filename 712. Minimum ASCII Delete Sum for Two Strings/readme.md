# LeetCode 712. Minimum ASCII Delete Sum for Two Strings

## Problem Statement

Given two strings `s1` and `s2`, return the minimum sum of ASCII values of deleted characters required to make the two strings equal.

## Approach: Recursion + Memoization (Dynamic Programming)

### Intuition

The goal is to make both strings equal by deleting characters with the minimum possible ASCII cost.

We define `solve(i, j)` as the minimum deletion cost required to make the prefixes `s1[0...i]` and `s2[0...j]` equal.

For each pair of characters, we have three cases:

1. **Both characters are equal:** No deletion is required for these characters. Move to the previous characters in both strings.
2. **Characters are different:** We can either delete the current character from `s1` or delete it from `s2`. Choose the option with the smaller total cost.
3. **One string becomes empty:** Delete all remaining characters from the other string and add their ASCII values.

We use memoization to avoid solving the same subproblem multiple times.

### Algorithm

1. Create a 2D DP array initialized with `-1`.
2. Start recursion from the last indices of both strings.
3. If the characters match, recursively process the previous characters.
4. Otherwise, calculate the cost of deleting either character and take the minimum.
5. Handle empty-string cases by summing the ASCII values of the remaining characters.
6. Return the minimum deletion cost.

## C++ Solution

```cpp
class Solution {
private:
    int solve(const string& s1, const string& s2,
              int i, int j, vector<vector<int>>& dp) {

        if (i < 0) {
            int sum = 0;
            for (int k = 0; k <= j; k++) {
                sum += (int)s2[k];
            }
            return sum;
        }

        if (j < 0) {
            int sum = 0;
            for (int k = 0; k <= i; k++) {
                sum += (int)s1[k];
            }
            return sum;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            return dp[i][j] =
                solve(s1, s2, i - 1, j - 1, dp);
        }

        return dp[i][j] = min(
            (int)s1[i] + solve(s1, s2, i - 1, j, dp),
            (int)s2[j] + solve(s1, s2, i, j - 1, dp)
        );
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s1, s2, n - 1, m - 1, dp);
    }
};
```

## Complexity Analysis

Let `n` be the length of `s1` and `m` be the length of `s2`.

- **Time Complexity:** `O(n * m * (n + m))` in the worst case, because the base cases sum the remaining characters using loops.
- **Space Complexity:** `O(n * m)` for the DP table, plus `O(n + m)` for the recursion stack.

**Optimization:** Precomputing prefix ASCII sums allows the base cases to run in `O(1)`, reducing the time complexity to `O(n * m)`.

## Dry Run

**Input:**

```text
s1 = "sea"
s2 = "eat"
```

ASCII values:

| Character | ASCII Value |
|---|---:|
| `s` | 115 |
| `e` | 101 |
| `a` | 97 |
| `t` | 116 |

The longest common subsequence is `"ea"`. We can keep these characters and delete:

- `s` from `s1`, costing `115`.
- `t` from `s2`, costing `116`.

Total minimum deletion cost:

```text
115 + 116 = 231
```

**Output:**

```text
231
```

## Key Takeaway

This problem demonstrates how recursion with memoization can optimize overlapping subproblems. When characters differ, exploring both deletion choices and taking the minimum leads to the optimal answer.

**Tags:** `Dynamic Programming` `Recursion` `Memoization` `Strings`

**LeetCode:** https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

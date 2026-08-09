/*## Maximum Area of a Square Appearing More Than Once

### Intuition

We first need to know the **largest square of `1`s ending at every cell**.

For this, we use the standard DP for the **Largest Square of 1s** problem:

```cpp
dp[i][j] = 1 + min(
    dp[i-1][j],
    dp[i][j-1],
    dp[i-1][j-1]
);
```

Here, `dp[i][j]` represents the **side length of the largest all-1 square whose bottom-right corner is `(i, j)`**.

After calculating `dp`, we know the maximum possible square size.

---

### How do we find a square size that occurs more than once?

Suppose we are checking squares of side `k`.

If:

```cpp
dp[i][j] >= k
```

then there is a `k × k` square ending at `(i,j)`.

Its top-left corner is:

```cpp
row = i - k + 1;
col = j - k + 1;
```

So we collect the minimum and maximum row/column of all such top-left corners.

If two squares have top-left corners separated by at least `k` rows:

```cpp
maxr - minr >= k
```

then they are vertically separated enough to be two distinct `k × k` squares.

Similarly:

```cpp
maxc - minc >= k
```

means they are horizontally separated enough.

We check sizes from **largest to smallest**, so the first valid `k` gives the maximum area.

---

## Approach

1. Build the `dp` table using bottom-up DP.
2. Find the largest possible square size `maxSquare`.
3. Start checking from `maxSquare` down to `1`.
4. For every size `k`, find all possible `k × k` squares.
5. Track the minimum and maximum top-left row/column.
6. If two squares are separated by at least `k` rows or columns, return `k²`.
7. If no such square exists, return `0`.

---

## C++ Code

```cpp*/
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxSquare = 0;

        // Step 1: Find the largest square of 1s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 1) {

                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 1 + min({
                            dp[i - 1][j],
                            dp[i][j - 1],
                            dp[i - 1][j - 1]
                        });
                    }

                    maxSquare = max(maxSquare, dp[i][j]);
                }
            }
        }

        // Step 2: Check square sizes from largest to smallest
        for (int k = maxSquare; k >= 1; k--) {

            int minr = m;
            int maxr = -1;

            int minc = n;
            int maxc = -1;

            // Find all k x k squares
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (dp[i][j] >= k) {

                        // Top-left corner of k x k square
                        int row = i - k + 1;
                        int col = j - k + 1;

                        minr = min(minr, row);
                        maxr = max(maxr, row);

                        minc = min(minc, col);
                        maxc = max(maxc, col);
                    }
                }
            }

            // Two squares are separated vertically
            if (maxr - minr >= k) {
                return k * k;
            }

            // Two squares are separated horizontally
            if (maxc - minc >= k) {
                return k * k;
            }
        }

        return 0;
    }
};/*
```

---

## Time Complexity

The DP table takes:

```text
O(m × n)
```

Then, for every possible square size `k`, we scan the entire matrix.

There can be at most `min(m,n)` different values of `k`.

Therefore:

```text
Time: O(m × n × min(m,n))
```

For a square matrix where `m = n`:

```text
O(n³)
```

---

## Space Complexity

We store the complete `dp` table:

```text
O(m × n)
```

So:

```text
Space: O(m × n)
```

---

# Dry Run

Consider:

```text
mat =
1 1 0 1 1
1 1 0 1 1
0 0 0 0 0
1 1 1 0 0
1 1 1 0 0
```

The DP table becomes:

```text
1 1 0 1 1
1 2 0 1 2
0 0 0 0 0
1 1 1 0 0
1 2 2 0 0
```

So:

```text
maxSquare = 2
```

Now check `k = 2`.

We have multiple `2 × 2` squares:

```text
(0,0)          (0,3)

1 1            1 1
1 1            1 1
```

Their top-left columns are:

```text
0 and 3
```

Since:

```text
maxc - minc
= 3 - 0
= 3
>= 2
```

there are at least two distinct `2 × 2` squares.

Therefore:

```text
answer = 2 × 2 = 4
```

### Final Answer

```text
4
```

### Key idea to remember

> **`dp[i][j]` tells us the largest square ending at `(i,j)`. For a fixed `k`, `dp[i][j] >= k` means a `k × k` square exists. Since we check `k` from largest to smallest, the first repeated/separated size gives the maximum area.**
*/

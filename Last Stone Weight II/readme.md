# Last Stone Weight II

## Intuition

The goal is to minimize the final weight after smashing stones together. Instead of simulating every possible smash, we can divide the stones into two groups.

Let:
- `sum` be the total weight of all stones.
- `total` be the sum of the stones in the first group.
- `sum - total` be the sum of the stones in the second group.

The final difference between the two groups is:

\[
|total - (sum - total)|
\]

To minimize this difference, we need to divide the stones into two groups with sums as close as possible. Therefore, we aim to find a subset whose sum is close to half of the total sum.

## Approach

1. Calculate the total sum of all stones.
2. Set the target to `ceil(sum / 2)`.
3. Use recursion with memoization to explore two choices for each stone:
   - **Take:** Include the current stone in the subset.
   - **Not Take:** Skip the current stone.
4. Stop exploring a branch when the selected sum reaches the target or all stones have been processed.
5. Calculate the absolute difference between the two groups and return the minimum difference.

The DP state `dp[i][total]` stores the minimum difference for the current index and selected sum.

## C++ Solution

```cpp
class Solution {
private:
    int solve(vector<int>& stones, int i, int total,
              int target, int sum, vector<vector<int>>& dp) {

        if (total >= target || i == stones.size()) {
            return abs(total - (sum - total));
        }

        if (dp[i][total] != -1) {
            return dp[i][total];
        }

        int notTake = solve(
            stones, i + 1, total, target, sum, dp
        );

        int take = solve(
            stones, i + 1, total + stones[i],
            target, sum, dp
        );

        return dp[i][total] = min(notTake, take);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;

        for (int stone : stones) {
            sum += stone;
        }

        int target = ceil((double)sum / 2);

        vector<vector<int>> dp(
            stones.size() + 1,
            vector<int>(target + 1, -1)
        );

        return solve(stones, 0, 0, target, sum, dp);
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(n * S)`
  - `n` is the number of stones.
  - `S` is the sum of all stone weights.
  - There are at most `O(n * S)` DP states, each requiring constant work.

- **Space Complexity:** `O(n * S)`
  - The DP table requires `O(n * S)` space.
  - The recursion stack requires `O(n)` additional space.

## Dry Run

**Input:**

```text
stones = [2, 7, 4, 1, 8, 1]
```

**Step 1:** Calculate the total sum.

```text
sum = 2 + 7 + 4 + 1 + 8 + 1 = 23
target = ceil(23 / 2) = 12
```

**Step 2:** Find a subset with a sum as close as possible to `12`.

One possible subset is:

```text
Group 1 = [2, 7, 1, 1]
Group 1 sum = 11
```

The remaining stones are:

```text
Group 2 = [4, 8]
Group 2 sum = 12
```

**Step 3:** Calculate the final difference.

```text
Difference = |11 - 12| = 1
```

**Output:**

```text
1
```

## Key Takeaway

This problem can be reduced to a **subset sum / 0/1 knapsack problem**. By dividing the stones into two groups with nearly equal sums, we minimize the final remaining weight. Recursion with memoization avoids recomputing overlapping states and improves efficiency.

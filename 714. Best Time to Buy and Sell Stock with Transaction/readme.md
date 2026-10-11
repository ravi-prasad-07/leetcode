# Best Time to Buy and Sell Stock with Transaction Fee

## Problem Statement

You are given an array `prices` where `prices[i]` represents the price of a stock on the `i`-th day, and an integer `fee` representing the transaction fee for each transaction.

You can complete as many transactions as you like, but you must pay the transaction fee for each completed transaction.

Return the maximum profit you can achieve.

**LeetCode Problem:** [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

---

## Intuition

On every day, we have two possible states:

- **`buy = 1`:** We are allowed to buy a stock.
- **`buy = 0`:** We already hold a stock and can sell it.

For each state, we have two choices: perform an operation or skip it.

### Case 1: `buy == 1`

We can either:

1. Buy the stock by subtracting its price from our profit.
2. Skip buying and move to the next day.

```cpp
max(
    -prices[idx] + solve(idx + 1, 0),
    solve(idx + 1, 1)
)
```

### Case 2: `buy == 0`

We can either:

1. Sell the stock and subtract the transaction fee.
2. Hold the stock and wait for a better selling price.

```cpp
max(
    prices[idx] - fee + solve(idx + 1, 1),
    solve(idx + 1, 0)
)
```

We use **memoization** to store the results of previously calculated states and avoid redundant recursive calls.

## Approach: Recursion + Memoization

1. Create a DP table of size `n × 2`, initialized with `-1`.
2. Start from index `0` with `buy = 1`, because initially we do not own a stock.
3. If `idx` reaches the end of the array, return `0`.
4. If the current state is already calculated, return `dp[idx][buy]`.
5. If `buy == 1`, calculate the maximum profit between buying and skipping.
6. If `buy == 0`, calculate the maximum profit between selling and holding.
7. Store the result in `dp[idx][buy]`.
8. Return the result for the initial state.

### DP State

`dp[idx][buy]` represents the maximum profit obtainable from day `idx` onward, given the current buying state.

- `dp[idx][1]`: Maximum profit when we are allowed to buy.
- `dp[idx][0]`: Maximum profit when we are holding a stock and can sell it.

---

## C++ Solution

```cpp
class Solution {
private:
    int solve(const vector<int>& arr, int fee, int idx, int buy,
              vector<vector<int>>& dp) {

        if (idx >= arr.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        if (buy) {
            int buyStock = -arr[idx] +
                           solve(arr, fee, idx + 1, 0, dp);

            int skip = solve(arr, fee, idx + 1, 1, dp);

            return dp[idx][buy] = max(buyStock, skip);
        }
        else {
            int sellStock = arr[idx] - fee +
                            solve(arr, fee, idx + 1, 1, dp);

            int hold = solve(arr, fee, idx + 1, 0, dp);

            return dp[idx][buy] = max(sellStock, hold);
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(
            prices.size(),
            vector<int>(2, -1)
        );

        return solve(prices, fee, 0, 1, dp);
    }
};
```

---

## Example

**Input:**

```text
prices = [1, 3, 2, 8, 4, 9]
fee = 2
```

**Output:**

```text
8
```

**Explanation:**

- Buy at price `1` and sell at price `8`.
- Profit = `8 - 1 - 2 = 5`.
- Buy at price `4` and sell at price `9`.
- Profit = `9 - 4 - 2 = 3`.

Total profit = `5 + 3 = 8`.

Therefore, the maximum profit is `8`.

---

## Dry Run

| Operation | Buy Price | Sell Price | Transaction Fee | Profit |
|---|---:|---:|---:|---:|
| First transaction | 1 | 8 | 2 | 5 |
| Second transaction | 4 | 9 | 2 | 3 |
| **Total** | | | | **8** |

The DP solution explores all valid choices and memoizes the best result for each state. It does not need to explicitly select these transactions during execution; the table stores the maximum achievable profit.

---

## Complexity Analysis

Let `n` be the number of elements in the `prices` array.

### Time Complexity: `O(n)`

There are `2n` possible DP states, and each state is calculated at most once. Each state performs constant-time work apart from recursive calls that are themselves memoized.

### Space Complexity: `O(n)`

- **DP table:** `O(n)` for `n × 2` states.
- **Recursion stack:** `O(n)` in the worst case.

Therefore, the overall auxiliary space complexity is `O(n)`.

---

## Key Takeaways

- This problem can be solved using dynamic programming.
- The `buy` variable represents the current stock-buying state.
- The transaction fee is subtracted when selling the stock.
- Memoization avoids repeated calculations.
- Each day has two possible states, giving a linear-time solution.

**Pattern:** Dynamic Programming → Stock Buy/Sell → Recursion + Memoization

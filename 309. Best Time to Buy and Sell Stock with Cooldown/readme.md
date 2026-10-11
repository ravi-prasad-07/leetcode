# LeetCode 309: Best Time to Buy and Sell Stock with Cooldown

## 📌 Problem Statement

You are given an array `prices` where `prices[i]` represents the price of a stock on the `i-th` day.

You can complete as many transactions as you like, but after selling your stock, you must wait **one day before buying again** (cooldown).

Return the maximum profit you can achieve.

**LeetCode:** [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

---

## 💡 Intuition

At every day, we have two possible states:

- `buy = 1`: We are allowed to buy a stock.
- `buy = 0`: We are currently holding a stock and can sell it.

For each state, we have two choices:

1. Perform the transaction (buy or sell).
2. Skip the current day.

We choose the option that gives the maximum profit.

**Important:** When we sell a stock, we move to `idx + 2` because the next day must be a cooldown day.

---

## 🚀 Approach: Recursion + Memoization

We define the recursive function:

`solve(arr, idx, buy, dp)`

- `idx`: Current day.
- `buy`: Current state (1 = can buy, 0 = holding stock).
- `dp[idx][buy]`: Maximum profit possible from the current state.

### Case 1: `buy == 1`

We can either buy the stock or skip the current day.

- **Buy:** `-arr[idx] + solve(arr, idx + 1, 0, dp)`
- **Skip:** `solve(arr, idx + 1, 1, dp)`

We take the maximum of these two choices.

### Case 2: `buy == 0`

We can either sell the stock or continue holding it.

- **Sell:** `arr[idx] + solve(arr, idx + 2, 1, dp)`
- **Skip:** `solve(arr, idx + 1, 0, dp)`

After selling, we move to `idx + 2` to maintain the cooldown.

### Base Case

If `idx >= arr.size()`, there are no days left, so we return `0`.

### Memoization

We store the result of every state in the `dp` table to avoid recalculating the same state.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int solve(vector<int>& arr, int idx, int buy,
              vector<vector<int>>& dp) {

        if (idx >= arr.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        if (buy) {
            return dp[idx][buy] = max(
                -arr[idx] + solve(arr, idx + 1, 0, dp),
                solve(arr, idx + 1, 1, dp)
            );
        }
        else {
            return dp[idx][buy] = max(
                arr[idx] + solve(arr, idx + 2, 1, dp),
                solve(arr, idx + 1, 0, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(
            prices.size(),
            vector<int>(2, -1)
        );

        return solve(prices, 0, 1, dp);
    }
};
```

---

## 🔍 Dry Run

**Input:**

```text
prices = [1, 2, 3, 0, 2]
```

One optimal sequence of transactions:

| Day | Price | Action | Profit |
|---|---:|---|---:|
| 0 | 1 | Buy | -1 |
| 1 | 2 | Sell | +2 |
| 2 | 3 | Cooldown | 0 |
| 3 | 0 | Buy | -0 |
| 4 | 2 | Sell | +2 |

**Total Profit:**

```text
(2 - 1) + (2 - 0) = 1 + 2 = 3
```

**Output:**

```text
3
```

---

## ⏱️ Complexity Analysis

Let `n` be the number of days.

- **Time Complexity:** `O(n)` — there are at most `2n` states, and each state is computed once.
- **Space Complexity:** `O(n)` — the DP table requires `O(n)` space, and the recursion stack can also require `O(n)` space.

Therefore, the overall time and auxiliary space complexities are:

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## 🔑 Key Takeaway

The main idea is to use two states (`buy = 1` and `buy = 0`) and memoization to calculate the maximum profit efficiently.

The most important transition is:

```cpp
arr[idx] + solve(arr, idx + 2, 1, dp)
```

Moving to `idx + 2` after selling ensures that the cooldown rule is followed.

---

**Topic:** Dynamic Programming | Recursion | Memoization

**Difficulty:** Medium

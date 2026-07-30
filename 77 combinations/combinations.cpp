/*# LeetCode 77. Combinations

## Problem Statement

Given two integers `n` and `k`, return **all possible combinations** of `k` numbers chosen from the range `[1, n]`.

You may return the answer in **any order**.

---

## Intuition

The problem asks us to generate every possible combination of `k` numbers without repetition. A natural way to achieve this is by building combinations one element at a time.

Starting from `1`, we pick a number, add it to the current combination, and recursively choose the next number from the remaining elements. Whenever the current combination reaches size `k`, we have found a valid answer.

Since we always move forward (`i + 1`), duplicate combinations such as `[2,1]` after `[1,2]` are automatically avoided.

---

## Approach

We use the **Backtracking** technique.

1. Maintain a temporary vector `temp` to store the current combination.
2. Start choosing numbers from `start`.
3. For every chosen number:

   * Add it to `temp`.
   * Recursively choose the next number from `i + 1`.
   * Remove the last element (backtrack) to try other possibilities.
4. If the size of `temp` becomes `k`, add it to the answer.

This explores every valid combination exactly once.

---

## Algorithm

1. Initialize an empty answer vector `ans`.
2. Create a recursive function `solve(start, n, k, temp, ans)`.
3. If `temp.size() == k`:

   * Store `temp` in `ans`.
   * Return.
4. Iterate from `start` to `n`:

   * Push the current number into `temp`.
   * Recur with `start = i + 1`.
   * Pop the last element to backtrack.
5. Return `ans`.

---

## Dry Run

### Input

```text
n = 4
k = 2
```

### Recursive Tree

```
[]
├── [1]
│   ├── [1,2] ✔
│   ├── [1,3] ✔
│   └── [1,4] ✔
│
├── [2]
│   ├── [2,3] ✔
│   └── [2,4] ✔
│
├── [3]
│   └── [3,4] ✔
│
└── [4]
```

### Output

```text
[
 [1,2],
 [1,3],
 [1,4],
 [2,3],
 [2,4],
 [3,4]
]
```

---

## Complexity Analysis

### Time Complexity

**O(C(n, k) × k)**

* There are **C(n, k)** possible combinations.
* Copying each combination of size `k` into the answer takes **O(k)** time.

---

### Space Complexity

**O(k)**

* The recursion stack and temporary vector together require at most `k` extra space.
* The output array is not included in the auxiliary space complexity.

---

## C++ Solution

```cpp*/
class Solution {
public:
    void solve(int start, int n, int k,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++) {
            temp.push_back(i);

            solve(i + 1, n, k, temp, ans);

            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(1, n, k, temp, ans);

        return ans;
    }
};/*
```

---

## Key Takeaways

* **Backtracking** is well-suited for generating combinations.
* The `start` index ensures each combination is generated only once.
* Backtracking explores all possible choices while keeping the current combination valid.
* This solution is clean, easy to understand, and efficient enough to pass all LeetCode test cases.
*/

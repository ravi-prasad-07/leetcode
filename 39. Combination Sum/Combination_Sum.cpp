class Solution {
public:
    void solve(int i, int tar, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res){
        if(tar == 0){
            res.push_back(temp);
            return;
        }

        if(i >= (int)arr.size() || arr[i] > tar){
            return;
        }

        // Take current element
        temp.push_back(arr[i]);
        solve(i, tar - arr[i], arr, temp, res);
        temp.pop_back();

        // Skip current element
        solve(i + 1, tar, arr, temp, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;

        solve(0, target, candidates, temp, res);

        return res;
    }
};
/*
# LeetCode 39. Combination Sum

## Intuition

For each candidate, we have **two choices**:

1. **Take the current element** → Since we can use the same number multiple times, we stay at the same index.
2. **Skip the current element** → Move to the next index.

To avoid unnecessary recursion, we first sort the array. Once a candidate becomes greater than the remaining target, we can stop exploring that path because all subsequent elements will also be larger.

---

## Approach

1. Sort the `candidates` array.
2. Start recursion from index `0`.
3. If the remaining target becomes `0`, we have found a valid combination, so store it.
4. If:

   * index goes out of bounds, or
   * current candidate is greater than the remaining target,

   then return.
5. Otherwise:

   * Include the current candidate and recurse with the **same index**.
   * Backtrack by removing the last element.
   * Exclude the current candidate and recurse with the **next index**.

This guarantees that:

* Every combination is generated only once.
* Unlimited use of an element is allowed because we don't increment the index after taking it.

---

## Time Complexity

Let **N** be the number of candidates.

The number of possible combinations depends on the target and candidate values, so the worst-case complexity is exponential.

**Time Complexity:** **O(2^(T/M))** (approximately exponential), where:

* **T** = target
* **M** = smallest candidate value

More generally, the complexity is proportional to the total number of valid recursive states and generated combinations.

---

## Space Complexity

* Recursive stack depth: **O(T / M)**
* Temporary combination storage: **O(T / M)**

Ignoring the output array,

**Space Complexity:** **O(T / M)**

---

## Code

```cpp
class Solution {
public:
    void solve(int i, int tar, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res){
        if(tar == 0){
            res.push_back(temp);
            return;
        }

        if(i >= (int)arr.size() || arr[i] > tar){
            return;
        }

        // Take current element
        temp.push_back(arr[i]);
        solve(i, tar - arr[i], arr, temp, res);
        temp.pop_back();

        // Skip current element
        solve(i + 1, tar, arr, temp, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;

        solve(0, target, candidates, temp, res);

        return res;
    }
};
```

---

# Dry Run

### Input

```text
candidates = [2,3,6,7]
target = 7
```

After sorting:

```text
[2,3,6,7]
```

### Recursive Execution

```
solve(0,7)
│
├── Take 2
│   temp = [2]
│   solve(0,5)
│   │
│   ├── Take 2
│   │   temp = [2,2]
│   │   solve(0,3)
│   │   │
│   │   ├── Take 2
│   │   │   temp = [2,2,2]
│   │   │   solve(0,1)
│   │   │   2 > 1 → Return
│   │   │
│   │   └── Skip 2
│   │       temp = [2,2]
│   │       Take 3
│   │       temp = [2,2,3]
│   │       solve(1,0)
│   │       ✔ Store [2,2,3]
│   │
│   └── Skip 2
│       temp = [2]
│       Take 3
│       temp = [2,3]
│       solve(1,2)
│       3 > 2 → Return
│
└── Skip 2
    solve(1,7)
    │
    ├── Take 3
    │   temp = [3]
    │   solve(1,4)
    │   No valid combination
    │
    └── Skip 3
        solve(2,7)
        │
        ├── Take 6
        │   Remaining = 1
        │   Return
        │
        └── Skip 6
            Take 7
            temp = [7]
            solve(3,0)
            ✔ Store [7]
```

### Output

```text
[
  [2,2,3],
  [7]
]
```

The algorithm explores every valid include/exclude choice while pruning branches where the current candidate exceeds the remaining target, ensuring all unique combinations are found.

*/

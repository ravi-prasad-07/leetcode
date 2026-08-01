/*# Intuition

We need to find all possible combinations of **`k` distinct numbers** from **1 to 9** whose sum equals **`n`**.

Since each number can only be used **once**, we can use **backtracking** to explore all possible combinations.

At every step:

* Choose a number from the current `start` value to `9`.
* Add it to the current combination.
* Reduce the remaining sum by that number.
* Recursively search for the remaining numbers.
* Backtrack by removing the last chosen number to try other possibilities.

We stop exploring when:

* We already selected `k` numbers.
* The remaining sum becomes negative.

---

# Approach

1. Maintain a temporary vector `temp` to store the current combination.
2. Start choosing numbers from `start` to `9`.
3. For every chosen number:

   * Add it into `temp`.
   * Recur with:

     * `start = i + 1` (to avoid reusing numbers)
     * `n = n - i`
   * Remove the last element (backtracking).
4. If `temp.size() == k`:

   * If the remaining sum is exactly `0`, store the combination.
   * Otherwise, return.
5. If the remaining sum becomes negative, stop exploring that path.

---

# Time Complexity

The search explores combinations of choosing `k` numbers from `9`.

**Time Complexity:** **O(C(9, k) × k)**

* There are **C(9, k)** possible combinations.
* Copying each valid combination takes **O(k)** time.

Since `9` is fixed, this is effectively a constant-time solution.

---

# Space Complexity

**O(k)**

* Recursive call stack depth is at most `k`.
* Temporary vector stores at most `k` elements.
* Result vector is not included in auxiliary space.

---

# Code

```cpp*/
class Solution {
public:

    void solve(int start, int k, int n, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size() == k){
            if(n == 0){
                res.push_back(temp);
            }
            return;
        }

        if(n < 0){
            return;
        }

        for(int i = start; i <= 9; i++){
            temp.push_back(i);
            solve(i + 1, k, n - i, temp, res);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(1, k, n, temp, res);

        return res;
    }
};/*
```

---

# Dry Run

### Input

```text
k = 3
n = 7
```

### Execution

Start:

```text
temp = []
start = 1
remaining = 7
```

Choose **1**

```text
temp = [1]
remaining = 6
start = 2
```

Choose **2**

```text
temp = [1,2]
remaining = 4
start = 3
```

Choose **3**

```text
temp = [1,2,3]
remaining = 1
```

* Already selected 3 numbers.
* Remaining sum ≠ 0.
* Backtrack.

Choose **4**

```text
temp = [1,2,4]
remaining = 0
```

* Selected 3 numbers.
* Remaining sum is 0.
* Store:

```text
[[1,2,4]]
```

Backtrack.

Try:

```text
[1,2,5]
remaining = -1
```

Stop this path.

Continue exploring all remaining possibilities:

```text
[1,3,4]  -> sum = 8
[2,3,4]  -> sum = 9
...
```

None satisfy the conditions.

### Final Output

```text
[[1,2,4]]
```
*/

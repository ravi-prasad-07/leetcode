/*# LeetCode 47. Permutations II

## Intuition

The main challenge is handling **duplicate numbers**.

If we generate all permutations normally, duplicate values will produce identical permutations multiple times.

To avoid this:

1. **Sort** the array so duplicate values become adjacent.
2. Keep a `used` array to track which indices are already included in the current permutation.
3. While choosing the next element, skip duplicates using the condition:

   ```cpp
   if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
       continue;
   ```

   This ensures that among equal numbers, we always use the **leftmost unused duplicate first**, preventing duplicate permutations.

---

## Approach

1. Sort the input array.
2. Maintain:

   * `path` → current permutation being built.
   * `used` → whether an index has already been chosen.
3. Recursively try every unused element.
4. Before choosing `nums[i]`, check:

   * If already used → skip.
   * If it is the same as the previous element **and the previous duplicate hasn't been used in the current branch**, skip it.
5. When `path.size() == nums.size()`, a unique permutation is formed.

---

## Why does this duplicate check work?

```cpp
if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
    continue;
```

Suppose:

```text
nums = [1,1,2]
```

At the first level:

```
Choose first 1  ✓
Choose second 1 ✗
```

Why skip the second `1`?

Because both `1`s are identical. Starting with the second one would generate exactly the same permutations as starting with the first one.

However, once the first `1` has already been used in the current permutation:

```
used = [true, false, false]
```

Now the second `1` **is allowed**, since it represents a different position in the permutation.

This rule removes duplicate branches while keeping all unique permutations.

---

## Time Complexity

* Sorting: **O(n log n)**
* Backtracking generates all unique permutations.

Worst case (all elements distinct):

**O(n × n!)**

Each permutation takes **O(n)** to construct.

---

## Space Complexity

* Recursive stack: **O(n)**
* `used` array: **O(n)**
* `path`: **O(n)**

Auxiliary Space:

**O(n)**

(Output space is **O(n × n!)**, which is not counted.)

---

## Code

```cpp*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Skip duplicate permutations
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums);

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        used.assign(nums.size(), false);

        backtrack(nums);

        return ans;
    }
};/*
```

---

# Dry Run

### Input

```text
nums = [1,1,2]
```

After sorting:

```text
[1,1,2]
```

---

### Level 0

```
path = []
used = [F,F,F]
```

Choose index 0 (`1`)

```
path = [1]
used = [T,F,F]
```

---

### Level 1

Choose index 1 (`1`)

```
path = [1,1]
used = [T,T,F]
```

---

### Level 2

Choose index 2 (`2`)

```
path = [1,1,2]
```

Store:

```
[1,1,2]
```

Backtrack.

---

### Back to Level 1

Choose index 2 (`2`)

```
path = [1,2]
used = [T,F,T]
```

Choose remaining `1`

```
path = [1,2,1]
```

Store:

```
[1,2,1]
```

Backtrack.

---

### Back to Level 0

Try index 1 (`1`)

Condition:

```cpp
nums[1] == nums[0]
&& !used[0]
```

becomes

```text
1 == 1 && true
```

So this branch is **skipped**, preventing duplicate permutations.

---

Choose index 2 (`2`)

```
path = [2]
```

Then choose first `1`

```
path = [2,1]
```

Then second `1`

```
path = [2,1,1]
```

Store:

```
[2,1,1]
```

---

### Final Answer

```text
[
 [1,1,2],
 [1,2,1],
 [2,1,1]
]
```

Only unique permutations are generated, and duplicate branches are pruned before recursion.
*/

/*# LeetCode 46. Permutations

## Intuition

To generate all possible permutations, we fix one position at a time.

* At index `l`, every element from `l` to `r` has a chance to occupy that position.
* We swap the current element with each possible candidate.
* After fixing one element, we recursively generate permutations for the remaining positions.
* Once recursion returns, we swap back (backtracking) so the array is restored for the next choice.

This ensures every possible arrangement is explored exactly once.

---

## Approach

1. Start from the first index (`l = 0`).
2. For every index `i` from `l` to `r`:

   * Swap `nums[l]` with `nums[i]`.
   * Recursively generate permutations for the remaining indices (`l + 1`).
   * Swap back to restore the original array (backtracking).
3. When `l == r`, every position has been fixed, so store the current permutation.

---

## Time Complexity

* There are **n!** permutations.
* Each permutation takes **O(n)** time to copy into the answer.

**Time Complexity:** **O(n × n!)**

---

## Space Complexity

* Recursive call stack depth is **O(n)**.
* No extra data structure is used apart from recursion.
* (Ignoring the output array, which stores `n!` permutations.)

**Space Complexity:** **O(n)**

---

## Code

```cpp*/
class Solution {
public:
    using dt = vector<vector<int>>;

    void permute(vector<int>& nums, dt& ans, int l, int r) {
        if (l == r) {
            ans.push_back(nums);
            return;
        }

        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            permute(nums, ans, l + 1, r);
            swap(nums[l], nums[i]); // Backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dt ans;
        permute(nums, ans, 0, nums.size() - 1);
        return ans;
    }
};
/*```

---

# Dry Run

### Input

```text
nums = [1,2,3]
```

### Initial Call

```text
permute([1,2,3], l=0, r=2)
```

### Level 0 (`l = 0`)

#### i = 0

Swap(0,0)

```text
[1,2,3]
```

Call `l = 1`

---

### Level 1 (`l = 1`)

#### i = 1

Swap(1,1)

```text
[1,2,3]
```

Call `l = 2`

* `l == r`
* Store:

```text
[1,2,3]
```

Backtrack.

---

#### i = 2

Swap(1,2)

```text
[1,3,2]
```

Call `l = 2`

Store:

```text
[1,3,2]
```

Backtrack to

```text
[1,2,3]
```

Return to previous level.

---

### Back to Level 0

#### i = 1

Swap(0,1)

```text
[2,1,3]
```

Call `l = 1`

* Swap(1,1) → Store `[2,1,3]`
* Swap(1,2) → Store `[2,3,1]`

Backtrack to

```text
[1,2,3]
```

---

#### i = 2

Swap(0,2)

```text
[3,2,1]
```

Call `l = 1`

* Swap(1,1) → Store `[3,2,1]`
* Swap(1,2) → Store `[3,1,2]`

Backtrack to

```text
[1,2,3]
```

---

### Final Output

```text
[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,2,1],
 [3,1,2]
]
```

The array is restored after every recursive call because of the second `swap()`, allowing the algorithm to correctly explore every permutation through backtracking.
*/

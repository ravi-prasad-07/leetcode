## Intuition

We need to find all ranges of numbers that are missing from `[lower, upper]`.

After sorting:

```text
nums = [1, 3, 5, 8]
lower = 1
upper = 10
```

Maintain:

```text
aarambh = smallest number that has not been covered yet
```

Initially:

```text
aarambh = lower
```

For every valid number `it`:

* If `it > aarambh`, then all numbers from `aarambh` to `it - 1` are missing.
* After processing `it`, the next possible missing number becomes:

```text
aarambh = it + 1
```

Finally, if `aarambh <= upper`, then `[aarambh, upper]` is also missing.

---

# Approach

1. Sort `nums`.
2. Set `aarambh = lower`.
3. Traverse every number:

   * Skip numbers outside `[lower, upper]`.
   * Skip duplicates/already processed numbers using `it < aarambh`.
   * If `it > aarambh`, add the range:

     ```cpp
     [aarambh, it - 1]
     ```
   * Update:

     ```cpp
     aarambh = it + 1;
     ```
4. If numbers remain after the last element, add:

   ```cpp
   [aarambh, upper]
   ```

## Code

```cpp
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(
        vector<int>& nums, int lower, int upper) {
        
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        int aarambh = lower;

        for (int it : nums) {

            // Ignore numbers outside the required range
            if (it < lower) {
                continue;
            }

            if (it > upper) {
                break;
            }

            // Ignore duplicates / already covered numbers
            if (it < aarambh) {
                continue;
            }

            // Missing range exists before current number
            if (it > aarambh) {
                res.push_back({aarambh, it - 1});
            }

            // Next number to check
            aarambh = it + 1;
        }

        // Remaining missing range
        if (aarambh <= upper) {
            res.push_back({aarambh, upper});
        }

        return res;
    }
};
```

## Time Complexity

* Sorting: `O(n log n)`
* Traversing the array: `O(n)`

**Total:**

```text
O(n log n)
```

## Space Complexity

Ignoring the output array:

```text
O(log n)
```

due to the sorting implementation's stack usage.

If considering the returned result:

```text
O(k)
```

where `k` is the number of missing ranges.

---

# Dry Run

### Input

```cpp
nums = {1, 3, 5, 8};
lower = 1;
upper = 10;
```

After sorting:

```text
[1, 3, 5, 8]
```

Initial:

```text
aarambh = 1
res = []
```

| `it` | `aarambh` before | Action                            | `res`                 |
| ---- | ---------------: | --------------------------------- | --------------------- |
| 1    |                1 | `it == aarambh`, no missing range | `[]`                  |
| 3    |                2 | `3 > 2`, add `[2,2]`              | `[[2,2]]`             |
| 5    |                4 | `5 > 4`, add `[4,4]`              | `[[2,2],[4,4]]`       |
| 8    |                6 | `8 > 6`, add `[6,7]`              | `[[2,2],[4,4],[6,7]]` |

After traversal:

```text
aarambh = 9
upper = 10
```

So add:

```text
[9,10]
```

### Final Answer

```cpp
[[2,2], [4,4], [6,7], [9,10]]
```

Your main logic was already good—the important extra condition is:

```cpp
if (it < aarambh) continue;
```

This makes the solution handle **duplicates safely**.

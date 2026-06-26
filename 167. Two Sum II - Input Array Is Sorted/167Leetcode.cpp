## LeetCode 167. Two Sum II - Input Array Is Sorted

### Intuition

Since the array is **sorted in non-decreasing order**, we can use the **two-pointer technique**.

* Start one pointer (`i`) at the beginning and another (`j`) at the end.
* If the sum is smaller than the target, move `i` forward to increase the sum.
* If the sum is larger than the target, move `j` backward to decrease the sum.
* When the sum equals the target, return the 1-based indices.

This works because the array is sorted.

---

### Approach

1. Initialize:

   * `i = 0` (left pointer)
   * `j = n - 1` (right pointer)

2. While `i < j`:

   * Calculate `numbers[i] + numbers[j]`.
   * If equal to `target`, return `{i + 1, j + 1}`.
   * If less than `target`, increment `i`.
   * Otherwise, decrement `j`.

3. The problem guarantees exactly one solution, so we will always find an answer.

---

### Time Complexity

* **O(n)**

Each pointer moves at most `n` times.

### Space Complexity

* **O(1)**

Only a few variables are used.

---

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            }
            else if (numbers[i] + numbers[j] < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {};
    }
};
```

---

### Dry Run

#### Example

```cpp
numbers = [2,7,11,15]
target = 9
```

| i | j | numbers[i] | numbers[j] | Sum | Action       |
| - | - | ---------- | ---------- | --- | ------------ |
| 0 | 3 | 2          | 15         | 17  | Sum > 9, j-- |
| 0 | 2 | 2          | 11         | 13  | Sum > 9, j-- |
| 0 | 1 | 2          | 7          | 9   | Found answer |

Return:

```cpp
{1, 2}
```

### Is Your Solution Optimal?

✅ Yes. Your solution is **optimal**.

* Time: **O(n)** (best possible for this problem)
* Space: **O(1)**
* Uses the sorted property perfectly with the two-pointer approach.

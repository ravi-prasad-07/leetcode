## LeetCode 373. Find K Pairs with Smallest Sums

### Intuition

Since both arrays are **sorted**, the smallest possible pair is always `(nums1[0], nums2[0])`.

Think of each pair `(i, j)` as a cell in a sorted matrix where:

* Rows represent `nums1`
* Columns represent `nums2`
* Cell value = `nums1[i] + nums2[j]`

Starting from `(0,0)`, the next possible smallest pairs are:

* `(i+1, j)` (move down)
* `(i, j+1)` (move right)

To always process the smallest available pair first, we use a **min-heap (priority queue)**.

Since the same cell can be reached from multiple paths, we maintain a **visited set** to avoid pushing duplicate indices into the heap.

---

### Approach

1. Handle edge cases where either array is empty or `k == 0`.
2. Create a min-heap storing:

   * Sum of the pair
   * Indices `(i, j)`
3. Insert the first pair `(0,0)` into the heap and mark it visited.
4. While the heap is not empty and `k > 0`:

   * Pop the smallest sum pair.
   * Add the corresponding values to the answer.
   * Push `(i+1, j)` if valid and not visited.
   * Push `(i, j+1)` if valid and not visited.
5. Return the collected pairs.

---

### Time Complexity

* Each pair is inserted into the heap at most once.
* At most `min(k, m × n)` pairs are processed.

**Time Complexity:**
[
O(\min(k, m \times n)\log(\min(k, m \times n)))
]

where:

* `m = nums1.size()`
* `n = nums2.size()`

---

### Space Complexity

* Priority Queue stores at most `min(k, m × n)` pairs.
* Visited set also stores at most `min(k, m × n)` index pairs.

**Space Complexity:**
[
O(\min(k, m \times n))
]

---

### Code

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        if (nums1.empty() || nums2.empty() || k == 0) {
            return {};
        }

        vector<vector<int>> ans;
        set<pair<int, int>> visit;

        int m = nums1.size();
        int n = nums2.size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        visit.insert({0, 0});

        while (k-- && !pq.empty()) {

            auto tp = pq.top();
            pq.pop();

            int i = tp.second.first;
            int j = tp.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visit.find({i + 1, j}) == visit.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visit.insert({i + 1, j});
            }

            if (j + 1 < n && visit.find({i, j + 1}) == visit.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visit.insert({i, j + 1});
            }
        }

        return ans;
    }
};
```

---

## Dry Run

### Input

```text
nums1 = [1,7,11]
nums2 = [2,4,6]
k = 3
```

### Initial State

```text
Min Heap:
(3, (0,0))   // 1 + 2

Visited:
{(0,0)}
```

---

### Iteration 1

Pop:

```text
(3, (0,0))
```

Answer:

```text
[[1,2]]
```

Push neighbors:

```text
(1,0) -> 7+2 = 9
(0,1) -> 1+4 = 5
```

Heap:

```text
(5,(0,1))
(9,(1,0))
```

---

### Iteration 2

Pop:

```text
(5,(0,1))
```

Answer:

```text
[[1,2],[1,4]]
```

Push neighbors:

```text
(1,1) -> 7+4 = 11
(0,2) -> 1+6 = 7
```

Heap:

```text
(7,(0,2))
(9,(1,0))
(11,(1,1))
```

---

### Iteration 3

Pop:

```text
(7,(0,2))
```

Answer:

```text
[[1,2],[1,4],[1,6]]
```

Since `k = 3`, we stop.

### Final Output

```text
[[1,2],[1,4],[1,6]]
```

**Note:** This solution treats the problem as exploring a sorted matrix using a best-first search (min-heap). While it is correct, there is a more optimized approach that initializes the heap with the first element of each row, achieving **O(k log min(m, k))** time and **O(min(m, k))** space.

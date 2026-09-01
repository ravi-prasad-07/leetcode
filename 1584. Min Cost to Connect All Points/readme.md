## LeetCode: 1584. Min Cost to Connect All Points

### 💡 Intuition

This problem asks us to connect all points with the **minimum total cost**.

The cost of connecting two points is their **Manhattan distance**:

$$
|x_1-x_2| + |y_1-y_2|
$$

This is exactly a **Minimum Spanning Tree (MST)** problem.

We can use **Prim's Algorithm**:

* Start from point `0`.
* Maintain a `priority_queue` containing possible edges to unvisited points.
* Always choose the edge with the **smallest cost**.
* If the point is already visited, skip it.
* Otherwise, add its cost to the answer and use that point to generate new possible connections.

Since every point can potentially connect to every other point, we don't need to explicitly construct an adjacency matrix/list. We calculate the Manhattan distance when needed.

---

### 🚀 Approach

1. Create a `vis` array to track points already included in the MST.
2. Use a min-heap:

   ```cpp
   priority_queue<pair<int,int>,
                  vector<pair<int,int>>,
                  greater<pair<int,int>>> pq;
   ```

   Each element is:

   ```text
   {cost, point}
   ```
3. Initially, push `{0, 0}` because we start from point `0`.
4. While the priority queue isn't empty:

   * Take the minimum-cost connection.
   * If the point is already visited, skip it.
   * Mark it visited.
   * Add its cost to `sum`.
   * Calculate its Manhattan distance to every unvisited point and push those connections into the heap.
5. Once all points are visited, `sum` is the minimum cost.

---

### 💻 Code

```cpp
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int sum = 0;

        vector<int> vis(n, 0);

        // {cost, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Start from point 0
        pq.push({0, 0});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            // Already included in MST
            if (vis[node])
                continue;

            vis[node] = 1;
            sum += wt;

            // Try connecting current point with every
            // unvisited point
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int cost =
                        abs(points[node][0] - points[i][0]) +
                        abs(points[node][1] - points[i][1]);

                    pq.push({cost, i});
                }
            }
        }

        return sum;
    }
};
```

### ⏱️ Complexity

There are `n` points and potentially `O(n²)` connections.

For every selected point, we check all `n` points:

* **Time:** `O(n² log n)`
* **Space:** `O(n²)` in the worst case because the priority queue can contain many candidate edges.

> With a more optimized Prim implementation using an array of minimum distances instead of a priority queue, this can be reduced to **O(n²)** time and **O(n)** space.

---

## 🧪 Dry Run

Consider:

```text
points = [[0,0], [2,2], [3,10], [5,2], [7,0]]
```

Start:

```text
pq = {(0,0)}
sum = 0
```

### Step 1

Take:

```text
(0, 0)
```

Visit point `0`.

Distances:

```text
0 → 1 = |0-2| + |0-2| = 4
0 → 2 = |0-3| + |0-10| = 13
0 → 3 = |0-5| + |0-2| = 7
0 → 4 = |0-7| + |0-0| = 7
```

Minimum is point `1` with cost `4`.

```text
sum = 0
```

### Step 2

Take:

```text
(4, 1)
```

Visit point `1`.

```text
sum = 4
```

Important new distances:

```text
1 → 3 = |2-5| + |2-2| = 3
1 → 2 = |2-3| + |2-10| = 9
1 → 4 = |2-7| + |2-0| = 7
```

Minimum is point `3` with cost `3`.

### Step 3

Take:

```text
(3, 3)
```

```text
sum = 4 + 3 = 7
```

From point `3`:

```text
3 → 4 = |5-7| + |2-0| = 4
3 → 2 = |5-3| + |2-10| = 10
```

Minimum is point `4` with cost `4`.

### Step 4

Take:

```text
(4, 4)
```

```text
sum = 7 + 4 = 11
```

From point `4`:

```text
4 → 2 = |7-3| + |0-10| = 14
```

### Step 5

Take point `2` with its best available connection:

```text
cost = 9
```

So:

```text
sum = 11 + 9
    = 20
```

Therefore:

```text
Answer = 20
```

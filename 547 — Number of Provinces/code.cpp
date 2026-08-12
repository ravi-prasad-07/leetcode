# LeetCode 547 — Number of Provinces

### Intuition

We can treat `isConnected` as an **adjacency matrix of a graph**:

* Each city is a **node**.
* `isConnected[i][j] == 1` means city `i` and city `j` are directly connected.
* A **province** is a group of cities where every city is reachable from the others.

So, we need to count the number of **connected components** in the graph.

We use **DFS**:

1. Maintain a `vis` array to keep track of visited cities.
2. Start DFS from every unvisited city.
3. One DFS traversal visits all cities belonging to the same province.
4. Therefore, every time we start a new DFS, we have found **one new province**.

---

### Approach

For every city `i`:

```text
If city i is not visited:
    Start DFS from i
    Increment province count
```

Inside DFS:

```text
Mark current city as visited.

Check every city connected to current city.
If it is connected and not visited:
    Recursively perform DFS on it.
```

Because DFS visits every city reachable from the starting city, one DFS completely explores one province.

---

### Code

```cpp
class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node) {
        vis[node] = 1;

        for (int i = 0; i < isConnected[node].size(); i++) {
            if (isConnected[node][i] == 1 && !vis[i]) {
                dfs(isConnected, vis, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, vis, i);
                cnt++;
            }
        }

        return cnt;
    }
};
```

### Time Complexity

There are `n` cities, and for each visited city we scan its entire row of the adjacency matrix.

* Each row has `n` elements.
* We process at most `n` rows.

Therefore:

**Time Complexity: `O(n²)`**

### Space Complexity

We use:

* `vis` array → `O(n)`
* DFS recursion stack → `O(n)` in the worst case

Therefore:

**Space Complexity: `O(n)`**

---

## Dry Run

Consider:

```text
isConnected = [
    [1,1,0],
    [1,1,0],
    [0,0,1]
]
```

Graphically:

```text
0 ---- 1       2
 \____/
```

### Step 1: `i = 0`

`vis[0] = 0`, so start DFS.

```text
DFS(0)
```

Mark `0` visited.

City `0` is connected to city `1`.

```text
DFS(1)
```

Mark `1` visited.

City `1` is already connected to `0`, but `0` is already visited.

Now:

```text
vis = [1, 1, 0]
cnt = 1
```

So cities `0` and `1` form **one province**.

### Step 2: `i = 1`

`vis[1] == 1`, so skip it.

### Step 3: `i = 2`

`vis[2] == 0`, so start another DFS.

```text
DFS(2)
```

Mark `2` visited.

```text
vis = [1, 1, 1]
cnt = 2
```

Therefore:

```text
Answer = 2
```

### Key Idea to Remember

> **Every time we find an unvisited node and start DFS, we have discovered one new connected component (province).**

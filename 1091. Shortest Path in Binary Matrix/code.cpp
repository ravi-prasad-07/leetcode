class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If the starting or ending cell is blocked,
        // there is no possible path.
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }

        // visited[i][j] tells whether the cell has already
        // been visited during BFS.
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Queue for BFS traversal.
        // Each pair represents the coordinates {row, column}.
        queue<pair<int, int>> q;

        // Start BFS from the top-left cell.
        q.push({0, 0});
        visited[0][0] = 1;

        // All 8 possible directions:
        // horizontal, vertical, and diagonal.
        int directions[8][2] = {
            {0, 1}, {0, -1},
            {1, 0}, {-1, 0},
            {1, 1}, {1, -1},
            {-1, 1}, {-1, -1}
        };

        // The path starts with the cell (0, 0),
        // so the initial path length is 1.
        int distance = 1;

        // BFS explores the grid level by level.
        // Each level represents one additional cell in the path.
        while (!q.empty()) {
            int levelSize = q.size();

            // Process all cells at the current BFS level.
            for (int k = 0; k < levelSize; k++) {
                auto [row, col] = q.front();
                q.pop();

                // If we reach the bottom-right cell,
                // BFS guarantees this is the shortest path.
                if (row == n - 1 && col == m - 1) {
                    return distance;
                }

                // Explore all 8 neighboring cells.
                for (int d = 0; d < 8; d++) {
                    int newRow = row + directions[d][0];
                    int newCol = col + directions[d][1];

                    // A cell can be visited if:
                    // 1. It is inside the grid.
                    // 2. It has not been visited before.
                    // 3. It is an empty cell (value = 0).
                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < m &&
                        !visited[newRow][newCol] &&
                        grid[newRow][newCol] == 0) {

                        // Mark as visited before pushing to avoid
                        // adding the same cell multiple times.
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }

            // Move to the next BFS level.
            distance++;
        }

        // Destination cannot be reached.
        return -1;
    }
};
/*
Your solution is **correct and optimal** for LeetCode **1091. Shortest Path in Binary Matrix**. It uses **BFS**, which is the best choice here because every valid move has the same cost: **1 step**.

## Intuition

We need to find the shortest path from `(0,0)` to `(n-1,m-1)`.

Since:

* We can move in **8 directions**.
* Every move costs the same.
* We need the **minimum number of cells in the path**.

This is a classic **shortest path in an unweighted graph**, so **BFS** is optimal.

BFS explores cells level by level:

* Level 1 → starting cell
* Level 2 → cells reachable in one move
* Level 3 → cells reachable in two moves

Therefore, the first time we reach `(n-1, m-1)`, we have found the shortest path.

---

## Approach

1. If the starting or ending cell is blocked (`1`), return `-1`.
2. Start BFS from `(0,0)`.
3. Mark `(0,0)` as visited.
4. Use 8 possible directions.
5. Process BFS level by level.
6. Maintain `dist`, representing the number of cells in the current path.
7. When we reach `(n-1,m-1)`, return `dist`.
8. If BFS finishes without reaching the destination, return `-1`.

---

## Code

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Start or destination is blocked
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        int dir[8][2] = {
            {0, 1}, {0, -1},
            {1, 0}, {-1, 0},
            {1, 1}, {1, -1},
            {-1, 1}, {-1, -1}
        };

        int dist = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int k = 0; k < sz; k++) {
                auto [i, j] = q.front();
                q.pop();

                // Destination reached
                if (i == n - 1 && j == m - 1) {
                    return dist;
                }

                for (int d = 0; d < 8; d++) {
                    int ir = i + dir[d][0];
                    int jc = j + dir[d][1];

                    if (ir >= 0 && ir < n &&
                        jc >= 0 && jc < m &&
                        vis[ir][jc] == 0 &&
                        grid[ir][jc] == 0) {

                        q.push({ir, jc});
                        vis[ir][jc] = 1;
                    }
                }
            }

            dist++;
        }

        return -1;
    }
};
```

## Time Complexity

**O(n × m)**

Each cell is visited at most once, and for every cell we check 8 directions.

## Space Complexity

**O(n × m)**

* `vis` matrix: `O(n × m)`
* BFS queue can contain up to `O(n × m)` cells.

---

## Dry Run

Consider:

```text
grid =
[
  [0, 1, 0],
  [0, 0, 0],
  [1, 1, 0]
]
```

Start:

```text
Queue = [(0,0)]
dist = 1
```

### Level 1

Process `(0,0)`.

Valid unvisited neighbor:

```text
(1,0)
```

Now:

```text
Queue = [(1,0)]
dist = 2
```

### Level 2

Process `(1,0)`.

Valid neighbors:

```text
(1,1)
```

Now:

```text
Queue = [(1,1)]
dist = 3
```

### Level 3

Process `(1,1)`.

Valid neighbors include:

```text
(1,2)
(2,2)
```

Now:

```text
Queue = [(1,2), (2,2)]
dist = 4
```

### Level 4

Eventually `(2,2)` is popped.

Since:

```cpp
i == n - 1 && j == m - 1
```

we return:

```text
4
```

### Final Answer

```text
Shortest path length = 4
```

**Conclusion:** Your BFS solution is optimal. Dijkstra would also work, but it is unnecessary here because all edges have equal weight. BFS gives the same shortest path with simpler logic and better practical efficiency.

*/

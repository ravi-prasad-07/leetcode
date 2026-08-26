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

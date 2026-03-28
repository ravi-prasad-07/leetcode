class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<int>>& visit) {
        
        // Base case
        if (k == word.length()) return true;

        int m = board.size();
        int n = board[0].size();

        // Boundary + conditions
        if (i < 0 || j < 0 || i >= m || j >= n ||
            visit[i][j] || board[i][j] != word[k]) {
            return false;
        }

        // Mark visited
        visit[i][j] = 1;

        // Explore 4 directions
        bool found = dfs(board, word, i+1, j, k+1, visit) ||
                     dfs(board, word, i-1, j, k+1, visit) ||
                     dfs(board, word, i, j+1, k+1, visit) ||
                     dfs(board, word, i, j-1, k+1, visit);

        // Backtrack
        visit[i][j] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visit(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visit)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
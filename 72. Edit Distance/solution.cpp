class Solution {
private:
    int solve(const string& str, const string& st,
              int n, int m, vector<vector<int>>& dp) {

        if (n < 0) {
            return m + 1;
        }

        if (m < 0) {
            return n + 1;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (str[n] == st[m]) {
            return dp[n][m] =
                solve(str, st, n - 1, m - 1, dp);
        }

        int insert = solve(str, st, n, m - 1, dp);
        int del = solve(str, st, n - 1, m, dp);
        int replace = solve(str, st, n - 1, m - 1, dp);

        return dp[n][m] =
            1 + min({insert, del, replace});
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(
            word1.length(),
            vector<int>(word2.length(), -1)
        );

        return solve(
            word1,
            word2,
            word1.length() - 1,
            word2.length() - 1,
            dp
        );
    }
};

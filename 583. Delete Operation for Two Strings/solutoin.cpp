class Solution {
private:

    int solve(const string& str, const string& st, int i, int j, vector<vector<int>>& dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(str[i]==st[j]){
            return dp[i][j]=solve(str, st, i-1, j-1, dp);
        }

        return dp[i][j]=min(1 + solve(str, st, i, j-1, dp), 1 + solve(str, st, i-1, j, dp));
    }

public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int res=solve(word1, word2, n-1, m-1, dp);
        return res;
    }
};

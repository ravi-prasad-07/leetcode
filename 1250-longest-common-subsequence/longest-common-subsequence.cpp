class Solution {
private:

    int solve(const string& str, const string& st, int n, int m, vector<vector<int>>& dp){
        if(n<0 || m<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }

        if(str[n]==st[m]){
            return dp[n][m]=1 + solve(str, st, n-1, m-1, dp);
        }
        return dp[n][m]=max(solve(str, st, n, m-1, dp), solve(str, st, n-1, m, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        int res=solve(text1, text2, text1.length()-1, text2.length()-1, dp);
        return res;
    }
};
class Solution {
private:

    int solve(const string& s, int i, int j, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j]=solve(s, i+1, j-1, dp);
        }

        return dp[i][j]=min(1 + solve(s, i, j-1, dp), 1 + solve(s, i+1, j, dp));

    }

public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        int res=solve(s, 0, s.length()-1, dp);

        return res;
    }
};
class Solution {
private:

    bool pallin(const string& s, int i, int j, vector<vector<int>>& pal){
        if(i>=j){
            return true;
        }
        if(pal[i][j]!=-1){
            return pal[i][j];
        }
        if(s[i]!=s[j]){
            return pal[i][j]=0;
        }

        return pal[i][j]=pallin(s, i+1, j-1, pal);
    }

    int solve(const string& s, int i, vector<int>& dp, vector<vector<int>>& pal){
        if(i==s.length()){
            return -1;
        }
        if(dp[i]!=-2){
            return dp[i];
        }

        int ans=INT_MAX;
        for(int k=i; k<s.length(); k++){
            if(pallin(s, i, k, pal)) {
                ans=min(ans, 1 + solve(s, k + 1, dp, pal));
            }
        }

        return dp[i]=ans;
    }

public:
    int minCut(string s) {
        vector<int> dp(s.length(), -2);
        vector<vector<int>> pal(s.length(), vector<int>(s.length(), -1));

        return solve(s, 0, dp, pal);
    }
};
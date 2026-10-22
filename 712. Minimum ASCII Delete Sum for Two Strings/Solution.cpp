class Solution {
private:

    int solve(const string& s1, const string& s2, int i, int j, vector<vector<int>>& dp){
        if(i<0){
            int sum=0;
            for (int k=0; k<=j; k++) {
                sum+=(int)s2[k];
            }
            return sum;
        }
        if(j<0){
            int sum=0;
            for (int k=0; k<=i; k++) {
                sum+=(int)s1[k];
            }
            return sum;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1, s2, i-1, j-1, dp);
        }

        return dp[i][j]=min((int)s1[i] + solve(s1, s2, i-1, j, dp), (int)s2[j] + solve(s1, s2, i, j-1, dp));
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res=solve(s1, s2, n-1, m-1, dp);

        return res;
    }
};

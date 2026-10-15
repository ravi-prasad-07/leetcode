class Solution{
private:

    int solve(int n, int i, vector<vector<int>>& dp){
        if(n==0){
            return 0;
        }
        if(i*i>n){
            return INT_MAX;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }

        int sq=i*i;
        int take=solve(n-sq, i, dp);
        if(take!=INT_MAX){
            take+=1;
        }
        int not_take=solve(n,i+1, dp);

        return dp[n][i]=min(take, not_take);

    }

public:
    int numSquares(int n) {

        vector<vector<int>> dp(n+1, vector<int>(sqrt(n) + 2, -1));

        return solve(n, 1, dp);
    }
};
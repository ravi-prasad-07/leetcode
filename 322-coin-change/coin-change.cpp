class Solution {
public:

    int solve(vector<int>& arr, int amt, int n, vector<vector<int>>& dp){
        if(amt==0){
            return 0;
        }
        if(n==0){
            return INT_MAX;
        }
        if(dp[n][amt]!=-1){
            return dp[n][amt];
        }

        int notake=solve(arr, amt, n-1, dp);
        int take=INT_MAX;

        if(arr[n-1]<=amt){
            int res=solve(arr, amt-arr[n-1], n, dp);

            if(res!=INT_MAX) {
                take=1+res;
            }
        }
        
        return dp[n][amt]=min(take, notake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(), amt=amount;
        vector<vector<int>> dp(n+1, vector<int>(amt+1, -1));

        long long sum=solve(coins, amt, n, dp);

        return sum>=INT_MAX ? -1:sum;
    }
};
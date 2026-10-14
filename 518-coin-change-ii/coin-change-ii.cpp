class Solution {
private:

    int solve(const vector<int>& arr, int amt, int n, vector<vector<int>>& dp){
        if(amt==0){
            return 1;
        }
        if(n<0 || amt<0){
            return 0;
        }
        if(dp[n][amt]!=-1){
            return dp[n][amt];
        }

        int take=0;
        if(arr[n]<=amt){
            take=solve(arr, amt-arr[n], n, dp);
        }
        int not_take=solve(arr, amt, n-1, dp);

        return dp[n][amt]=take + not_take;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int res=solve(coins, amount, n-1, dp);

        return res;
    }
};
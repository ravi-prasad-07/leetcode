class Solution {
private:
    int solve(const vector<int>& arr, int fee, int idx, int buy, vector<vector<int>>& dp){
        if(idx>=arr.size()){
            return 0;
        }

        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }

        if(buy){
            return dp[idx][buy]=max(-arr[idx] + solve(arr, fee, idx+1, 0, dp), 0 + solve(arr, fee, idx+1, 1, dp));
        }
        else{
            return dp[idx][buy]=max(arr[idx] - fee + solve(arr, fee, idx+1, 1, dp), 0 + solve(arr, fee, idx+1, 0, dp));
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        
        int res=solve(prices, fee, 0, 1, dp);

        return res;
    }
};
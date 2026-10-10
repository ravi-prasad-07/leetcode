class Solution {
public:

    int solve(vector<int>& arr, int idx, int buy, int k, vector<vector<vector<int>>>& dp){
        if(k==0 || idx>=arr.size()){
            return 0;
        }

        if(dp[idx][buy][k]!=-1){
            return dp[idx][buy][k];
        }

        if(buy){
            return dp[idx][buy][k]=max(-arr[idx] + solve(arr, idx+1, 0, k, dp), 0 + solve(arr, idx+1, 1, k, dp));
        }

        return dp[idx][buy][k]=max(arr[idx] + solve(arr, idx+1, 1, k-1, dp), 0 + solve(arr, idx+1, 0, k, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

        int res=solve(prices, 0, 1, k, dp);

        return res;
    }
};
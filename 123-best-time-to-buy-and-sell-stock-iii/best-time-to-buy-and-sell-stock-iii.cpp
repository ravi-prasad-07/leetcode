class Solution {
public:

    int solve(vector<int>& arr, int idx, int buy, int opr, vector<vector<vector<int>>>& dp){
        if(opr==0 || idx>=arr.size()){
            return 0;
        }

        if(dp[idx][buy][opr]!=-1){
            return dp[idx][buy][opr];
        }

        if(buy){
            return dp[idx][buy][opr]=max(-arr[idx] + solve(arr, idx+1, 0, opr, dp), 0 + solve(arr, idx+1, 1, opr, dp));
        }
        else{
            return dp[idx][buy][opr]=max(arr[idx] + solve(arr, idx+1, 1, opr-1, dp), 0 + solve(arr, idx+1, 0, opr, dp));
        }
    }

    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        int res=solve(prices, 0, 1, 2, dp);
        
        return res;
    }
};
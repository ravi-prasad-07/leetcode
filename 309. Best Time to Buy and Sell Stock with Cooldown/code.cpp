class Solution {
public:
    int solve(vector<int>& arr, int idx, int buy,
              vector<vector<int>>& dp) {

        if (idx >= arr.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        if (buy) {
            return dp[idx][buy] = max(
                -arr[idx] + solve(arr, idx + 1, 0, dp),
                solve(arr, idx + 1, 1, dp)
            );
        }
        else {
            return dp[idx][buy] = max(
                arr[idx] + solve(arr, idx + 2, 1, dp),
                solve(arr, idx + 1, 0, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(
            prices.size(),
            vector<int>(2, -1)
        );

        return solve(prices, 0, 1, dp);
    }
};

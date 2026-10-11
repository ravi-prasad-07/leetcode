class Solution {
private:
    int solve(const vector<int>& arr, int fee, int idx, int buy,
              vector<vector<int>>& dp) {

        if (idx >= arr.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        if (buy) {
            int buyStock = -arr[idx] +
                           solve(arr, fee, idx + 1, 0, dp);

            int skip = solve(arr, fee, idx + 1, 1, dp);

            return dp[idx][buy] = max(buyStock, skip);
        }
        else {
            int sellStock = arr[idx] - fee +
                            solve(arr, fee, idx + 1, 1, dp);

            int hold = solve(arr, fee, idx + 1, 0, dp);

            return dp[idx][buy] = max(sellStock, hold);
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(
            prices.size(),
            vector<int>(2, -1)
        );

        return solve(prices, fee, 0, 1, dp);
    }
};

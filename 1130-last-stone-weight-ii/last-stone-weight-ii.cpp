class Solution {
private:

    int solve(vector<int>& stones, int i, int total, int target, int sum, vector<vector<int>>& dp){
        if(total>=target || i==stones.size()){
            return abs(total - (sum - total));
        }
        if(dp[i][total]!=-1){
            return dp[i][total];
        }

        return dp[i][total]=min(solve(stones, i+1, total, target, sum, dp),
                                solve(stones, i+1, total + stones[i], target, sum, dp));
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(auto it: stones){
            sum+=it;
        }

        int target=ceil((double)sum/2);
        vector<vector<int>> dp(stones.size()+1, vector<int>(target+1, -1));

        int res=solve(stones, 0, 0, target, sum, dp);

        return res;
    }
};
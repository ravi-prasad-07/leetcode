class Solution {
private:

    bool solve(vector<int>& arr, int target, int n, vector<vector<int>>& dp){
        if(target==0){
            return true;
        }
        if(n<0){
            return false;
        }

        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        bool take=false;

        if(arr[n]<=target){
            take=solve(arr, target-arr[n], n-1, dp) || solve(arr, target, n-1, dp);
        }

        bool skip=solve(arr, target, n-1, dp);

        return dp[n][target]=take  || skip;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum=0;

        for(auto it: nums){
            sum+=it;
        }

        if(sum%2!=0){
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>((sum/2) + 1, -1));

        return solve(nums, sum/2, nums.size()-1, dp);
    }
};
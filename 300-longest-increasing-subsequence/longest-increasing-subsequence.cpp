class Solution {
private:

    int solve(const vector<int>& num, int i, int prev, vector<vector<int>>& dp){
        if(i>=num.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        int take=0;
        if(prev==-1 || num[prev]<num[i]){
            take=1 + solve(num, i+1, i, dp);
        }
        int not_take=solve(num, i+1, prev, dp);

        return dp[i][prev+1]=max(take, not_take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));

        int res=solve(nums, 0, -1, dp);
        return res;
    }
};
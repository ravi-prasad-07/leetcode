class Solution {
private:

    vector<int> solve(const vector<int>& num, int i, int prev, vector<vector<vector<int>>>& dp){
        if(i>=num.size()){
            return {};
        }
        if(!dp[i][prev+1].empty()){
            return dp[i][prev+1];
        }

        vector<int> take;
        if(prev==-1 || num[i]%num[prev]==0){
            take=solve(num, i+1, i, dp);
            take.push_back(num[i]);
        }

        vector<int> not_take;
        not_take=solve(num, i+1, prev, dp);

        if(take.size()>not_take.size()){
            return dp[i][prev+1]=take;
        }
        return dp[i][prev+1]=not_take;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size()+1));

        vector<int> ans=solve(nums, 0, -1, dp);

        return ans;
    }
};
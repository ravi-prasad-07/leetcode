class Solution {
private:

    int mcm(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int mx=INT_MIN;
        for(int k=i; k<=j; k++){
            int temp=mcm(arr, i, k-1, dp) + mcm(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j+1];
            mx=max(mx, temp);
        }

        return dp[i][j]=mx;
    }

public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr;

        arr.push_back(1);
        for(auto it: nums){
            arr.push_back(it);
        }
        arr.push_back(1);

        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

        int ans=mcm(arr, 1, nums.size(), dp);
        return ans;
    }
};
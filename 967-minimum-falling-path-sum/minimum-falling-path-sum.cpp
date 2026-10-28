class Solution {
private:

    long long solve(vector<vector<int>>& arr, int i, int j, vector<vector<long long>>& dp){
        int n=arr.size();
        if(j<0 || j>=n){
            return LLONG_MAX;
        }
        if(i==n-1){
            return arr[i][j];
        }

        if(dp[i][j]!=LLONG_MIN){
            return dp[i][j];
        }
        
        long long take1=solve(arr, i+1, j-1, dp);
        long long take2=solve(arr, i+1, j, dp);
        long long take3=solve(arr, i+1, j+1, dp);

        return dp[i][j]=arr[i][j]+min({take1, take2, take3});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        long long ans=LLONG_MAX;
        vector<vector<long long>> dp(matrix.size(), vector<long long>(matrix[0].size(), LLONG_MIN));

        for(int i=0; i<matrix.size(); i++){
            long long res=solve(matrix, 0, i, dp);
            ans=min(ans, res);
        }
        
        return ans;
    }
};
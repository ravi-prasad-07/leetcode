class Solution {
public:

    long long solve(unordered_set<int>& arr, int a, int b, int x, int pos, int back, int lim, vector<vector<int>>& dp){
        if(pos==x){
            return 0;
        }
        if(pos<0 || pos>lim){
            return INT_MAX;
        }
        
        if(dp[pos][back]!=-1){
            return dp[pos][back];
        }
        if(arr.count(pos)){
            return INT_MAX;
        }

        dp[pos][back]=INT_MAX;

        long long fwd=solve(arr, a, b, x, pos+a, 0, lim, dp);
        if(fwd!=INT_MAX){
            fwd++;
        }

        long long bck=INT_MAX;

        if(back==0){
            bck=solve(arr, a, b, x, pos-b, 1, lim, dp);
            if(bck!=INT_MAX){
                bck++;
            }
        }

        return dp[pos][back]=min(fwd, bck);
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int maxi=x;
        unordered_set<int> arr;
        for(auto it: forbidden){
            maxi=max(maxi, it);
            arr.insert(it);
        }

        int lim=maxi+a+b;

        vector<vector<int>> dp(lim+1, vector<int>(2, -1));

        long long res=solve(arr, a, b, x, 0, 0, lim, dp);

        return res>=INT_MAX ? -1:(int)res;
    }
};
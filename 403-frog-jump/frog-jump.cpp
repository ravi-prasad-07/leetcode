class Solution {
public:

    unordered_map<long long, bool> dp;

    bool cross(int i, int n, int k, vector<int>& frog){
        if(i==n-1){
            return true;
        }

        long long key=((long long)i<<32) | k;
        if(dp.count(key)){
            return dp[key];
        }

        for(int j=i+1; j<n; j++){
            int jump=frog[j]-frog[i];
            
            if(jump>k+1){
                break;
            }

            if(jump==k-1 || jump==k || jump==k+1){
                if(cross(j, n, jump, frog)){
                    return dp[key]=true;
                }
            }
        }

        return dp[key]=false;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();

        if(stones[1]!=1){
            return false;
        }

        return cross(1, n, 1, stones);
    }
};
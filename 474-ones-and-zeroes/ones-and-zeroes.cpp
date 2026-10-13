class Solution {
private:

    int solve(const vector<string>& str, int m, int n, int z, int o, int sz, vector<vector<vector<int>>>& dp){
        if(sz<0){
            return 0;
        }
        if(dp[sz][z][o]!=-1){
            return dp[sz][z][o];
        }

        int cnto=0, cntz=0;
        for(char ch: str[sz]){
            if(ch=='0'){
                cntz++;
            }
            else{
                cnto++;
            }
        }

        int not_take=solve(str, m, n, z, o, sz-1, dp);
        int take=0;

        if(o+cnto<=n && z+cntz<=m){
            take=1 + solve(str, m, n, z+cntz, o+cnto, sz-1, dp);
        }

        return dp[sz][z][o]=max(take, not_take);

    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int sz=strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        int res=solve(strs, m, n, 0, 0, sz-1, dp);

        return res;
    }
};
class Solution {
public:

    int solve(string& s, int i, int n, vector<int>& dp){
        if(i==n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int res=solve(s, i+1, n, dp);
        if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                res+=solve(s, i+2, n, dp);
            }
        }

        return dp[i]=res;
    }  

    int numDecodings(string s) {

        vector<int> dp(s.length(), -1);

        return solve(s, 0, s.length(), dp);
    }
};
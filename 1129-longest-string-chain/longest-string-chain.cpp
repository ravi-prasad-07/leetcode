class Solution {
private:

    static bool cmp(string a, string b) {
        return a.size() < b.size();
    }

    bool compare(const string& s1, const string& s2){
        int n=s1.length();
        int m=s2.length();

        if(m-n!=1){
            return false;
        }

        int i=0, j=0;

        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return i==n;
    }

    int solve(const vector<string>& arr, int i, int prev, vector<vector<int>>& dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        int take=0;
        if(prev==-1 || compare(arr[prev], arr[i])==1){
            take=1 + solve(arr, i+1, i, dp);
        }
        int not_take=solve(arr, i+1, prev, dp);

        return dp[i][prev+1]=max(take, not_take);
    }

public:
    int longestStrChain(vector<string>& words) {
        if(words.size()==1){
            return 1;
        }

        sort(words.begin(), words.end(), cmp);

        vector<vector<int>> dp(words.size(), vector<int>(words.size() + 1, -1));

        int res=solve(words, 0, -1, dp);

        return res;
    }
};
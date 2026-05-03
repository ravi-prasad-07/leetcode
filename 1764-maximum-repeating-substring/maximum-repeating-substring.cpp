class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        if (n < m) return 0;

        vector<int> dp(n, 0);
        int max_k = 0;

        for(int i=m-1;i<n;i++){
            bool match=true;
            for(int j=0;j<m;j++){
                if(sequence[i-m+1+j]!=word[j]){
                    match=false;
                    break;
                }
            }

            if(match){
                dp[i]=(i>=m) ? dp[i-m]+1 : 1;
                max_k=max(max_k, dp[i]);
            }
        }

        return max_k;
    }
};
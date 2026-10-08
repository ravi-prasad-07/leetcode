class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int i=1, n=s.length(), length=0;
        vector<int> lps(n, 0);

        while(i<n){
            if(s[i]==s[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length!=0){
                    length=lps[length-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        if(lps[n-1]==0){
            return false;
        }

        int k=n-lps[n-1];

        return n%k==0;
    }
};
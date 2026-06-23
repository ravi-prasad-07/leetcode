class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.length();
        int freq=0,ans=0;
        int ump[26]={0};

        for(int r=0;r<n;r++){
            ump[s[r]-'A']++;
            freq=max(freq, ump[s[r]-'A']);

            while((r-l+1)-freq>k){
                ump[s[l]-'A']--;
                l++;
            }

            ans=max(ans, r-l+1);
        }

        return ans;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> ump;
        int left=0, ans=0;

        for(int right=0; right<s.length(); right++){
            ump[s[right]]++;

            while(ump['a']>0 && ump['b']>0 && ump['c']>0){
                ans=ans+s.length()-left-(right-left+1)+1;
                ump[s[left]]--;
                left++;
            }
        }

        return ans;
    }
};
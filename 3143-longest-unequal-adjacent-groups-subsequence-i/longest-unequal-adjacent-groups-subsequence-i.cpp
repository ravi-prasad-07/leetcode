class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string> res;

        res.push_back(words[0]);
        int last=groups[0];

        for(int i=0;i<n;i++){
            if(groups[i]!=last){
                res.push_back(words[i]);
                last=groups[i];
            }
        }

        return res;
    }
};
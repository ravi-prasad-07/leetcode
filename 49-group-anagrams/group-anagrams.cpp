class Solution {
private:

    bool cmp(const string& str, const string& st){
        int n=str.length();
        int m=str.length();

        if(n!=m){
            return false;
        }

        unordered_map<char, bool> ump;

        for(auto it: str){
            ump[it]=true;
        }

        for(auto it: st){
            if(!ump.count(it)){
                return false;
            }
        }

        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()<2){
            return {strs};
        }

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ump;

        for(int i=0; i<strs.size(); i++){
            string temp=strs[i];

            sort(temp.begin(), temp.end());

            ump[temp].push_back(strs[i]);
        }

        for(auto it: ump){
            ans.push_back(it.second);
        }

        return ans;
    }
};
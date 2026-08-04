class Solution {
public:

    void solve(string& s, vector<string>& ans, int pos){
        if(pos==s.length()){
            ans.push_back(s);
            return;
        }

        if(isdigit(s[pos])){
            solve(s, ans, pos+1);
        }
        else{
            s[pos]=tolower(s[pos]);
            solve(s, ans, pos+1);

            s[pos]=toupper(s[pos]);
            solve(s, ans, pos+1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, ans, 0);

        return ans;
    }
};
class Solution {
public:

    void solve(int i, string& str, unordered_map<char, string>& mp, vector<string>& res, string& temp){
        if(i==str.length()){
            res.push_back(temp);
            return;
        }

        char ch=str[i];
        for(auto it: mp[ch]){
            temp+=it;
            solve(i+1, str, mp, res, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> res;
        string temp;

        solve(0, digits, mp, res, temp);

        return res;
    }
};
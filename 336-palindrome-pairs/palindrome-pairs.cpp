class Solution {
public:
    bool pallin(string& str, int st, int end){
        while(st<end){
            if(str[st]!=str[end]) return false;
            st++; end--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, vector<int>> ump;
        for(int i=0; i<words.size(); i++){
            ump[words[i]].push_back(i);
        }

        vector<vector<int>> res;

        for(int i=0; i<words.size(); i++){
            int len=words[i].size();
            string temp=words[i];

            for(int j=0; j<=len; j++){
                if(pallin(temp, j, temp.length()-1)){
                    string left=temp.substr(0, j);
                    string revLeft(left.rbegin(), left.rend());
                    auto it=ump.find(revLeft);
                    if(it!=ump.end()){
                        for(int idx : it->second){
                            if(idx != i) res.push_back({i, idx});
                        }
                    }
                }

                if(j!=0 && pallin(temp, 0, j-1)){
                    string right=temp.substr(j);
                    string revRight(right.rbegin(), right.rend());
                    auto it=ump.find(revRight);
                    if(it!=ump.end()){
                        for(int idx : it->second){
                            if(idx != i) res.push_back({idx, i});
                        }
                    }
                }
            }
        }

        return res;
    }
};
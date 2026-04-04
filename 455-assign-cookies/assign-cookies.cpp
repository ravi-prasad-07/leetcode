class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0,j=0,cnt=0;
        int gs=g.size()-1,ss=s.size()-1;
        while(i<=gs && j<=ss){
            if(g[i]<=s[j]){
                i++;
                cnt++;
            }
            j++;
        }

        return cnt;
    }
};
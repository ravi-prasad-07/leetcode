class Solution {
private:

    int pallinCount(const string& str, int l, int r){
        int n=str.length();
        int cnt=0;

        while(l>=0 && r<n && str[l]==str[r]){
            r++;
            l--;
            cnt++;
        }

        return cnt;
    }

public:
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.length();

        for(int i=0; i<n; i++){
            int l=i,r=i;
            cnt+=pallinCount(s, l, r);
            cnt+=pallinCount(s, l, r+1);
        }

        return cnt;
    }
};
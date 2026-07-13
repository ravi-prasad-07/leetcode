class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.length()-1;
        int j=t.length()-1;

        while(i>=0 || j>=0){
            int ss=0, st=0;

            while(i>=0){
                if(s[i]=='#'){
                    ss++;
                    i--;
                }
                else if(ss>0){
                    ss--;
                    i--;
                }
                else{
                    break;
                }
            }

            while (j >= 0) {
                if (t[j] == '#') {
                    st++;
                    j--;
                }
                else if (st > 0) {
                    st--;
                    j--;
                }
                else {
                    break;
                }
            }

            if(i>=0 && j>=0){
                if(s[i]!=t[j]){
                    return false;
                }
            }
            else if(i>=0 || j>=0){
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};
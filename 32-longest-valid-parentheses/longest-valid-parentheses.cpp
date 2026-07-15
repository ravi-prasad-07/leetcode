class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0){
            return 0;
        }

        int open=0, close=0;
        int ans=0;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }

            if(open==close){
                int len=open+close;
                ans=max(ans, len);
            }
            else if(close>open){
                open=close=0;
            }
        }

        open=close=0;

        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }

            if(open==close){
                ans=max(ans, open+close);
            }
            else if(open>close){
                open=close=0;
            }
        }

        return ans;
    }
};
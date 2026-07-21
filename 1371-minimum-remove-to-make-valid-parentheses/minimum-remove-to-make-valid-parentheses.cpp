class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string str="";
        int open=0;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                open++;
                str+="(";
            }
            else if(s[i]==')'){
                if(open>0){
                    str+=")";
                    open--;
                }
            }
            else{
                str+=s[i];
            }
        }

        string ans="";

        for(int i=str.length()-1; i>=0; i--){
            if(str[i]=='(' && open>0){
                open--;
            }
            else{
                ans+=str[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
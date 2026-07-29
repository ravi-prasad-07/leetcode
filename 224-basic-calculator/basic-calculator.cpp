class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long num=0;
        int ans=0;
        int sign=1;

        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                continue;
            }

            if(isdigit(s[i])){
                num=num*10 + (s[i]-'0');
            }
            else if(s[i]=='+'){
                ans+=num*sign;
                num=0;
                sign=1;
            }
            else if(s[i]=='-'){
                ans+=num*sign;
                num=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);

                ans=0;
                num=0;
                sign=1;
            }
            else if(s[i]==')'){
                ans+=num*sign;
                num=0;

                int top_sign=st.top(); st.pop();
                int top_num=st.top(); st.pop();

                ans=top_num + (ans*top_sign);
            }
        }
        
        ans+=num*sign;
        return ans;
    }
};
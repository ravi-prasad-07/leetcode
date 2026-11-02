class Solution {
private:

    char solve(vector<char>& val, char oper){
        if(oper=='!'){
            return val[0]=='t' ? 'f':'t';
        }
        else if(oper=='&'){
            for(char ch: val){
                if(ch=='f'){
                    return 'f';
                }
            }

            return 't';
        }
        else if(oper=='|'){
            for(char ch: val){
                if(ch=='t'){
                    return 't';
                }
            }

            return 'f';
        }

        return val[0];
    }

public:
    bool parseBoolExpr(string expression) {
        int n=expression.length();

        stack<char> st;

        for(int i=0; i<n; i++){
            if(expression[i]==',') continue;
            
            if(expression[i]==')'){
                vector<char> val;

                while(st.top()!='('){
                    val.push_back(st.top());
                    st.pop();
                }

                st.pop();
                if(!st.empty()){
                    char oper=st.top();
                    st.pop();

                    st.push(solve(val, oper));
                }
            }
            else{
                st.push(expression[i]);
            }
        }

        return st.top()=='t' ? true:false;
    }
};
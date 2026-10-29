class Solution {
public:
    bool checkValidString(string s) {
        int low=0, high=0;

        for(char ch: s){
            if(ch=='('){
                low++;
                high++;
            }
            else if(ch==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }

            if(high<0){
                return false;
            }

            low=max(low, 0);
        }

        return low==0;
    }
};
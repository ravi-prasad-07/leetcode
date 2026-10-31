class Solution {
public:
    int minimumLength(string s) {
        int i=0, j=s.length()-1;

        while(i<j && s[i]==s[j]){
                char ch=s[i];
                while(i<=j && ch==s[i]) i++;
                while(i<=j && ch==s[j]) j--;
        }

        return j-i+1;
    }
};
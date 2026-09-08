class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int n=str.length();
        vector<int> ind(n);

        if(str.length()==1){
            return num;
        }

        ind[n-1]=n-1;
        for(int i=n-2; i>=0; i--){
            if(str[i]-'0'>str[ind[i+1]]-'0'){
                ind[i]=i;
            }
            else{
                ind[i]=ind[i+1];
            }
        }

        for(int i=0; i<n; i++){
            if(str[i]-'0'<str[ind[i]]-'0'){
                swap(str[i], str[ind[i]]);
                return stoi(str);
            }
        }

        return stoi(str);
    }
};
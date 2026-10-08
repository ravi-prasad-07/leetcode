class Solution {
public:

    bool kmp(string& a, string& b){
        int m=b.length();
        int n=a.length();

        vector<int> lps(m, 0);

        int i=1, length=0;

        while(i<m){
            if(b[i]==b[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length!=0){
                    length=lps[length-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }

        int j=0, k=0;

        while(j<n && k<m){
            if(a[j]==b[k]){
                j++;
                k++;
            }
            else{
                if(k!=0){
                    k=lps[k-1];
                }
                else{
                    j++;
                }
            }
        }

        if(k==m){
            return true;
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int n=b.length(), m=a.length();

        int k=ceil((double)n/m);

        string s="";

        for(int i=0; i<k; i++){
            s+=a;
        }

        if(kmp(s, b)){
            return k;
        }

        s+=a;

        if(kmp(s, b)){
            return k+1;
        }

        return -1;
    }
};
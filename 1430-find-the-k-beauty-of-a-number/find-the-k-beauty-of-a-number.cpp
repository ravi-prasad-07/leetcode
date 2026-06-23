class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt=0,chk=0;
        string n=to_string(num);
        
        int ston=0;
        int tens=1;
        for(int i=1;i<k;i++){
            tens*=10;
        }

        for(int i=0;i<n.length();i++){
            ston=ston*10 + (n[i]-'0');
            chk++;
            if(chk==k){
                if(ston!=0 && num%ston==0){
                    cnt++;
                }

                ston=ston-((n[i-k+1]-'0')*tens); 
                chk=k-1;
            }
        }

        return cnt;
    }
};
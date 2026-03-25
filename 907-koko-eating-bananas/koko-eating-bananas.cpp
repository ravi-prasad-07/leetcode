class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long m=INT_MIN,sum=0,temp=0;
        for(auto it:piles){
            if(it>m){
                m=it;
            }
        }

        int mid=1,end=m,i;
        while(mid<end){
            sum=0;
            i=(mid+end)/2;
            for(int j=0;j<piles.size();j++){
                if(piles[j]%i==0){
                    temp=piles[j]/i;
                }
                else{
                    temp=(piles[j]/i)+1;
                }
                sum+=temp;
            }
            if(sum<=h){
                end=i;
            }
            else{
                mid=i+1;
            }
        }

        return end;
    }
};
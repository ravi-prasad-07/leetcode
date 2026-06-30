class Solution {
public:

    int cal(long long i){
        int res=0;
        while(i){
            i/=5;
            res+=i;
        }

        return res;
    }

    int preimageSizeFZF(int k) {
        if(k==0){
            return 5;
        }

        long long i=0, j=5000000005LL;
        long long l=-1, r=-1;

        while(i<=j){
            long long mid=i+(j-i)/2;
            int temp=cal(mid);

            if(temp==k){
                l=mid;
                j=mid-1;
            }
            else if(temp>k){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

        if(l==-1){
            return 0;
        }

        i=0, j=5000000005LL;

        while(i<=j){
            long long mid=i+(j-i)/2;
            int temp=cal(mid);

            if(temp==k){
                r=mid;
                i=mid+1;
            }
            else if(temp>k){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

        return r-l+1;
    }
};
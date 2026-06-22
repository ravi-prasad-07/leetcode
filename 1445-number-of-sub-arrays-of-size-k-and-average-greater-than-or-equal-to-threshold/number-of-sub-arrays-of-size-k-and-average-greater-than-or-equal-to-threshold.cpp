class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0, sum=0;
        int l=0;

        for(int r=0;r<arr.size();r++){
            sum+=arr[r];

            if(r-l+1==k){
                if((sum/k)>=threshold){
                    cnt++;
                }
                sum=sum-arr[l];
                l++;
            }
        }

        return cnt;
    }
};
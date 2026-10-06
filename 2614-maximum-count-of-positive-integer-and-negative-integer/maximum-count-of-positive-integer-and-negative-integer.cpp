class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=0, pos=0, zero=0;

        int low=0, high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]<0){
                neg=mid+1;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        low=neg, high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==0){
                zero=mid+1;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        zero=zero>0 ? zero-neg : zero;
        pos=nums.size()-neg-zero;

        return max(neg, pos);
    }
};
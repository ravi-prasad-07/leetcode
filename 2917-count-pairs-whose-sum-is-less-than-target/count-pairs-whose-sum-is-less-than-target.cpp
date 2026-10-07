class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int low=0, high=nums.size()-1, cnt=0;

        while(low<high){
            if(nums[low]+nums[high]<target){
                cnt+=high-low;
                low++;
            }
            else{
                high--;
            }
        }

        return cnt;
    }
};
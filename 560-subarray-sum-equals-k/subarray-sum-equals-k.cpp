class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0]=1;
        int sum=0, ans=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];

            if(ump.count(sum-k)){
                ans+=ump[sum-k];
            }
            
            ump[sum]++;
        }

        return ans;

    }
};
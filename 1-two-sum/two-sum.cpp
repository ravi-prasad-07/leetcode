class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;

        for(int i=0; i<nums.size(); i++){
            int n=target-nums[i];

            if(ump.count(n)){
                return {ump[n], i};
            }

            ump[nums[i]]=i;
        }

        return {};
    }
};
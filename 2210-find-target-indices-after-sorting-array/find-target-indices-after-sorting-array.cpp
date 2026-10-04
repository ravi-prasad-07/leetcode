class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;

        int small=0, equal=0;

        for(int it: nums){
            if(it<target){
                small++;
            }
            else if(it==target){
                equal++;
            }
        }

        for(int i=small; i<small+equal; i++){
            ans.push_back(i);
        }

        return ans;
    }
};
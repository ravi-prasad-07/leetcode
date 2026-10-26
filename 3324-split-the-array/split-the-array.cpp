class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> ump;

        for(auto it: nums){
            ump[it]++;

            if(ump[it]>2){
                return false;
            }
        }

        return true;
    }
};
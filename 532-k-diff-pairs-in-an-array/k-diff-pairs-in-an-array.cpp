class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }

        unordered_map<int, int> ump;
        int cnt=0;

        for(auto it: nums){
            ump[it]++;
        }

        if(k==0){
            for(auto [num, f]: ump){
                if(f>1){
                    cnt++;
                }
            }
        }
        else{
            for(auto [num, f]: ump){
                if(ump.count(num+k)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ump;
        int sum=0, mx=0;
        ump[0]=-1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }
            
            if(ump.count(sum)){
                mx=max(mx, i-ump[sum]);
            }
            else{
                ump[sum]=i;
            }
        }

        return mx;
    }
};
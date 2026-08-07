class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        if(nums.size()==1){
            return {to_string(nums[0])};
        }

        vector<string> ans;
        int k=0,n=nums.size();
        
        for(int i=0; i<n-1; i++){
            if((long long)nums[i+1]-(long long)nums[i]!=1){
                if(i==k){
                    ans.push_back(to_string(nums[i]));
                }
                else{
                    ans.push_back(to_string(nums[k])+"->"+to_string(nums[i]));
                }
                k=i+1;
            }

        }

        if (k==n-1) {
            ans.push_back(to_string(nums[k]));
        } else {
            ans.push_back(to_string(nums[k])+"->"+to_string(nums[n - 1]));
        }

        return ans;
    }
};
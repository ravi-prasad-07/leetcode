class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size()<=0){
            return 0;
        }

        int ans=0;
        int l=0, r=height.size()-1;
        int maxL=height[l], maxR=height[r];

        while(l<r){
            if(maxL<maxR){
                l++;
                maxL=max(maxL, height[l]);
                ans+=maxL-height[l];
            }
            else{
                r--;
                maxR=max(maxR, height[r]);
                ans+=maxR-height[r];
            }
        }

        return ans;
    }
};
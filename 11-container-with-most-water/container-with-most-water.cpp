class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0, l=0, r=height.size()-1;

        while(l<r){
            int m=0;
            if(height[l]<height[r]){    
                m=(r-l)*height[l];
                l++;
            }
            else{
                m=(r-l)*height[r];
                r--;
            }
            ans=max(m, ans);
        }

        return ans;
    }
};
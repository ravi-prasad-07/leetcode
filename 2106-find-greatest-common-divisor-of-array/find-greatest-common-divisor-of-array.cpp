class Solution {
public:

    int hcf(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int small=INT_MAX;
        int large=INT_MIN;

        for(auto it:nums){
            if(small>it){
                small=it;
            }
            if(large<it){
                large=it;
            }
        }

        return hcf(small, large);
    }
};
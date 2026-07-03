class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        st.reserve(nums.size() * 2);

        for (int x: nums){
            st.insert(x);
        }

        int res=0;

        for (int it: st) {
            if (!st.count(it-1)) {
                int curr=it;
                int len=1;

                while (st.count(curr+1)) {
                    curr++;
                    len++;
                }

                res = max(res, len);
            }
        }

        return res;
    }
};
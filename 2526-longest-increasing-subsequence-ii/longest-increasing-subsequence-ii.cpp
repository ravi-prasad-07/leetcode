class Solution {
public:
    vector<int> tree;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node+1, start, mid, idx, val);
        else update(2*node+2, mid+1, end, idx, val);
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return max(query(2*node+1, start, mid, l, r),
                   query(2*node+2, mid+1, end, l, r));
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        tree.assign(4 * (maxVal + 1), 0);

        int ans = 0;
        for (int num : nums) {
            int lo = max(0, num - k);
            int hi = num - 1;
            int best = (hi >= lo) ? query(0, 0, maxVal, lo, hi) : 0;
            int length = best + 1;
            update(0, 0, maxVal, num, length);
            ans = max(ans, length);
        }
        return ans;
    }
};
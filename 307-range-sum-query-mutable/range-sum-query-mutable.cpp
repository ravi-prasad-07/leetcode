class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int n;

    NumArray(vector<int>& nums_) {
        nums = nums_;
        n = nums.size();
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            add(i, nums[i]);
        }
    }

    void add(int i, int val) {
        for (int idx = i + 1; idx <= n; idx += idx & (-idx)) {
            tree[idx] += val;
        }
    }

    int prefixSum(int i) {
        int sum = 0;
        for (int idx = i + 1; idx > 0; idx -= idx & (-idx)) {
            sum += tree[idx];
        }
        return sum;
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefixSum(right);
        return prefixSum(right) - prefixSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
class Solution {
public:

    static const int m=1111;

    int segment[4*m];

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]){
            return a[0] < b[0];
        }
        
        return a[1] > b[1];
    }

    void buildSeg(int idx, int l, int r){
        if(l==r){
            segment[idx]=1;
            return;
        }

        int mid=l+(r-l)/2;
        buildSeg(2*idx,l, mid);
        buildSeg(2*idx+1, mid+1, r);

        segment[idx]=segment[2*idx]+segment[2*idx+1];
    }

    int query(int idx, int l, int r, int val){
        if(l==r){
            return l;
        }

        int mid=l+(r-l)/2;
        int l_child=2*idx, l_wt=segment[l_child];

        if(val<=l_wt){
            return query(l_child, l, mid, val);
        }
        else{
            return query(l_child+1, mid+1, r, val-l_wt);
        }

    }

    void update(int idx, int l, int r, int pos){
        if(l==r){
            segment[idx]=0;
            return;
        }

        int mid=l+(r-l)/2;

        if(pos<=mid){
            update(2*idx, l, mid, pos);
        }
        else{
            update(2*idx+1, mid+1, r, pos);
        }

        segment[idx]=segment[2*idx]+segment[2*idx+1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), cmp);
        int n=people.size();
        vector<vector<int>> ans(n);

        buildSeg(1, 0, n-1);

        for(const auto v: people){
            int pos=v[1]+1;
            int idx=query(1, 0, n-1, pos);
            ans[idx]=v;
            update(1, 0, n-1, idx);
        }

        return ans;
    }
};
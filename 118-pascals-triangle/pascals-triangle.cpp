class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);

        for(int i=0;i<n;i++){
            int num=1;
            for(int j=0;j<=i;j++){
                res[i].push_back(num);
                num=num*(i-j)/(j+1);
            }
        }

        return res;
    }
};
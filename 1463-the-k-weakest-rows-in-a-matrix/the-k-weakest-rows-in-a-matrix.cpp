class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vec;

        for(int i=0; i<mat.size(); i++){
            int sum=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    sum++;
                }
                else{
                    break;
                }
            }
            vec.push_back({sum, i});
        }

        nth_element(vec.begin(), vec.begin() + k, vec.end());
        sort(vec.begin(), vec.begin() + k);

        vector<int> ans(k);

        for(int i=0; i<k; i++){
            ans[i]=vec[i].second;
        }

        return ans;
    }
};
class Solution {
public:

    int numSpecial(vector<vector<int>>& mat) {

        int cnt=0;
        int m=mat.size();
        int n=mat[0].size();

        vector<int> row(m,0), col(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]+=mat[i][j];
                col[j]+=mat[i][j];
            }
        }

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
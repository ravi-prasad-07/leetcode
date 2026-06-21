class NumMatrix {
public:

    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        ans.resize(n+1, vector<int>(m+1));

        ans[0][0]=matrix[0][0];
        
        for(int i=1;i<m;i++){
            ans[0][i]=ans[0][i-1]+matrix[0][i];
        }
        for(int i=1;i<n;i++){
            ans[i][0]=ans[i-1][0]+matrix[i][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ans[i][j]=matrix[i][j]+ans[i-1][j]-ans[i-1][j-1]+ans[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = ans[row2][col2];

        if(row1>0){
            res-=ans[row1-1][col2];
        }
        if(col1>0){
            res-=ans[row2][col1-1];
        }
        if (row1>0 && col1>0){
            res+=ans[row1-1][col1-1];
        }

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
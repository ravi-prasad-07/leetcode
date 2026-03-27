class Solution {
public:
    bool areSimilar(vector<vector<int>>& ori, int k) {
        vector<vector<int>> mat=ori;
        int m=mat.size();//row
        int n=mat[0].size();//column
        int temp;

        while(k>0){
            for(int i=0;i<m;i++){
                if(i%2==0){
                    temp=mat[i][0];
                    for(int j=0;j<n-1;j++){
                        mat[i][j]=mat[i][j+1];
                    }
                    mat[i][n-1]=temp;
                }
                else{
                    temp=mat[i][n-1];
                    for(int j=n-1;j>0;j--){
                        mat[i][j]=mat[i][j-1];
                    }
                    mat[i][0]=temp;
                }
            }
            k--;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ori[i][j]!=mat[i][j]){
                    return false;
                }
            }
        }

        return true;
    }
};
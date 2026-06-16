class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        vector<vector<int>> dis={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int val=q.front().second;

            q.pop();

            ans[i][j]=val;

            for(int k=0;k<4;k++){
                int ni=i+dis[k][0];
                int nj=j+dis[k][1];

                if(ni>=0 && nj>=0 && ni<mat.size() && nj<mat[0].size() &&
                vis[ni][nj]==0){

                    vis[ni][nj] = 1;
                    q.push({{ni,nj},val+1});
                }
            }
        }

        return ans;
    }
};
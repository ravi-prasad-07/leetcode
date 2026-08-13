class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int, int>> q;

        for(int i=0; i<grid.size(); i++){
            if(grid[i][0]==1){
                q.push({i, 0});
                visit[i][0]=1;
            }
            if(grid[i][grid[0].size()-1]==1){
                q.push({i, grid[0].size()-1});
                visit[i][grid[0].size()-1]=1;                
            }
        }

        for(int i=0; i<grid[0].size(); i++){
            if(grid[0][i]==1){
                q.push({0, i});
                visit[0][i]=1;
            }
            if(grid[grid.size()-1][i]==1){
                q.push({grid.size()-1, i});
                visit[grid.size()-1][i]=1;                
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();

            for(int k=0; k<4; k++){
                int nr=i+arr[k][0];
                int nc=j+arr[k][1];
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() &&
                visit[nr][nc]==0 && grid[nr][nc]==1){

                    visit[nr][nc]=1;
                    q.push({nr,nc});

                }
            }
        }

        int cnt=0;
        for(int i=1; i<grid.size()-1; i++){
            for(int j=1; j<grid[0].size()-1; j++){
                if(grid[i][j]==1 && visit[i][j]==0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
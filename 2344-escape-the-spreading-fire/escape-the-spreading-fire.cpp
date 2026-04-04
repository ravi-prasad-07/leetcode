class Solution {
public:

    vector<vector<int>> burn(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        vector<vector<int>> fireTime(m,vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fireTime[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int t=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr=r+dir[i][0];
                    int nc=c+dir[i][1];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=2 && fireTime[nr][nc]==INT_MAX){
                        fireTime[nr][nc]=t;
                        q.push({nr,nc});
                    }
                }
            }
            t++;
        }

        return fireTime;
    }

    bool escape(vector<vector<int>>& grid, vector<vector<int>>& fireTime, int wait){
        
        if(fireTime[0][0]<=wait){
            return false;
        }
        
        int m=grid.size();
        int n=grid[0].size();

        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        q.push({0,0});
        vis[0][0]=1;

        int steps=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nr=r+dir[k][0];
                    int nc=c+dir[k][1];

                    if(nr<0 || nr>=m || nc<0 || nc>=n){
                        continue;
                    }
                    if(grid[nr][nc]==2 || vis[nr][nc]==1){
                        continue;
                    }

                    int arrive=wait+steps;

                    if(nr==m-1 && nc==n-1){
                        if(arrive<=fireTime[nr][nc]){
                            return true;
                        }
                        continue;
                    }

                    if(arrive<fireTime[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }                
            }

            steps++;
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int low=0, hi=m*n, ans=-1;

        vector<vector<int>> fire=burn(grid);

        while(low<=hi){
            int mid=low+(hi-low)/2;

            if(escape(grid, fire, mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans==m*n ? 1e9:ans;
    }
};
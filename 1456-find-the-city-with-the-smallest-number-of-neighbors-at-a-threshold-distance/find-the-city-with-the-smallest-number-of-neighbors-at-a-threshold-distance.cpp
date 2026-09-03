class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int inf=1e9;
        
        vector<vector<int>> reach(n, vector<int>(n, inf));

        for(int i=0; i<n; i++){
            reach[i][i]=0;
        }

        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            reach[u][v]=wt;
            reach[v][u]=wt;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    reach[i][j]=min(reach[i][j], reach[i][k]+reach[k][j]);
                }
            }
        }

        int ans=INT_MAX;
        int res;

        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(reach[i][j]==inf) continue;
                
                if(reach[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(ans>=cnt){
                ans=cnt;
                res=i;
            }
        }

        return res;
    }
};
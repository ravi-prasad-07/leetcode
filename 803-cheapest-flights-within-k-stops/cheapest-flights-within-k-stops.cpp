class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n,INT_MAX);
        dis[src]=0;

        for(int i=0;i<=k;i++){
            vector<int> temp=dis;
            for(auto it:flights){
                int u=it[0];
                int v=it[1];
                int w=it[2];

                if(dis[u]!=INT_MAX && dis[u]+w<temp[v]){
                    temp[v]=dis[u]+w;
                }
            }
            dis=temp;
        }

        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};
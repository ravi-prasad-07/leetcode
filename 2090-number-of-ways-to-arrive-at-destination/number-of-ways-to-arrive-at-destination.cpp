class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF=1e18;
        const int MOD=1e9+7;
        
        vector<vector<pair<int, int>>> arr(n);

        for(int i=0; i<roads.size(); i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int t=roads[i][2];

            arr[u].push_back({v, t});
            arr[v].push_back({u, t});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        vector<long long> dis(n, INF);
        vector<int> root(n);

        dis[0]=0;
        root[0]=1;

        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, u]=pq.top();
            pq.pop();

            if(d>dis[u]) continue;

            for(auto it: arr[u]){
                int wt=it.second;
                int v=it.first;

                if(dis[v]>d+wt){
                    dis[v]=d+wt;
                    pq.push({dis[v], v});

                    root[v]=root[u];
                }
                else if(dis[v]==d+wt){
                    root[v]=(root[v]+root[u])%MOD;
                }
            }
        }

        return root[n-1];
    }
};
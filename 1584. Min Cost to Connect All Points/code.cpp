class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int sum = 0;

        vector<int> vis(n, 0);

        // {cost, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Start from point 0
        pq.push({0, 0});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            // Already included in MST
            if (vis[node])
                continue;

            vis[node] = 1;
            sum += wt;

            // Try connecting current point with every
            // unvisited point
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int cost =
                        abs(points[node][0] - points[i][0]) +
                        abs(points[node][1] - points[i][1]);

                    pq.push({cost, i});
                }
            }
        }

        return sum;
    }
};

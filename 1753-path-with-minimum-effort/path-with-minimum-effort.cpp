class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0]=0;
        pq.push({0, {0, 0}});
        int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!pq.empty()){
            auto[effort, cell]=pq.top();
            auto[row, col]=cell;
            pq.pop();

            if(row==m-1 && col==n-1){
                return effort;
            }

            if(effort>dist[row][col]){
                continue;
            }

            for(int k=0; k<4; k++){
                int newRow=row+dir[k][0];
                int newCol=col+dir[k][1];

                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n){
                    int diff=abs(heights[row][col]-heights[newRow][newCol]);
                    int newEffort=max(effort, diff);

                    if(newEffort<dist[newRow][newCol]){
                        dist[newRow][newCol]=newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }

        return 0;
    }
};
/*
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int first=abs(heights[0][0]-heights[0][1]);
        int second=abs(heights[0][0]-heights[1][0]);
        vector<vector<int>> vis(heights.size(), vector<int>(heights[0].size(), 0));
        int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};

        queue<pair<int, int>> q;
        q.push({0, 0});
        int m=heights.size();
        int n=heights[0].size();
        bool set=false;

        while(!q.empty()){
            auto[i, j]=q.front();
            q.pop();

            if(i==m-1 && j==n-1){
                set=true;
                break;
            }

            for(int k=0; k<4; k++){
                int ir=i+dir[k][0];
                int jc=j+dir[k][1];

                if(ir>=0 && ir<m && jc<n && jc>=0 && vis[ir][jc]!=1 && abs(heights[i][j]-heights[ir][jc])==first){
                    q.push({ir, jc});
                    vis[ir][jc]=1;
                }
            }
        }

        queue<pair<int, int>> q1;
        q1.push({0, 0});
        vector<vector<int>> vis1(heights.size(), vector<int>(heights[0].size(), 0));
        bool set1=false;

        while(!q1.empty()){
            auto[i, j]=q1.front();
            q1.pop();

            if(i==m-1 && j==n-1){
                set1=true;
                break;
            }

            for(int k=0; k<4; k++){
                int ir=i+dir[k][0];
                int jc=j+dir[k][1];

                if(ir>=0 && ir<m && jc<n && jc>=0 && vis1[ir][jc]!=1 && abs(heights[i][j]-heights[ir][jc])==second){
                    q1.push({ir, jc});
                    vis1[ir][jc]=1;
                }
            }
        }

        if(set && set1){
            return min(first, second);
        }
        else if(set){
            return first;
        }
        else{
            return second;
        }

        return -1;
    }
};
*/
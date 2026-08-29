class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int> degree(n);
        vector<vector<int>> help(n);

        for(int i=0; i<n; i++){
            degree[i]=graph[i].size();

            for(int it: graph[i]){
                help[it].push_back(i);
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;

        while(!q.empty()){
            int idx=q.front();
            q.pop();

            ans.push_back(idx);

            for(int i: help[idx]){
                degree[i]--;

                if(degree[i]==0){
                    q.push(i);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
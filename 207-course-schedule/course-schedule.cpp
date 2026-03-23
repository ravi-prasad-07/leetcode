class Solution {
public:

    bool dfs(vector<int> adj[],vector<int>& visit,vector<int>& pathvisit,int point){
    visit[point]=1;
    pathvisit[point]=1;

    for(int i=0;i<adj[point].size();i++){
        if(!visit[adj[point][i]]){
            if(dfs(adj,visit,pathvisit,adj[point][i])){
                return true;    
            }
        }
        else if(pathvisit[adj[point][i]]){
                return true;
        }
    }

    pathvisit[point]=0;
    return false;
}

bool isCyclic(vector<int> adj[],vector<int>& visit,vector<int>& pathvisit,int ver){
    
    for(int i=0;i<ver;i++){
        if(!visit[i]){
            if(dfs(adj,visit,pathvisit,i)){
                return true;
            }
        }
    }

    return false;
}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathvisit(numCourses, 0);

        // for(int i=0;i<numCourses;i++){
        //     for(auto it:adj[i]){
        //         visited[it]++;
        //     }
        // }

        // queue<int> q;
        // for(int i=0;i<numCourses;i++){
        //     if(visited[i]==0){
        //         q.push(i);
        //     }
        // }

        // vector<int> topo;
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     topo.push_back(node);

        //     for(auto it: adj[node]){
        //         visited[it]--;
        //         if(visited[it]==0){
        //             q.push(it);
        //         }
        //     }
        // }

        // if(topo.size()==numCourses){
        //     return true;
        // }

        // return false;
        return !isCyclic(adj,visited,pathvisit,numCourses);;
    }
};
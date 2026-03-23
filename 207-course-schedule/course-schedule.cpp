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
                return false;
            }
        }
    }

    return true;
}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathvisit(numCourses, 0);

        return isCyclic(adj,visited,pathvisit,numCourses);
    }
};
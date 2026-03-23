class Solution {
public:

    bool dfs(vector<int> adj[],vector<int>& visit,vector<int>& pathvisit,int point, stack<int>& st){
        visit[point]=1;
        pathvisit[point]=1;
        int flag=0;

        for(int i=0;i<adj[point].size();i++){
            if(!visit[adj[point][i]]){
                if(dfs(adj,visit,pathvisit,adj[point][i],st)){
                    flag=1;
                    break;    
                }
            }
            else if(pathvisit[adj[point][i]]){
                    flag=1;
                    break;
            }
        }

        st.push(point);
        pathvisit[point]=0;
        if(!flag){
            return false;
        }
        return true;
    }

    bool isCyclic(vector<int> adj[],vector<int>& visit,vector<int>& pathvisit,int ver,vector<int>& topo){
        stack<int> st;
        int flag=1;
        for(int i=0;i<ver;i++){
            if(!visit[i]){
                if(dfs(adj,visit,pathvisit,i,st)){
                    flag=0;
                    break;
                }
            }
        }

        while(!st.empty()){
            int node=st.top();
            st.pop();

            topo.push_back(node);
        }

        if(flag){
            return true;
        }
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathvisit(numCourses, 0);
        vector<int> topo;

        if(isCyclic(adj,visited,pathvisit,numCourses,topo)){
            return topo;
        }
        else{
            return {};
        }
    }
};
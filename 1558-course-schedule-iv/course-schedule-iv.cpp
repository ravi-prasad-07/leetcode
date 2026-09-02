class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n=numCourses;
        vector<vector<bool>> reach(n, vector<bool>(n, false));
        vector<bool> ans;

        for(auto it: prerequisites) {
            int u=it[0];
            int v=it[1];

            reach[u][v]=true;
        }
        
        for(int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    reach[i][j]=reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }
        }

        for(int i=0; i<queries.size(); i++){
            ans.push_back(reach[queries[i][0]][queries[i][1]]);
        }

        return ans;
    }
};
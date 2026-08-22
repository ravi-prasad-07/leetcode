class Solution {
public:

    int findParent(int a, vector<int>& parent){
        if(parent[a]<0){
            return a;
        }

        return parent[a]=findParent(parent[a], parent);
    }

    void unionSet(int a, int b, vector<int>& parent/*, vector<int>& rank*/){
        int Parent_a=findParent(a, parent);
        int Parent_b=findParent(b, parent);

        if(Parent_a==Parent_b){
            return;
        }
        if(parent[Parent_a]>parent[Parent_b]/*rank[Parent_a]<rank[Parent_b]*/){
            swap(Parent_a, Parent_b);
        }
        /*else if(rank[Parent_a]>rank[Parent_b]){
            parent[Parent_b]=Parent_a;
        }
        else{
            parent[Parent_b]=Parent_a;
            rank[Parent_a]++;
        }*/

        parent[Parent_a] += parent[Parent_b];
        parent[Parent_b] = Parent_a;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1, -1);
        //vector<int> rank(edges.size()+1, 0);

        for(int i=0; i<edges.size(); i++){
            int a=edges[i][0];
            int b=edges[i][1];

            if(findParent(a, parent)==findParent(b, parent)){
                return{a, b};
            }
            unionSet(a, b, parent/*, rank*/);
        }

        return {};
    }
};
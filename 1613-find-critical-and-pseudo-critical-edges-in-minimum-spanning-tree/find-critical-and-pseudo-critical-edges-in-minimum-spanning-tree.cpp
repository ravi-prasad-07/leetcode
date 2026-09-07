class Solution {
public:

    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[2]<b[2];
    }

    int findPar(int u, vector<int>& par){
        if(u==par[u]){
            return u;
        }

        return par[u]=findPar(par[u], par);
    }

    void unite(int u, int v, vector<int>& rank, vector<int>& par){
            int pu=findPar(u, par);
            int pv=findPar(v, par);

            if(pu==pv) return;

            if(rank[pu]>rank[pv]){
                par[pv]=pu;
            }
            else if(rank[pu]<rank[pv]){
                par[pu]=pv;
            }
            else{
                par[pv]=pu;
                rank[pu]++;
            }
    }

    int krushkal(vector<vector<int>>& arr, int n){
        vector<int> par(n);
        vector<int> rank(n, 0);

        int mst=0;

        for(int i=0; i<n; i++){
            par[i]=i;
        }

        for(int i=0; i<arr.size(); i++){
            int pu=findPar(arr[i][0], par);
            int pv=findPar(arr[i][1], par);
            int wt=arr[i][2];

            if(pu==pv) continue;

            mst+=wt;
            unite(pu, pv, rank, par);
        }

        return mst;
    }

    int skipKrush(vector<vector<int>>& arr, int skip, int n){
        vector<int> par(n);
        vector<int> rank(n, 0);

        int mst=0,edge=0;

        for(int i=0; i<n; i++){
            par[i]=i;
        }

        for(int i=0; i<arr.size(); i++){
            if(i==skip) continue;

            int pu=findPar(arr[i][0], par);
            int pv=findPar(arr[i][1], par);
            int wt=arr[i][2];

            if(pu==pv) continue;

            mst+=wt;
            edge++;
            unite(pu, pv, rank, par);
        }

        if(edge!=n-1){
            return INT_MAX;
        }
        return mst;
    }

    int includeKrush(vector<vector<int>>& arr, int skip, int n){
        vector<int> par(n);
        vector<int> rank(n, 0);

        for(int i=0; i<n; i++){
            par[i]=i;
        }

        int mst=arr[skip][2];
        int edge=1;

        unite(arr[skip][0], arr[skip][1], rank, par);


        for(int i=0; i<arr.size(); i++){
            if(i==skip) continue;

            int pu=findPar(arr[i][0], par);
            int pv=findPar(arr[i][1], par);
            int wt=arr[i][2];

            if(pu==pv) continue;

            mst+=wt;
            edge++;
            unite(pu, pv, rank, par);
        }

        if(edge!=n-1){
            return INT_MAX;
        }

        return mst;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int s=edges.size();
        vector<vector<int>> ans(2);

        for(int i=0; i<s; i++){
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), cmp);

        int mst=krushkal(edges, n);

        for(int i=0; i<s; i++){
            int chk=skipKrush(edges, i, n);
            if(chk>mst){
                ans[0].push_back(edges[i][3]);
            }
            else{
                int fmst=includeKrush(edges, i, n);
                
                if(fmst==mst){
                    ans[1].push_back(edges[i][3]);
                }
            }
        }

        return ans;
    }
};
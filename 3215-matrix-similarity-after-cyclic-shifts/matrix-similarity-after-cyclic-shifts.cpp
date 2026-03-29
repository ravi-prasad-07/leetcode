class Solution {
public:
    bool areSimilar(vector<vector<int>>& ori, int k) {
        int m=ori.size();
        int n=ori[0].size();

        k =k%n;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int newCol;

                if(i%2==0) {
                    newCol=(j+k)%n;
                } else {
                    newCol=(j-k+n)%n;
                }

                if(ori[i][j]!=ori[i][newCol]) {
                    return false;
                }
            }
        }

        return true;
    }
};
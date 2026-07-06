class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1;

        for(int i=0; i<points.size(); i++){
            unordered_map<double, int> ump;
            for(int j=i+1; j<points.size(); j++){
                double temp;
                if(points[i][0]==points[j][0]){
                    temp=DBL_MAX;
                }
                else{
                    temp=double(points[j][1]-points[i][1])/double(points[j][0]-points[i][0]);
                }

                ump[temp]++;
                ans=max(ans, ump[temp]+1);
            }
        }

        return ans;
    }
};
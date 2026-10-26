class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            return intervals;
        }
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int start=intervals[0][0];
        int prev=intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=prev){
                prev=max(prev, intervals[i][1]);
            }
            else{
                ans.push_back({start, prev});
                start=intervals[i][0];
                prev=intervals[i][1];
            }
        }

        ans.push_back({start, prev});

        return ans;
    }
};
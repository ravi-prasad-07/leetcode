class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1){
            return 0;
        }

        sort(intervals.begin(),intervals.end());

        int pre=intervals[0][1];
        int cnt=0;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<pre){
                cnt++;
                pre=min(pre,intervals[i][1]);
            }
            else{
                pre=intervals[i][1];
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX,bns=INT_MAX;
        int cns=INT_MAX,dns=INT_MAX;

        for(int i=0;i<landStartTime.size();i++){
            int sum=landStartTime[i]+landDuration[i];
            ans=min(sum,ans);
        }
        for(int i=0;i<waterStartTime.size();i++){
            int temp=max(ans,waterStartTime[i]);
            int sum=temp+waterDuration[i];
            bns=min(sum,bns);
        }


        for(int i=0;i<waterStartTime.size();i++){
            int sum=waterStartTime[i]+waterDuration[i];
            cns=min(sum,cns);
        }
        for(int i=0;i<landStartTime.size();i++){
            int temp=max(cns,landStartTime[i]);
            int sum=temp+landDuration[i];
            dns=min(sum,dns);
        }

        return min(bns,dns);
    }
};
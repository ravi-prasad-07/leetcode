class Solution {
public:

    int fun(int at, int p, int lt){
        int r=at%p;
        if(r<lt){
            return 0;
        }

        return p-r;
    }

    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx=INT_MIN;
        for(int it: lights){
            mx=max(mx, it);
        }

        int ans=INT_MIN;
        for(int it: arrivalTime){
            ans=max(ans, fun(it, period, mx));
        }

        return ans;
    }
};
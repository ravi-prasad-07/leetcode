class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        int st=0,end=mountain.size()-1;

        // while(st<end){
        //     int mid=st+(end-st)/2;

        //     if(mountain[mid]>mountain[mid+1]){
        //         res.push_back(mid);
        //         end=mid;
        //     }
        //     else{
        //         st=mid+1;
        //     }
        // }
        for(int i=1;i<mountain.size()-1;i++){
            if(mountain[i-1]<mountain[i] && mountain[i]>mountain[i+1]){
                res.push_back(i);
            }
        }

        return res;
    }
};
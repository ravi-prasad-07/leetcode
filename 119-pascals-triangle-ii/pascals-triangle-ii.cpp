class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> res;
        long long num=1,i=rowIndex;
        
        for(int j=0;j<=i;j++){
            res.push_back(num);
            num=num*(i-j)/(j+1);
        }

        return res;
    }
};
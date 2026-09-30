class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA=0;
        int sumB=0;

        for(auto x: aliceSizes){
            sumA+=x;
        }
        for(auto y: bobSizes){
            sumB+=y;
        }

        int diff=(sumB-sumA)/2;

        unordered_set<int> bob(bobSizes.begin(), bobSizes.end());

        for(auto x: aliceSizes){
            int y=x+diff;

            if(bob.count(y)){
                return {x, y};
            }
        }

        return {};
    }
};
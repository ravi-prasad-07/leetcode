
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD=1e9+7;

        sort(inventory.rbegin(), inventory.rend());
        inventory.push_back(0);

        long long profit=0;
        int n=inventory.size();

        for(int i=0; i<n-1 && orders>0; i++){
            long long high=inventory[i];
            long long low=inventory[i+1];
            long long width=i+1;

            long long count=(high-low)*width;

            if(count<=orders){
                long long sum=high*(high+1)/2 - low*(low+1)/2;

                profit=(profit+sum*width)%MOD;
                orders-=count;
            }
            else{
                long long full=orders/width;
                long long remainder=orders%width;
                long long last=high-full;

                long long sum=high*(high+1)/2 - last*(last+1)/2;

                profit=(profit+sum*width)%MOD;
                profit=(profit+remainder*last)%MOD;

                orders=0;
            }
        }

        return profit;
    }
};
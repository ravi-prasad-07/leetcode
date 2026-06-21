class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1){
            return 1;
        }

        int case1=1,case2=1;
        int max1=INT_MIN, max2=INT_MIN;
        bool c1=false, c2=false;

        for(int i=0;i<arr.size()-1;i++){
            if(i%2!=0 && arr[i]>arr[i+1]){
                case1++;
                c1=true;
            }
            else if(i%2==0 && arr[i]<arr[i+1]){
                case1++;
                c1=true;
            }
            else{
                c1=false;
            }

            max1=max(max1,case1);

            if(c1==false){
                case1=1;
            }
        }

        for(int i=0;i<arr.size()-1;i++){
            if(i%2==0 && arr[i]>arr[i+1]){
                case2++;
                c2=true;
            }
            else if(i%2!=0 && arr[i]<arr[i+1]){
                case2++;
                c2=true;
            }
            else{
                c2=false;
            }

            max2=max(max2,case2);

            if(c2==false){
                case2=1;
            }
        }

        return max(max1, max2);
    }
};
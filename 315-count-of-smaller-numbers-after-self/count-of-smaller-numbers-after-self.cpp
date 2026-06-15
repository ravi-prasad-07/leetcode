class Solution {
public:

    void merge(vector<pair<int, int>>& arr, vector<int>& ans, int left, int mid, int right){
        int low=left,high=mid+1;
        int cnt=0;

        vector<pair<int, int>> temp;

        while(low<=mid && high<=right){
            if(arr[low].first <= arr[high].first){
                temp.push_back(arr[low]);
                ans[arr[low].second] += cnt;
                low++;
            }
            else{
                temp.push_back(arr[high]);
                cnt++;
                high++;
            }
        }

        while(low<=mid){
            temp.push_back(arr[low]);
            ans[arr[low].second] += cnt;
            low++;
        }
        while(high<=right){
            temp.push_back(arr[high]);
            high++;
        }

        for(int i=0;i<temp.size();i++){
            arr[i+left]=temp[i];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, vector<int>& ans, int left, int right){
        if(left>=right){
            return;
        }

        int mid=left+(right-left)/2;

        mergeSort(arr, ans, left, mid);
        mergeSort(arr, ans, mid+1, right);

        merge(arr, ans, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> arr;
        vector<int> ans(nums.size(), 0);

        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, ans, 0, nums.size()-1);

        return ans;
    }
};
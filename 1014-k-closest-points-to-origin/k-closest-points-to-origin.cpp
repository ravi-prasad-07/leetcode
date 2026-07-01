class Solution {
public:

    int dist(vector<int>& arr){
        return arr[0]*arr[0] + arr[1]*arr[1];
    }

    int partition(vector<vector<int>>& points, int low, int high) {
        int random = low + rand() % (high - low + 1);
        swap(points[low], points[random]);

        int piv = dist(points[low]);

        int i=low+1;
        int j=high;

        while(true){
            while(i<=high && dist(points[i])<=piv){
                i++;
            }

            while(j>=low+1 && dist(points[j])>piv){
                j--;
            }

            if(i>=j){
                break;
            }

            swap(points[i], points[j]);
        }

        swap(points[low], points[j]);

        return j;
    }

    void randQuickSelect(vector<vector<int>>& arr, int i, int j, int k){
        if(i>=j){
            return;
        }

        int pivot=partition(arr, i, j);

        if(pivot==k){
            return;
        }

        if(pivot>k){
            randQuickSelect(arr, i, pivot-1, k);
        }
        else{
            randQuickSelect(arr, pivot+1, j, k);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        randQuickSelect(points, 0, points.size()-1, k-1);

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};
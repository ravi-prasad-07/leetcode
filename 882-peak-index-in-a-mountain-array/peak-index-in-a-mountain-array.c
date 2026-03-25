int peakIndexInMountainArray(int* arr, int arrSize) {

    int st=0,end=arrSize-1,mid;
    while(st<end){
        mid=st+(end-st)/2;
        if(arr[mid]>arr[mid+1]){
            end=mid;
        }
        else{
            st=mid+1;
        }
    }
    return st;
    
}
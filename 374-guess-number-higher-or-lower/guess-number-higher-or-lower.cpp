/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=0, high=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            int api_call=guess(mid);

            if(api_call==0){
                return mid;
            }
            else if(api_call==-1){
                high=mid-1;
            }
            else if(api_call==1){
                low=mid+1;
            }
        }

        return -1;
    }
};
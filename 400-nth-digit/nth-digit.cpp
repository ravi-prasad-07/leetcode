class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9){
            return n;
        }

        long long count=1, digit=9;
        long long start=1;
        while(n>count*digit){
            n-=count*digit;
            digit*=10;
            start*=10;
            count++;
        }

        long long num=start+(n-1)/count;
        long long idx=(n-1)%count;

        string str=to_string(num);

        return str[idx]-'0';

    }
};
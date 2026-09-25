class Solution {
public:
    int mySqrt(int x) {
        //T.C = O(log n)
        long long low = 1, high = x;
        while(low <= high){
            long long mid = low + ((high - low) / 2);
            if(mid * mid <= x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};
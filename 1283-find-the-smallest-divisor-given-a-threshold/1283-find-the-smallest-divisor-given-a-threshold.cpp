class Solution {
public:
    long long sumOfD(vector<int>& nums, int val) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum = sum + ceil((double)nums[i] / (double)val);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //T.C = O(log(maxi) x n);
        //S.C = O(1)
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0;i < n;i++){
            maxi = max(nums[i], maxi);
        }
        int low = 1, high = maxi;
        while(low <= high){
            int mid = low + ((high - low) / 2);
            if(sumOfD(nums, mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Brute Force
        //T.C = O(n^2), S.C = O(1)
        // long long n = nums.size();
        // long long maxi = LONG_MIN;
        // for (int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += nums[j];
        //         maxi = max(sum, maxi);
        //     }
        // }
        // return maxi;
        
        //Optimal Approach using Kadanes Algorithm
        //T.C = O(n), S.C = O(1)
        int n = nums.size();
        long long maxi = LONG_MIN, sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] <= maxSum) {
                currentSum += nums[i];
            }
            else {
                subarrays++;
                currentSum = nums[i];
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        //T.C = O(n × log(sum(nums) - max(nums)))
        //S.C = O(1)
        if (k > nums.size())
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int subarrays = countSubarrays(nums, mid);

            if (subarrays > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};
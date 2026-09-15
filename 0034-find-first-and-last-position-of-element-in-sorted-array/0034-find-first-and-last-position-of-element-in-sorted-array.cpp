class Solution {
public:

    // T.C = 2 * log n, S.C = O(1)
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        if (lb == nums.size() || nums[lb] != target)
            return {-1, -1};
        return {lb, upperBound(nums, target) - 1};
    }
};
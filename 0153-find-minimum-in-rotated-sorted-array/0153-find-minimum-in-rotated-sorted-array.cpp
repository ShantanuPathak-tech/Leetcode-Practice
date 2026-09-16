class Solution {
public:
    int findMin(vector<int>& arr) {
        //T.C = O(log n)
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If the array or the part of array obtained after eliminating is
            // already sorted no need to perform binary search In such case the
            // arr[low] is the minimum element for satisfying such condition the
            // arr[low] should be less than arr[high];
            if (arr[low] <= arr[high]) {
                ans = min(ans, arr[low]);
                break;
            }

            if (arr[low] <= arr[mid]) {
                ans = min(arr[low], ans);
                low = mid + 1; // Pick up the smallest in the right sorted half
                               // and eliminate the rest of array
            } else {
                high = mid - 1;
                ans = min(ans, arr[mid]);
            }
        }
        return ans;
    }
};
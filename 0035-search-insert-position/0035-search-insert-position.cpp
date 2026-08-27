class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Time comp = O(log n);
        //Space comp = O(1)
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }           
        }
        return low;
    }
};
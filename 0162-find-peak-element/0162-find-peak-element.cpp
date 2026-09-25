class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //T.C = O(log n)
        int n = nums.size();
        int low = 1, high = n - 2;
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(nums[mid] > nums[mid - 1]){
                low = mid + 1;
            }
            else if(nums[mid] > nums[mid + 1]){
                high = mid - 1;
            }
            //Else statement for a condition in which the mid is at bottom 
            //for ex nums[] = [1, 5, 1, 2, 1]
            //In such case you can go either way
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
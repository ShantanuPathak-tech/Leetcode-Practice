class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Using separate Variables and Iteration
        // T.C = O(2N), S.C= O(1)
        //  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        //  for(int i = 0;i < nums.size();i++){
        //      if(nums[i] == 0) cnt0++;
        //      if(nums[i] == 1) cnt1++;
        //      if(nums[i] == 2) cnt2++;
        //  }
        //  for(int i = 0; i < cnt0;i++){
        //      nums[i] = 0;
        //  }
        //  for(int i = cnt0; i < cnt0 + cnt1;i++){
        //      nums[i] = 1;
        //  }
        //  for(int i = cnt0+cnt1; i < nums.size();i++){
        //      nums[i] = 2;
        //  }

        // Optimal Approach
        //T.C = O(N), S.C = O(1)
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
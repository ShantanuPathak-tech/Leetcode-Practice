class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = nums.size() - 1;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == val){
                swap(nums[j], nums[i]);
                nums.pop_back();
                i--;
                j--;
            }
        }
        return i+1;
    }
};
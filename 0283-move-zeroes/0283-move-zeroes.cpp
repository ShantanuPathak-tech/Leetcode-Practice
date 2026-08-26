class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Time Comp:- O(n) and S.C:- O(1)
        int i = -1;
        for(int j = 0; j < nums.size(); j++){
            //searches for first 0 to minimize iterations
            if(nums[j] == 0){
                i = j;
                break;
            }
        }
        if(i == -1) return;//if no zeros present return directly no looping
        for(int j = i+1; j < nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Time comp:- O(n)
        //Space comp:- O(1)
        int count = 0;
        int maximum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                maximum = max(maximum, count);
            }
            else{
                count = 0;
            }
        }
        return maximum;
    }
};
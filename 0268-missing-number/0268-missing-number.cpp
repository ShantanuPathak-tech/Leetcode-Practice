class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Sum method might overflow due to the formula calculations being stored

        // int sum = (nums.size() * ( nums.size() + 1 ) ) / 2;
        // int arrsum = 0;
        // for(int i = 0; i< nums.size();i++){
        //     arrsum += nums[i];
        // }
        // return sum - arrsum;

        //Using XOR
        //Time complexity :- O(n)
        //Space complexity :- O(1)
        int xor1 = 0;
        int xor2 = 0;
        for(int i = 0; i < nums.size(); i++){
            xor2 = xor2 ^ nums[i];//XOR's the elements in nums array 
            xor1 = xor1 ^ (i+1);//XOR's all elememts that should be present between 0 to n
        }
        return xor1 ^ xor2;
    }
};
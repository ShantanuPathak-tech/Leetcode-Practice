class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //Brute Force Approach
        //T.C = O(2N), S.C = O(N)
        // int n = nums.size();
        // vector <int> pos;
        // vector <int> neg;
        // for(int i = 0;i < n;i++){
        //     if(nums[i] >= 0){
        //         pos.push_back(nums[i]);
        //     }
        //     else{
        //         neg.push_back(nums[i]);
        //     }
        // }
        // for(int i = 0; i < n/2;i++){
        //     nums[2 * i] = pos[i];
        //     nums[(2 * i) + 1] = neg[i];
        // }
        // return nums;

        //Optimal Approach
        //T.C = O(N), S.C = O(N)
        int n = nums.size();
        vector <int> ans(n, 0);
        int posIndex = 0, negIndex = 1;
        for(int i = 0;i < n;i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex = negIndex + 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex = posIndex + 2;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force 
        //T.C = O(n^2) S.C = O(1);

        // for(int i = 0;i < nums.size();i++){
        //     for(int j = i+1;j< nums.size();j++){
        //         if(nums[i] + nums[j] == target){
        //             return{i, j}; 
        //         }
        //     }
        // }
        // return{};

        //Optimal Approach Using Hashmap
        //T.C = O(n log n) S.C = O(n);

        map <int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];
            int element2 = target - element;
            if(mpp.find(element2) != mpp.end()){
                return {mpp[element2], i};
            }
            mpp[element] = i;
        }
        return{-1, -1};

        
    }
};
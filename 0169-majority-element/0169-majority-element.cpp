class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Brute Force Approach 
        //T.C = O(n^2)
        // for(int i = 0;i < nums.size();i++){
        //     int cnt = 0;
        //     for(int j = 0;j < nums.size();j++){
        //         if(nums[j] == nums[i]){
        //             cnt++;
        //         }
        //     }
        //     if(cnt > (nums.size()/2)){
        //         return nums[i];
        //     }
        // }
        // return 0;

        //Better Approach Using Hashing
        //T.C = O(n log(n))+O(n), S.C = O(n);
        // map<int,int> mpp;
        // for(int i= 0;i <nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it: mpp){
        //     if(it.second > (nums.size()/2)){
        //         return it.first;
        //     }
        // }
        // return 0;

        //Optimal Approach
        //T.C = O(n), S.C = O(1)
        int element = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){ 
            if(cnt == 0){
                element = nums[i];
                cnt = 1;
            }
            else if(nums[i] == element){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        //If Majority element does not exist then check only
        // int cnt1 = 0;
        // for(int i = 0; i< nums.size();i++){
        //     if(nums[i] == element) cnt1++
        // }
        // if(cnt1 > (nums.size() / 2)){
        // return element;
        // }
        //return 0;
        return element;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Brute Force T.C = O(n^2)
        //  vector<int> ans;
        //  for(int i = 0;i < nums.size();i++){
        //      if(ans.size() == 0 || ans[0] != nums[i]){
        //          int cnt = 0;
        //          for(int j = 0;j< nums.size();j++){
        //              if(nums[j] == nums[i]){
        //                  cnt++;
        //              }
        //          }
        //          if(cnt > (nums.size() / 3)){
        //              ans.push_back(nums[i]);
        //          }
        //      }
        //      if(ans.size() == 2){
        //          break;
        //      }
        //  }
        //  return ans;

        // Better Approach T.C = O(n log n), S.C = O(n)
        // map<int, int> mpp;
        // vector<int> ans;
        // int minimum = (nums.size() / 3) + 1;
        // for (int i = 0; i < nums.size(); i++) {
        //     mpp[nums[i]]++;
        //     if (mpp[nums[i]] == minimum) {
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;

        //Optimal Aprroach
        //T.C = O(2N), S.C = O(1)
        vector<int> ans;
        int element1 = INT_MIN, element2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && nums[i] != element2) {
                cnt1 = 1;
                element1 = nums[i];
            } 
            else if(cnt2 == 0 && nums[i] != element1){
                cnt2 = 1;
                element2 = nums[i];
            }
            else if (element1 == nums[i]) {
                cnt1++;
            } 
            else if (element2 == nums[i]){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
            
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0;i < nums.size();i++){
            if(element1 == nums[i]) cnt1++;
            if(element2 == nums[i]) cnt2++;
        }
        int mini = (int) (nums.size() / 3) + 1;
        if(cnt1 >= mini) ans.push_back(element1);
        if(cnt2 >= mini) ans.push_back(element2);

        return ans;
    }
};
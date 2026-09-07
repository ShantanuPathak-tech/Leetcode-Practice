class Solution {
public:
    // Brute Force T.C  = O(n^2)
    //  bool linearSearch(vector<int>& nums, int target){
    //              for(int j = 0; j< nums.size();j++){
    //                  if(nums[j] == target){
    //                      return true;
    //                  }
    //              }
    //              return false;
    //          }
    int longestConsecutive(vector<int>& nums) {
        // int longest = 1;

        // for(int i = 0;i < nums.size();i++){
        //     int x = nums[i];
        //     int cnt = 1;

        //     while(linearSearch(nums, x+1) == true){
        //         x = x+1;
        //         cnt = cnt+1;
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;

        //Better approach
        //T.C = O(N log N)

        // int longest = 1, cnt = 0, last_smaller = INT_MIN;
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] - 1 == last_smaller) {
        //         cnt = cnt + 1;
        //         last_smaller = nums[i];
        //     } else if (last_smaller != nums[i]) {
        //         cnt = 1;
        //         last_smaller = nums[i];
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;

        //Optimal Approach
        //T.C = O(3N)
        if(nums.size() == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int i = 0;i < nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    cnt +=1;
                    x = x+1;
                }
                longest = max(cnt, longest);
            }
        }
        return longest;
    }
};
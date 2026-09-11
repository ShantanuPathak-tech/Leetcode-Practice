class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Brute Force T.C = O(n^3 + ), S.C = 2 * O(no of triplets)
        // set<vector<int>> st;
        //  for (int i = 0; i < nums.size(); i++) {
        //      for (int j = i + 1; j < nums.size(); j++) {
        //          for (int k = j + 1; k < nums.size(); k++) {
        //              if (nums[i] + nums[j] + nums[k] == 0) {
        //                  vector<int> temp = {nums[i], nums[j], nums[k]};
        //                  sort(temp.begin(), temp.end());
        //                  st.insert(temp);
        //              }
        //          }
        //      }
        //  }
        //  vector<vector<int>> ans(st.begin(), st.end());
        //  return ans;
        //---------------------------------------------------------------------------------------------
        // Better Approach Using Hashmap
        // We know that:- nums[i] + nums[j] + nums[k] == 0 so,
        // nums[k] = -(nums[i] + nums[j]) Store this in a D.S and check in
        // hashmap if an element exists who satisfies this and creates a unique
        // Triplet

        // T.C = O(n^2 x log(size of set)), S.C = O(n)
        //  set<vector<int>> st; // Final Answer Set
        //  for (int i = 0; i < nums.size(); i++) {
        //      set<int> hash;
        //      for (int j = i + 1; j < nums.size(); j++) {
        //          int k = -(nums[i] + nums[j]);
        //          if (hash.find(k) != hash.end()) {
        //              vector<int> temp = {nums[i], nums[j], k};
        //              sort(temp.begin(), temp.end());
        //              st.insert(temp);
        //          }
        //          hash.insert(nums[j]);
        //      }
        //  }
        //  vector<vector<int>> ans(st.begin(), st.end());
        //  return ans;

        //---------------------------------------------------------------------------------------------
        // Optimal Aprroach By sorting array and Two Pointers
        //T.C = O(n log n) + O(n^2)
        //S.C = O(no of unique triplets)
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //T.C = O(N), S.C = O(N)
        unordered_map<int, int> mpp;
        int preSum = 0, cnt = 0;
        mpp[0] = 1;
        for(int i = 0;i < nums.size();i++){
            preSum += nums[i];
            int remove = preSum-k;
            cnt += mpp[remove];
            mpp[preSum]++;
        }
        return cnt;
    }
};
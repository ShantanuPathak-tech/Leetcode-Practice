class Solution {
public:
    int jump(vector<int>& nums) {
        //T.C = O(N) as we are traversing each element one at a time 
        //S.C = O(1)
        int jumps = 0, left = 0, right = 0;
        while(right < nums.size() - 1){
            int farthest = 0;
            for(int i = left;i <= right;i++){
                farthest = max(i + nums[i], farthest);
            }
            left = right + 1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
};
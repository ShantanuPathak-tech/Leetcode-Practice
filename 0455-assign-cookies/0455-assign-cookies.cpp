class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //T.C = O(N log N + M log M + M)
        //S.C = O(1);
        int n = g.size(), m = s.size();
        int left = 0, right = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(left < m && right < n){
            if(g[right] <= s[left]){
                right++;
            }
            left++;
        }
        return right;
    }
};
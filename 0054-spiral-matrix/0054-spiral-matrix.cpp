class Solution {
public:
    // The first two loops are guaranteed safe by the main while condition, but
    // the last two need if checks because modifying top++ and right-- mid-cycle
    // can cause them to re-traverse and duplicate already-processed rows or
    // columns.
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        //T.C = O(n x m) for traversal
        //S.C = O(1) or O(n x m) if counted for storage

        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {

            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // Handles the edge case if there is a single row nothing to
            // traverse backward
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
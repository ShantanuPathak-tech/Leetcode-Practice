class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Brute force approach using another matrix
        //T.C = O(n^2), S.C = O(n^2)
        // int n;
        // vector<vector<int>> ans(n, vector<int>(n, 0));
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;i < n;i++){
        //         ans[j][n-i-1] = matrix[i][j];
        //     }
        // }

        //Optimal Approach
        //Transpose The Matrix
        //T.C = O(n^2)
        //S.C = O(1)
        int n = matrix.size();
        for(int i = 0;i < n-1;i++){
            for(int j = i+1;j < n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //Reverse the Rows of the Transposed Matrix
        for(int i = 0;i < n;i++){
            //row is matrix[i]
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
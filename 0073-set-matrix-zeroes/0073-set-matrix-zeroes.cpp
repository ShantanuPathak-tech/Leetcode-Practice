class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        //Brute Approach
        //T.C = O(2 x n x m)
        //S.C = O(n)+O(m)
        // size_t n = matrix.size();
        // size_t m = matrix[0].size();

        // vector<int> row(n,0);
        // vector<int> col(m,0);
        // for(size_t i = 0; i< n;i++){
        //     for(size_t j = 0;j < m;j++){
        //         if(matrix[i][j] == 0){
        //             row[i] = 1;
        //             col[j] = 1;
        //         }
        //     }
        // }
        // for(size_t i = 0;i < n;i++){
        //     for(size_t j = 0;j< m;j++){
        //         if(row[i] == 1 || col[j] == 1){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        //Optimal Approach
        //T.C = O(2 x n x m)
        // vector<int> row(n,0); -> matrix[..][0]
        // vector<int> col(m,0); -> matrix[0][..];
        size_t n = matrix.size();
        size_t m = matrix[0].size();
        int col0 = 1;

        for(size_t i = 0; i< n;i++){
            for(size_t j = 0;j < m;j++){
                 if(matrix[i][j] == 0){
                    //mark the ith row
                    matrix[i][0] = 0;
                    //mark the jth column
                    if(j != 0){
                    matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                 }
            }
        }
        for(int i = 1;i < n;i++){
            for(int j = 1;j < m;j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int j = 0;j < m;j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0;i < n;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
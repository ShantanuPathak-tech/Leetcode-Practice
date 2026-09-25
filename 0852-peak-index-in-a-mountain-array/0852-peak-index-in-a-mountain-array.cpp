class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        //T.C = O(log n)
        int st = 1; 
        int end = A.size()-2;

        if(A.size() == 1) return 0;
        if(A[0] > A[1]) return 0;
        if(A[A.size()-1] > A[A.size() - 2]) return A.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(A[mid-1] < A[mid] && A[mid] > A[mid+1]){
                return mid;
            } else if(A[mid-1] < A[mid]){
                st = mid+1;
            } else{
                end = mid-1;
            }
        }

        return -1;
        
    }
};
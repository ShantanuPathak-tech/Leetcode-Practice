class Solution {
public:
    int findMax(vector<int>& piles) {
        int maximum = INT_MIN;
        int n = piles.size();
        for(int i = 0;i < n;i++){
            maximum = max(maximum, piles[i]);
        }
        return maximum;
    }
    long long totalHours(vector<int>& piles, int h){
        long long totalH = 0;
        int n = piles.size();
        for(int i = 0;i < n;i++){
            totalH += ceil((double)piles[i] / (double)h);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //T.C = O(n * log (maxElement))
        int low = 1, high = findMax(piles);
        while(low <= high){
            int mid = low + ((high - low) / 2); 
            long long totalH = totalHours(piles, mid);
            if(totalH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
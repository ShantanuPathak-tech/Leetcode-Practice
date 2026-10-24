class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //T.C = O(N)
        long long lSum = 0, rSum = 0, maxSum = 0;
        int n = cardPoints.size();
        for (int i = lSum; i < k; i++) {
            lSum += cardPoints[i];
        }
        maxSum = lSum;

        int rIndex = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            lSum -= cardPoints[i];
            rSum += cardPoints[rIndex];
            rIndex--;
            maxSum = max(maxSum, lSum + rSum);
        }
        return maxSum;
    }
};
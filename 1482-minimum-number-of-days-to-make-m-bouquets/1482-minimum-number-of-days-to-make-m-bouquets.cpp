class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        int bouquet = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                bouquet += cnt / k;
                cnt = 0;
            }
        }
        bouquet += cnt / k;
        if (bouquet >= m)
            return true;
        else
            return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //Brute Force Approach
        //T.C = O(n * (maxi - mini))
        // int n = bloomDay.size();

        // if ((long long)m * k > bloomDay.size())
        //     return -1;

        // int mini = INT_MAX, maxi = INT_MIN;
        // for (int i = 0; i < n; i++) {
        //     mini = min(bloomDay[i], mini);
        //     maxi = max(bloomDay[i], maxi);
        // }
        // for (int i = mini; i <= maxi; i++) {
        //     if (possible(bloomDay, m, k, i) == true) {
        //         return i;
        //     }
        // }
        // return -1;

        //Optimal Approach using binary search
        //T.C = O(n x log(maxi - mini + 1))
        //S.C = O(1)
        int n = bloomDay.size();
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(bloomDay[i], mini);
            maxi = max(bloomDay[i], maxi);
        }
        int low = mini, high = maxi;
        if ((long long)m * k > bloomDay.size())
           return -1;

        while(low <= high){
            int mid = low + ((high - low) / 2);
            if(possible(bloomDay, m, k, mid) == true){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
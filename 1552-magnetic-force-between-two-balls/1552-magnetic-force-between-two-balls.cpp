class Solution {
public:
    bool canWePlace(vector<int>& position, int dist, int m) {
        int cntBalls = 1, last = position[0];
        for (int i = 1; i < position.size(); i++){
            if(position[i] - last >= dist){
                cntBalls++;
                last = position[i];
            }
            if(cntBalls >= m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        //T.C = O(n log n)
        //S.C = O(1)
        sort(position.begin(), position.end());
        int low = 0, high = position[position.size()-1] - position[0];
        while(low <= high){
            int mid = low + ((high - low) / 2);
            if(canWePlace(position, mid, m) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};
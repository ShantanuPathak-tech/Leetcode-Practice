class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //T.C = O(N), S.C = O(1)
        int five = 0, ten = 0; //No need to take 20 as we are not returning 20 to anyone
        for(int i = 0;i < bills.size(); i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                if(five > 0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five = five - 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
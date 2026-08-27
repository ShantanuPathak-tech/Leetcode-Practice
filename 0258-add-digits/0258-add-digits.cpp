class Solution {
public:
    int addDigits(int num) {
        //Time comp:- O(log n)
        //Space comp:- O(1)
        if(num < 10){
            return num;
        }
        while(num > 9){
            int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        num = sum;
        }
        return num;
    }
};
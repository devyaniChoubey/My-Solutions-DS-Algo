https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;

        int five = 1, ten = 0, twenty = 0;
        for(int i=1;i < bills.size();i++){
            if(bills[i] == 5){
                five++;
            }else if(bills[i] == 10){
                if(five < 0) return false;
                else {
                    five--;
                    ten++;
                }
            }else if(bills[i] == 20){
                if(five > 0){
                    if(ten > 0){
                        ten--;
                        five--;
                        twenty++;
                    }else if(five > 2){
                        five -= 3;
                        twenty++;
                    }else return false;
                }else return false;
            }
        }

        return true;
    }
};
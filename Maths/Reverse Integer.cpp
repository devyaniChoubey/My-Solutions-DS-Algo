https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        bool neg = false;

        if(x < 0) neg = true;
        int reversed = 0;

        x = abs(x);

        while(x != 0){
            int rem = x%10;

            x = x/10;

            if(reversed > INT_MAX/10 || (reversed == INT_MAX/10 && rem > 7)){
                return 0;
            }

            reversed = reversed*10+rem;
        }

        if(neg)return -1 * reversed;
        else return reversed;


    }
};
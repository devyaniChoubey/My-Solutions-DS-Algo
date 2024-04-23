https://leetcode.com/problems/powx-n/


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool sign = true;
        if(n < 0) sign = false;

        n = abs(n);

        while(n > 0){
            if(n % 2 == 1){
                ans = ans*x;
                n--;
            }else{
                x = x*x;
                n = n/2;
            }
        }

        if(!sign) return 1/ans;

        return ans;
    }
};
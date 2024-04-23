https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if(dividend < 0 && divisor >= 0) sign = false;
        else if(dividend >= 0 && divisor < 0) sign = false;

        long num = abs(dividend);
        long den = abs(divisor);

        int quotient = 0;
        
        while(num >= den){
            int cnt = 0;

            while(den << (cnt+1) <= num){
                cnt++;
            }

            num -= (den << cnt);
            quotient += (1 << cnt);
        }

        if(quotient == (1 << 31) && sign == true) return INT_MAX;
        else if(quotient == (1 << 31) && sign == false) return INT_MIN;

        return sign ? quotient : -quotient;

    }
};
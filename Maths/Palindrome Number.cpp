https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long long reversed = 0;
        long long temp = x;

        while(temp != 0){
            int d = temp%10;
            reversed = reversed*10 + d;
            temp = temp/10;
        }

        return (reversed == x);
    }
};



class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversed = 0;

        while(x > reversed){
            int d = x%10;
            reversed = reversed*10 + d;
            x = x/10;
        }

        if(x == reversed || x == reversed/10) return true;
        else return false;
    }
};
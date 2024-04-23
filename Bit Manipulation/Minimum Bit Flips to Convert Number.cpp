
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

start = 10101001
goal = 10100011

start^goal = 00001010

count no of set bits in start^goal

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = (start ^ goal);
        
        int setBits = 0;

        while(n != 0){
            n = n&(n-1);
            setBits++;
        }

        return setBits;
    }
};
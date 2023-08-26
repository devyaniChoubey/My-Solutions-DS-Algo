https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int totalZeroes = 0;
        int n = s.length();
        for(char c:s){
            if(c == '0') totalZeroes++;
        }

        // convert all 0s to 1s or all 1s to 0s
        int res = min(totalZeroes, n - totalZeroes);

        int zeroesLeft = 0, zeroesRight = 0, onesLeft = 0;
        for(int i=0;i < n;i++){
            if(s[i] == '0') zeroesLeft++;

            onesLeft = (i+1) - zeroesLeft;
            zeroesRight = totalZeroes - zeroesLeft;

            // convert onesLeft to 0s and zerosRight to 1s
            res = min(res, onesLeft + zeroesRight);
        }

        return res;
    }
};
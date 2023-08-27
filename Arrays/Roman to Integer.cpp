
https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;

        int roman[24] = {};

        roman['I' - 'A'] = 1;
        roman['V' - 'A'] = 5;
        roman['X' - 'A'] = 10;
        roman['L' - 'A'] = 50;
        roman['C' - 'A'] = 100;
        roman['D' - 'A'] = 500;
        roman['M' - 'A'] = 1000;

        int n = s.length();

        int res = 0;

        for(int i=0;i < n;i++){
            int s1 = roman[s[i] - 'A'];

            if(i+1 < n){
                int s2 = roman[s[i+1] - 'A'];

                if(s1 >= s2){
                    res += s1;
                }else{
                    res += (s2 - s1);
                    i++;
                }

            }else{
               res += s1;
            }
        }

        return res;

    }
};
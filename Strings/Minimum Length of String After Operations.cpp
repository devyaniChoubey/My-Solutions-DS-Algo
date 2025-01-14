https://leetcode.com/problems/minimum-length-of-string-after-operations/?envType=daily-question&envId=2025-01-13

class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26, 0);
        for(char &c:s){
            freq[c-'a']++;
        }

        int ans = s.length();

        for(int i=0;i < 26;i++){
            if(freq[i] >= 2 && freq[i] % 2 == 0){
                ans -= (freq[i] - 2);
            }else if(freq[i] % 2 != 0){
                ans -= (freq[i] - 1);
            }
        }

        return ans;
    }
};
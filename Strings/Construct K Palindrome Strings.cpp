https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>freq(26, 0);

        int n = s.length();

        if(n < k) return false;
        if(n == k) return true;
        for(int i=0;i < n;i++){
            freq[s[i] - 'a']++;
        }

        int oddCnt = 0;

        for(int i=0;i < 26;i++){
            if(freq[i] % 2 != 0){
                oddCnt++;
            }
        }

        if(oddCnt > k) return false;
        return true;
    }
};
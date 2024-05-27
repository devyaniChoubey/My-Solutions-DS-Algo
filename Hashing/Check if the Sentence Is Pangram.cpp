https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[26] = {};
        int count = 0;

        for(char &c:sentence){
            if(cnt[c-'a'] == 0) count++;
            cnt[c-'a']++;
        }

        if(count == 26) return true;
        else return false;
    }
};
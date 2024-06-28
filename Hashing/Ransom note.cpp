https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter[26] = {};

        for(char &c:magazine) counter[c-'a']++;

        for(char &c:ransomNote){
            counter[c-'a']--;
            if(counter[c-'a'] < 0) return false;
        }

        return true;
    }
};
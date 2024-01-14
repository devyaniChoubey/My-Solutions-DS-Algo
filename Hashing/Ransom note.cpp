https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(26, 0);

        for(int i=0;i < magazine.size();i++) freq[magazine[i] - 'a']++;
        
        for(int i=0;i < ransomNote.size();i++){
            if(freq[ransomNote[i] - 'a'] > 0) {
                freq[ransomNote[i] - 'a']--;
            }else return false;
        }

        return true;

    }
};
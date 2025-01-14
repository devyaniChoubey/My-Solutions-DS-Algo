https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>firstPos(26, -1);
        vector<int>lastPos(26, -1);

        for(int i=0;i < s.length();i++){
            int pos = s[i] - 'a';
            if(firstPos[pos] == -1) firstPos[pos] = i;
            lastPos[pos] = i;
        }
        int res = 0;

        for(int i=0;i < 26;i++){
            if(firstPos[i] == -1) continue;

            unordered_set<char>between;
            for(int position=firstPos[i]+1;position < lastPos[i];position++){
                between.insert(s[position]);
            }

            res += between.size();
        }

        return res;
    }
};
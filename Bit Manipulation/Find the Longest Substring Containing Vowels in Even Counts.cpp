https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>charMap(26, 0);

        charMap['a' - 'a'] = 1;
        charMap['e' - 'a'] = 2;
        charMap['i' - 'a'] = 4;
        charMap['o' - 'a'] = 8;
        charMap['u' - 'a'] = 16;

        vector<int>prefixMap(32, -1);
        int xorVal = 0;
        int ans = 0;

        for(int i=0;i < s.length();i++){
            xorVal ^= charMap[s[i] - 'a'];

            if(prefixMap[xorVal] == -1 && xorVal != 0) prefixMap[xorVal] = i;

            ans = max(ans, i - prefixMap[xorVal]);
        }

        return ans;
    }
};
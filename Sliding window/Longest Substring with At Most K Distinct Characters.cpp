https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int>mp;
        int left = 0, right = 0;
        int n = s.length();
        int len = 0;

        while(right < n){
            mp[s[right]] = right;

            if(mp.size() > k){
                int del_idx = INT_MAX;

                for(auto it:mp){
                    del_idx = min(del_idx , it.second);
                }

                mp.erase(s[del_idx]);
                left = del_idx + 1;
            }

            len = max(len, right - left + 1);

            right++;
        }

        return len;
    }
};
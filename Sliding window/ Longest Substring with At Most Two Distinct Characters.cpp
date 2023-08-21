https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int>mp;
        int n = s.length();

        int left = 0, right = 0;

        int len = 0;

        while(right < n){
            mp[s[right]] = right;

            if(mp.size() > 2){
                int del_idx = INT_MAX;
                for(auto it:mp){
                    del_idx = min(del_idx, it.second);
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




class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int>mp;
        int n = s.length();

        int left = 0, right = 0;

        int len = 0;

        while(right < n){
            mp[s[right]]++;
            while(mp.size() > 2){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }

            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }
};
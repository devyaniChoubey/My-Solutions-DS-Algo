https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


// O(2*N) time complexity
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        int n = s.length();

        map<char, int>mp;
        int ans = 0;

        while(right < n){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;

        }

        return ans;
    }
};


// O(N) time complexity

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        vector<int>mp(256, -1);
        int n = s.length();
        int ans = 0;

        while(right < n){
            if(mp[s[right]] != -1){
                left = max(left, mp[s[right]] + 1);
            }

            ans = max(ans, right - left + 1);
            mp[s[right]] = right;
            right++;
        }

        return ans;
    }
};

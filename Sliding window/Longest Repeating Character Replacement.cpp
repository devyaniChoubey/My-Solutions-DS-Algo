https://leetcode.com/problems/longest-repeating-character-replacement/description/

https://leetcode.com/problems/longest-repeating-character-replacement/solutions/91285/sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters/


// The problem says that we can make at most k changes to the string (any character can be replaced with any other character).
//  So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes. 
//  The answer to this is

// length of the entire string - number of times of the maximum occurring character in the string

// Given this, we can apply the at most k changes constraint and maintain a sliding window such that

// (length of substring - number of times of the maximum occurring character in the substring) <= k

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26, 0);
        int left = 0, right = 0;
        int n = s.length();
        int maxCharCount = 0;
        int ans = 0;

        while(right < n){
            hash[s[right] - 'A']++;

            maxCharCount = max(maxCharCount, hash[s[right] - 'A']);

            while(right - left + 1 - maxCharCount > k){
                hash[s[left] - 'A']--;
                left++;
                for(auto it:hash){
                    maxCharCount = max(maxCharCount, it);
                }
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};
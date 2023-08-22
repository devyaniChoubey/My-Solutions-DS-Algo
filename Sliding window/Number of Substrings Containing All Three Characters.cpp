https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/


// Explanation for count += 1 + (end - right)
// Example : abcabc

// 0 1 2 3 4 5
// a b c a b c

// l = 0, r = 0, end = 5
// Valid Windows->

// 1st Window : abc
// l = 0, r = 2 and count -> 1 + (5 - 2) = 4
// The substrings for this window are:
// abc, abca, abcab, abcabc

// 2nd Window: bca
// l = 1, r = 3 and count -> 1 + (5 - 3) = 3
// The substrings for this window are:
// bca, bcab, bcabc

// 3rd Window: cab
// l = 2, r = 4 and count -> 1 + (5 - 4) = 2
// The substrings for this window are:
// cab, cabc

// 2nd Window: abc
// l = 3, r = 5 and count -> 1 + (5 - 5) = 1
// The substring for this window is:
// abc

// Total count = 4 + 3 + 2 + 1 = 10


class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>mp(3, 0);
        int n = s.length();
        
        int end = n-1;
        int left = 0, right = 0;
        int countSubArray = 0;

        while(right < n){
            mp[s[right] - 'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                countSubArray += (end - right) + 1;
                mp[s[left] - 'a']--;
                left++;
            }

            right++;
        }

        return countSubArray;
    }
};
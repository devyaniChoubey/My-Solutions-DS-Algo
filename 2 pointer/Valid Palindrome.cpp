https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;

        int start = 0, end = s.length();

        while(start <= end){
            if(!isalnum(s[start])) start++;
            else if(!isalnum(s[end])) end--;
            else{
                if(tolower(s[start]) != tolower(s[end])) return false;
                else{
                    start++;
                    end--;
                }
            }
        }

        return true;
    }
};
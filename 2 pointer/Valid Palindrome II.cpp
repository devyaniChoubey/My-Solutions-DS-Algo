// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:

    bool isPalindrome(int left, int right, string s){
        while(left <= right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        

        while(left <= right){
            if(s[left] != s[right]){
                return (isPalindrome(left, right-1,s) || isPalindrome(left+1, right,s));
            }
            left++;
            right--;
        }

        return true;

    }
};
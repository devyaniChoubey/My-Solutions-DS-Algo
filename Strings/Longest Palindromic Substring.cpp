https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string helper(int left,int right,  string s){
        int n = s.length();
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;right++;
        }

        return s.substr(left+1, right - left - 1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans;
        for(int i=0;i < n;i++){
            if(helper(i,i, s).length() > ans.length()){
                ans = helper(i,i, s);
            }

            if(i < n - 1 && helper(i,i+1, s).length() > ans.length()){
                ans = helper(i,i+1, s);
            }
        }

        return ans;
    }
};
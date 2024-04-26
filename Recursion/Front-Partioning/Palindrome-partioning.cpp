https://leetcode.com/problems/palindrome-partitioning/submissions/991077825/

class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start] != s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int ind, string &s, vector<string>&path, vector<vector<string>>&ans){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=ind;i < s.size();i++){
            if(isPalindrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(0, s, path, ans);
        return ans;
    }
};
https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    void solve(int ind,string &s, string &path, vector<string>&ans, unordered_set<string>&dict){
        if(ind == s.length()){
            ans.push_back(path);
            return;
        }

        for(int i=ind;i < s.length();i++){
            if(dict.count(s.substr(ind, i-ind+1))){
                string temp = path;
                if(path.length() != 0) path.append(" ");
                path.append(s.substr(ind, i-ind+1));
                solve(i+1,s, path, ans, dict);
                path = temp;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        string path;
        vector<string>ans;
        solve(0,s, path, ans, dict);
        return ans;
    }
};
https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    unordered_set<string>wordList;
    void solve(int pos, string res, string s, vector<string>&ans){
        int n = s.length();
        if(pos >= n){
            //remove empty space
            ans.push_back(res.substr(1, res.size() - 1));
            return;
        }

        for(int i=pos;i < n;i++){
            if(wordList.count(s.substr(pos, i-pos+1))){
                solve(i+1, res + " " + s.substr(pos, i-pos+1), s, ans);
            }
        }

    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict) wordList.insert(it);
        vector<string>ans;
        solve(0, "", s, ans);
        return ans;
    }
};
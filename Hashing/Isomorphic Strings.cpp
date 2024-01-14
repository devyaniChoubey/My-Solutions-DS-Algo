
https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>s_t, t_s;

        for(int i=0;i < s.length();i++){
            if(s_t.find(s[i]) != s_t.end() || t_s.find(t[i]) != t_s.end()){
                if(s_t[s[i]] != t[i] || t_s[t[i]] != s[i]) return false;
            }else{
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
        }

        return true;
    }
};
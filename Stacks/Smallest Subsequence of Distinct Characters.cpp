https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>last_occurence;
        unordered_map<char,bool>seen;

        stack<char>st;

        for(int i=0;i < s.length();i++) last_occurence[s[i]] = i;

        for(int i=0;i < s.length();i++){
            if(seen.find(s[i]) != seen.end()) continue;

            while(!st.empty() && st.top() > s[i] && last_occurence[st.top()] > i){
                seen.erase(st.top());
                st.pop();
            }

            st.push(s[i]);
            seen[s[i]] = true;
        }

        string ans = "";

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i < s.length();i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
            else{
                if(!st.empty()){
                    char c = st.top();
                    if(s[i] == ']' && c != '[') return false;
                    if(s[i] == '}' && c != '{') return false;
                    if(s[i] == ')' && c != '(') return false;
                    st.pop();
                }else return false;
            }
        }

        return st.size() == 0;
    }
};
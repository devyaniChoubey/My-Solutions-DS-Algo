https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i < s.length();i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else s[i] = '*';
            }
        }

        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
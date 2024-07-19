https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/editorial

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>openParenthesesIndices;
        string result = "";

        for(char &c:s){
            if(c == '('){
                openParenthesesIndices.push(result.size());
            }else if(c == ')'){
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                reverse(result.begin() + start, result.end());
            }else{
                result.push_back(c);
            }
        }

        return result;
    }
};




class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();

        vector<int>pair(n);
        stack<int>st;

        for(int i=0;i < n;i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                int left = st.top();
                st.pop();
                pair[left] = i;
                pair[i] = left;
            }
        }

        string result = "";

        for(int curInd=0, direction=1;curInd < n;curInd+=direction){
            if(s[curInd] == '(' || s[curInd] == ')'){
                curInd = pair[curInd];
                direction = -direction;
            }else{
                result.push_back(s[curInd]);
            }
        }

        return result;
    }
};
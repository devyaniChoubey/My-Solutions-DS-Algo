https://leetcode.com/problems/remove-k-digits/description/

class Solution {
public:
    string removeKdigits(string &num, int k) {
        stack<char>st;
        for(char c: num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }

            if(st.empty() && c == '0'){}
            else st.push(c);

        }

        while(!st.empty() && k > 0){
            st.pop();
            k--; 
        }

        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin() , res.end());

        if(res.length() == 0)return "0";
        else return res;
    }   
};
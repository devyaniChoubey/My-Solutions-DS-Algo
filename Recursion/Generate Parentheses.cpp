https://leetcode.com/problems/generate-parentheses/

//Solution1

class Solution {
public:
    void solve(int leftCount , int rightCount,string &temp, vector<string>&ans,int n){
        if(temp.size() == 2*n) {
            ans.push_back(temp);
            return;
        }

        if(leftCount < n){
            temp.push_back('(');
            solve(leftCount+1, rightCount, temp, ans, n);
            temp.pop_back();
        }

        if(leftCount > rightCount){
            temp.push_back(')');
            solve(leftCount, rightCount+1, temp, ans, n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;

        solve(0, 0, temp, ans,n);

        return ans;
    }
};


//Solution2

class Solution {
public:
    void solve(string &temp, stack<char>&st, vector<string>&ans,int n){
        if(temp.length() == n*2 && st.size() == 0) {
            ans.push_back(temp);
            return;
        }else if(temp.length() == n*2){
            return;
        }

        if(st.size() < n){
            temp.push_back('(');
            st.push('(');
            solve(temp, st, ans,n);
            temp.pop_back();
            st.pop();
        }

        if(!st.empty()){
            st.pop();
            temp.push_back(')');
            solve(temp, st, ans,n);
            temp.pop_back();
            st.push('(');
        }
    }
    vector<string> generateParenthesis(int n) {
        stack<char>st;

        st.push('(');

        vector<string>ans;

        string temp = "(";

        solve(temp, st, ans,n);

        return ans;
    }
};
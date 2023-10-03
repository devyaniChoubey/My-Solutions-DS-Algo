https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string s) {
    stack<char>st;
    
    for(char ch:s){
        if(ch == ')'){
            char top = st.top();
            st.pop();
            
            bool flag = true;
            while(!st.empty() && top != '('){
                if(top == '+' || top == '-' || top == '*' || top == '/') flag = false;
                
                top = st.top();
                st.pop();
            }
            
            if(flag) return true;
        }else st.push(ch);
    }
    
    return false;
}

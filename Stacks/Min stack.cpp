https://leetcode.com/problems/min-stack/description/

class MinStack {
public:

    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = val;
        if(!st.empty()) minVal = min(val, st.top().second);;
        st.push({val, minVal});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


//Method 2

class MinStack {
public:
    stack<int>st;
    stack<vector<int>>minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty() || val < minStack.top()[0]) minStack.push({val, 1});
        else if(val == minStack.top()[0]) minStack.top()[1]++;
    }
    
    void pop() {
        if(st.top() == minStack.top()[0]) minStack.top()[1]--;

        if(minStack.top()[1] == 0) minStack.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top()[0];
    }
};

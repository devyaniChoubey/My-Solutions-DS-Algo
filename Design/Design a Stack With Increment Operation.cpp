https://leetcode.com/problems/design-a-stack-with-increment-operation/

https://leetcode.com/problems/design-a-stack-with-increment-operation/solutions/539716/java-c-python-lazy-increment-o-1/

class CustomStack {
public:
    
    int maxS;
    vector<int>stack, inc;
    CustomStack(int maxSize) {
        maxS = maxSize;
    }
    
    void push(int x) {
        if(stack.size() == maxS) return;
        stack.push_back(x);
        inc.push_back(0); 
    }
    
    int pop() {
        int i = stack.size()-1;

        if(i < 0) return -1;
        if(i > 0) inc[i-1] += inc[i];

        int res = stack[i] + inc[i];

        stack.pop_back();
        inc.pop_back();

        return res;
    }
    
    void increment(int k, int val) {
        int i = min(k, (int)stack.size()) - 1;
        if(i >= 0)inc[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
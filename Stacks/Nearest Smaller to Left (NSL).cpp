https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int>leftSmaller(n, -1);
        stack<int>st;
        
        for(int i=0;i < n;i++){
            while(!st.empty() && st.top() >= a[i]) st.pop();
            
            if(!st.empty()) leftSmaller[i] = st.top();
            
            st.push(a[i]);
        }
        
        return leftSmaller;
    }
};
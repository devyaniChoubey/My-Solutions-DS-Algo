https://leetcode.com/problems/largest-rectangle-in-histogram/description/


//Solution 1
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftSmaller(n, 0);
        vector<int>rightSmaller(n, n-1);
        stack<int>st;

        for(int i=n-1;i >= 0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = st.top() - 1;

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i < n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.top() + 1;

            st.push(i);
        }

        int maxArea = 0;

        for(int i=0;i < n;i++){
            maxArea = max(maxArea, (rightSmaller[i] - leftSmaller[i] + 1)*heights[i]);
        }

        return maxArea;
        
    }
};


//Solution 2

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftSmaller(n, -1);
        vector<int>rightSmaller(n, n);
        stack<int>st;

        for(int i=n-1;i >= 0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) rightSmaller[i] = n;
            else rightSmaller[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i < n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) leftSmaller[i] = -1;
            else leftSmaller[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;

        for(int i=0;i < n;i++){
            maxArea = max(maxArea, (rightSmaller[i] - leftSmaller[i] - 1)*heights[i]);
        }

        return maxArea;
        
    }
};
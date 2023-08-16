https://leetcode.com/problems/maximal-rectangle/description/

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;
        vector<int>prevHeight(col, 0), curHeight(col, 0);
        for(int i=0;i < row;i++){
            for(int j=0;j < col;j++){
                if(matrix[i][j] == '1') curHeight[j] = 1 + prevHeight[j];
                else curHeight[j] = 0;
            }
            maxArea = max(largestRectangleArea(curHeight) , maxArea);
            prevHeight = curHeight;
        }

        return maxArea;
    }
};
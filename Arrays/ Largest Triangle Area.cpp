https://leetcode.com/problems/largest-triangle-area/description/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        for(auto a:points){
            for(auto b:points){
                for(auto c:points){
                    double area = (0.5)*abs(
                        a[0]*(b[1] - c[1]) + 
                        b[0]*(c[1] - a[1]) + 
                        c[0]*(a[1] - b[1])
                    );
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
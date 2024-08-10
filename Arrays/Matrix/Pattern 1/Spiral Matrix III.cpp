https://leetcode.com/problems/spiral-matrix-iii/description/?envType=company&envId=google&favoriteSlug=google-thirty-days

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>traversed;
        vector<vector<int>>directions = {{0,1} , {1, 0} , {0, -1},{-1, 0}};
        
        for(int steps = 1, direction = 0;traversed.size() < rows*cols;steps++){
            for(int i=0;i < 2;i++){
                for(int j=0;j < steps;j++){
                    if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)traversed.push_back({rStart, cStart});
                    rStart += directions[direction][0];
                    cStart += directions[direction][1];
                }
                direction = (direction+1)%4;
            }

        }

        return traversed;
    }
};
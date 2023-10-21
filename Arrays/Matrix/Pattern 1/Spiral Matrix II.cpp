https://leetcode.com/problems/spiral-matrix-ii/description/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir = 0;

        vector<vector<int>>ans(n, vector<int>(n, 1));

        int cur = 1;

        int top = 0, bottom = n-1, left = 0, right = n-1;

        while(left <= right && top <= bottom){
            if(dir == 0){
                for(int i=left;i <= right;i++){
                    ans[top][i] = cur++;
                }
                top++;
            }else if(dir == 1){
                for(int i=top;i <= bottom;i++){
                    ans[i][right] = cur++;
                }
                right--;
            }else if(dir == 2){
                for(int i=right;i >= left;i--){
                    ans[bottom][i] = cur++;
                }
                bottom--;
            }else if(dir == 3){
                for(int i=bottom;i >= top;i--){
                    ans[i][left] = cur++;
                }
                left++;
            }

            dir++;
            dir = dir%4;
        }

        return ans;
    }
};
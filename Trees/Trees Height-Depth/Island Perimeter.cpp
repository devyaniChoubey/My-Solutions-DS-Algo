https://leetcode.com/problems/island-perimeter/description/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int m = grid.size();
        int n = grid[0].size();

        int perimeter = 0;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    perimeter += 4;

                    for(int k=0;k < 4;k++){
                        int nRow = i + delRow[k];
                        int nCol = j + delCol[k];
                        
                        if(nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && grid[nRow][nCol] == 1) perimeter--;
                    }
                }
            }
        }

        return perimeter;
    }
};